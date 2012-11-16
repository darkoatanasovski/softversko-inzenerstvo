// kolokviumska_03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

class myvector{
private:
	vector<int> vec;
public:
	myvector()
	{
		vec.reserve(100);
	}
	void insert_element(int elem)
	{
		vec.push_back(elem);
	}
	void sort_vector()
	{
		int min = vec[0];
		vector<int> min_indexes;
		vector<int>::iterator it;
		for(int i=0;i<vec.size();i++)
		{
			if(vec[i] < min)
			{
				min = vec[i];
			}
		}
		int i=0;
		vector<int>::iterator tmp_iterator = vec.begin();
		for(it = vec.begin();it!=vec.end();++it)
		{
			if(*it == min)
			{
				min_indexes.push_back(i);
				sort(tmp_iterator,it);
				tmp_iterator = it;
			}
			i++;
		}
		cout<<endl<<"Min indexes:"<<endl;
		copy(min_indexes.begin(),min_indexes.end(),ostream_iterator<int>(cout," "));
		cout<<endl;
	}
	void printElements()
	{
		cout<<endl;
		copy(vec.begin(),vec.end(),ostream_iterator<int>(cout," "));
		cout<<endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	myvector v;
	v.insert_element(5);
	v.insert_element(3);
	v.insert_element(2);
	v.insert_element(5);
	v.insert_element(6);
	v.insert_element(3);
	v.insert_element(2);
	v.insert_element(7);
	v.printElements();
	v.sort_vector();
	v.printElements();
	return 0;
}

