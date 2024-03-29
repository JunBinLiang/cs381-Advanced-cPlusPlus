// InvertedIndex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include<fstream>
#include<map>
#include<vector>
using namespace std;


void split(std::string const &str, const char delim,
	std::vector<std::string> &out)
{
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}


int main()
{
	ifstream input;
	input.open("input.txt");
	
	map<string, vector<vector<int>>>hashmap;

	if (input.is_open()) {
		string line;
		int count = 1;
		while (getline(input, line)) {
			vector<string> words;
			split(line, ',', words); 
			line = "";
			for (int i = 0; i < words.size(); i++) {
				line += words[i];
			}
			words.clear();
			split(line, '.', words);
			line = "";
			for (int i = 0; i < words.size(); i++) {
				line += words[i];
			}
			words.clear();
			split(line, ' ', words);
			//finish parsing
			

			for (int i = 0; i < words.size(); i++) {
				string s = words[i];
				if (s == "--") {
					continue;
				}
				map<string, vector<vector<int>>>::iterator it;
				it = hashmap.find(s);

				if (it == hashmap.end()) {
					vector<vector<int>>list;
					vector<int>pair;
					pair.push_back(count);
					pair.push_back(i);
					list.push_back(pair);
					hashmap[s] = list;
				}
				else {
					vector<int>pair;
					pair.push_back(count);
					pair.push_back(i);
					hashmap[s].push_back(pair);
				}
			}
			count++;
		}
		
		for (auto itr = hashmap.begin(); itr != hashmap.end(); ++itr) {
			string ans = "";
			ans = ans + itr->first + "  |  " + std::to_string(itr->second.size())+ "  [";
			for (int i = 0; i < itr->second.size(); i++) {
				int whichline = itr->second[i][0];
				int pos= itr->second[i][1];
				if (i == itr->second.size() - 1) {
					ans = ans + "(" + std::to_string(whichline) + "," + std::to_string(pos) + ")";
				}
				else {
					ans = ans + "(" + std::to_string(whichline) + "," + std::to_string(pos) + "),";
				}
				
			}
			ans=ans+"]";
			cout << ans << endl;
		}


		input.close();
	}

    return 0;
}

