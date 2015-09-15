#include <iostream>
#include "arrays-strings.h"

using namespace std;

int main(int argc, char **argv)
{
	string s = "is not unique";
	string s2 = "uniqe yop";
	
	cout << isUnique(s2);
	cout << isUniqueWOArray(s);
}
