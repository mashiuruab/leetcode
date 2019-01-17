#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

map<string, int> key_val;
map<int, vector<string>> intermediate_map;

void put_intermediate(int value, string path) {
	if(intermediate_map.find(value) != intermediate_map.end()) { // that means it is found
		vector<string>& strs = intermediate_map[value];
		bool found = false;
		for(int i=0;i<strs.size(); i++) {
			if(strs[i] == path) {
				found = true;
				break;
			}	
		}

		if(!found) {
			intermediate_map[value].push_back(path);
		}
	} else {
		vector<string> strs;
		strs.push_back(path);
		intermediate_map[value] = strs;
	}
}

void reached(int target, int n, string path) {
	// check whether exist in  sub problem
	int remain = target -  n;
	if((intermediate_map.find(remain) != intermediate_map.end())) { // found in sub problem
		vector<string>& val_str = intermediate_map[remain];
		
		string temp = path;
		for(int i=0;i<val_str.size();i++){
			temp = temp + val_str[i];
			key_val[temp] = 1;
			temp = path;	
		}

		return;
	}

	// finished checking

	if(target == n) {
		key_val[path] = 1;
		return;
	} else if (n > target) {
		return;
	}
	
	if(remain != 1) {
		
	}

	int n1 = n + 1;
	string path1 = path + "1+";
	//cout<< " called taget = " << target << ", n1 = " << n1 << ",  path1 = " << path1 << endl;
	
	put_intermediate(n1, path1);
	reached(target, n1, path1);
	
	int n2 = n + 2;
	string path2 = path + "2+";

	put_intermediate(n2, path2);
	reached(target, n2, path2);
}

int climbStairs(int n) {
	put_intermediate(1, "1+");
	reached(n, 1, "1+");

	put_intermediate(2, "2+");
	reached(n, 2, "2+");
	
	int total = 0;
	for(map<string, int>::iterator it = key_val.begin(); it != key_val.end(); it++) {
		cout<< "key = " << it->first << ", val = " << it->second << endl;
		total += it->second;
	}

	cout<< "intermediate map >>>>>>>>>>>>." << endl;
	for(map<int, vector<string>>::iterator it = intermediate_map.begin(); it != intermediate_map.end(); it++) {
		cout<< "key = " << it->first << " -> ";
		for(int j=0;j<it->second.size();j++) cout<< it->second[j] <<  ", ";
		cout<< endl;
	}
	

	return total; 
}

int main(int argc, char** argv) {
	cout<< " First>>>>>>>>>>>>>>>>>>>>>>>>>> " << endl;
	cout<< climbStairs(2) << endl;

	key_val.clear();
	intermediate_map.clear();

	cout<< " Second>>>>>>>>>>>>>>>>>>>>>>>>> " << endl;
	cout<< climbStairs(3) << endl;

	key_val.clear();
	intermediate_map.clear();

	cout<< " Third>>>>>>>>>>>>>>>>>>>>>>>>> " << endl;
	cout<< climbStairs(35) << endl;

	key_val.clear();
	intermediate_map.clear();

	cout<< " 4>>>>>>>>>>>>>>>>>>>>>>>>> " << endl;
	cout<< climbStairs(4) << endl;

	key_val.clear();
	intermediate_map.clear();

	cout<< " 5>>>>>>>>>>>>>>>>>>>>>>>>> " << endl;
	cout<< climbStairs(5) << endl;

	return 0;
}
