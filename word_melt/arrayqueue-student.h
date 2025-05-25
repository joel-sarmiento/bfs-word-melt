/*
 * file: arrayqueue-student.h
 * author: Joel Sarmiento
 *
 * This file implements the methods of ArrayQueue
 */

#ifndef ARRAY_QUEUE_STUDENT_H
#define ARRAY_QUEUE_STUDENT_H

#include "arrayqueue-prof.h"
#include <cassert>


/*
 * ArrayQueue
 *
 * This is a default constructor that creates an ArrayQueue that is empty
 * but has some capacity > 0
 *
 * Parameters:
 *     none
 *
 * Return value: none
 */
template <class Base>
ArrayQueue<Base>::ArrayQueue() {
    capacity = 10;
    data = new Base[capacity];
    length = 0;
    front = 0;
}


/*
 * ArrayQueue
 *
 * This is a copy constructor that creates a deep copy of the given ArrayQueue
 * object
 *
 * Parameters:
 *     q: a queue to be copied
 *
 * Return value: none
 */
template <class Base>
ArrayQueue<Base>::ArrayQueue(const ArrayQueue<Base> &q) {
    capacity = q.capacity;
    data = new Base[capacity];
    length = q.length;
    front = q.front;
    for (int i = 0; i < capacity; ++i) {
        data[i] = q.data[i];
    }
}


/*
 * ~ArrayQueue
 *
 * This is the destructor that cleans up any memory that the ArrayQueue has
 * dynamically allocated, and sets the data members to look like the queue
 * is empty.
 *
 * Parameters: none
 *
 * Return value: none
 */
template <class Base>
ArrayQueue<Base>::~ArrayQueue() {
    delete[] data;
    
    capacity = 10;
    length = 0;
    front = 0;
}


/*
 * add
 *
 * This method adds an element to the back of the queue.
 *
 * Parameters:
 *     item: an element to be added to the queue
 *
 * Return value: none
 */
template <class Base>
void ArrayQueue<Base>::add(const Base &item) {
    if (length == capacity) {
        doubleCapacity();
    }
    
    int rear = (front + length) % capacity;
    data[rear] = item;
    length++;
}


/*
 * remove
 *
 * This method removes one item from the front of the queue
 *
 * Parameters: none
 *
 * Return value: none
 */
template <class Base>
void ArrayQueue<Base>::remove() {
    assert (length != 0);
    front = (front + 1) % capacity;
    length--;
}


/*
 * getFront
 *
 * This method returns the front of the queue
 *
 * Parameters: none
 *
 * Return value: the front of the queue
 */
template <class Base>
const Base &ArrayQueue<Base>::getFront() const {
    assert (length != 0);
    return data[front];
}


/*
 * getLength
 *
 * This method returns the length of the queue
 *
 * Parameters: none
 *
 * Return value: the length of the queue
 */
template <class Base>
int ArrayQueue<Base>::getLength() const {
    return length;
    
}


/*
 * operator=
 *
 * This method first checks to see if the queue we are assigning to is
 * the same as this, and if not, makes a deep copy of the given queue
 *
 * Parameters: 
 *     q: a queue to be copied
 *
 * Return value: a deep copy of a given queue
 */
template <class Base>
const ArrayQueue<Base> &ArrayQueue<Base>::operator=(const ArrayQueue<Base> &q) {
    if (this != &q) {
        delete[] data;
        capacity = q.capacity;
        data = new Base[capacity];
        length = q.length;
        front = q.front;
        for (int i = 0; i < capacity; ++i) {
            data[i] = q.data[i];
        }
    }
    return *this;
}


/*
 * doubleCapacity
 *
 * This method doubles the capacity of the ArrayQueue, and updates
 * the data members so they are now valid for the newly allocated array.
 *
 * Parameters: none
 *
 * Return value: none
 */
template <class Base>
void ArrayQueue<Base>::doubleCapacity() {
    int newCapacity = capacity * 2;
    
    Base *newData = new Base[capacity];
    
    for (int i = 0; i < length; ++i) {
        newData[i] = data[(front + i) % capacity];
    }
    
    front = 0;
    capacity = newCapacity;
    delete[] data;
    data = newData;
}

#endif
