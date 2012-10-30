#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <algorithm>

using namespace std;
class CityNotFoundException{
public:
	void printException()
	{
		cout << "Exception: City not found! "<< endl << endl;
	}
};
class city
{
private:
public:
	map<city, double> cityNetwork;
	string cityName;
	int cityPopulation;
	
	city(string n, int p)
	{
		this->cityName = n;
		this->cityPopulation = p;
	}
	bool friend operator<(const city& lhs, const city& rhs)
	{
		return lhs.cityPopulation > rhs.cityPopulation ? false : true;
	}
	void addDistance(city c, double distance)
	{
		this->cityNetwork.insert(make_pair(c, distance));
	}	
	string getName()
	{
		return cityName;
	}

	int getCityPopulation()
	{
		return cityPopulation;
	}

	map<city, double> getCityNetwork()
	{
		return cityNetwork;
	}

	double getDistance(string cityName)
	{
		map<city, double>::iterator pos; 
		for (pos = this->cityNetwork.begin(); pos != this->cityNetwork.end(); ++pos) 
		{ 
			if(pos->first.cityName == cityName)
			{
				return pos->second;
			}
		}
		return 0.0;
	}
};

class state{
private:
	string stateName;
	vector<city> cities;

public:
	state(string stateName, vector<city> cities)
	{
		this->stateName = stateName;
		this->cities = cities;
	}
	void search(string cityName)
	{
		int found = -1;
		cout << endl;
		for(int i=0; i<this->cities.size(); i++)
		{
			if(this->cities[i].getName() == cityName)
			{
				found = i;
				break;
			}
		}
		if(found!=-1)
		{
			cout << "Found city: " << cityName << endl;
			cout << "City population: " << this->cities[found].getCityPopulation() << endl;
			cout << endl << "City network: " << endl;
			map<city,double>::iterator pos;
			for (pos = this->cities[found].cityNetwork.begin(); pos != this->cities[found].cityNetwork.end(); ++pos) 
			{ 
				cout << "City: " << pos->first.cityName << "\t" << "distance: " << pos->second << endl;
			}
		}else{
			throw CityNotFoundException();
		}
		cout << endl;
	}
	
	float roadNetwork()
	{
		map<city,double>::iterator pos; 
		float totalNetwork = 0.0;
		for(int i=0; i < this->cities.size(); i++)
		{
			for (pos = this->cities[i].cityNetwork.begin(); pos != this->cities[i].cityNetwork.end(); ++pos) 
			{ 
				 totalNetwork += (float)pos->second;
			}
		}
		return totalNetwork;
	}

	void mostDense()
	{
		int l_city ,r_city = 0;
		double expr = 0.0;
		double max_expr = 0.0;
		for(int i=0; i < this->cities.size(); i++)
		{
			for(int j=0; j < this->cities.size(); j++)	
			{
				if(i != j && this->cities[i].getDistance(this->cities[j].cityName) > 0)
				{
					expr = (this->cities[i].getCityPopulation() + this->cities[j].getCityPopulation()) / this->cities[i].getDistance(this->cities[j].cityName);
					if(expr > max_expr)
					{
						l_city = i;
						r_city = j;
						max_expr = expr;
					}
				}
			}
		}
		cout << "mostDense: " << this->cities[l_city].cityName << " - " << this->cities[r_city].cityName << " -> " << max_expr << endl << endl;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	city sk("Skopje",1500000);
	city ve("Veles",550760);
	city ku("Kumanovo",350760);
	city oh("Ohrid",135260);
	city te("Tetovo",415264);

	sk.addDistance(ve,102.54);
	sk.addDistance(ku,42.14);
	sk.addDistance(oh,188.34);
	ve.addDistance(sk,102.541);
	oh.addDistance(te,202.54);
	te.addDistance(ve,112.54);
	ku.addDistance(te,132.54);
	
	vector<city> cities;
	
	cities.push_back(sk);
	cities.push_back(ve);
	cities.push_back(ku);
	cities.push_back(oh);
	cities.push_back(te);
	
	state s("Macedonia",cities);
	cout << "Road network: " << s.roadNetwork() << " km" << endl;
	try{
		s.search("Skopje");
	}catch(CityNotFoundException e){
		e.printException();
	}
	s.mostDense();
	return 0;
}

