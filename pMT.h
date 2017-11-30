#pragma once

#include "bTREE.h"
#include <string>
using namespace std;

#ifndef pMT_H
#define pMT_H

class pMT
{
private:
    int selectedHash;
    bTREE myMerkle;
    
    string hash_1(string);
    string hash_2(string); 
    string hash_3(string);

    void rehash(bTREE * & tree);
    
public:
    pMT(int);
    ~pMT();
    
    int insert(string, int);
    
    int find(string, int, int);
    int findHash(string);
    
    string locateData(string);
    string locateHash(string);
    
    friend bool operator==(const pMT& lhs, const pMT& rhs);
    
    friend bool operator!=(const pMT& lhs, const pMT& rhs);
    
    friend pMT operator^(const pMT& lhs, const pMT& rhs);

    friend std::ostream& operator<<(std::ostream& out, const pMT& p);
    
};

#endif

