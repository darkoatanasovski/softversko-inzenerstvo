// kolokviumska_01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;
class OutOfRangeException{
public:
	void printException()
	{
		cout << endl << "Out of range!" << endl;
	}
};
template <typename T>
class mylist{
private:
	int size;
	int inserted_items;
	vector<T> vec;
public:
	mylist(int s)
	{
		size = s;
		inserted_items=0;
		vec.reserve(size);
	}
	mylist()
	{
		size = 10;
		inserted_items=0;
		vec.assign(size);
	}
	void insert_element(T elem)
	{
		if(inserted_items >= size)
		{
			throw OutOfRangeException();
		}else{
			vec.push_back(elem);
			inserted_items++;
		}
	}
	void remove_element(int pos)
	{
		vec.erase(vec.begin()+pos);
		inserted_items--;
	}
	T getElementAt(int pos)
	{
		if(pos >= inserted_items || pos < 0)
		{
			throw OutOfRangeException();
		}else
		{
			return vec[pos];
		}
	}
	void printList()
	{
		cout<<endl;
		copy(vec.begin(),vec.end(),ostream_iterator<T>(cout," "));
		cout<<endl;
	}
	void shift_left(int pos)
	{
		rotate(vec.begin(),vec.end()-pos,vec.end());
	}
	void shift_right(int pos)
	{
		rotate(vec.begin(),vec.begin()+pos,vec.end());
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	mylist<int> l(5);
	try{
	l.insert_element(2);
	l.insert_element(4);
	l.insert_element(6);
	l.insert_element(1);
	l.insert_element(24);
	l.insert_element(66);
	}catch(OutOfRangeException e)
	{
		e.printException();
	}
	l.printList();
	try{
		cout << "getElemenAt(22): " << l.getElementAt(22) << endl;
	}catch(OutOfRangeException e)
	{
		e.printException();
	}
	l.remove_element(2);
	l.printList();
	l.shift_left(2);
	l.printList();
	l.shift_right(3);
	l.printList();	
	return 0;
}

