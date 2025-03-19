 //
//  Splay.h
//  Kyle Cox - 400009491
//
//  Created by Dr. John Charlery on 03/13/2024.
//  Copyright (c) 2024 University of the West Indies. All rights reserved.
//
#ifndef SPLAYTREE_H
#define SPLAYTREE_H


class SplayNode
    {
        private:
            int idNo;
            string name;
            string surname;
            string major;
            float gpa;

        public:
                SplayNode *left;  	// pointer to left subtree
                SplayNode *right;    // pointer to right subtree

                //Constructor
                SplayNode(Record rec);
                SplayNode(int,string,string,string,float);
                SplayNode() {right = left = NULL;}

                //Mutators
                void setLeft(SplayNode* ptr)  { left = ptr; }
                void setRight(SplayNode* ptr) { right = ptr; }
                void setData(int, string, string, string, float);


                //Accessors
                SplayNode* getLeft()  const { return left;}
                SplayNode* getRight() const { return right;}
                int getID()         {return idNo;}
                string getName()    {return name;}
                string getSurname() {return surname;}
                string getMajor()   {return major;}
                float getGPA()      {return gpa;}
                string getData();
    };

SplayNode::SplayNode(Record rec)
{
        idNo    = rec.idNo;
        name    = rec.name;
        surname = rec.surname;
        major   = rec.major;
        gpa     = rec.gpa;
        left    = right = NULL;
}
SplayNode::SplayNode(int ID, string fname, string Surname, string Major, float Gpa)
{
        idNo    = ID;
        name    =  fname;
        surname = Surname;
        major   = Major;
        gpa     = Gpa;
        left    = right = NULL;
}

string SplayNode::getData()
    {
        string str = to_string(idNo);
        str.append("\t" + name + "\t\t" + surname + "\t\t" + major + "\t\t");
        str.append(trim(gpa) );     // Trim the GPA value to 2 places of decimal

        return str;
    }




void SplayNode::setData(int num, string fname, string lname, string maj, float grade)
    {
        idNo    = num;
        name    = fname;
        surname = lname;
        major   = maj;
        gpa     = grade;
    }




class SplayTree
    {
        private:
                SplayNode *root;

                // Utility functions
                SplayNode* RightRotate(SplayNode*);
                SplayNode* LeftRotate(SplayNode*);
                SplayNode* Splay(SplayNode*, Record);
                SplayNode* Splay(SplayNode*, int, string, string,string, float);
                SplayNode* InsertHelper(SplayNode*, Record);
                SplayNode* InsertHelper(SplayNode*, int, string, string,string, float);
                string inOrderHelper(SplayNode*);
                string preOrderHelper(SplayNode*);
                string postOrderHelper(SplayNode*);
                string displayNodesHelper( SplayNode * ) const;
                void deleteSplayNode( SplayNode* );
                SplayNode* findSplayNode(int);
                SplayNode* getSuccessor(SplayNode* );
                SplayNode* getParent(SplayNode* );
                SplayNode* getMinimum( SplayNode* );


            public:
                SplayTree(){ root = 0; };
                SplayNode* getRoot(){return root;}
                void insert(Record rec);
                void insert(int, string, string,string,float);
                string inOrder(){ return inOrderHelper(root);}
                string preOrder(){ return preOrderHelper(root);}
                string postOrder(){ return postOrderHelper(root);}
                string displayNodes();
                void remove(int);
    };

void SplayTree::insert(Record rec)
{
    root = InsertHelper(root, rec);

}
void SplayTree::insert(int ID, string fname,string surname, string major, float gpa)
{
    root = InsertHelper(root, ID, fname, surname, major, gpa);

}




SplayNode* SplayTree::Splay(SplayNode* root, Record rec)
    {
        if(root == NULL)
            return NULL;

        SplayNode* header = new SplayNode();

        SplayNode* LeftTreeMax = header;
        SplayNode* RightTreeMin = header;

        /* loop until root->left == NULL || root->right == NULL; then break!
         The zig/zag mode would only happen when cannot find key and will reach
         null on one side after RR or LL Rotation.
         */
        while(root->left != NULL || root->right != NULL)
            {
                if(rec.idNo < root->getID())
                    {
                        if(root->left == NULL)
                            break;

                        if(rec.idNo < root->left->getID())
                            {
                                root = RightRotate(root); /* Only zig-zig mode need to rotate once,
                                                        because zig-zag mode is handled as zig
                                                        mode, which doesn't require rotate,
                                                        just linking it to R Tree */
                                if(!root->left)
                                    break;
                            }

                        /* Link to Right Tree */
                        RightTreeMin->left = root;
                        RightTreeMin = RightTreeMin->left;
                        root = root->left;
                        RightTreeMin->left = NULL;
                    }
                else if(rec.idNo > root->getID())
                        {
                            if(root->right == NULL)
                                break;
                            if(rec.idNo > root->right->getID())
                                {
                                    root = LeftRotate(root);/* only zag-zag mode need to rotate once,
                                                        because zag-zig mode is handled as zag
                                                        mode, which doesn't require rotate,
                                                        just linking it to L Tree */
                                    if(root->right == NULL)
                                        break;
                                }
                            /* Link to Left Tree */
                            LeftTreeMax->right = root;
                            LeftTreeMax = LeftTreeMax->right;
                            root = root->right;
                            LeftTreeMax->right = NULL;
                        }
                    else
                        break;
                }
            /* assemble Left Tree, Middle Tree and Right tree together */
            LeftTreeMax->right = root->left;
            RightTreeMin->left = root->right;
            root->left = header->right;
            root->right = header->left;
            return root;
    }


SplayNode* SplayTree::RightRotate(SplayNode* ptr)
{
    SplayNode* leftchild = ptr->left;
    ptr->left = leftchild->right;
    leftchild->right = ptr;
    return leftchild;
}




SplayNode* SplayTree::LeftRotate(SplayNode* ptr)
{
    SplayNode* rightchild = ptr->right;
    ptr->right = rightchild->left;
    rightchild->left = ptr;
    return rightchild;
}









SplayNode* SplayTree::findSplayNode(int id)
    {
        SplayNode* ptr = root;

        while ( ptr != NULL )
            {
                if  (ptr->getID() == id)        // Found it!
                        {
                            return ptr;
                        }

                if (id < ptr->getID() )
                    {
                        ptr = ptr->left;
                    }
                else
                    {
                        ptr = ptr->right;
                    }
            }

        return NULL;            // Tree is empty OR did not find it
    }






SplayNode* SplayTree::getParent(SplayNode* ptr)
    {
        if (ptr == NULL)
            return NULL;

        if (ptr == root)
            return NULL;

        SplayNode* cur = root;

        while ( cur != NULL )
            {
                if (cur->left == ptr || cur->right == ptr)        // Found it!
                    {
                        return cur;
                    }
                else
                    {
                        if (ptr->getID() < cur->getID())
                            cur = cur->left;
                        else
                            cur = cur->right;
                    }
            }
         return cur;            // Parent for ptr is NOT found
    }




SplayNode* SplayTree::getSuccessor(SplayNode* ptr)
{
    if (ptr->right == NULL)
        return ptr->left;
    else
        return(getMinimum(ptr->right));
}




SplayNode* SplayTree::getMinimum(SplayNode *ptr)
{
    while(ptr->left != NULL)
        ptr = ptr->left;

    return ptr;
}






SplayNode* SplayTree::InsertHelper(SplayNode* root, Record rec)
    {
        SplayNode* newnode = new SplayNode(rec);

        if(root == NULL)
            return newnode;

        SplayNode* parent_temp = new SplayNode();
        SplayNode* temp = root;

        while(temp != NULL)
            {
                parent_temp = temp;

                if(rec.idNo <= temp->getID())
                    temp = temp->left;
                else
                    temp = temp->right;
            }

        if(rec.idNo <= parent_temp->getID())
            parent_temp->left = newnode;
        else
            parent_temp->right = newnode;

        root = Splay(root, rec);
        return (root);
    }







string SplayTree::inOrderHelper(SplayNode* ptr)
    {
        string str = "";

        if ( ptr != NULL )
            {
                str.append( inOrderHelper(ptr->left) );

                // Process the node, ptr
                str.append(ptr->getData());

                // Append ptr's children
                str.append("\t[");
                if (ptr->getLeft() != NULL){
                    str.append(to_string(ptr->getLeft()->getID()) + ", ");
                }else{
                    str.append("NULL, ");
                }
                if (ptr->getRight() != NULL){
                    str.append(to_string(ptr->getRight()->getID()) + "]\n");
                }else{
                    str.append("NULL]\n");
                }

                str.append( inOrderHelper(ptr->right) );
              }
		return str;
    }


string SplayTree::preOrderHelper(SplayNode* ptr)
    {
        string str = "";

        if ( ptr != NULL )
            {
                // Process the node, ptr
                str.append(ptr->getData());

                // Append ptr's children
                str.append("\t[");
                if (ptr->getLeft() != NULL){
                    str.append(to_string(ptr->getLeft()->getID()) + ", ");
                }else{
                    str.append("NULL, ");
                }
                if (ptr->getRight() != NULL){
                    str.append(to_string(ptr->getRight()->getID()) + "]\n");
                }else{
                    str.append("NULL]\n");
                }

                str.append( preOrderHelper(ptr->left) );
                str.append( preOrderHelper(ptr->right) );
              }
		return str;
    }


string SplayTree::postOrderHelper(SplayNode* ptr)
    {
        string str = "";

        if ( ptr != NULL )
            {
                str.append( postOrderHelper(ptr->left) );
                str.append( postOrderHelper(ptr->right) );

                // Process the node, ptr
                str.append(ptr->getData());

                // Append ptr's children
                str.append("\t[");
                if (ptr->getLeft() != NULL){
                    str.append(to_string(ptr->getLeft()->getID()) + ", ");
                }else{
                    str.append("NULL, ");
                }
                if (ptr->getRight() != NULL){
                    str.append(to_string(ptr->getRight()->getID()) + "]\n");
                }else{
                    str.append("NULL]\n");
                }

              }
		return str;
    }





void SplayTree::remove(int str)
    {
        SplayNode* markedSplayNode = findSplayNode(str);
        deleteSplayNode(markedSplayNode);
    }





void SplayTree::deleteSplayNode(SplayNode* node2Zap)
    {

        if (node2Zap == NULL)    //If node2Zap is NULL then do nothing.
            return;
        else
            {
                SplayNode *successor, *successorChild, *parent;

                if (node2Zap->left == NULL || node2Zap->right == NULL)
                    successor = node2Zap;
                else                                        // node2Zap has 2 children
                    successor = getSuccessor(node2Zap);


                successorChild = successor->right;
                parent = getParent(successor);


                // Transfer data from successor to node2Zap
                node2Zap->setData(successor-> getID(), successor-> getName(), successor-> getSurname(), successor-> getMajor(), successor-> getGPA());


                if ( parent == NULL)
                    root = successorChild;
                else if (successor == parent->left)
                        parent->left = successorChild;
                    else
                        parent->right = successorChild;

                if (successor != node2Zap)
                    node2Zap->setData(successor-> getID(), successor-> getName(), successor-> getSurname(), successor-> getMajor(), successor-> getGPA());

                delete successor;

            }

    }


    SplayNode* SplayTree::InsertHelper(SplayNode* root, int ID, string fname,string surname,string major,float gpa)
    {
        SplayNode* newnode = new SplayNode(ID,fname,surname,major,gpa);

        if(root == NULL)
            return newnode;

        SplayNode* parent_temp = new SplayNode();
        SplayNode* temp = root;

        while(temp != NULL)
            {
                parent_temp = temp;

                if(ID <= temp->getID())
                    temp = temp->left;
                else
                    temp = temp->right;
            }

        if(ID <= parent_temp->getID())
            parent_temp->left = newnode;
        else
            parent_temp->right = newnode;

        root = Splay(root,ID,fname,surname,major,gpa );
        return (root);
    }



SplayNode* SplayTree::Splay(SplayNode* root, int ID, string fname, string surname, string major, float gpa)
    {
        if(root == NULL)
            return NULL;

        SplayNode* header = new SplayNode();

        SplayNode* LeftTreeMax = header;
        SplayNode* RightTreeMin = header;

        /* loop until root->left == NULL || root->right == NULL; then break!
         The zig/zag mode would only happen when cannot find key and will reach
         null on one side after RR or LL Rotation.
         */
        while(root->left != NULL || root->right != NULL)
            {
                if(ID < root->getID())
                    {
                        if(root->left == NULL)
                            break;

                        if(ID < root->left->getID())
                            {
                                root = RightRotate(root); /* Only zig-zig mode need to rotate once,
                                                        because zig-zag mode is handled as zig
                                                        mode, which doesn't require rotate,
                                                        just linking it to R Tree */
                                if(!root->left)
                                    break;
                            }

                        /* Link to Right Tree */
                        RightTreeMin->left = root;
                        RightTreeMin = RightTreeMin->left;
                        root = root->left;
                        RightTreeMin->left = NULL;
                    }
                else if(ID > root->getID())
                        {
                            if(root->right == NULL)
                                break;
                            if(ID > root->right->getID())
                                {
                                    root = LeftRotate(root);/* only zag-zag mode need to rotate once,
                                                        because zag-zig mode is handled as zag
                                                        mode, which doesn't require rotate,
                                                        just linking it to L Tree */
                                    if(root->right == NULL)
                                        break;
                                }
                            /* Link to Left Tree */
                            LeftTreeMax->right = root;
                            LeftTreeMax = LeftTreeMax->right;
                            root = root->right;
                            LeftTreeMax->right = NULL;
                        }
                    else
                        break;
                }
            /* assemble Left Tree, Middle Tree and Right tree together */
            LeftTreeMax->right = root->left;
            RightTreeMin->left = root->right;
            root->left = header->right;
            root->right = header->left;
            return root;
    }


#endif
