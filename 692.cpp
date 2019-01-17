#include<iostream>
#include<queue>
#include<vector>
#include<map>

using namespace std;

struct Container {
public:
	string key;
	int freq;
};

class Compare {
public:
	bool operator()(Container &a,  Container &b){
		if(a.freq < b.freq) {
			return true;
		} else if (a.freq == b.freq) {
			return a.key > b.key;
		} else {
			return false;
		}
	}
};

void create_queue(vector<string> &nums, priority_queue<Container, vector<Container>, Compare> &p_queue) {
	map<string, Container> k_map;

	for(int i=0;i<nums.size();i++){
		auto it  = k_map.find(nums[i]);

		if(it == k_map.end()) {
			Container cnt;
			cnt.key = nums[i];
			cnt.freq = 1;
			k_map[nums[i]] = cnt;
		} else {
			it->second.freq++;
		}
	}

	for(auto it = k_map.begin(); it != k_map.end(); it++) {
		//cout<< "pushing key = " << it->second.key << ", value = " << it->second.freq << endl;
		p_queue.push(it->second);
	}
}

vector<string> topKFrequent(vector<string>& words, int k) {
	priority_queue<Container, vector<Container>, Compare> p_queue;
	create_queue(words, p_queue);

	vector<string> result;

	for(int i=0;i<k;i++){
		result.push_back(p_queue.top().key);
		p_queue.pop();
	}

	return result;
}

int main(int argc, char** argv){
	vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
	vector<string> words2 = {"glarko","zlfiwwb","nsfspyox","pwqvwmlgri","qggx","qrkgmliewc","zskaqzwo","zskaqzwo","ijy","htpvnmozay","jqrlad","ccjel","qrkgmliewc","qkjzgws","fqizrrnmif","jqrlad","nbuorw","qrkgmliewc","htpvnmozay","nftk","glarko","hdemkfr","axyak","hdemkfr","nsfspyox","nsfspyox","qrkgmliewc","nftk","nftk","ccjel","qrkgmliewc","ocgjsu","ijy","glarko","nbuorw","nsfspyox","qkjzgws","qkjzgws","fqizrrnmif","pwqvwmlgri","nftk","qrkgmliewc","jqrlad","nftk","zskaqzwo","glarko","nsfspyox","zlfiwwb","hwlvqgkdbo","htpvnmozay","nsfspyox","zskaqzwo","htpvnmozay","zskaqzwo","nbuorw","qkjzgws","zlfiwwb","pwqvwmlgri","zskaqzwo","qengse","glarko","qkjzgws","pwqvwmlgri","fqizrrnmif","nbuorw","nftk","ijy","hdemkfr","nftk","qkjzgws","jqrlad","nftk","ccjel","qggx","ijy","qengse","nftk","htpvnmozay","qengse","eonrg","qengse","fqizrrnmif","hwlvqgkdbo","qengse","qengse","qggx","qkjzgws","qggx","pwqvwmlgri","htpvnmozay","qrkgmliewc","qengse","fqizrrnmif","qkjzgws","qengse","nftk","htpvnmozay","qggx","zlfiwwb","bwp","ocgjsu","qrkgmliewc","ccjel","hdemkfr","nsfspyox","hdemkfr","qggx","zlfiwwb","nsfspyox","ijy","qkjzgws","fqizrrnmif","qkjzgws","qrkgmliewc","glarko","hdemkfr","pwqvwmlgri"};
	int k = 2;

	vector<string> result = topKFrequent(words,  k);

	for(int i=0;i<k;i++){
		cout<< result[i] << endl;
	}
	return  0;
}
