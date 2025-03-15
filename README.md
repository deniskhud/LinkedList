# Linked List Implementation in C++

This project contains an implementation of a singly linked list in C++. It provides basic operations such as insertion, deletion, and reversal.

## Features

- Insert elements at specific positions or at the front/back.
- Remove elements from any position.
- Reverse the linked list.
- Support for index access via `[]` operator.
- Memory management with copy constructor and assignment operator.

## How to use

1. Clone the repository.
2. Compile the code with any C++ compiler.
3. Use the provided functions to interact with the linked list.

## Example Usage
// Create a list of integers
List<int> myList;

// Add elements to the list
myList.push_back(10);  // Add to the end of the list
myList.push_back(20);
myList.push_back(30);
myList.push_front(5);  // Add to the front of the list

// Print the list
cout << "Original List: ";
myList.print();  // Output: 5 -> 10 -> 20 -> 30 -> NULL

// Access an element using the [] operator
cout << "Element at index 1: " << myList[1] << :endl;  // Output: 10

// Insert an element at a specific position
myList.insert(15, 2);  // Insert 15 at index 2

// Print the modified list
cout << "List after insertion: ";
myList.print();  // Output: 5 -> 10 -> 15 -> 20 -> 30 -> NULL

// Reverse the list
myList.reverseList();
cout << "Reversed List: ";
myList.print();  // Output: 30 -> 20 -> 15 -> 10 -> 5 -> NULL

// Remove element from the front
myList.pop_front();
cout << "List after pop_front: ";
myList.print();  // Output: 20 -> 15 -> 10 -> 5 -> NULL

// Remove element from the back
myList.pop_back();
cout << "List after pop_back: ";
myList.print();  // Output: 20 -> 15 -> 10 -> NULL

// Remove element at a specific index
myList.removeAt(1);  // Remove element at index 1
cout << "List after removeAt(1): ";
myList.print();  // Output: 20 -> 10 -> NULL

// Clear the list
myList.clear();
cout << "List after clear: ";
myList.print();  // Output: List is empty