//Zadacata raboti, ama neznam dali e toa toa sto se bara vo nea. Mnogu mi se konfuzni ova tipcive sto gi smisluvaat zadacive :)
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

void fobj(vector<int> v, int shift)
{
	rotate(v.begin(),v.begin()+shift,v.end());
	cout<<(shift+1)<<" rotacija"<<endl;
	copy(v.begin(),v.end(),ostream_iterator<int>(cout,""));
	cout<<endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	copy(vec.begin(),vec.end(),ostream_iterator<int>(cout,""));
	cout<<endl;
	for(int i=0;i<vec.size();i++)
	{
		fobj(vec,i);
	}
	
	return 0;
}

