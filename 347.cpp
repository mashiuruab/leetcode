#include<iostream>
#include<queue>
#include<vector>
#include<map>

using namespace std;

class Container {
public:
	int key;
	int freq;
};

class Compare {
public:
	bool operator()(Container &a,  Container &b){
		return  a.freq < b.freq;
	}
};

void create_queue(vector<int> &nums, priority_queue<Container, vector<Container>, Compare> &p_queue) {
	map<int, Container> k_map;

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

vector<int> topKFrequent(vector<int>& nums, int k) {
	priority_queue<Container, vector<Container>, Compare> p_queue;
	create_queue(nums, p_queue);

	vector<int> result;

	for(int i=0;i<k;i++){
		result.push_back(p_queue.top().key);
		p_queue.pop();
	}

	return result;
}


int main(int argc,  char** argv) {
	//  time  complexity  of this  implementation is O (n + klogn)
	vector<int> nums = {1,1,1,2,2,3};
	int k = 2;

	vector<int> result = topKFrequent(nums, k);

	for(int i=0;i<k;i++) {
		cout<< result[i] << endl;
	}
	return 0;
}
