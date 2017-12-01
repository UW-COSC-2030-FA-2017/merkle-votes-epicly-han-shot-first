#pragma once
#include <string>
#include <math.h>
#include <queue>
// #include "pMT.h"
using namespace std;

#ifndef BTREE_H
#define BTREE_H

class bTREE
{
    struct treeNode{
        string data;
        int time;
        treeNode* leftptr;
        treeNode* rightptr;
        bool isleaf;
    };

private:
    //some data structure to hold your treeNodes together ...
    //DATASTUCTURE treeNodes tree;
    //any helper private variables you need

    treeNode * root;

    int numberOfNodesH(treeNode * subtree);
    // dont need node counting variable. just use method
    void destroy(treeNode * & subtree);
    bool inorderSearch(treeNode*&, string, bool&);
    bool preorderLocate(treeNode * & subtree, string s, bool &found, string &map);
    void displayLeft(ostream & outfile, treeNode  * subtree, string) const;
    void displayRight(ostream & outfile, treeNode * subtree, string) const;

public:
    bTREE();
    ~bTREE();

    int dataInserted();
    int numberOfNodes();

    bool insert(string, int);

    bool find(string);

    void print(std::ostream& ) const;

    string locate(string);

    // friend class pMT;

    //friend void rehash(bTREE * & tree);

    friend bool operator==(const bTREE& lhs, const bTREE& rhs);
    friend bool operator!=(const bTREE& lhs, const bTREE& rhs);
    friend ostream & operator<<(ostream& out, const bTREE& p);

};

#endif
