#pragma once
#include <string>
#include <math.h>
using namespace std;

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

    int numberOfNodesH() const;
    int nodeCount = 0;

    void postOrderInsert(treeNode * subtree, treeNode * leaf, int trigger) const;

public:
    bTREE();
    ~bTREE();

    int dataInserted();
    int numberOfNodes();

    bool insert(string, int);

    bool find(string);

    string locate(string);


    friend bool operator==(const bTREE& lhs, const bTREE& rhs);
    friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

    friend std::ostream& operator<<(std::ostream& out, const bTREE& p);

};
