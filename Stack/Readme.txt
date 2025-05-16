#README

This document describes stack ADT implementations in two ways: ArrayStack (dynamic array-based) and ListStack (linked list-based).

## ArrayStack Implementation

### Overview
- Implements a stack using a dynamic array that automatically resizes
- To handle memory leakage and ensure efficient memory usage- 
  - Grows when 50% full (doubles capacity)
  - Shrinks when less than 25% full (halves capacity)

### Methods Implemented:

1. **Constructor : (ArrayStack(int initial_capacity))**
   - Initializes data array with specified capacity
   - Sets initial size to 0

2. **Destructor (~ArrayStack())**
   - Frees dynamically allocated array memory

3. **void push(int item)**
   - Checks if array is 50% full(current_size>=capacity/2) and resizes if needed
   - Adds element to top of stack
   - Increments the size counter

4. **int pop()**
   - Checks for empty stack. Displays error message and returns -1 if empty.
   - Returns top element and decrements size
   - Resizes array if less than 25% full
  

5. **void clear()**
   - Logically clears stack by resetting size to 0
   - Doesn't free memory (array retains capacity)

6. **int size()**
   - Returns current number of elements

7. **int top()**
   - Returns top element without removing it.
   - Returns -1 and error message if empty.

8. **bool empty()**
   - Returns true if stack has no elements

9. **print()**
   - Displays elements from top to bottom in the format: |elem1, elem2, ..., elemN>

10. **resize(int new_capacity)**
    - Creates a new array with the specified capacity.
    - Copies existing elements from the original array    
    - Updates capacity and data pointer 

## ListStack Implementation

### Overview
- Implements stack using singly linked list
- Each operation maintains head pointer and size counter
- No capacity constraints (limited only by memory)

### Methods Implemented:

1. **Constructor (ListStack())**
   - Initializes head pointer to nullptr
   - Sets initial size to 0

2. **Destructor (~ListStack())**
   - Calls clear() to deallocate all nodes in the linked list.

3. **void push(int item)**
   - Creates new node with given item.
   - Links new node to current head.
   - Updates head pointer.
   - Increments size counter.

4. **void pop()**
   - Checks for empty stack. Returns -1 if the stack is empty.
   - Removes head node and returns its data
   - Updates head pointer to next node
   - Decrements size counter
   

5. **void clear()**
   - Traverses list and deletes all nodes
   - Resets head to nullptr
   - Resets size to 0

6. **int size()**
   - Returns current number of elements

7. **int top()**
   - Returns head node's data without removal
   - Returns -1 and error message if stack is empty.

8. **bool empty()**
   - Returns true if head pointer is nullptr

9. **print()**
   - Displays elements from top to bottom in format: |elem1, elem2, ..., elemN>
   - Traverses list from head to tail

## Notes

- Both implementations handle empty stack cases with error messages
- ArrayStack dynamically manages memory with resize operations
- ListStack uses node-based allocation/deallocation
- Both provide identical stack interfaces with consistent behavior
