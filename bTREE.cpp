#include "bTREE.h"


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
    return nodeCount;
	// numberOfNodesH(root);
}

bool bTREE::insert(string data, int time)
{
    // if (root == NULL) {
    //     return false;
    // }

    if (nodeCount == 0) {   // inserting at the root position
        treeNode * leaf = new treeNode();

        leaf->data = data;
        leaf->time = time;
        leaf->leftptr = NULL;
        leaf->rightptr = NULL;
        leaf->isleaf = true;

        root = leaf;

        nodeCount++;
        return true;
    }

    int h = ceil(log2(nodeCount + 1));
    int trigger = (int) ((double) pow(2, h - 1) - nodeCount); //(double) pow(2, h - 2) - (double) (pow(2, h - 1) - nodeCount));
    if (trigger < 0) {
        trigger = -trigger;
    }

    if (trigger > 0) {  // add to current row
        // trigger is the number of leafs to count in a postorder traversal
        // if trigger == 0 then insert leaf
        // if post order traversal to leaf -> trigger-- (still within this if)

        // post order traversal
        // call postOrderInsert


    }
    else {              // make a new row
        // leftmost traversal OR the first node edited in in a postOrder traversal
    }

    // do after all operations
    nodeCount++;

}

void postOrderInsert(treeNode * subtree, treeNode * leaf, int trigger) const {
        if (trigger == 0) {
            // traverse to next leaf
            // subtree

            // modify parent to not be a leaf if it is a leaf
            return;
        }

        if (subtree->isleaf && trigger != 0) {
            trigger--;
        }
    // } while (trigger < 0);
}

int bTREE::find(string)
{
}

string bTREE::locate()
{
}

friend bool bTREE::operator ==(const bTREE& lhs, const bTREE& rhs)
{
}

friend bool bTREE::operator !=(const bTREE& lhs, const bTREE& rhs)
{
}

friend std::ostream& bTREE::operator <<(std::ostream& out, const bTREE& p)
{
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
