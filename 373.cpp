#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

struct Container {
	int key;
	vector<pair<int, int>> list;
};

class Compare {
public:
	bool operator() (const Container &c1, const Container &c2) {
		return  c1.key > c2.key;
	}
};

void create_queue(vector<int> &nums1,  vector<int> &nums2, priority_queue<Container, vector<Container>, Compare> &p_queue) {
	map<int, Container> k_map;

	//  time  complexity O(n^2)
	for(int i=0;i<nums1.size();i++){
		for(int j=0;j<nums2.size();j++){
			int sum_key =  nums1[i] + nums2[j];
			auto it = k_map.find(sum_key);
			if(it == k_map.end()) {
				Container cnt;
				cnt.key  = sum_key;
				pair<int, int>  temp = make_pair(nums1[i], nums2[j]);
				cnt.list.push_back(temp);

				k_map[sum_key] = cnt;
			} else {
				pair<int, int> temp =  make_pair(nums1[i], nums2[j]);
				it->second.list.push_back(temp);
			}	
		}
	}


	//  time  complexity O(nlogn)
	for(auto it = k_map.begin(); it != k_map.end(); it++) {
		p_queue.push(it->second);
	}

	/*
	while(!p_queue.empty()) {
		Container cnt = p_queue.top();
		p_queue.pop();

		for(int i=0;i<cnt.list.size();i++){
			pair<int, int>  temp = cnt.list[i];
			cout << "key  =  "  << cnt.key << "(" << temp.first << ", " << temp.second << ") " << endl;
		}		
	}
	*/
}

vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Container, vector<Container>, Compare>  p_queue;

	create_queue(nums1, nums2, p_queue);

	vector<pair<int, int>> result;

	//  time  complexity O(klogn)
	while(k > 0 && !p_queue.empty()) {
		Container cnt = p_queue.top();
		p_queue.pop();

		for(int j=0;j<cnt.list.size();j++){
			result.push_back(cnt.list[j]);
			k--;
			if(k ==  0) {
				break;
			}
		}
	}

	return result;
}

int main(int argc, char** argv) { // total time complexity O(n^2) + O(nlogn) + O(klogn)
	/*
	vector<int> nums1 = {1,7,11};
	vector<int> nums2 = {2,4,6};
	*/

	vector<int> nums1 = {1,1,2};
	vector<int> nums2 = {1,2,3};
	int k = 2;

	vector<pair<int, int>> result = kSmallestPairs(nums1, nums2, k);

	for(int i=0;i<k;i++) {
		cout<< "[" << result[i].first << ", " << result[i].second << "]" << endl;
	}
	
	return 0;
}
