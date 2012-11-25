#include "stdafx.h"
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

char gen[] = {'a','c','t','g'};
bool GenesCounter(char curr)
{
	static int counter = 0;
	bool ret = false;
	
	if(gen[counter] != curr)
	{
		counter = 0;
	}

	if(gen[counter] == curr)
	{
		counter++;
	}
	

	if(counter >= 3)
	{
		counter = 0;
		ret = true;
	}

	return ret;
}

int _tmain(int argc, _TCHAR* argv[])
{
	list<char> coll;

	/*aactggggacccactgagctactgggaaccatg*/
	coll.push_back('a');
	coll.push_back('a');
	coll.push_back('c');
	coll.push_back('t');
	coll.push_back('g');
	coll.push_back('g');
	coll.push_back('g');
	coll.push_back('g');
	coll.push_back('a');
	coll.push_back('c');
	coll.push_back('c');
	coll.push_back('c');
	coll.push_back('a');
	coll.push_back('a');
	coll.push_back('t');
	coll.push_back('g');
	coll.push_back('a');
	coll.push_back('g');
	coll.push_back('c');
	coll.push_back('a');
	coll.push_back('c');
	coll.push_back('t');
	coll.push_back('g');
	coll.push_back('a');
	int count = count_if(coll.begin(), coll.end(), GenesCounter);

	cout <<"DNK Seq: ";
	copy(coll.begin(),coll.end(),ostream_iterator<char>(cout, ""));
	cout<<endl;
	cout << "Count: " << count << endl;
	return 0;
}

