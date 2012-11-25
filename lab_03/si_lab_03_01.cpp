#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

class PowerOf2{
public:
	int power(int n)
	{
		if(n == 0 || n == 2)
		{
			return 0;
		}

		if(n % 2 != 0)
		{
			return 1;
		}
		
		return power(n/2);
	}
	bool operator() (int elem) 
	{
		return power(elem)==0;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> coll;
	for(int i=1;i<10;i++)
	{
		PowerOf2 p2;
		coll.push_back(i);
	}
	copy(coll.begin(),coll.end(),ostream_iterator<int>(cout, " "));
	cout<<endl;

	vector<int>::iterator iter = remove_if(coll.begin(),coll.end(),PowerOf2() );

	copy(coll.begin(), iter, ostream_iterator<int>(cout, " "));
	cout<<endl;
	return 0;
}

