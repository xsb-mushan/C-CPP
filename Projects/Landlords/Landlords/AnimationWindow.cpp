#include "AnimationWindow.h"

AnimationWindow::AnimationWindow(QWidget* parent) : QWidget(parent)
{
	
}

void AnimationWindow::showBetScore(int bet)
{
	m_x = 0;
	if (bet == 1)
	{
		m_image.load(":/images/score1.png");
	}
	else if (bet == 2)
	{
		m_image.load(":/images/score2.png");
	}
	else if (bet == 3)
	{
		m_image.load(":/images/score3.png");
	}
	update();
	QTimer::singleShot(2000, this, &AnimationWindow::hide);
}

void AnimationWindow::showSequence(Type type)
{
	m_x = 0;
	if (type == SeqSingle)
		m_image.load(":/images/shunzi.png");
	else if (type == SeqPair)
		m_image.load(":/images/liandui.png");
	update();
	QTimer::singleShot(2000, this, &AnimationWindow::hide);
}

void AnimationWindow::showJokerBomb()
{
	m_index = 0;
	m_x = 0;
	QTimer* timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, [=]() {
		m_index++;
		if (m_index > 8)
		{
			timer->stop();
			timer->deleteLater();
			m_index = 8;
			hide();
		}
		QString name = QString(":/images/joker_bomb_%1.png").arg(m_index);
		m_image.load(name);
		update();
	});
	timer->start(60);
}

void AnimationWindow::showBomb()
{
	m_index = 0;
	m_x = 0;
	QTimer* timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, [=]() {
		m_index++;
		if (m_index > 12)
		{
			timer->stop();
			timer->deleteLater();
			m_index = 12;
			hide();
		}
		QString name = QString(":/images/bomb_%1.png").arg(m_index);
		m_image.load(name);
		update();
	});
	timer->start(60);
}

void AnimationWindow::showPlane()
{
	m_x = width();
	m_image.load(":/images/plane_1.png");
	setFixedHeight(m_image.height());
	update();

	int step = width() / 5;
	QTimer* timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, [=]() {
		static int dist = 0;
		static int times = 0;
		dist += 5;
		if (dist >= step)
		{
			dist = 0;
			times++;
			QString name = QString(":/images/plane_%1.png").arg(times % 5 + 1);
			m_image.load(name);
		}
		if (m_x <= -110)
		{
			timer->stop();
			timer->deleteLater();
			dist = times = 0;
			hide();
		}
		m_x -= 5;
		update();
	});
	timer->start(15);
}

void AnimationWindow::paintEvent(QPaintEvent* event)
{
	QPainter p(this);
	p.drawPixmap(m_x, 0, m_image.width(), m_image.height(), m_image);
}
