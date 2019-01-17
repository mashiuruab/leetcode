#include<iostream>
#include<climits>
#include<vector>
#include<string>

using namespace std;

bool isPowerOfFour(int num) {
	if(num == 1) {
		return true;
	}

	long int count = 1;
	long int temp;

	while(count <= num) {
		//cout << count << endl;
		count = count<<2;
		temp = num & count;
		//cout << "temp = " << temp << ", num = " << num << ", count = " <<  count << endl;
		if(temp == num) return true;
	}

	return false;
}

bool isPowerOfTwo(int n) {
	if(n == 1) {
		return true;
	}
	long int count = 1;
	long int temp;

	while(count <= n) {
		count = count<<1;
		temp = n & count;
		if(temp == n) return true;
	}

	return false;   
}

// 191

int hammingWeight(uint32_t n) {
	int count = 0;
	int temp;

	for(int i=0;i<32;i++){
		temp = n & 1;
		if(temp) {
			count++;
		}
		n = n>>1;
	}

	return count;        
}

// 169

int majorityElement(vector<int>& nums) {
	int count = 1;
	int candidate_index = 0;
	int c_value;

	// majority  voting algorithms

	for(int i=1;i<nums.size();i++) {
		c_value = nums[candidate_index];

		if(c_value == nums[i]) {
			count++;
		} else {
			count--;
			if(count == 0) {
				candidate_index = i;
				count = 1;
			}
		}

	}



	count = 0;

	for(int i=0;i<nums.size();i++){
		if(nums[candidate_index] == nums[i]) {
			count++;
		}
	}

	if(count > (nums.size() / 2)) {
		return nums[candidate_index];;
	} else {
		cout << "error "<< endl;
		return false;
	}
	
}

int missingNumber(vector<int>& nums) {
	int result = nums[0];

	for(int i=1;i<nums.size();i++) {
		result = result ^ nums[i];
	}

	for(int i=0;i<=nums.size();i++) {
		result = result ^ i;
	}

	return result;
}

int bit_count_f(int value) {
	int count  = 0;
	while(value != 0) {
		count++;
		value = value & (value - 1);
	}

	return count;
}

vector<int> countBits(int num) {
        vector<int> result;
	int bit_count;

	for(int i=0;i<=num;i++) {
		bit_count = bit_count_f(i);
		result.push_back(bit_count);
	}

	return result;
}

vector<int> countBits_e(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i) {
		ret[i] = ret[i&(i-1)] + 1;
		cout << " i = " << i << ", " << ret[i] << endl;
	}

        return ret;
}

// 190

uint32_t reverseBits(uint32_t n) {
	uint32_t right_bit;
	uint32_t result = 0;

	int count = 0;
	int left_shift;

	while(n != 0){
		left_shift = 31 - count;
		right_bit = n & 1;
		right_bit = right_bit<<left_shift;
		result = result | right_bit; 
		n = n>>1;
		count++;
	}

	return result;
}

// 389

char findTheDifference(string s, string t) {
	char ch = s[0];

	for(int i=1;i<s.length();i++) {
		ch = ch ^ s[i];
	}

	for(int i=0;i<t.length();i++) {
		ch = ch ^ t[i];
	}
	
	return ch;
}


int main(int argc, char** argv) {
	/*
	vector<int> nums1 = {3,0,1};
	vector<int> nums2 = {9,6,4,2,3,5,7,0,1};

	cout<< missingNumber(nums1) << endl;

	cout<< missingNumber(nums2) << endl;
	*/

	//cout<< reverseBits(43261596) << endl;

	//cout << reverseBits(43261596) << endl;

	cout << findTheDifference("abcd", "abcde")<<endl;

	return  0;
}
