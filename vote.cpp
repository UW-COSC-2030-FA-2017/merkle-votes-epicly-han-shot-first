#include <stdio.h>
#include "pMT.cpp"
#include "bTREE.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>	// to covert string to int
using namespace std;
int main(int argc, char **argv)
{
	pMT tester(2);
    string data, time;
    ifstream myfile ("my_test.txt");
    if (myfile.is_open())
    {
      while ( myfile >> data >> time)
      {
      	istringstream buffer(time);
      	int time_val = 0;
      	buffer >> time_val;
        cout << tester.insert(data, time_val) << endl;
      }
      myfile.close();
    }
    else cout << "Unable to open file";

    cout << tester;

 	cout << endl << tester.findHash("UWOo}3';o)uQ+Ki#_;m5/mcOsi{mQ-'S");

	return 0;
}
