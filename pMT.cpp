#include <iomanip>
#include "bTREE.h"
#include "pMt.h"
using namespace std;
pMT::pMT(int hashSelect)
/**
 * @brief
 * @param hashSelect a number corresponding to the hashfunction to use for this pMT
 * @return
 */
{
	myMerkle = bTREE();
	selectedHash = hashSelect;
}

pMT::~pMT()
/**
 * @brief destructor
 * @return nada
 */
{
}

int pMT::insert(string vote, int time)
/**
 * @brief insert a vote and time into a leaf node of tree
 * @param vote - a string
 * @param time - an int representing the time
 * @return the number of operations needed to do the insert, -1 if out of memory
 */

{
	switch (selectedHash) 
	{
		case 1:
		myMerkle.insert(hash_1(vote), time);
		break;
		case 2:
		myMerkle.insert(hash_2(vote), time);
		break;
		case 3:
		myMerkle.insert(hash_3(vote), time);
		break;
	}

	return myMerkle.dataInserted();
}

int pMT::find(string vote, int time, int hashSelect)
/**
 * @brief given a vote, timestamp, and hash function, does this vote exist in the tree?
 * @param vote, a string
 * @param time, an int
 * @param hashSelect, an int corresponding to the hash functions _1, _2, and _3
 * @return 0 if not found, else number of opperations required to find the matching vote
 */
{
	return 0;
}

int pMT::findHash(string mhash)
/**
 * @brief does this hash exist in the tree?
 * @param mhash, a string to search for in the tree
 * @return 0 if not found, else number of opperations required to find the matching hash
 */
{
	return 0;
}


string pMT::locateData(string vote)
/**
 * @brief Function takes a hash of Vote and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root.
 * @param vote, the data to search for
 * @return sequence of L's and R's comprising the movement to the leaf node; else return a dot '.'
 */
{
	return "0";
}

string pMT::locateHash(string mhash)
/**
 * @brief Function takes a hash and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root.
 * @param mhash, the hash to search for
 * @return sequence of L's and R's comprising the movement to the hash node, ; else return a dot '.'
 */
{
	return "0";
}



string pMT::hash_1(string key)
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 * creator: Sam
 */
{
    char charKey[64];

    // put the key in a char array of length 32 (maximum output length)
    for (int i = 0, j = 0; i < 64; i++, j++) {
        if (j == key.length()) {
            j = 0;
        }

        charKey[i] = (char) key.at(j);
    }


    string hash;

    // max unsigned long 4294967295
    // max prime in range: 4294967291
    unsigned long myPrime = 4294967291;

    // mod 95 then plus 33 to avoid

    // do the operation on the first character
    hash = (char) ((((((int) charKey[0] + (int) charKey[1])) % myPrime) % 94) + 33);

    // do the operation on the rest
    for (int i = 2; i < 63; i += 2) {

        hash += (char) ((((((int) charKey[i] + (int) charKey[i + 1]) * i) % myPrime) % 94) + 33);
    }


    return hash;


}

string pMT::hash_2(string key)
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
 //  int prime = 2147483647;
 //  int hash = 5381; //"5381 is just a number that, in testing, resulted in fewer collisions and better avalanching." - stackoverflow user Mahmoud Al-Qudsi
 //  int length = key.length();
 //  // if length is not 32 characters make it by cycling through
	// // the key and adding more characters
 //  // borrowed from Jared's hash function, hash_3
 //  if (length < 32) {
	// 	while (key.length() < 32)
	// 	{
	// 		static int i = 0;
	// 		key += key.at(i);
	// 		i++;
	// 	}
	// 	length = key.length();
	// }
 //  //create my hash
 //  for (i=0; i < length; i++)
 //  {
 //    hash += ((unsigned char)key[i] % prime) + 42;
 //  }
 //  // use <iomanip>'s "hex" to convert to hexadecimal, thus a string that can be returned.
 //  hex << hash;
 //  return hash;
}
//Jared's Hash
string pMT::hash_3(string key)
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */

{
	// initialize prime constants
	const int A = 15607;
	const int B = 38303;

	// initialize new string and length
	string new_key = "";
	int length = key.length();

	// if length is < 32 make it 32 by cycling through
	// the key and adding more characters
	// if the length is > 32  make it 32 by putting the last chacters first
	if (length < 32) {
		int i = 0;
		while (key.length() < 32)
		{
			key += key.at(i);
			i++;
		}
		length = key.length();
	}
	else if (length > 32) {
		int j = 0;
		while (key.length() > 32)
		{
			key.at(j) = key.at(length - (j + 1));
			key.erase(length - (j + 1));
			j++;
		}
		length = key.length();
	}

	// make hash
	for (int i = 0; i < length; i++)
	{
		int ascii = (unsigned char)key.at(i);
		new_key += (((((ascii * A) ^ (ascii * B) * i) ) % 93) + 33);
	}

	return new_key;

}

// friend bool pMT::operator ==(const pMT& lhs, const pMT& rhs)
// /**
//  * @brief Comparison between two merkle trees
//  * @param lhs, the left hand side of the equality statment
//  * @param rhs, the right hand side of the equality statement
//  * @return true if equal, false otherwise
//  */
// {
// }

// friend bool pMT::operator !=(const pMT& lhs, const pMT& rhs)
// /**
//  * @brief Comparison between two merkle trees
//  * @param lhs, the left hand side of the equality statment
//  * @param rhs, the right hand side of the equality statement
//  * @return true if not equal, false otherwise
//  */
// {
// }

// friend pMT pMT::operator ^=(const pMT& lhs, const pMT& rhs)
// /**
//  * @brief XOR between two merkle trees
//  * @param lhs, the left hand side of the equality statment
//  * @param rhs, the right hand side of the equality statement
//  * @return true if not equal, false otherwise
//  */
// {
// }


ostream& operator <<(ostream& out, const pMT& p)
/**
 * @brief Print out a tree
 * @param out
 * @param p
 * @return a tree to the screen
 */
{
	out << p.myMerkle;
	return out;
}


// friend pMT pMT::operator ^(const pMT& lhs, const pMT& rhs)
// /**
//  * @brief Where do two trees differ
//  * @param lhs
//  * @param rhs
//  * @return a tree comprised of the right hand side tree nodes that are different from the left
//  */
// {
// }
