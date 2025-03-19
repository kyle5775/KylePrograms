/*
 * Author: Kyle Cox
 * File: Deque.h
 * Date: 25 February 2024
 * program: Projectg 1
 */

#ifndef DEQUE_H
#define DEQUE_H

#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

class Deque{
    private:
        Node* head; // Pointer to the first node in the queue
        Node* tail; // Pointer to the last node in the queue
    public:
// Mutator functions

    // Function to empty the deque
    void purgeDeque() {
        head = tail = NULL; // Set both head and tail pointers to NULL
    }

    // Function to display string representation of all nodes in the deque
    string showAll();

    // Function to display string representation of the head node in the deque
    string showHead();

    // Function to display string representation of the tail node in the deque
    string showTail();

    // Function to dequeue (remove and return) the head node from the deque
    string dequeueHead();

    // Function to dequeue (remove and return) the tail node from the deque
    string dequeueTail();

    // Function to enqueue a new node with provided data at the head of the deque
    void enqueueHead(long, string, string, string, float);

    // Function to enqueue a new node with provided data at the tail of the deque
    void enqueueTail(long, string, string, string, float);

    };

// A Function the displays all records
string Deque::showAll()

    {
        //if statement for if the queue is empty
            if (head == NULL){
            return "The Queue is EMPTY!"; // returns a string
    }
        else
            {
                //Going through the records using a while lopp that appends the records in a string varible call str
                string str = "";
                Node* current = head;

                while (current != NULL)
                    {
                        str.append(current->showRecord() + "\n");
                        current = current->getNext();
                    }
                return str;
            }

    }

//Function to display the head node;
string Deque::showHead(){
    //if statement for if the queue is empty
    if(head == NULL){
    return "The Queue is EMPTY!";
     //return a string
    }
        else
        {
            return (head->showRecord());
             //return head record
        }

}

//Function to display the tail node;
string Deque::showTail(){
//if statement for if the queue is empty
    if(head == NULL){

    return "The Queue is EMPTY!";
     //return a string

    }
    else
    {
            Node* Ptr = head; //Pointer that points to the head record
            //Going through the records using a while loop that return the last node in the deque
            while(Ptr->getNext() != NULL){
                Ptr = Ptr ->getNext();
            }
            return Ptr->showRecord();
    }
}

//Remove and return the object for the front of the Queue.
string Deque::dequeueHead(){
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


string Deque::dequeueTail() {
     //if statement for if the queue is empty
    if (head == NULL) {
        return "The Queue is EMPTY!";
    }

    Node* cur = head;
    Node* prev = NULL;

    // Traverse the deque to find the last node and its previous node
    while (cur->getNext() != NULL) {
        prev = cur;
        cur = cur->getNext();
    }

    // If deque has only one element
    if (prev == NULL) {
        head = NULL;
    }

    else
    {
        prev->setNext(NULL);
    }

    string str = cur->showRecord();
    delete cur;

    return str;
}



// Enqueue at the Head of the Deque
void Deque::enqueueHead(long num, string firstName, string lastName, string maj, float score) {
    // Create a new node with the given data
    Node* node = new Node(num, firstName, lastName, maj, score);

    // If the deque is empty
    if (head == NULL) {
        // Set both head and tail to the new node
        head = tail = node;
        return;
    }
    else {
        // Set the next pointer of the new node to the current head
        node->setNext(head);
        // Update the head to point to the new node
        head = node;
        return;
    }
}


// Enqueue at the Tail of the Deque
void Deque::enqueueTail(long num, string firstName, string lastName, string maj, float score) {
    // Create a new node with the given data
    Node* node = new Node(num, firstName, lastName, maj, score);

    // If the deque is empty
    if (head == NULL) {
        // Set both head and tail to the new node
        head = tail = node;
        return;
    }
    else {
        // Traverse the deque to find the last node
        Node* current = head;
        while (current->getNext() != NULL) {
            current = current->getNext();
        }
        // Set the next pointer of the last node to the new node
        current->setNext(node);
        return;
    }
}

    #endif
