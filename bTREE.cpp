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
    if (numberOfNodes() > 2)
    {
        q.push(root);
        // Do level order traversal until we find
        // an empty place. 
        while (!q.empty()) {
            treeNode * temp = q.front();
            q.pop();
     
            if (!temp->leftptr) {
                treeNode * new_node = new treeNode();
                new_node->data = data;
                new_node->time = timeStamp;
                new_node->leftptr = NULL;
                new_node->rightptr = NULL;
                new_node->isleaf = true;
                temp->leftptr = new_node;
                temp->isleaf = false;
                break;
            } else
                q.push(temp->leftptr);
     
            if (!temp->rightptr) {
                treeNode * new_node = new treeNode();
                new_node->data = data;
                new_node->time = timeStamp;
                new_node->leftptr = NULL;
                new_node->rightptr = NULL;
                new_node->isleaf = true;
                temp->rightptr = new_node;
                temp->isleaf = false;
                break;
            } else
                q.push(temp->rightptr);
        }
    }
    else 
    {
        if (numberOfNodes() > 0)
        {
            if (numberOfNodes() == 1)
            {
                treeNode * new_node = new treeNode();
                new_node->data = data;
                new_node->time = timeStamp;
                new_node->leftptr = NULL;
                new_node->rightptr = NULL;
                new_node->isleaf = true;
                root->leftptr = new_node;
                root->isleaf = false;
            }
            else if (numberOfNodes() == 2)
            {
                treeNode * new_node = new treeNode();
                new_node->data = data;
                new_node->time = timeStamp;
                new_node->leftptr = NULL;
                new_node->rightptr = NULL;
                new_node->isleaf = true;
                root->rightptr = new_node;
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
    }

    return true;

    // // if (root == NULL) {
    // //     return false;
    // // }
    // int nodeCount = numberOfNodes();

    // if (nodeCount == 0) {   // inserting at the root position
    //     treeNode * leaf = new treeNode();

    //     leaf->data = data;
    //     leaf->time = time;
    //     leaf->leftptr = NULL;
    //     leaf->rightptr = NULL;
    //     leaf->isleaf = true;

    //     root = leaf;

    //     nodeCount++;
    //     return true;
    // }

    // int h = ceil(log2(nodeCount + 1));
    // int trigger = (int) ((double) pow(2, h - 1) - nodeCount); //(double) pow(2, h - 2) - (double) (pow(2, h - 1) - nodeCount));
    // if (trigger < 0) {
    //     trigger = -trigger;
    // }

    // if (trigger > 0) {  // add to current row
    //     // trigger is the number of leafs to count in a postorder traversal
    //     // if trigger == 0 then insert leaf
    //     // if post order traversal to leaf -> trigger-- (still within this if)

    //     // post order traversal
    //     // call postOrderInsert


    // }
    // else {              // make a new row
    //     // leftmost traversal OR the first node edited in in a postOrder traversal
    // }

    // // do after all operations
    // nodeCount++;

}

// void postOrderInsert(treeNode * subtree, treeNode * leaf, int trigger) const {
//         if (trigger == 0) {
//             // traverse to next leaf
//             // subtree

//             // modify parent to not be a leaf if it is a leaf
//             return;
//         }

//         if (subtree->isleaf && trigger != 0) {
//             trigger--;
//         }
//     // } while (trigger < 0);
// }

bool bTREE::find(string s)
{
    // returns true if exists false if not
    return false;
}

string bTREE::locate(string s)
{
    return "0";
}

// friend bool bTREE::operator ==(const bTREE& lhs, const bTREE& rhs)
// {
//     if (lhs->data.compare(rhs->data) == 0)
//         return true;
//     else 
//         return false;
// }

// friend bool bTREE::operator !=(const bTREE& lhs, const bTREE& rhs)
// {
//     if (lhs->data.compare(rhs->data) =! 0)
//         return true;
//     else         
//         return false;
// }

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
        outfile << prefix + "/" << endl;
    }
    else
    {
        displayLeft(outfile, subtree->leftptr, prefix + "    ");
        outfile << prefix + "/---" << subtree->data << endl;
        displayRight(outfile, subtree->rightptr, prefix + "|    ");
    }
}

void bTREE::displayRight(ostream & outfile, treeNode * subtree, std::string prefix) const
{
    if (subtree == NULL)
    {
        outfile << prefix + "\\" << endl;
    }
    else 
    {
        displayLeft(outfile, subtree->leftptr, prefix + "|    ");
        outfile << prefix + "\\---" << subtree->data << endl;
        displayRight(outfile, subtree->rightptr, prefix + "    ");
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
