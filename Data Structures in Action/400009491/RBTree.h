//  RBTree.h
// Kyle Cox - 400009491
//
//
//  Created by Dr. John Charlery on 03/13/2024.
//  Copyright (c) 2024 University of the West Indies. All rights reserved.
//

#ifndef RBTREE_H
#define RBTREE_h

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class RBTNode
    {
        private:
            int idNo;
            string name;
            string surname;
            string major;
            float gpa;
            string color;



        public:
            RBTNode* parent;
            RBTNode* left;
            RBTNode* right;

            // Constructor functions
            RBTNode() {left = right = parent = NULL; color = "red";}
            RBTNode(int, string, string, string, float);
            RBTNode(Record);


            // Accessor functions
            RBTNode* getLeft()  {return left;};
            RBTNode* getRight() {return right;}
            int getID()         {return idNo;}
            string getColor()         {return color;}
            string getName()    {return name;}
            string getSurname() {return surname;}
            string getMajor()   {return major;}
            float getGPA()      {return gpa;}
            string getData();


            // Mutator functions
            void setData(int, string, string, string, float);
            void setColor(string col){color=col;}

     };
   void  RBTNode::setData(int num, string fname, string lname, string maj, float grade)
    {
        idNo = num;
        name = fname;
        surname = lname;
        major = maj;
        gpa = grade;

    }

    RBTNode::RBTNode(int num, string fname, string lname, string maj, float grade)
    {
        idNo = num;
        name = fname;
        surname = lname;
        major = maj;
        gpa = grade;
        left = right = NULL;

    }

RBTNode::RBTNode(Record rec)
    {
        idNo    = rec.idNo;
        name    = rec.name;
        surname = rec.surname;
        major   = rec.major;
        gpa     = rec.gpa;
        left    = right = NULL;
    }


string RBTNode::getData()
    {
        string str = to_string(idNo);
        str.append("\t" + name + "\t\t" + surname + "\t\t" + major + "\t\t");
        str.append(trim(gpa) );     // Trim the GPA value to 2 places of decimal

        return str;
    }

class RBTree{
    private:
        RBTNode* root;
        // Utility functions
            void    rotateLeft( RBTNode* );
            void    rotateRight(RBTNode* );
            void    fixUp(RBTNode* );
            string  inOrderHelper(RBTNode* );
            string  preOrderHelper(RBTNode* );
            string  postOrderHelper(RBTNode* );
            void    deleteNode(RBTNode* );
            RBTNode* findNode(int );
            RBTNode* getMinimum(RBTNode *);
            RBTNode* getSuccessor(RBTNode *);

        public:
            // Constructor function
            RBTree(){ root = NULL;}

            // Mutator functions
            void insert(Record);
            void insert(int, string, string, string,float);

            void remove(int);

            // Accessor functions
            RBTNode* getRoot(){ return root;}
            string preOrder()  { return preOrderHelper(root); }
            string postOrder() { return postOrderHelper(root); }
            string inOrder()   { return inOrderHelper(root); }

};

void RBTree::rotateLeft( RBTNode* ptr )
	{
        RBTNode* rightChild = ptr->right;
        ptr->right = rightChild->left;

        if (rightChild->left != NULL)
            rightChild->left->parent = ptr;

        rightChild->parent = ptr->parent;

        if (ptr == root)
            root = rightChild;
        else
            {
                if( ptr == ptr->parent->left)
                    ptr->parent->left = rightChild;
                 else
                    ptr->parent->right = rightChild;
            }

        rightChild->left = ptr;
        ptr->parent = rightChild;
 	}


 	void RBTree::rotateRight(RBTNode* ptr)
	{
        RBTNode* leftChild = ptr->left;
        ptr->left = leftChild->right;

        if (leftChild->right != NULL)
            leftChild->right->parent = ptr;

        leftChild->parent = ptr->parent;

        if (ptr == root)
            root = leftChild;
        else
            {
                if( ptr == ptr->parent->right)
                    ptr->parent->right = leftChild;
                 else
                    ptr->parent->left = leftChild;
            }

        leftChild->right = ptr;
        ptr->parent = leftChild;

    }

    RBTNode* RBTree::findNode(int ID)
	{
		RBTNode* ptr = root;

		while ( ptr != NULL )
            {
                if  (ptr->getID() == ID)        // Found it!
                    {
                        return ptr;
                    }

                if (ID < ptr->getID() )
                    ptr = ptr->left;
                else
                    ptr = ptr->right;
            }

        return NULL;            // Tree is empty OR did not find it
	}


	void RBTree::remove(int val)
     {
        RBTNode* markedNode = findNode(val);
         deleteNode(markedNode);
    }


RBTNode* RBTree::getMinimum(RBTNode *ptr)
    {
        while(ptr->left != NULL)
            ptr = ptr->left;

        return ptr;
    }

void RBTree::deleteNode(RBTNode* ptr) {
    if (ptr == NULL)
        return;

    RBTNode *successor, *successorChild;
    if (ptr->left == NULL || ptr->right == NULL)
        successor = ptr;
    else
        successor = getSuccessor(ptr);

    if (successor->left != NULL)
        successorChild = successor->left;
    else
        successorChild = successor->right;

    if (successorChild != NULL)
        successorChild->parent = successor->parent;

    if (successor->parent == NULL)
        root = successorChild;
    else if (successor == successor->parent->left)
        successor->parent->left = successorChild;
    else
        successor->parent->right = successorChild;

    if (successor != ptr)
        ptr->setData(successor->getID(), successor->getName(), successor->getSurname(), successor->getMajor(), successor->getGPA());

    if (successor->getColor() == "BLACK" && successorChild != NULL)
        fixUp(successorChild);

    delete ptr; // Free the memory of the deleted node
}



RBTNode* RBTree::getSuccessor(RBTNode* ptr)
    {
        if (ptr->right == NULL)
            return ptr->left;
        else
            return(getMinimum(ptr->right));
    }

void RBTree::fixUp( RBTNode *ptr )
    {
        RBTNode *ptrsUncle = NULL;

        while ( ptr != root && ptr->parent->getColor() == "RED" )
            {
                if ( ptr->parent == ptr->parent->parent->left )
                    {       // ptr's parent is a LEFT child
                        ptrsUncle = ptr->parent->parent->right;

                        if (  ptrsUncle != NULL && ptrsUncle->getColor() == "RED" )
                            {
                                ptr->parent->setColor("BLACK");
                                ptrsUncle->setColor("BLACK");
                                ptr->parent->parent->setColor("RED");
                                ptr = ptr->parent->parent;
                            }
                        else
                            {
                                if ( ptr == ptr->parent->right )
                                    {
                                        ptr = ptr->parent;
                                        rotateLeft( ptr );
                                    }

                                ptr->parent->setColor("BLACK");
                                ptr->parent->parent->setColor("RED");
                                rotateRight( ptr->parent->parent );
                            }
                    }
                else            // ptr's parent is a RIGHT child
                    {
                        ptrsUncle = ptr->parent->parent->left;

                        if ( ptrsUncle != NULL && ptrsUncle->getColor() == "RED" )
                            {
                                ptr->parent->setColor("BLACK");
                                ptrsUncle->setColor("BLACK");
                                ptr->parent->parent->setColor("RED");
                                ptr = ptr->parent->parent;
                            }
                        else
                            {
                                if ( ptr == ptr->parent->left )
                                    {
                                        ptr = ptr->parent;
                                        rotateRight( ptr );
                                    }
                                ptr->parent->setColor("BLACK");
                                ptr->parent->parent->setColor("RED");
                                rotateLeft( ptr->parent->parent );
                            }
                    }
            }

        root->setColor("BLACK");

        ptrsUncle = NULL;
    }


void RBTree::insert(Record rec)
	{

        RBTNode* newnode = new RBTNode( rec.idNo, rec.name, rec.surname, rec.major, rec.gpa);      // Create the new node

        if (root == NULL)                   // Tree is empty - newnode is first node
            {
                newnode->setColor("BLACK");
                root = newnode;
                return;
            }
        else                                // Tree is NOT empty
            {
                RBTNode* ancestor = NULL;
                RBTNode* current = root;

                while (current != NULL)
                    {
                        ancestor = current;

                        if ( newnode->getID() < current->getID() )
                            current = current->left;
                        else
                            current = current->right;
                    }

                newnode->parent = ancestor;

                if ( newnode->getID() < ancestor->getID() )
                    ancestor->left = newnode;
                else
                    ancestor->right= newnode;

                fixUp(newnode);
            }
	}

void RBTree::insert(int ID, string name, string surname,string major,float gpa)
	{

        RBTNode* newnode = new RBTNode( ID,name,surname,major,gpa);      // Create the new node

        if (root == NULL)                   // Tree is empty - newnode is first node
            {
                newnode->setColor("BLACK");
                root = newnode;
                return;
            }
        else                                // Tree is NOT empty
            {
                RBTNode* ancestor = NULL;
                RBTNode* current = root;

                while (current != NULL)
                    {
                        ancestor = current;

                        if ( newnode->getID() < current->getID() )
                            current = current->left;
                        else
                            current = current->right;
                    }

                newnode->parent = ancestor;

                if ( newnode->getID() < ancestor->getID() )
                    ancestor->left = newnode;
                else
                    ancestor->right= newnode;

                fixUp(newnode);
            }
	}

string RBTree::inOrderHelper(RBTNode* ptr)
	{
        string str = "";

        if ( ptr != NULL )
            {
                str.append( inOrderHelper(ptr->getLeft()) );

                // Process the node, ptr
                str.append( ptr->getData());

                // Append ptr's children
                str.append("\t[");
                if (ptr->getLeft() != NULL)
                    str.append(to_string(ptr->getLeft()->getID()) + ", ");
                else
                    str.append("NULL, ");

                if (ptr->getRight() != NULL)
                    str.append(to_string(ptr->getRight()->getID()) + "]\n");
                else
                    str.append("NULL]\n");

                str.append( inOrderHelper(ptr->getRight())
                );
              }
		return str;
	}




string RBTree::preOrderHelper(RBTNode* ptr)
	{
        string str = "";

        if ( ptr != NULL )
            {

                // Process the node, ptr
                str.append( ptr->getData() );


                // Append ptr's children
                str.append("\t[");
                if (ptr->getLeft() != NULL)
                    str.append(to_string(ptr->getLeft()->getID()) + ", ");
                else
                    str.append("NULL, ");

                if (ptr->getRight() != NULL)
                    str.append(to_string(ptr->getRight()->getID()) + "]\n");
                else
                    str.append("NULL]\n");
                str.append( preOrderHelper(ptr->getLeft()) );
                str.append( preOrderHelper(ptr->getRight()) );
              }

        return str;
	}




string RBTree::postOrderHelper(RBTNode* ptr)
	{
         string str = "";


    if (ptr != NULL)
    {
        str.append(postOrderHelper(ptr->getLeft()));
        str.append(postOrderHelper(ptr->getRight()));
        // Process the node, ptr
        str.append(ptr->getData());

        // Append ptr's children
        str.append("\t[");
        if (ptr->getLeft() != NULL)
            str.append(to_string(ptr->getLeft()->getID()) + ", ");
        else
            str.append("NULL, ");

        if (ptr->getRight() != NULL)
            str.append(to_string(ptr->getRight()->getID()) + "]\n");
        else
            str.append("NULL]\n");
    }

    return str;

    }

#endif
