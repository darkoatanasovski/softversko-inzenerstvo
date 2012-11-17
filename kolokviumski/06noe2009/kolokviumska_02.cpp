// kolokviumska_02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <iterator>

using namespace std;
class dictionary{
private:
	map<string,vector<string>> items;
public:
	dictionary()
	{
		menu();	
	}
	void menu()
	{
		int option = 4;
		string w;
		string mkd_w;
		cout << endl << "Choose option:" << endl;
		cout << "1. Add word" << endl;
		cout << "2. Search word" << endl;
		cout << "3. Get top MKD word" << endl;
		cout << "4. Exit" << endl;

		cin >> option;
		switch (option)
		{
		case 1:
			cout << "Add MKD word: ";
			cin >> mkd_w;
			cout << "Add translation: ";
			cin >> w;
			insert_word(mkd_w,w);
			menu();
			break;
		case 2:
			cout << "Search for: ";
			cin >> w;
			serach_word(w);
			menu();
			break;
		case 3:
			getTopMKDWord();
			menu();
			break;
		default:
			cout << "Thnak you! Exiting..." << endl;
			break;
		}

	}
	void insert_word(string mkd_word, string word)
	{
		vector<string> tmp; 
		tmp.push_back(word);
		if(serach_word(mkd_word) == -1) //ako funkcijata search vrati -1, znaci deka ne go nasla zborot(vo slucajov key za mapata, i dodavame nov element vo mapata key->string i value->vector(zatoa sto eden zbor moze da ima povekje prevodi))
		{
			items.insert(make_pair(mkd_word,tmp)); //standardno dodavanje element vo mapa
		}else{ //zborot koj go prakame kako prv parametar vo ovaa funkcija, e pronajden i ne dodavame nov, tuku iteratorot treba da pokazuva kon toj key, vo slucajov MKD word
			map<string,vector<string>>::iterator pos; //iterator za da ja izmineme mapata
			for(pos = items.begin(); pos!=items.end(); ++pos)
			{
				if(pos->first == mkd_word) //koga iteratorot kje pokazuva na zborot za koj sakame da vneseme prevod
				{
					pos->second.push_back(word); //pos->first e key za mapata, a pos->second e value, vo slucajov vector<string>, vo vektor se dodava element so push_back, taka sto pos->second.push_back(word) dodavame nov prevod za postoeckiot zbor na MKD
					break; // izleguvame od ciklusot, zatoa sto vekje e zavrsena rabotata
				}
			}
		}
		
	}
	int serach_word(string word)
	{
		map<string,vector<string>>::iterator pos;
		int i=0;
		for(pos = items.begin(); pos!=items.end(); ++pos)
		{
			if(pos->first == word)
			{
				pos->second;
				vector<string>::iterator it;
				cout << "Translations: " << endl;
				for(it = pos->second.begin(); it != pos->second.end(); ++it)
				{
					cout << *it << endl;
				}
				return i;
			}
			i++;
		}
		return -1;
	}
	void getTopMKDWord()
	{
		int max_translations = 0;
		map<string,vector<string>>::iterator pos;
		map<string,vector<string>>::iterator tmp_pos;
		for(pos = items.begin(); pos!=items.end(); ++pos)
		{
			if(pos->second.size() > max_translations)
			{
				max_translations = pos->second.size();
				tmp_pos = pos;
			}
		}
		cout << "The word with most translations is: '" << tmp_pos->first << "' with " << max_translations << " translations!" << endl;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	dictionary d;
	return 0;
}

