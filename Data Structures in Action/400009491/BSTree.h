//
//  BSTree.h
//  Kyle Cox - 400009491
//
//  Created by Dr. John Charlery on 03/13/2024.
//  Copyright (c) 2024 University of the West Indies. All rights reserved.
//

#ifndef BST_BSTree_h
#define BST_BSTree_h

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class BSTNode
    {
        private:
            int idNo;
            string name;
            string surname;
            string major;
            float gpa;

            BSTNode* left;
            BSTNode* right;

        public:

            // Constructor functions
            BSTNode() {left = right = NULL;}
            BSTNode(int, string, string, string, float);
            BSTNode(Record);
    
            // Accessor functions
            BSTNode* getLeft()  {return left;};
            BSTNode* getRight() {return right;}
            int getID()         {return idNo;}
            string getName()    {return name;}
            string getSurname() {return surname;}
            string getMajor()   {return major;}
            float getGPA()      {return gpa;}
            string getData();


            // Mutator functions
            void setData(int, string, string, string, float);
            void setLeft(BSTNode* ptr) {left = ptr;}
            void setRight(BSTNode* ptr){right = ptr;}
            void copyData(BSTNode*);
     };




BSTNode::BSTNode(int num, string fname, string lname, string maj, float grade)
    {
        idNo = num;
        name = fname;
        surname = lname;
        major = maj;
        gpa = grade;
        left = right = NULL;
    }





BSTNode::BSTNode(Record rec)
    {
        idNo    = rec.idNo;
        name    = rec.name;
        surname = rec.surname;
        major   = rec.major;
        gpa     = rec.gpa;
        left    = right = NULL;
    }


string BSTNode::getData()
    {
        string str = to_string(idNo);
        str.append("\t" + name + "\t\t" + surname + "\t\t" + major + "\t\t");
        str.append(trim(gpa) );     // Trim the GPA value to 2 places of decimal
        
        return str;
    }




void BSTNode::copyData(BSTNode* ptr)
    {
        idNo    = ptr->getID();
        name    = ptr->getName();
        surname = ptr->getSurname();
        major   = ptr->getMajor();
        gpa     = ptr->getGPA();
    }





class BSTree
    {
        private:
            BSTNode* root;
    
            // Recursive counterpart for inserting a node
            BSTNode* insertHelper(BSTNode*, int, string, string, string, float);
    
            // Recursive counterpart for deleting a node
             BSTNode* deleteHelper(BSTNode*, int);

            // Recursive counterpart of preorder traversal
            string preOrderHelper(BSTNode* );
    
            // Recursive counterpart of postorder traversal
            string postOrderHelper(BSTNode* );

            // Recursive counterpart of inorder traversal
            string inOrderHelper(BSTNode* );
    
        public:
            //  Constructor function
            BSTree() { root = NULL;}
    
            // Mutator functions
            void purge() { root = NULL;}
            void insert(int, string, string, string, float);
            void insert(Record);
            void remove(int val) { root = deleteHelper(root, val);}
        
            // Accessor functions
            BSTNode* getRoot() { return root;}
            string preOrder()  { return preOrderHelper(root); }
            string postOrder() { return postOrderHelper(root); }
            string inOrder()   { return inOrderHelper(root); }
    
    };





void BSTree::insert(int num, string fname, string lname, string maj, float grade)
    {
        root = insertHelper(root, num, fname, lname, maj, grade);
    }

void BSTree::insert(Record rec)
    {
        root = insertHelper(root, rec.idNo, rec.name, rec.surname, rec.major, rec.gpa);
    }





BSTNode* BSTree::insertHelper(BSTNode* ptr, int num, string fname, string lname, string maj, float grade)
    {
        if ( ptr == NULL )         // The tree is empty - new first node!
            {
                ptr = new BSTNode(num, fname, lname, maj, grade);
            }
        else                       // choose which sub-tree to follow
            {
                if (num >= ptr->getID())          // insert in right subtree - Operational defn.
                    ptr->setRight(insertHelper(ptr->getRight(), num, fname, lname, maj, grade));
                else                              // insert in left subtree
                    ptr->setLeft(insertHelper(ptr->getLeft(), num, fname, lname, maj, grade));
            }
        return ptr;
    }







BSTNode* BSTree::deleteHelper(BSTNode* ptr, int val)
    {
        BSTNode* successor;
        
        // Base condition
        if (ptr == NULL)
            {
                return NULL;
            }
        
        if (val > ptr->getID())                               // Search for val in right sub-tree
            ptr->setRight(deleteHelper(ptr->getRight(), val));
        
        else if (val < ptr->getID())                           // Search for val in left sub-tree
                ptr->setLeft(deleteHelper(ptr->getLeft(), val));
        
            else    //Found it! ptr is the node to be deleted
                {
                   if (ptr->getRight() !=  NULL)
                       {  // Seek out the succesor in the right sub-tree
                           successor = ptr->getRight();                 // Go right...
                           while ( successor->getLeft() != NULL )       // ...and then go deep left
                               successor = successor->getLeft();
                           
                           // Transfer data from successor to ptr (ptr is the node to be deleted)
                           ptr->copyData( successor );
                           
                           // Now reset ptr's right child
                           ptr->setRight(deleteHelper( ptr->getRight(), ptr->getID() ));
                       }
                   else
                       return (ptr->getLeft());
                }
        return ptr;
    }







string BSTree::inOrderHelper(BSTNode* ptr)
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




string BSTree::preOrderHelper(BSTNode* ptr)
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




string BSTree::postOrderHelper(BSTNode* ptr)
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
