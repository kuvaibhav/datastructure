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
	Node<Object> *fron;
	Node<Object> *rear;

public:
	LLQueue();

	// Note:  copy constructors are required.
	// Be sure to do a "deep copy" -- if I 
	// make a copy and modify one, it should not affect the other. 
	LLQueue(const LLQueue & st);
	LLQueue & operator=(const LLQueue & st) {
		if (this == &st) {
			return *this;
		}
		while(fron != nullptr) {
			Node<Object> * dupl = fron;
			fron = fron->next;
			delete dupl;
		}
		Node<Object> *t = st.fron;
		while(t!=nullptr) {
			enqueue(t->data);
			t = t->next;
		}
		return *this;
	}

	~LLQueue()
	{
		// You need to implement the destructor also.
		while (fron != nullptr) {
			Node<Object> * dupl = fron;
			fron = fron->next;
			delete dupl;
		}
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
LLQueue<Object>::LLQueue(const LLQueue & st) {
	fron = nullptr;
	rear = nullptr;
	Node<Object>* temp = st.fron;
	while(temp != nullptr) {
		enqueue(temp->data);
		temp = temp->next;
	}
}

template<typename Object>
void LLQueue<Object>::dequeue() {
	if (fron == nullptr) {
		throw QueueEmptyException("Error ! Queue is empty");
	}
	else {
		Node<Object>* t = fron;
		fron = fron->next;
		if (fron == nullptr) {
			rear = nullptr;
		}
		delete t;
	}
}

template<typename Object>
LLQueue<Object>::LLQueue() {
	fron = nullptr;
	rear = nullptr;
}

template<typename Object>
void LLQueue<Object>::enqueue(const Object & elem) {
	Node<Object>* t = new Node<Object>;
	t->data =  elem;
	t->next = nullptr;
	if (fron == nullptr) {
		fron = t;
		rear = t;
	} else {
		rear->next = t;
		rear = t;
		}
	}

template<typename Object>
Object & LLQueue<Object>::front() {
	if (fron == nullptr) {
		throw QueueEmptyException("Error! Queue is empty");
	} else {
		return fron->data;
	}
}

template<typename Object>
const Object & LLQueue<Object>::front() const {
	if (fron == nullptr) {
		throw QueueEmptyException("Error! Queue is empty");
	} else {
		return fron->data;
	}
}

template<typename Object>
bool LLQueue<Object>::isEmpty() const noexcept{
	if (fron == nullptr){
        return true;
    }
    return false;
}

template<typename Object>
size_t LLQueue<Object>::size() const noexcept{
	if (fron == nullptr) {
		return 0;
	} else {
		int size=1;
		Node<Object> *t = fron;
		while(t->next != nullptr) {
			size = size + 1;
			t = t->next;
		}
		return size;
	}
}

#endif 
