//
// MinHeap.h
// Kyle Cox - 400009491
//
#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

 using namespace std;

class MinHeapNode {
private:
    int idNo;
    string name;
    string surname;
    string major;
    float gpa;

public:

    // Constructor functions
     MinHeapNode() : idNo(0), name(""), surname(""), major(""), gpa(0.0) {}
    MinHeapNode(int, string, string, string, float);
    MinHeapNode(Record);

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

MinHeapNode::MinHeapNode(Record rec)
    // Initialize MinHeapNode with data from a Record Struct
    {
        idNo    = rec.idNo;
        name    = rec.name;
        surname = rec.surname;
        major   = rec.major;
        gpa     = rec.gpa;
    }



string MinHeapNode::getData()
    {
       // Initialize a string to store the data
    string str = to_string(idNo);
    // Append the data of the SetNode with appropriate formatting
    str.append("\t" + name + "\t\t" + surname + "\t\t" + major + "\t\t");
    // Trim the GPA value to 2 decimal places and append it
    str.append(trim(gpa));

        return str;
    }

MinHeapNode::MinHeapNode(int num, string fname, string lname, string maj, float grade)
    {
        //// Initialize SetNode with individual attributes
        idNo = num;
        name = fname;
        surname = lname;
        major = maj;
        gpa = grade;

    }

    class MinHeap
    {
        private:
            vector<MinHeapNode> elements;
       public:
           MinHeap(){elements.resize(1);}
            string displayHeap();                    //display Heap
             void addMinHeap(Record);               // Add to MinHeap
            void addMinHeap(int, string, string, string, float); //add node to min Heapify
             void minHeapify(unsigned int);      // Heapify MinHeap
             void deleteMinHeap(int);   //delete node
             void removeMinRoot();  //remove root
             string sortMinHeap(); //sort min heap
    };



//===================================================================================
// Add new element to MinHeap
//===================================================================================


void MinHeap::addMinHeap(Record rec)
{
    // Create a new MinHeapNode using data from a Record object
    MinHeapNode newNode(rec.idNo, rec.name, rec.surname, rec.major, rec.gpa);
    // Add the new node to the elements vector
    elements.push_back(newNode);
    // Perform min-heapify operation to maintain the heap property
    minHeapify(elements.size() - 1);
}



void MinHeap::addMinHeap(int ID, string name, string surname, string major, float gpa)
    {
        // Create a new MinHeapNode using data from individual attributes
        MinHeapNode newNode(ID, name,surname, major, gpa);
        // Add the new node to the elements vector
        elements.push_back(newNode);
         //Perform min-heapify operation to maintain the heap property
       minHeapify(elements.size() - 1);
    }


//===================================================================================
// Recursive heapify function for a MinHeap
//===================================================================================
void MinHeap::minHeapify(unsigned int index)
    {
        unsigned int left, right, minn;
        left = 2*index;
        right = 2*index + 1;

        // Base case
        if (index == 0)
            return;

        // Check the children, if they exist and pick the larger for swapping
        if (left < elements.size() && elements[left].getID() < elements[index].getID())
            minn = left;
        else
            minn = index;

        if (right < elements.size() && elements[right].getID() < elements[minn].getID())
            minn = right;

        if (minn != index)
            {
                MinHeapNode temp = elements[minn];
                elements[minn] = elements[index];
                elements[index] = temp;
                minHeapify(minn);
            }

        // Now check the parent, if it exists
        minHeapify(index/2);

    }






string MinHeap::displayHeap()
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


void MinHeap::removeMinRoot()
{
    if (elements.size() < 2)
        return;
    else
    {
        elements[1] = elements[elements.size() - 1]; // Swap last element with root
        elements.resize(elements.size() - 1); // Resize to remove the last element
        minHeapify(1); // Call minHeapify with the index of the root
    }
}




string MinHeap::sortMinHeap()
{
    // Initialize an empty string to store the sorted elements
    string str = "";

    // Continue until there is only one element left in the heap (the root)
    while (elements.size() > 1)
    {
        // Append the data of the minimum element (root) to the string
        str.append(elements[1].getData());
        // Add a newline character to separate each element
        str.append("\t\n");

        // Remove the minimum element from the heap
        removeMinRoot();
    }

    // Add a newline character to mark the end of sorted elements
    str.append("\n");

    // Return the string containing the sorted elements
    return str;
}






void MinHeap::deleteMinHeap(int value)
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
            minHeapify(x);              // parent
            minHeapify((2 * x) + 1);    // left child
            minHeapify((2 * x) + 2);    // right child

            // No need to search further, exit the loop
            break;
        }
        x++;
    }
}


#endif
