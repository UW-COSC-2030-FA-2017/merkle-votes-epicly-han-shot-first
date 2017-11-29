#include <stdio.h>
#include "pMT.h"
#include "bTREE.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	//printf("Hello World");

	// test insert 
	bTREE alpha;
	alpha.insert("data1", 1);
	alpha.insert("data2", 2);
	alpha.insert("data3", 3);
	alpha.insert("data4", 4);
	alpha.insert("data5", 1);
	alpha.insert("data6", 2);
	alpha.insert("data7", 3);
	alpha.insert("data8", 4); 
	alpha.insert("data9", 88);	
	cout << alpha.numberOfNodes() << endl;
	cout << "*****Print inorder tree*****" << endl;
	// for some reason this prints mirrored... 
	cout << alpha << endl;
	return 0;
}
