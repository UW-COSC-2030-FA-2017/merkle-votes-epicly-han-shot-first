#include <stdio.h>
#include "pMT.h"
#include "bTREE.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>	// to covert string to int
using namespace std;

int main(int argc, char **argv)
{
	//printf("Hello World");

	//test insert with bTREE
	bTREE alpha;
	alpha.insert("11111111111111111111111111111111", 1);
	alpha.insert("22222222222222222222222222222222", 2);
	alpha.insert("33333333333333333333333333333333", 3);
	alpha.insert("44444444444444444444444444444444", 4);
	alpha.insert("55555555555555555555555555555555", 1);
	alpha.insert("66666666666666666666666666666666", 2);
	alpha.insert("77777777777777777777777777777777", 3);
	alpha.insert("88888888888888888888888888888888", 4); 
	alpha.insert("99999999999999999999999999999999", 88);	
	// for some reason this prints mirrored... 
	cout << alpha << endl;

	// read from file and real stuff
	pMT tester(3);

    string data, time;
    ifstream myfile ("my_test.txt");
    if (myfile.is_open())
    {
      while ( myfile >> data >> time)
      {
      	istringstream buffer(time);
      	int time_val = 0;
      	buffer >> time_val;
        tester.insert(data, time_val);
      }
      myfile.close();
    } 
    else cout << "Unable to open file"; 

    cout << tester;

	return 0;
}
