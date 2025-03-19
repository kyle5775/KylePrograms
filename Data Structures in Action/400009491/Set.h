//
//  Set.h
//  Kyle Cox - 400009491
//
#ifndef SET_h
#define SET_h

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;


class SetNode {
private:
    int idNo;
    string name;
    string surname;
    string major;
    float gpa;

public:
    // Constructor functions
    SetNode(int, string, string, string, float);
    SetNode(Record);

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

SetNode::SetNode(Record rec)
{
    // Initialize SetNode with data from a Record object
    idNo = rec.idNo;
    name = rec.name;
    surname = rec.surname;
    major = rec.major;
    gpa = rec.gpa;
}

string SetNode::getData()
{
    // Initialize a string to store the data
    string str = to_string(idNo);
    // Append the data of the SetNode with appropriate formatting
    str.append("\t" + name + "\t\t" + surname + "\t\t" + major + "\t\t");
    // Trim the GPA value to 2 decimal places and append it
    str.append(trim(gpa));

    return str;
}

SetNode::SetNode(int num, string fname, string lname, string maj, float grade)
{
    // Initialize SetNode with individual attributes
    idNo = num;
    name = fname;
    surname = lname;
    major = maj;
    gpa = grade;
}



class Set {
private:
    vector<SetNode> elements;

public:

    // Function to check if an element with a given ID exists in the set
    bool find(int);

    // Function to add a record to the set
    void add(Record);

    // Function to add a record to the set with individual attributes
    void add(int, string, string, string, float);

    // Function to compute the union of two sets
    void unionSet(Set*, Set*);

    // Function to compute the intersection of two sets
    void intersectionSet(Set*, Set*);

    // Function to display the elements in the set
    string display();

    // Function to delete an element from the set based on its ID
    void deleteFromSet(int);
};


void Set::deleteFromSet(int ID)
{
    // Iterate over each element in the set
    for (int x = 0; x < elements.size(); x++)
    {
        // Check if the current element's ID matches the specified ID
        if (elements[x].getID() == ID) {
            // If a match is found, erase the element from the set
            elements.erase(elements.begin() + x);
        }
    }
}


void Set::intersectionSet(Set* setA, Set* setB)
{
    // Clear the current elements in the set
    elements.clear();

    // Iterate over elements of setA
    for (int x = 0; x < setA->elements.size(); x++)
    {
        // Check if the major of the element in setA is "COMP"
        if (setA->elements[x].getMajor() == "COMP")
        {
            // If so, add the element to the intersection set
            elements.push_back(setA->elements[x]);
        }
    }

    // Iterate over elements of setB
    for (int y = 0; y < setB->elements.size(); y++)
    {
        // Check if the major of the element in setB is "COMP"
        if (setB->elements[y].getMajor() == "COMP")
        {
            // If so, add the element to the intersection set
            elements.push_back(setB->elements[y]);
        }
    }
}


void Set::unionSet(Set* setA, Set* setB)
{
    // Clear the current elements in the set
    elements.clear();

    // Add all elements from setA to the union set
    for (int x = 0; x < setA->elements.size(); x++)
    {
        elements.push_back(setA->elements[x]);
    }

    // Iterate over elements of setB
    for (int y = 0; y < setB->elements.size(); y++)
    {
        // Check if the element from setB is not already in the union set
        if (!find(setB->elements[y].getID()))
        {
            // If not, add the element to the union set
            elements.push_back(setB->elements[y]);
        }
    }
}


bool Set::find(int ID)
{
    // Iterate over elements in the set
    for (int i = 0; i < elements.size(); i++)
    {
        // Check if the current element's ID matches the specified ID
        if (elements[i].getID() == ID)
        {
            // If a match is found, return true
            return true;
        }
    }
    // If no match is found, return false
    return false;
}




void Set::add(Record rec) {
    // Check if the element is already in the set
    bool found = find(rec.idNo);

    if (found) {

        // Handle the case where the element is already in the set
        // For example, you could print a message or perform some other action

    } else {
        // Add the new element to the set
        SetNode newNode(rec.idNo, rec.name, rec.surname, rec.major, rec.gpa);
        elements.push_back(newNode); // Pass the object, not the pointer
    }
}


void Set::add(int ID, string fname, string Surname, string Major, float Gpa) {
    // Check if the element is already in the set
    bool found = find(ID);

    if (found) {

        // Handle the case where the element is already in the set
        // For example, you could print a message or perform some other action

    } else {
        // Add the new element to the set
        SetNode newNode(ID, fname,Surname, Major,Gpa);
        elements.push_back(newNode); // Pass the object, not the pointer
    }
}


string Set::display()
{
    // Initialize an empty string to store the elements
    string str = "";

    // Iterate over elements in the set
    for(int x = 0; x < elements.size(); x++)
    {
        // Append the data of the current element to the string
        str += elements[x].getData();
        // Add a newline character to separate each element
        str.append("\n");
    }
    // Return the string containing the elements
    return str;
}



#endif
