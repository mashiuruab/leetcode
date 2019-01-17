#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<int> m_nums;
vector<int> longest;
int longest_length = -1;
int length;

void traverse(int index, vector<int> &seq, int prev_value) {
	//cout << index << endl;
	if(index == (length - 1)) {
		if(prev_value != m_nums[index]) seq.push_back(m_nums[index]);
		//cout << "size " << seq.size() << endl;
		int temp_length = seq.size();
		if(longest_length < temp_length) {
			longest_length = temp_length;
			longest = seq;
		}
		return;
	}
	
	//cout<< "prev_value = " << prev_value << endl;

	if(prev_value == -1 && index == 0) { // it is the first value
		//cout << "1. pushed " << m_nums[index] << endl;
		seq.push_back(m_nums[index]);
		traverse(index+1,seq,m_nums[index]);
	} else if (index != 0) {
		int current = m_nums[index];
		int next = m_nums[index+1];

		if((current > prev_value) && (current > next)) {
			//cout << "2. pushed " << m_nums[index] << endl;
			seq.push_back(m_nums[index]);
			traverse(index+1,seq,m_nums[index]);
		} else if ((current < prev_value) && (current < next)) {
			//cout << "3. pushed " << m_nums[index] << endl;
			seq.push_back(m_nums[index]);
			traverse(index+1,seq,m_nums[index]);
		} else {
			//cout << "4. not pushed " << m_nums[index] << endl;
			traverse(index+1,seq,prev_value);
		}
	}
}

int wiggleMaxLength(vector<int>& nums) {
	if(nums.size() <= 1) {
		return  nums.size();
	} else if (nums.size() == 2) {
		if(nums[0] != nums[1]) {
			return 2;
		} else {
			return 1;
		}
	}

	m_nums = nums;
	length = m_nums.size();
	longest.clear();
	longest_length = -1;

	for(int i=0;i<nums.size();i++) {
		if((length - i) > longest_length) {
			vector<int> seq;
			//cout << " started with " << i << endl;
			traverse(i, seq, -1);
			seq.clear();
		}
	}

	//cout << "###################### Result = " << longest_length << endl;

	return longest_length;
}

int main(int argc, char** argv) {
	vector<int> nums = {1,7,4,9,2,5};
	vector<int> nums1 = {1,17,5,10,13,15,10,5,16,8};
	vector<int> nums2 = {1,2,3,4,5,6,7,8,9};

	cout << wiggleMaxLength(nums) << endl;
	cout << wiggleMaxLength(nums1) << endl;
	cout << wiggleMaxLength(nums2) << endl;

	return 0;
}
