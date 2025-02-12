// stack.h -- class definition for the stack ADT
#ifndef __STACK_H__
#define __STACK_H__

typedef unsigned long Item;

class Stack
{
	private:
		enum {MAX=10};// constant specific to class
		Item items[MAX];// holds stack items
		int top;// index for top stack item
	public:
		Stack();
		bool isempty() const;
		bool isfull() const;
		// push() returns false if stack already is full, true otherwise
		bool push(const Item & item);// add item to stack
		// pop() returns false if stack alraedy is empty, true otherwise
		bool pop(Item & item);// pop top into item
};

#endif
