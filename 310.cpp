#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<limits.h>
#include<algorithm>

using namespace std;

vector<int> results;
int min_height = INT_MAX;
//map<int, int> h_map;

int get_height(int src, map<int, vector<int>> &s_map, vector<bool> visited) {
	if(visited[src]) {
		return 0;
	}

	/*
	auto f_it = h_map.find(src);

	if(f_it != h_map.end()) {
		return f_it->second;
	}

	*/	

	vector<int> &siblings = s_map[src];
	visited[src] = true;
	int max_height = INT_MIN;
	int temp_height = 0;

	for(int i = 0; i < siblings.size(); i++) {
		temp_height = 1 + get_height(siblings[i], s_map, visited);
		if(max_height < temp_height) {
			max_height = temp_height;
		}
	}

	//h_map[src] = max_height;

	return max_height;
}

vector<int> heights(int n, map<int, vector<int>> &s_map) {
	
	for(int i = 0; i < n; i++) {
		vector<bool> visited(n, false);
		//h_map.clear();
		int temp_height = get_height(i, s_map, visited);
		//cout << ">>>>>>>>>>>>> src = " << i << ", height = " << temp_height << endl;

		if(temp_height == 1) {
			cout << "[Debug] Could happend in case of disconneced vertex" << endl;
			continue;
		}

		if(min_height > temp_height) {
			min_height = temp_height;
			results.clear();
			results.push_back(i);
		} else if (min_height ==  temp_height) {
			results.push_back(i);
		}
	}

	return results;
}

void populate_map(map<int, vector<int>> &s_map, vector<pair<int, int>> &edges) {
	for(int i = 0; i < edges.size(); i++) {
		pair<int, int> &temp = edges[i];
		auto it1 = s_map.find(temp.first);
		auto it2 = s_map.find(temp.second);

		if(it1 == s_map.end()) {
			vector<int> t2;
			t2.push_back(temp.second);
			s_map[temp.first] = t2;
		} else {
			vector<int> &temp_vec = it1->second;
			if(std::find(temp_vec.begin(), temp_vec.end(), temp.second) == temp_vec.end()) {
				temp_vec.push_back(temp.second);
			}
		}

		if(it2 == s_map.end()) {
			vector<int> t3;
			t3.push_back(temp.first);
			s_map[temp.second] = t3;
		} else {
			vector<int> &temp_vec = it2->second;
			if(std::find(temp_vec.begin(), temp_vec.end(), temp.first) == temp_vec.end()) {
				temp_vec.push_back(temp.first);
			}
		}
	}
}

int main(int args, char** argv) {
	vector<pair<int, int>> edges;
	int n = 6;

	edges.push_back(make_pair(0, 3));
	edges.push_back(make_pair(1, 3));
	edges.push_back(make_pair(2, 3));
	edges.push_back(make_pair(4, 3));
	edges.push_back(make_pair(5, 4));

	map<int, vector<int>> s_map;
	populate_map(s_map, edges);

	/*for(auto it = s_map.begin(); it != s_map.end(); it++) {
		cout << "key = " << it->first << ", values = ";
		for(int i = 0; i < it->second.size(); i++) {
			cout << it->second[i] << ", ";
		}
		cout << endl;
	}
	*/

	vector<int> sources = heights(n, s_map);

	for(int i = 0; i < sources.size(); i++) {
		cout << sources[i] << endl;
	}

	return 0;
}
