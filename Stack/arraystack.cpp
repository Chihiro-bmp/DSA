#include "stack.h"
#include <iostream>

// Constructor implementation
ArrayStack::ArrayStack(int initial_capacity=10) {
    // TODO: Initialize data members (data, capacity, current_size)
    // TODO: Allocate memory for the array with the specified initial capacity

    capacity=initial_capacity;
    data=new int[capacity];
    current_size=0;
}

// Destructor implementation
ArrayStack::~ArrayStack() {
    // TODO: Free the dynamically allocated memory for the array
    delete[] data;
}

// Push implementation
void ArrayStack::push(int item) {
    // TODO: Check if the array is 50% full (current_size >= capacity/2)
    // TODO: If 50% full, resize the array to double its current capacity
    // TODO: Add the new element to the top of the stack and increment current_size

    if(current_size>=capacity/2){
        resize(capacity*2);
    }
    data[current_size++]=item;
}

// Pop implementation
int ArrayStack::pop() {
    // TODO: Check if the stack is empty, display error message if it is
    // TODO: Decrement current_size and return the element at the top of the stack
    // TODO: If the array is less than 25% full, resize it to half its current capacity
    // TODO: Return the popped element
    if(empty()){
       // std::cout<<"Stack is Empty"<<std::endl;
        return -1;
    }
    
    int pop=data[current_size-1];
    current_size--;

    if(current_size< capacity/4){
        resize(capacity/2);
    }

    return pop;
}

// Clear implementation
void ArrayStack::clear() {
    // TODO: Reset the stack to be empty (set current_size to 0)
    // TODO: No need to free memory, just logically clear the stack
    current_size=0;
}

// Size implementation
int ArrayStack::size() const {
    // TODO: Return the number of elements currently in the stack (current_size)
    return current_size;
}

// Top implementation
int ArrayStack::top() const {
    // TODO: Check if the stack is empty, display error message if it is
    // TODO: Return the element at the top of the stack without removing it

    if(empty()){
        //std::cout<<"Stack is Empty. No Top element found."<<std::endl;
        return -1;
    }

    return data[current_size-1];
}

// Empty implementation
bool ArrayStack::empty() const {
    // TODO: Return whether the stack is empty (current_size == 0)
    return current_size==0;
}

// Print implementation
void ArrayStack::print() const {
    // TODO: Print stack elements from top to bottom in the format: |elem1, elem2, ..., elemN>

    std::cout<<"|";

    for(int i=current_size-1;i>=0;i--){

        std::cout<<data[i];

        if(i!=0){
            std::cout<<", ";
        }
    }
    std::cout<<">"<<std::endl;
}

// Resize implementation
void ArrayStack::resize(int new_capacity) {
    // TODO: Create a new array with the new capacity
    // TODO: Copy elements from the old array to the new array
    // TODO: Delete the old array
    // TODO: Update the data pointer and capacity

    int* temp=new int[new_capacity];

    for(int i=0;i<current_size;i++){
        temp[i]=data[i];
    }

    delete[] data;
    capacity=new_capacity;
    data=temp;
}