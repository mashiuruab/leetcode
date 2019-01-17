#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

int length;
int k_val;
vector<vector<int>> result;
map<string, int> key_map;

string path_f(set<int> path_set) {
	string path = "";

	for(set<int>::iterator it = path_set.begin(); it != path_set.end(); it++) {
		path += to_string(*it);
	}

	return path;
}

void traverse(int index, set<int> path_set, vector<int> container, vector<int> seen_index) {
	container.push_back(index);
	seen_index[index-1] = 5;
	string prev = path_f(path_set);
	set<int> prev_set = path_set;

	path_set.insert(index);
	string path = path_f(path_set);

	if((container.size()  == k_val) && (key_map.find(path) == key_map.end())) {
		result.push_back(container);
		container.pop_back();
		key_map[path] = 1;
		path = prev;
		path_set = prev_set;
	}

	int count = 0;

	for(int i=1;i<=length;i++){
		if(seen_index[i-1] != 5) {
			traverse(i,path_set, container, seen_index);	
		}
	}
}

vector<vector<int>> combine(int n, int k) {
        length = n;
	k_val = k;
	
	for(int i=1;i<=length;i++) {
		set<int> path_set;
		vector<int> container;
		vector<int> seen_index;
		seen_index.resize(length);
		traverse(i, path_set, container, seen_index);
	}

	return result;
}

int main(int argc,char** argv) {
	combine(10,7);

	int count = 0;
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<< result[i][j] << " ";
		}
		
		count++;
		cout<< endl;
	}

	cout << "Total Found = " << count << endl;

	return 0;
}
