/*
 * Author: Kyle Cox
 * File: Queue.h
 * Date: 25 February 2024
 * program: Project 1
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include <iostream>
#include <string>
using namespace std;


class Queue
{
private:
    Node* head; // Pointer to the first node in the queue
    Node* tail; // Pointer to the last node in the queue

public:


    //Mutator functions
    void purgeQueue(){head = tail = NULL;} // Set both head and tail pointers to NULL

     // Function to enqueue a new node with provided data
    void enqueue(long, string, string, string, float);

    // Accessor functions

    // Function to display string representation of all nodes in the queue
    string showAll();

    // Function to display string representation of the head node in the queue
    string showHead();

    // Function to display string representation of the tail node in the queue
    string showTail();

    // Function to dequeue (remove and return) the head node from the queue
    string dequeue();

};

//Remove and return the object for the front of the Queue.
string Queue::dequeue() {
    // Case of the list is empty
    if (head == NULL) {
        return "The Queue is EMPTY!";
    }

    string str = head->showRecord();
    Node* temp = head;

    head = head->getNext();

    // If the queue is now empty, update tail pointer
    if (head == NULL) {
        tail = NULL;
    }

    delete temp;

    return str;
}

void Queue::enqueue(long num, string firstName, string lastName, string maj, float score)
    {
        Node* node = new Node(num, firstName, lastName, maj, score); //create node

        if (head == NULL)       // The Queue is empty
            {
                head = tail = node;
                return;
            }
        else
            {
                tail->setNext(node); //place node in queue
                tail = node;

                return;
            }
    }
//Function to display the tail node;
string Queue::showTail(){
     //if statement for if the queue is empty
    if(head == NULL){
    return "The Queue is EMPTY!";
    }
    else
    {
            //return tail record
            return (tail->showRecord());
    }
}
//Function to display the head node;
string Queue::showHead(){
     //if statement for if the queue is empty
    if(head == NULL){
    return "The Queue is EMPTY!";
    }
        else{
            //return head record
            return (head->showRecord());
        }
}

// A Function the displays all records
string Queue::showAll()
    {
        //if statement for if the queue is empty
        if (head == NULL){
            return "The Queue is EMPTY!";
        // returns a string
    }
        else
            {
                string str = "";
                Node* current = head;
                        //Going through the records using a while lopp that appends the records in a string varible call str
                while (current != NULL)
                    {
                        str.append(current->showRecord() + "\n");
                        current = current->getNext();
                    }
                return str;
            }

    }

#endif
