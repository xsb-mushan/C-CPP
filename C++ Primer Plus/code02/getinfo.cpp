// getinfo.cpp -- input and output
#include<iostream>

int main(void)
{
	using namespace std;
	
	int carrots;
	
	cout<<"How many carrots do you have?"<< endl;
	cin>>carrots;
	cout<<"Here are two more. ";
	carrots=carrots+2;
	//the next line concatenates output
	cout<<"Now you have "<<carrots<<" carrots."<<endl;
	return 0;
}
