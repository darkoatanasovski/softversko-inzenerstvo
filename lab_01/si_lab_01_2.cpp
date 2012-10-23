// si_lab_01_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;
class ElementNotFoundException{
public:
	void printException()
	{
		cout << "Exception: Element not found! "<< endl << endl;
	}
};
template <typename T>
class stack{
private:
	int n;
	int counter;
	T *arr;
	float m_mean;
public:
	stack(int n)
	{
		this->counter = 0;
		this->n = n;
		this->arr = new T[this->n]();
	}
	void push_front(T elem)
	{
		for(int i=this->counter;i>0;i--)
		{
			this->arr[i] = this->arr[i-1];
		}
		this->arr[0] = elem;
		this->counter++;
	}
	void push_back(T elem)
	{
		this->arr[this->counter] = elem;
		this->counter++;
	}
	void pop_back()
	{
		this->counter--;
		this->arr[this->counter] = 0;
	}
	void pop_front()
	{
		for(int i=0;i<this->counter;i++)
		{
			this->arr[i] = this->arr[i+1];
		}
		this->counter--;
	}
	int search(T elem)
	{
		for(int i=0;i<this->counter;i++)
		{
			if(this->arr[i] == elem)
			{
				return i;
			}
		}
		throw ElementNotFoundException();
	}
	float mean()
	{
		T sum = 0;
		for(int i=0;i<this->counter;i++)
		{
			sum += this->arr[i];
		}
		this->m_mean = (float)sum/this->counter;
		return this->m_mean;
	}
	float std_dev()
	{
		this->mean();
		float sum = 0;
		for(int i=0;i<this->counter;i++)
		{
			sum += this->power((float)this->m_mean-(float)this->arr[i]);
		}
		
		return sqrt((float)sum/this->counter);
	}
	float power(float num)
	{
		return num*num;
	}
	void print()
	{
		if(!this->counter)
		{
			cout << "Array is empty!" << endl;
		}else
		{
			cout << "Elements: ";
			for(int i=0;i<this->counter;i++)
			{
				cout << this->arr[i] << " ";
			}
			cout << endl;
			cout << "Mean: " << this->mean() << endl;
			printf("Std dev: %.3f\n", this->std_dev());
			cout << "-------------------------------" << endl << endl << endl;
		}
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	stack<int> obj(5);

	obj.push_front(5);
	obj.push_front(12);
	obj.push_back(7);
	obj.push_front(9);
	obj.push_back(31);

	obj.print();

	try{
		cout << "Element position: " << obj.search(28) << endl << endl;
	}catch(ElementNotFoundException e){
		e.printException();
	}

	obj.pop_back();
	obj.pop_front();

	obj.print();
	return 0;
}

