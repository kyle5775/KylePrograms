/*
 * Name     : Node.h
 * Program   : Project 1
 * Author   : Kyle Cox
 * Date     : 25 February, 2024
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;


class Node
    {
        // Private Attributes of a Node
    private:
        long         idNo;
        string 	     name;
        string 	     surname;
        string 	     major;
        float  	     gpa;
        Node* next;

    public:
        //Overloaded Constructor to assign Attributes
        Node(long, string, string, string, float);

        // Mutator functions
        void setidNo(long id){idNo = id;};
        void setName(string Name){name = Name;};
        void setSurname(string Surname){surname = Surname;};
        void setMajor(string Major){major = Major;};
        void setGPA(float GPA){gpa = GPA;};
        void setNext(Node* ptr){next = ptr;}

        // Accessor functions
        long getIdNo(){return idNo;};
        string getName(){return name;};
        string getSurname(){return surname;}
        string getMajor(){return major;}
        float getGPA(){return gpa;}
        string showRecord();
        Node* getNext(){return next;}


    };

//The Overloading constuctor that assign the vaules
 Node::Node(long num, string firstName, string lastName, string maj, float score)
    {
        //Attributes of the node
        idNo    = num;
        name    = firstName;
        surname = lastName;
        major   = maj;
        gpa     = score;
        next    = NULL;
    }
// A Fuction that displays the record of the node by appended each attribute in a string variable call str
string Node::showRecord()
{
    string str = "";
    str.append(to_string(idNo) + "\t");
    str.append(name + "\t");
    str.append(surname + "\t");
    str.append(major + "\t");
    str.append(to_string(gpa));

    return str;
}

#endif
