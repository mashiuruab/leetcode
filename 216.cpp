#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

int m_k;
int m_n;
map<string, int> k_map;

string get_sorted(string key, string ns) {
	if(key.length() == 0) {
		return ns;
	}

	string result = "";
	bool inserted = false;

	for(int i=0;i<key.length();i++){
		int c_val = key[i] - '0';
		if(c_val < stoi(ns)) {
			result += to_string(c_val);
		} else {
			//cout<< key[i] << ns << endl;
			//cout << "called here ......." << endl;
			result += ns;
			for(int j=i;j<key.length();j++){
				result += key[j];
			}

			inserted = true;
			break;			
		}
	}

	if(!inserted) {
		result += ns;
	}

	//cout << "called with " << key << ", ns = " << ns << ", returned = " << result << endl;

	

	return result;
}

void traverse(int sum, string key) {
	string tempkey;

	for(int i=9;i>=1;i--){
		if(sum + i > m_n) continue;

		if(key.find(to_string(i)) != string::npos) continue;
		
		tempkey = get_sorted(key, to_string(i));
		//cout << "key = " << key << ", tempkey = " << tempkey << ", i = " << i << endl;

		if(k_map.find(tempkey) != k_map.end()) {
			continue;
		}

		if((sum + i == m_n) && (tempkey.length() == m_k)) {
			/*
			cout << "get_sorted called with " << key << ", " << to_string(i) << endl;
			cout << "sum =  " << sum << ", i = " << i << ", key_length = " << key.length() << endl;
			cout<< "(sum  + i) = " << sum + i << ", " << tempkey << endl;
			*/
			k_map[tempkey] = 1;
			continue;
		}
		
		if(sum + i < m_n && tempkey.length() < m_k) {
			traverse(sum + i, tempkey);
		}
	}
}

vector<vector<int>> combinationSum3(int k, int n) {
	m_n = n;
	m_k = k;

	k_map.clear();

	vector<vector<int>> result;

	if(n == ((10 * 9) / 2)) {
		vector<int> item;
		for(int i=1;i<=9;i++) {
			item.push_back(i);
		}

		result.push_back(item);
		return result;
	}
	
        traverse(0, "");

	//cout << "k = " << k << ", n = " << n << endl; 

	for(map<string, int>::iterator it = k_map.begin(); it != k_map.end(); it++){
		cout<< it->first << endl;
		vector<int> temp;
		int c;

		for(int i=0;i<it->first.length();i++){
			c = it->first[i] - '0';
			temp.push_back(c);				
		}

		result.push_back(temp);
	}

	return result;
}

int main(int argc, char** argv) {
	/*
	combinationSum3(3,7);
	k_map.clear();
	combinationSum3(3,9);
	*/
	
	combinationSum3(2,18);

	combinationSum3(9, 45);

	//cout<< get_sorted("1", "2") << endl;
	return 0;
}

