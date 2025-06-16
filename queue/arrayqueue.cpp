#include "queue.h"
#include <iostream>
using namespace std;
// Constructor implementation
ArrayQueue::ArrayQueue(int initial_capacity)
{
    // TODO: Initialize data members (data, capacity, front_idx, rear_idx)
    // TODO: Allocate memory for the array with the specified initial capacity
    capacity=initial_capacity>=2?initial_capacity:2;
    data=new int[capacity]; 
    front_idx=0;
    rear_idx=-1;
    
}

// Destructor implementation
ArrayQueue::~ArrayQueue()
{
    // TODO: Free the dynamically allocated memory for the array
    delete[] data;
}

// Enqueue implementation (add an item to the rear of the queue)
void ArrayQueue::enqueue(int item)
{
    // TODO: Check if the array is full  
    // TODO: If full, resize the array to double its current capacity

     if(size()==capacity){
        resize(capacity*2);
    }

    // TODO: Add the new element to the rear of the queue
    rear_idx=(rear_idx+1)%capacity;
    data[rear_idx]=item;
}

// Dequeue implementation (remove an item from the front of the queue)
int ArrayQueue::dequeue()
{
    // TODO: Check if the queue is empty, display error message if it is
    if(empty()){
        cout<<"Error! Dequeue operation cannot be done on empty queue."<<endl;
        return -1;
    }
    // TODO: Decrement current_size and return the element at the front of the queue
    // TODO: Update front index

    int item=data[front_idx];
    
    if(front_idx==rear_idx){
        front_idx=0;
        rear_idx=-1;
    }else{
        front_idx=(front_idx+1)%capacity;
    }
    // TODO: Return the dequeued element

    //resize(shrink)
    if(capacity>2 && size()<capacity/4){
        resize(capacity/2);
    }

    return item;
}

// Clear implementation
void ArrayQueue::clear()
{
    // TODO: Reset the queue to be empty (reset capacity, front_idx, rear_idx, data)
    delete[] data;
    capacity=2;
    data=new int[capacity];
    front_idx=0;
    rear_idx=-1;

}

// Size implementation
int ArrayQueue::size() const
{
    // TODO: Return the number of elements currently in the queue
    if(empty()) return 0;

    if(rear_idx>=front_idx){
        return (rear_idx-front_idx+1);
    }else{
        return ((capacity-front_idx)+rear_idx+1);
    }
}

// Front implementation
int ArrayQueue::front() const
{
    // TODO: Check if the queue is empty, display error message if it is
    if(empty()){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    // TODO: Return the element at the front of the queue without removing it
    return data[front_idx];
}

// Back implementation (get the element at the back of the queue)
int ArrayQueue::back() const
{
    // TODO: Check if the queue is empty, display error message if it is
     if(empty()){
        cout<<"Queue is empty"<<endl;

        return -1;
    }
    // TODO: Return the element at the back of the queue without removing it
    return data[rear_idx];
}

// Empty implementation
bool ArrayQueue::empty() const
{
    // TODO: Return whether the queue is empty (current_size == 0)

    return rear_idx==-1;
}

// Print implementation
string ArrayQueue::toString() const
{
    // TODO: Convert queue to a string representation in the format: <elem1, elem2, ..., elemN|
    
    string output="<";

    if(!empty()){

        int cnt=size();

        for(int i=0;i<cnt;i++){

            output+= to_string(data[(front_idx+i)%capacity]);

            if(i<cnt-1) output+=", ";
        }
    }

    output+="|";
    
    return output;

}


// Resize implementation
void ArrayQueue::resize(int new_capacity)
{
    // TODO: Create a new array with the new capacity
    int* temp=new int[new_capacity];
    int cnt=size();
    // TODO: Copy elements from the old array to the new array

    for(int i=0;i<cnt;i++){
        temp[i]=data[(front_idx+i)%capacity];
    }

    // TODO: Delete the old array
    delete[] data;

    // TODO: Update the data pointer and capacity
    data=temp;
    capacity=new_capacity;
    
    // TODO: Update front and rear indices
    front_idx=0;
    rear_idx=cnt-1;
}

int ArrayQueue::getCapacity() const
{
    // TODO: Return the current capacity of the queue
    return capacity;
}