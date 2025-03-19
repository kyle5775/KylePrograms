//
// MaxHeap.h
//
#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

 using namespace std;

class MaxHeapNode {
private:
    int idNo;
    string name;
    string surname;
    string major;
    float gpa;

public:

    // Constructor functions
     MaxHeapNode() : idNo(0), name(""), surname(""), major(""), gpa(0.0) {}
    MaxHeapNode(int, string, string, string, float);
    MaxHeapNode(Record);

    // Accessor functions
    int getID()  { return idNo; }
    string getName()  { return name; }
    string getSurname()  { return surname; }
    string getMajor()  { return major; }
    float getGPA()  { return gpa; }
    string getData() ;

    // Mutator functions
    void setData(int, string, string, string, float);
};

MaxHeapNode::MaxHeapNode(Record rec)
    {
        idNo    = rec.idNo;
        name    = rec.name;
        surname = rec.surname;
        major   = rec.major;
        gpa     = rec.gpa;
    }



string MaxHeapNode::getData()
    {
        string str = to_string(idNo);
        str.append("\t" + name + "\t\t" + surname + "\t\t" + major + "\t\t");
        str.append(trim(gpa) );     // Trim the GPA value to 2 places of decimal

        return str;
    }

MaxHeapNode::MaxHeapNode(int num, string fname, string lname, string maj, float grade)
{
    // Initialize a MaxHeapNode with the provided data
    idNo = num;
    name = fname;
    surname = lname;
    major = maj;
    gpa = grade;
}


 class MaxHeap
    {
        private:
            vector<MaxHeapNode> elements;
       public:
           MaxHeap(){elements.resize(1);}
            string displayHeap();
             void addMaxHeap(Record);               // Add to MaxHeap
             void addMaxHeap(int, string, string, string, float);
             void maxHeapify(unsigned int );      // Heapify MaxHeap
             void deleteMaxHeap(int);
             void removeMaxRoot();
             string sortMaxHeap();
    };

void MaxHeap::addMaxHeap(int ID, string name, string surname, string major, float gpa)
    {
        //Create a new MaxHeapNode using data from a individual attrubes
         MaxHeapNode newNode(ID, name, surname, major, gpa);
        elements.push_back(newNode);
        maxHeapify(elements.size() - 1);
    }


//===================================================================================
// Recursive heapify function for a MaxHeap
//===================================================================================
void MaxHeap::maxHeapify(unsigned int index)
{
   unsigned int left, right, maxx;
        left = 2*index;
        right = 2*index + 1;

        // Base case
        if (index == 0)
            return;

        // Check the children, if they exist and pick the larger for swapping
        if (left < elements.size() && elements[left].getID() > elements[index].getID())
            maxx = left;
        else
            maxx = index;

        if (right < elements.size() && elements[right].getID() > elements[maxx].getID())
            maxx = right;

        if (maxx != index)
            {
                MaxHeapNode temp = elements[maxx];
                elements[maxx] = elements[index];
                elements[index] = temp;
                maxHeapify(maxx);
            }

        // Now check the parent, if it exists
        maxHeapify(index/2);
}

//===================================================================================
// Add new element to MaxHeap
//===================================================================================
void MaxHeap::addMaxHeap(Record rec)
    {
        // Create a new MaxHeapNode using data from a Record object
    MaxHeapNode newNode(rec.idNo, rec.name, rec.surname, rec.major, rec.gpa);
    // Add the new node to the elements vector
    elements.push_back(newNode);
    // Perform Max-heapify operation to maintain the heap property
    maxHeapify(elements.size() - 1);
    }


void MaxHeap::removeMaxRoot()
{
    // Check if the heap contains fewer than 2 elements
    if (elements.size() < 2)
        return; // If so, return without performing any operation
    else
    {
        // Replace the root with the last element in the heap
        elements[1] = elements[elements.size() - 1];
        // Reduce the size of the heap by one
        elements.resize(elements.size() - 1);
        // Re-heapify starting from the root
        maxHeapify(1);
    }
}

string MaxHeap::sortMaxHeap()
    {
      // Initialize an empty string to store the sorted elements
    string str = "";

    // Continue until there is only one element left in the heap (the root)
    while (elements.size() > 1)
    {
        // Append the data of the Max element (root) to the string
        str.append(elements[1].getData());
        // Add a newline character to separate each element
        str.append("\t\n");

        // Remove the minimum element from the heap
        removeMaxRoot();
    }

    // Add a newline character to mark the end of sorted elements
    str.append("\n");

    // Return the string containing the sorted elements
    return str;
    }

void MaxHeap::deleteMaxHeap(int value)
    {

    // Initialize index variable
    int x = 0;

    // Iterate until the end of the elements vector
    while (x < elements.size())
    {
        // Check if the current element's ID matches the specified value
        if (value == elements[x].getID())
        {
            // Replace the current element with the last element in the heap
            elements[x] = elements[elements.size() - 1];

            // Remove the last element from the heap
            elements.pop_back();

            // Re-heapify starting from the parent, left child, and right child of the replaced element
            maxHeapify(x);              // parent
            maxHeapify((2 * x) + 1);    // left child
            maxHeapify((2 * x) + 2);    // right child

            // No need to search further, exit the loop
            break;
        }
        x++;
    }
    }


string MaxHeap::displayHeap()
{
    // Initialize an empty string to store the elements
    string str = "";

    // Iterate over elements in the heap starting from index 1 (root)
    for (int x = 1; x < elements.size(); x++)
    {
        // Append the data of the current element to the string
        str.append(elements[x].getData());
        // Add a newline character to separate each element
        str.append("\n");
    }

    // Return the string containing the elements
    return str;
}

#endif
