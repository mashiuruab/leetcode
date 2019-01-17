#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

struct Container {
	char ch;
	int freq;
};

class Compare {
public:
	bool operator()(Container &c1, Container &c2) {
		return c1.freq < c2.freq;
	}
};

void create_queue(priority_queue<Container, vector<Container>, Compare> &p_queue, string s) {
	map<char, Container> k_map;

	//  O(n)
	for(int i = 0; i < s.length(); i++) {
		auto it = k_map.find(s[i]);

		if(it == k_map.end()) {
			Container cnt;
			cnt.ch = s[i];
			cnt.freq = 1;
			k_map[s[i]] = cnt;
		} else {
			it->second.freq++;
		}
	}

	// O(mlogn), is the size of map is m
	for(auto it = k_map.begin(); it != k_map.end(); it++) {
		p_queue.push(it->second);
	}
}

string frequencySort(string s) {
	priority_queue<Container,  vector<Container>, Compare> p_queue;

	create_queue(p_queue, s);

	string  result = "";

	// time complexity O(nlogn)
	while(!p_queue.empty()) {
		for(int i = 0; i < p_queue.top().freq; i++) {
			result += p_queue.top().ch;
		}

		p_queue.pop();
	}

	return result;
}

int main(int argc, char** argv) { // total time complexity = O(n + mlogn + nlogn)
	string s1 = "tree";
	string s2 = "cccaaa";
	string s3 = "Aabb";

	cout<< s1 << " = " << frequencySort(s1) << endl;
	cout<< s2 << " = " << frequencySort(s2) << endl;
	cout<< s3 << " = " << frequencySort(s3) << endl;

	return 0;
}
