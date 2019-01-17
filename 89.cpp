#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstdlib>

using namespace std;

int length;

void traverse(map<string, int> &key_map, vector<int> one_idx, int index, int order) {
	if(key_map.size() ==  (1<<length)) {
		return;
	}

	if(index !=  -1) {
		one_idx[index] = one_idx[index] == 1 ? 0 : 1;
	}
	

	string key = "";
	int count = 0;
	
	for(int i=0;i<length;i++) {
		//cout << one_idx[i];
		key += to_string(one_idx[i]);
		if(one_idx[i] == 1) {
			count++;
		}
	}
	
	//cout << endl;

	if(key_map.find(key) != key_map.end()) {
		return;
	}

	key_map[key] = order;
	order++;

	int random_idx = rand() % length;

	traverse(key_map, one_idx, random_idx, order);
	
}

vector<int> grayCode(int n) {
	if(n == 0) {
		vector<int> result = {0};
		return result;
	}

	length = n;
	vector<int> result;
	result.resize((1<<length));
	vector<int> one_idx;
	one_idx.resize(length);

	while(true) {
		map<string, int> key_map;
		traverse(key_map,one_idx,  -1, 0);
		if(key_map.size() == (1<<length)) {
			for(map<string, int>::iterator it = key_map.begin(); it !=  key_map.end();it++) {
				//cout<< it->first << ", " <<  it->second << endl;
				string valueStr  = it->first;
				int value  = 0;

				for(int i=valueStr.length()-1;i>=0;i--) {
					if(valueStr[i]  == '1') {
						value += 1<<(valueStr.length()-1-i);
					}					
				}
				result[it->second] = value;
			}
			
			break;
		}
	}

	return result;
}

int main(int argc, char** argv) {

	for(int i=0;i<=12;i++) {
		cout << "........................." << endl;
		cout << "n = " << i << endl;
		vector<int> result = grayCode(i);
		for(int i=0;i<result.size();i++) {
			cout<< result[i] << endl;
		}
	}
	

	return 0;
}
