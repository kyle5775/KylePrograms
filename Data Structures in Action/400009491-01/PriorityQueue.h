/*
 * Author: Kyle Cox
 * File: Priority Queue.h
 * Date: 25 February 2024
 * program: Project 1
 */

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

class PriorityQueue {
private:
    Node* head; // Pointer to the first node in the priority queue
    Node* tail; // Pointer to the last node in the priority queue

public:
    // Constructor
    PriorityQueue() {
        head = tail = NULL; // Initialize head and tail pointers to NULL
    }

    // Mutator function

    // Function to empty the priority queue
    void PurgePriorityQueue() {
        head = tail = NULL; // Set both head and tail pointers to NULL
    }

    // Accessor functions

    // Function to display string representation of all nodes in the priority queue
    string showAll();

    // Function to display string representation of the head node in the priority queue
    string showHead();

    // Function to display string representation of the tail node in the priority queue
    string showTail();

    // Function to dequeue (remove and return) the head node from the priority queue
    string dequeue();

    // Function to enqueue a new node with provided data in ascending order of priority
    void enqueueAscegOrder(long, string, string, string, float);
};


// Enqueue in Ascending Order of Priority
void PriorityQueue::enqueueAscegOrder(long num, string firstName, string lastName, string maj, float score) {
    // Create a new node with the given data
    Node* node = new Node(num, firstName, lastName, maj, score);

    // If the priority queue is empty
    if (head == NULL) {
        // Set the new node as the head
        head = node;
    }
    // If the priority of the new node is lower than the priority of the current head
    else if (num < head->getIdNo()) {
        // Set the new node's next pointer to the current head and update the head
        node->setNext(head);
        head = node;
    }
    else {
        // Traverse the priority queue to find the correct position for the new node
        Node* current = head;
        Node* prev = NULL;

        // Continue traversing until reaching the end of the queue or finding a node with lower priority
        while (current != NULL && num > current->getIdNo()) {
            prev = current;
            current = current->getNext();
        }

        // Insert the new node between prev and current
        prev->setNext(node);
        node->setNext(current);
    }
}


// Return a string representation of all records in the priority queue
string PriorityQueue::showAll() {
    // If the priority queue is empty
    if (head == NULL) {
        return "The Queue is EMPTY!";
    }
    else {
        string str = ""; // Initialize an empty string to hold the concatenated records
        Node* current = head; // Start traversing from the head

        // Traverse the priority queue and concatenate each record to the string
        while (current != NULL) {
            str.append(current->showRecord() + "\n"); // Append the record and a newline character
            current = current->getNext(); // Move to the next node
        }
        return str; // Return the concatenated string of records
    }
}

// Function to display the head node
string PriorityQueue::showHead() {
    // If the priority queue is empty
    if (head == NULL) {
        return "The Queue is EMPTY!";
    }
    else {
        return head->showRecord(); // Return the string representation of the head node
    }
}

// Function to display the tail node
string PriorityQueue::showTail() {
    // If the priority queue is empty
    if (head == NULL) {
        return "The Queue is EMPTY!";
    }
    else {
        Node* Ptr = head; // Start traversing from the head

        // Traverse the priority queue to find the tail node
        while (Ptr->getNext() != NULL) {
            Ptr = Ptr->getNext(); // Move to the next node
        }
        return Ptr->showRecord(); // Return the string representation of the tail node
    }
}

//Remove and return the object for the front of the Queue.
string PriorityQueue::dequeue(){
    // Case of the list is empty
     if(head == NULL){
    return "The Queue is EMPTY!";
    }
//storage the head data in string variable
     string str = head->showRecord();
     Node* temp = head;

     head = head->getNext();

     delete temp;

     return str;

}


#endif
