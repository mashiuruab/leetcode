#include<iostream>
#include<vector>
#include<map>
#include<utility>

using namespace std;

map<string, string> key_map;
vector<string> result;
map<string, int> cmap;

void create_map(vector<pair<string, string>> tickets) {
	for(int i=0;i<tickets.size();i++) {
		pair<string, string> &vpair = tickets[i];

		if(key_map.find(vpair.first) ==  key_map.end()) {
			key_map[vpair.first] = vpair.second;			
		} else if(key_map.find(vpair.first) !=  key_map.end()) {
			if(key_map[vpair.first] < vpair.second) {
				key_map[vpair.first] = vpair.second;
			}		
		}
	}
}

void traverse(string key) {
	if(cmap.find(key) != cmap.end()) {
		result.push_back(key);
		return;
	}

	result.push_back(key);
	cmap[key] = 1;

	if(key_map.find(key) == key_map.end()) {
		return;
	}

	traverse(key_map[key]);
}

vector<string> findItinerary(vector<pair<string, string>> tickets) {
	create_map(tickets);
	traverse("JFK");
	return result;
}

int main(int argc, char** argv) {
	return  0;
}
