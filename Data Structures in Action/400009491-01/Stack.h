 /*
 * Author: Kyle Cox
 * File: Stack.h
 * Date: 25 February 2024
 * program: Project 1
 */

#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    Node* head; // Pointer to the top node in the stack
    Node* tail; // Pointer to the bottom node in the stack

public:
    // Constructor
    Stack() {
        head = tail = NULL; // Initialize head and tail pointers to NULL
    }

    // Mutator functions

    // Function to pop (remove and return) the top element from the stack
    string pop();

    // Function to display string representation of all elements in the stack
    string showAll();

    // Function to push a new element onto the top of the stack with provided data
    void push(long, string, string, string, float);
};


// Function to pop an element from the stack
string Stack::pop() {
    // If the stack is empty
    if (head == NULL) {
        return "The Stack is empty";
    }

    Node* current = head;
    Node* prev = NULL;

    // Traverse the stack to find the last element
    while (current->getNext() != NULL) {
        prev = current;
        current = current->getNext();
    }

    // Update tail if popping the last element
    if (prev == NULL) {
        tail = NULL;
        head = NULL;
    }
    else {
        prev->setNext(NULL);
    }

    // Get the string representation of the popped element
    string str = current->showRecord();

    // Delete the popped node to prevent memory leak
    delete current;

    return str; // Return the string representation of the popped element
}


// Function to display all elements in the stack
string Stack::showAll() {
    // If the stack is empty
    if (head == NULL) {
        return "The Stack is EMPTY!";
    }
    else {
        string str = ""; // Initialize an empty string to hold the concatenated elements
        Node* current = head; // Start traversing from the head

        // Traverse the stack and concatenate each element's string representation to the string
        while (current != NULL) {
            str.append(current->showRecord() + "\n"); // Append the element's string representation and a newline character
            current = current->getNext(); // Move to the next node
        }
        return str; // Return the concatenated string of elements
    }
}


// Function to push an element onto the stack
void Stack::push(long num, string firstName, string lastName, string maj, float score) {
    // Create a new node with the given data
    Node* node = new Node(num, firstName, lastName, maj, score);

    // If the stack is empty
    if (head == NULL) {
        head = tail = node; // Set both head and tail to the new node
    }
    else {
        tail->setNext(node); // Set the next pointer of the current tail to the new node
        tail = node; // Update the tail to point to the new node
    }
}
#endif


