#ifndef __PROJ0_QUEUE_HPP
#define __PROJ0_QUEUE_HPP

#include <iostream>
#include "runtimeexcept.hpp"
using namespace std;

class QueueEmptyException : public RuntimeException 
{
public:
	QueueEmptyException(const std::string & err) : RuntimeException(err) {}
};

template<typename Object>
class Node {
public:
	Object data;
	Node* next;
};


template<typename Object>
class LLQueue
{
private:
	// fill in private member data here
	Object o;
	Object *fron;
	Object *rear;

public:
	LLQueue();

	// Note:  copy constructors are required.
	// Be sure to do a "deep copy" -- if I 
	// make a copy and modify one, it should not affect the other. 
	LLQueue(const LLQueue & st);
	LLQueue & operator=(const LLQueue & st);
	~LLQueue()
	{
		// You need to implement the destructor also.
	}

	size_t size() const noexcept;
	bool isEmpty() const noexcept;


	// The first front() function returns the front object in such a way it can be modified.
	// Of course, you wouldn't want to do this if you have a const LLQueue, but you do 
	// want to be able to do so otherwise.  The second function will be called on 
	// a const LLQueue, while others get the first function.
	
	Object & front();
	const Object & front() const;

	void enqueue(const Object & elem);

// does not return anything.  Just removes. 
	void dequeue();
};

// TODO:  Fill in the functions here. 
template<typename Object>
void LLQueue<Object>::dequeue() {
	return;
}

template<typename Object>
LLQueue<Object>::LLQueue() {
	fron = nullptr;
	rear = nullptr;
}

template<typename Object>
void LLQueue<Object>::enqueue(const Object & elem) {
	cout << "enqueuing something" << endl;
	return;
}

template<typename Object>
Object & LLQueue<Object>::front() {
	return o;
}

#endif 
