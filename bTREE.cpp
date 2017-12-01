#include "bTREE.h"
#include <string>
using namespace std;
#include <iostream>
#include <queue>

//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
    root = NULL;
}

bTREE::~bTREE()
{
	destroy( root );
}

int bTREE::dataInserted()
{
    //return the number of operations needed to do the insert, -1 if out of memory
    return 0;
}

int bTREE::numberOfNodesH(treeNode * subtree)
{
	if (subtree == NULL)
		return 0;
	else {
		return numberOfNodesH(subtree->leftptr) + 1 + numberOfNodesH(subtree->rightptr);
	}
}

int bTREE::numberOfNodes()
{
    //return nodeCount;
	return numberOfNodesH(root);
}

bool bTREE::insert(string data, int timeStamp)
{
    queue<struct treeNode*> q;

    // used refernce from geeksforgeeks.com 
    if (numberOfNodes() > 0)
    {
        q.push(root);
        // Do level order traversal until we find
        // an empty place. 
        while (!q.empty()) {
            treeNode * temp = q.front();
            q.pop();
     
            if (!temp->leftptr) {
                // create two new nodes
                // prev_node copys temp node
                // new_node makes new node in right ptr
                treeNode * prev_node = new treeNode();
                treeNode * new_node = new treeNode();

                // copy temp info to prev_node
                prev_node->data = temp->data;
                prev_node->time = temp->time;
                prev_node->isleaf = true;
                prev_node->leftptr = NULL;
                prev_node->rightptr = NULL;
               
                // add info to new_node
                new_node->data = data;
                new_node->time = timeStamp;
                new_node->leftptr = NULL;
                new_node->rightptr = NULL;
                new_node->isleaf = true;

                // make temp node parent of new_node and prev_node
                // this will be the hash of both
                temp-> data = "parent";
                temp->time = 666;
                temp->leftptr = prev_node;
                temp->rightptr = new_node;
                temp->isleaf = false;
                break;
            } else
            {
                q.push(temp->leftptr);
                q.push(temp->rightptr);
            }
        }
    }
    else 
    {
        // create root node
        treeNode * new_node = new treeNode();
        new_node->data = data;
        new_node->time = timeStamp;
        new_node->leftptr = NULL;
        new_node->rightptr = NULL;
        new_node->isleaf = true;
        root = new_node;
    }

    return true;
}

bool bTREE::inorderSearch(treeNode * & subtree, string s, bool &found)
{
    if (subtree != NULL)
    {
        inorderSearch(subtree->leftptr, s, found);
        if (subtree->data.compare(s) == 0)
        {
            found = true;
        }
        inorderSearch(subtree->rightptr, s, found);
    }

    return found;
}

bool bTREE::find(string s)
{
    // returns true if exists false if not
    bool found = false;
    return inorderSearch(root, s, found);

}

string bTREE::locate(string s)
{
    return "0";
}

bool operator ==(const bTREE& lhs, const bTREE& rhs)
{
    // if left tree == right tree return true
    // Return true if both trees are empty
    if (lhs.root == NULL  && rhs.root == NULL) return true;
 
    // Return false if one is empty and other is not
    if (lhs.root == NULL || rhs.root == NULL)  return false;
 
    // return true if root data is the same AND time is the same
    if(lhs.root->data.compare(rhs.root->data) == 0 
        && lhs.root->time == rhs.root->time) 
        return true;
    else 
        return false;

}

bool operator !=(const bTREE& lhs, const bTREE& rhs)
{
    // if left tree != right tree return true
    // Return false if both trees are empty
    if (lhs.root == NULL  && rhs.root == NULL) return false;
 
    // Return true if one is empty and other is not
    if (lhs.root == NULL || rhs.root == NULL)  return true;
 
    // return false if root data is the same AND time is the same
    if(lhs.root->data.compare(rhs.root->data) == 0 
        && lhs.root->time == rhs.root->time) 
        return false;
    else 
        return true;
}

ostream & operator <<(ostream & out, const bTREE & p)
{
    p.print(out);
    return out;
}

void bTREE::print(ostream & outfile) const
{
    if (root == NULL)
        outfile << "-" << endl;
    else 
    {
        displayLeft(outfile, root->leftptr, "    ");
        outfile << "---" << root->data << endl;
        displayRight(outfile, root->rightptr, "    ");
    }
}

void bTREE::displayLeft(ostream & outfile, treeNode * subtree, std::string prefix) const
{
    if (subtree == NULL)
    {
        outfile << prefix + "                              /" << endl;
    }
    else
    {
        displayLeft(outfile, subtree->leftptr, prefix + "                   ");
        outfile << prefix + "               /---" << subtree->data << endl;
        displayRight(outfile, subtree->rightptr, prefix + "              |    ");
    }
}

void bTREE::displayRight(ostream & outfile, treeNode * subtree, std::string prefix) const
{
    if (subtree == NULL)
    {
        outfile << prefix + "                              \\" << endl;
    }
    else 
    {
        displayLeft(outfile, subtree->leftptr, prefix + "              |    ");
        outfile << prefix + "               \\---" << subtree->data << endl;
        displayRight(outfile, subtree->rightptr, prefix + "                   ");
    }
}

void bTREE::destroy( treeNode * & subtree)
{
	if( subtree != NULL )
   	{
      destroy( subtree->leftptr );
      destroy( subtree->rightptr );
      delete subtree;
      subtree = NULL;
   	}
}

bTREE::treeNode* bTREE::getRoot()
{
    return root;
}
