#include "stdafx.h"
#include <iostream>

using namespace std;
template <typename T>
T max(T *arr, int n)
{
	T max = arr[0];
	for(int i=0;i<n;i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int array_int[] = {2,3,5,7,1,2};
	float array_float[] = {2.9,3.0,5.2,7.3};
	double array_double[] = {2,4,6,2,5};
	char array_char[] = {'a','c','t','d'};

	cout << "Max int: " << max(array_int,6) << endl;
	cout << "Max float: " << max(array_float,4) << endl;
	cout << "Max double: " << max(array_double,5) << endl;
	cout << "Max char: " << max(array_char,4) << endl;

	return 0;
}

