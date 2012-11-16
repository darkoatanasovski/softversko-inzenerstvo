// si_test_02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <string>
#include <iostream>
#include <list>
#include <utility>

using namespace std;

class SmallBidException{
public:
	void printException()
	{
		cout << "The bid is small :) " << endl;
	}
};
class betting{
private:
	string name;
	float price;
	multimap<string, float> map_bids;
public:
	betting()
	{
		name = "Laptop";
		price = 10.0;
	}
	void bid(string n, float p)
	{
		int insert = 1;
		multimap<string,float>::iterator pos;
		for(pos = map_bids.begin();pos!=map_bids.end();++pos)
		{
			if(pos->first == n)
			{
				if(pos->second < p)
				{
					insert = 1;
				}else{
					insert = -1;
					break;
				}
			}
		}
		if(insert == 1)
		{
			map_bids.insert(make_pair(n,p));
		}else{
			throw SmallBidException();
		}
	}

	void top_bids(int n)
	{
		cout << endl << endl;
		cout << "Predmet: "<< name << endl; 
		cout << "Pocetna cena: "<< price << endl;
		cout << "Vkupno ponuduvaci: "  << total_bidders() << endl;
		cout << "Vkupno ponudi: "  << total_bids() << endl;
		multimap<string,float>::iterator pos;
		cout << "Top ponudi:" << endl;
		int i = 0;
		list<string> tmp;
		for(pos = map_bids.end();true; --pos)
		{
			if(i==0)
			{
				--pos;
			}
			if(i >= n+1)
			{
				break;
			}
			cout << pos->first << " " << pos->second << endl;
			i++;

			if(pos == map_bids.begin())
			{
				break;
			}
		}
		cout << endl << endl;
	}

	int total_bidders()
	{
		list<string> l;
		multimap<string,float>::iterator pos;
		for(pos = map_bids.begin();pos!=map_bids.end();++pos)
		{
			l.push_back(pos->first);
		}
		l.unique();
		return l.size();
	}

	int total_bids()
	{
		return map_bids.size();
	}

};
int _tmain(int argc, _TCHAR* argv[])
{
	betting bet;
	
	try{
		bet.bid("Darko",33.221);
		bet.bid("Darko",34.221);
		bet.bid("Anica",24.221);
		bet.bid("Darko",44.221);
		bet.bid("Anica",22.221);
	}catch(SmallBidException e){
		e.printException();
	}

	bet.top_bids(4);
	return 0;
}

