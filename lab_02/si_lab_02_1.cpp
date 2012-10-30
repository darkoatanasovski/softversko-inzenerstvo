#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class container{
private:
	vector<int> v;
	int initial_vector_size;
	int absolute_resizing;
	float relative_resizing;
public:
	container(vector<int> v)
	{
		this->v = v;
		this->initial_vector_size = v.size();
		this->absolute_resizing = 0;
		this->relative_resizing = 0.0;
	}
	int getAbsoluteResizing()
	{
		return this->absolute_resizing;
	}
	float getRelativeResizing()
	{
		return this->relative_resizing;
	}
	void bitStuffing()
	{
		int counter = 0;
		for(int i = 0; i < this->v.size(); i++)
		{
			if(this->v[i] == 1)
			{
				counter++;
				if(counter == 5)
				{
					this->v.insert(v.begin()+i+1,0);
					this->absolute_resizing++;
					counter = 0;
				}
			}else{
				counter = 0;
			}
		}
		this->relative_resizing = ((float)this->absolute_resizing / 100.0 * (float)this->initial_vector_size);
	}
	void unBitStuffing()
	{
		int counter = 0;
		for(int i = 0; i < this->v.size(); i++)
		{
			if(this->v[i] == 1)
			{
				counter++;
				if(counter == 5)
				{
					this->v.erase(v.begin()+i+1);
					counter = 0;
				}
			}else{
				counter = 0;
			}
		}
	}
	void printElements()
	{
		cout << endl;
		copy(this->v.begin(), this->v.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
		cout << endl;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> v;
	int bit;
	cout << "Enter binary array:" << endl;
	do{
		if(cin.fail())
		{
			break;
		}
		cin >> bit;
		if(bit == 0 || bit == 1)
		{
			v.push_back(bit);
		}

	}
	while(bit == 0 || bit == 1);

	container c(v);
	cout << "Original vector: ";
	c.printElements();
	cout << "bitStuffing: ";
	c.bitStuffing();
	c.printElements();
	c.unBitStuffing();
	cout << "unBitStuffing: " << endl;
	c.printElements();
	cout << "Absolute resizing: " << c.getAbsoluteResizing() << endl;
	cout << "Relative resizing: " << c.getRelativeResizing() << endl;
	cout << endl;
	return 0;
}

