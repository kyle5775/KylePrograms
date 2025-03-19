//
//  AVL.h
//  Kyle Cox - 400009491
//
//
//  Created by Dr. John Charlery on 03/13/2024.
//  Copyright (c) 2024 University of the West Indies. All rights reserved.
//

#ifndef AVLTREE_h
#define AVLTREE_h
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class AVLNode
    {
        private:
            int idNo;
            string name;
            string surname;
            string major;
            float gpa;
            int height;



        public:
            AVLNode* left;
            AVLNode* right;

            // Constructor functions
            AVLNode() {left = right = NULL; height = 0;}
            AVLNode(int, string, string, string, float);
            AVLNode(Record);


            // Accessor functions
            AVLNode* getLeft()  {return left;};
            AVLNode* getRight() {return right;}
            int getID()         {return idNo;}
            int getHeight()         {return height;}
            string getName()    {return name;}
            string getSurname() {return surname;}
            string getMajor()   {return major;}
            float getGPA()      {return gpa;}
            string getData();


            // Mutator functions
            void setData(int, string, string, string, float);
            void setHeight(int ht){height =ht;}

            void setLeft(AVLNode* ptr) {left = ptr;}
            void setRight(AVLNode* ptr){right = ptr;}
            void copyData(AVLNode*);
     };
   void  AVLNode::setData(int num, string fname, string lname, string maj, float grade)
    {
        idNo = num;
        name = fname;
        surname = lname;
        major = maj;
        gpa = grade;
         height = 0;
    }

    AVLNode::AVLNode(int num, string fname, string lname, string maj, float grade)
    {
        idNo = num;
        name = fname;
        surname = lname;
        major = maj;
        gpa = grade;
        left = right = NULL;
        height = 0;
    }

AVLNode::AVLNode(Record rec)
    {
        idNo    = rec.idNo;
        name    = rec.name;
        surname = rec.surname;
        major   = rec.major;
        gpa     = rec.gpa;
        left    = right = NULL;
         height = 0;
    }


string AVLNode::getData()
    {
        string str = to_string(idNo);
        str.append("\t" + name + "\t\t" + surname + "\t\t" + major + "\t\t");
        str.append(trim(gpa) );     // Trim the GPA value to 2 places of decimal

        return str;
    }


void AVLNode::copyData(AVLNode* ptr)
    {
        idNo    = ptr->getID();
        name    = ptr->getName();
        surname = ptr->getSurname();
        major   = ptr->getMajor();
        gpa     = ptr->getGPA();
    }


class AVLTree{
        private:
            AVLNode* root;
             // Recursive counterpart for inserting a node
            AVLNode* insertHelper(AVLNode*, int, string, string, string, float);

            // Recursive counterpart for deleting a node
             AVLNode* deleteHelper(AVLNode*, int);

            // Recursive counterpart of preorder traversal
            string preOrderHelper(AVLNode* );

            // Recursive counterpart of postorder traversal
            string postOrderHelper(AVLNode* );

            // Recursive counterpart of inorder traversal
            string inOrderHelper(AVLNode* );
            AVLNode* rotateRight(AVLNode*);
            AVLNode* rotateLeft(AVLNode*);
            AVLNode* rotateDoubleRight(AVLNode*);
            AVLNode* rotateDoubleLeft(AVLNode*);
            AVLNode* rotateRightLeft(AVLNode*);
            AVLNode* rotateLeftRight(AVLNode*);

            int calcHeight(AVLNode*);
            int calcBalance(AVLNode*);



        public:
            //  Constructor function
            AVLTree() { root = NULL;}

            // Mutator functions
            void purge() { root = NULL;}
            void insert(int, string, string, string, float);
             void insert(Record);
            void remove(int val) { root = deleteHelper(root, val);}

            // Accessor functions
            AVLNode* getRoot() { return root;}
            string preOrder()  { return preOrderHelper(root); }
            string postOrder() { return postOrderHelper(root); }
            string inOrder()   { return inOrderHelper(root); }

    };
void AVLTree::insert(int num, string fname, string lname, string maj, float grade)
    {
        root = insertHelper(root, num, fname, lname, maj, grade);
    }

void AVLTree::insert(Record rec)
    {
        root = insertHelper(root, rec.idNo, rec.name, rec.surname, rec.major, rec.gpa);
    }
    int AVLTree::calcHeight(AVLNode* ptr)
    {
        int leftHeight, rightHeight;

        if( ptr == NULL)
            return(0);

        if(ptr->left == NULL)
            leftHeight = 0;
        else
            leftHeight = 1 + ptr->left->getHeight();

        if(ptr->right == NULL)
            rightHeight = 0;
        else
            rightHeight = 1 + ptr->right->getHeight();


        if(leftHeight > rightHeight)
            return(leftHeight);

        return(rightHeight);
    }





int AVLTree::calcBalance(AVLNode* ptr)
    {
        int leftHeight, rightHeight;

        if(ptr == NULL)
            return (0);

        if(ptr->left == NULL)
            leftHeight = 0;
        else
            leftHeight = 1 + ptr->left->getHeight();

        if(ptr->right == NULL)
            rightHeight = 0;
        else
            rightHeight = 1 + ptr->right->getHeight();

        return(leftHeight - rightHeight);
    }
AVLNode*  AVLTree::rotateRight(AVLNode* ptr)
    {
        AVLNode* newParent;

        newParent = ptr->left;
        ptr->left = newParent->right;
        newParent->right = ptr;
        ptr->setHeight(calcHeight(ptr));
        newParent->setHeight(calcHeight(newParent));

        return ( newParent );
    }





AVLNode*  AVLTree::rotateLeft(AVLNode* ptr)
    {
        AVLNode* newParent;

        newParent = ptr->right;
        ptr->right = newParent->left;
        newParent->left = ptr;
        ptr->setHeight(calcHeight(ptr));
        newParent->setHeight(calcHeight(newParent));

        return ( newParent );
    }





AVLNode*  AVLTree::rotateDoubleRight(AVLNode* ptr)
    {
        ptr = rotateLeft(ptr);
        return(ptr);
    }





AVLNode*  AVLTree::rotateDoubleLeft(AVLNode* ptr)
    {
        ptr = rotateRight(ptr);
        return(ptr);
    }





AVLNode*  AVLTree::rotateLeftRight(AVLNode* ptr)
    {
        ptr->left = rotateLeft(ptr->left);
        ptr = rotateRight(ptr);
        return(ptr);
    }
AVLNode*  AVLTree::rotateRightLeft(AVLNode* ptr)
    {
        ptr->right = rotateRight(ptr->right);
        ptr = rotateLeft(ptr);
        return(ptr);
    }


AVLNode*  AVLTree::deleteHelper(AVLNode* ptr, int num)
{
    AVLNode* successor;

    if ( ptr == NULL)           // Node location is empty
        {
            return NULL;
        }
    else
        if( num > ptr->getID() )                // Search in Right sub-tree
            {
                ptr->right = deleteHelper(ptr->right, num);
                if ( calcBalance(ptr) == 2)
                    {
                        if(calcBalance(ptr->left) >= 0)
                            ptr = rotateDoubleLeft(ptr);
                        else
                            ptr = rotateLeftRight(ptr);
                    }
            }
        else
            if( num < ptr->getID() )          // Search the Left sub-tree
                {
                    ptr->left = deleteHelper(ptr->left, num);
                    if( calcBalance(ptr) == -2 )                   //Rebalance during windup
                        {
                            if( calcBalance(ptr->right) <= 0)
                                ptr = rotateDoubleRight(ptr);
                            else
                                ptr = rotateRightLeft(ptr);
                        }
                }
            else
                {
                    //Node to to be deleted is found
                    if ( ptr->right != NULL)
                        {  //delete its inorder successor
                            successor = ptr->right;
                            while ( successor->left != NULL)
                                successor = successor->left;

                            ptr->setData( successor->getID(),successor->getName(), successor->getSurname(),successor->getMajor(),successor->getGPA());
                            ptr->right = deleteHelper( ptr->right, ptr->getID() );
                            if(calcBalance(ptr) == 2) // Rebalance during windup
                                {
                                    if(calcBalance(ptr->left) >= 0)
                                        ptr = rotateDoubleLeft(ptr);
                                    else
                                        ptr = rotateLeftRight(ptr);
                                }
                    }
                else
                    return(ptr->left);

                }
    ptr->setHeight(calcHeight(ptr));
    return(ptr);
}

AVLNode* AVLTree::insertHelper(AVLNode* ptr, int num, string fname, string lname, string maj, float grade)
    {
        if ( ptr == NULL )
            {
                ptr = new AVLNode(num, fname, lname, maj, grade);
            }
        else
            if(num >= ptr->getID())          // insert in right subtree; OP definition
                {
                    ptr->right = insertHelper(ptr->right,num, fname, lname, maj, grade );
                    if(calcBalance(ptr) == -2)          // Too heavy on the right
                        {
                            if(num > ptr->right->getID() )    // Regular right-heavy
                                ptr = rotateDoubleRight(ptr);
                            else                        // It's a special case: ">"
                                ptr = rotateRightLeft(ptr);
                        }
                }
            else
                if( num < ptr->getID() )
                    {
                        ptr->left = insertHelper(ptr->left, num, fname, lname, maj, grade);
                        if(calcBalance(ptr) == 2)       // Too heavy on the left
                            {
                                if( num < ptr->left->getID() )     // Regular left-heavy
                                    ptr = rotateDoubleLeft(ptr);
                                else                    // It's a special case: "<"
                                    ptr = rotateLeftRight(ptr);
                            }
                    }

        ptr->setHeight(calcHeight(ptr));
        return(ptr);
    }
    string AVLTree::inOrderHelper(AVLNode* ptr)
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




string AVLTree::preOrderHelper(AVLNode* ptr)
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




string AVLTree::postOrderHelper(AVLNode* ptr)
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
