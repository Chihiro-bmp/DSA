#include "stack.h"
#include <iostream>

// Constructor implementation
ListStack::ListStack() {
    // TODO: Initialize head to nullptr
    // TODO: Initialize current_size to 0
    head=nullptr;
    current_size=0;
}

// Destructor implementation
ListStack::~ListStack() {
    // TODO: Deallocate all nodes in the linked list
    // TODO: Consider using the clear() method

    clear();
}

// Push implementation
void ListStack::push(int item) {
    // TODO: Create a new node with the given item
    // TODO: Make the new node point to the current head
    // TODO: Update head to point to the new node
    // TODO: Increment current_size

    Node* new_Node=new Node(item,head);
    head=new_Node;
    current_size++;

  

}

// Pop implementation
int ListStack::pop() {
    // TODO: Check if the stack is empty, display error message if it is
    // TODO: Store the data from the head node
    // TODO: Update head to point to the next node
    // TODO: Delete the old head node
    // TODO: Decrement current_size
    // TODO: Return the stored data

    if(empty()){
        //std::cout<<"Stack is empty"<<std::endl;
        return -1;
    }

    Node* temp=head;
    int pop=temp->data;
    head=head->next;

    delete temp;
    current_size--;

    return pop;
}

// Clear implementation
void ListStack::clear() {
    // TODO: Traverse the linked list, deleting each node
    // TODO: Reset head to nullptr
    // TODO: Reset current_size to 0
   Node* current=head;

   while(current!=nullptr){
    Node* previous=current;
    current=current->next;
    delete previous;
    
   }

   head=nullptr;
   current_size=0;
    
}

// Size implementation
int ListStack::size() const {
    // TODO: Return the current size (current_size)

    return current_size;
}

// Top implementation
int ListStack::top() const {
    // TODO: Check if the stack is empty, display error message if it is
    // TODO: Return the data from the head node without removing it

    if(empty()){
        //std::cout<<"Stack is empty. No top element available."<<std::endl;
        return -1;
    }

    return head->data;
}

// Empty implementation
bool ListStack::empty() const {
    // TODO: Return whether head is nullptr

    return head==nullptr;
}

// Print implementation
void ListStack::print() const {
    // TODO: Print stack elements from top to bottom in the format: |elem1, elem2, ..., elemN>
    // TODO: Traverse the linked list from head, printing each node's data

    std::cout<<"| ";
    Node* temp=head;

    while(temp!=nullptr){

        std::cout<<temp->data;

        if(temp->next!=nullptr){
            std::cout<<",";
        }
    }
    
    std::cout<<">"<<std::endl;
}