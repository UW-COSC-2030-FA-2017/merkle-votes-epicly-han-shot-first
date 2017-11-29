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
	cout << alpha.numberOfNodes() << endl;

	// using inorder traversal to test
	// ill show you guys thursday or sooner
	// after the following methods can be deleted:
	// printTest
	// inorder
	alpha.printTest();
	return 0;
}
