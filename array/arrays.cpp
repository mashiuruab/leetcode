#include<iostream>
#include<vector>
#include<map>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	if(nums.size() ==  0) return 0;

	int prev = nums[0] - 1;
	int count2;
	

        for(int i=0;i<nums.size();i++) {
		
		while(prev == nums[i] && (i < nums.size())) {
			count2 = i;	
			while(count2 < (nums.size() - 1)) {
				nums[count2] = nums[count2+1];
				count2++;
			}
			nums.pop_back();			
		}	
		
		if (i < nums.size()) prev = nums[i];
	}

	return nums.size();
}

void rotate(vector<int>& nums, int k) {
	int temp;

	for(int i=0;i<k;i++) {
		temp = nums[nums.size()-1];
		for(int count=nums.size()-1;count > 0;count--) {
			nums[count] = nums[count-1];
		}
		nums[0] = temp;
	}        
}

bool containsDuplicate(vector<int>& nums) {
	map<int, int> key_value;

	for(int i=0;i<nums.size();i++) {
		if(key_value.find(nums[i]) != key_value.end()) {
			return true;
		} else {
			key_value[nums[i]] = 1;
		}
	}

	return false;        
}

vector<int> plusOne(vector<int>& digits) {
        vector<int> result;

	int carry = 0;
	int temp = 0;
		
	for(int count=digits.size()-1;count>=0;count--){
		if(count == (digits.size() - 1)) {
			temp = digits[count] + 1 + carry;
		} else {
			temp = digits[count] + carry;
		}
				
		if(temp <= 9) {
			carry = 0;
			digits[count] = temp;
		} else {
			carry = 1;
			digits[count] = (temp % 10);
		}
	}

	if(carry ==  0) {
		result = digits;
	} else {
		result.push_back(carry);
		for(int i=0;i<digits.size();i++) {
			result.push_back(digits[i]);
		}
	}

	return result;
}


//// why it was not successful  need to check 

void moveZeroes(vector<int>& nums) {	
	int count;
	int move_done  = 0;
	for(int i=0;i<nums.size();i++) {
		while((nums[i] ==  0) && (move_done <= (nums.size()-i-1))) {
			move_done++;
			count = i;
			while(count <= (nums.size() - i - 1)) {
				nums[count] = nums[count+1];
				count++;
			}
			nums[count] = 0;
		}
	}        
}


vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> result;

	for(int i=0;i<nums.size();i++){
		for(int j=0;j<nums.size();j++) {
			if(j == i) continue;

			if((nums[i] + nums[j]) == target) {
				result.push_back(i);
				result.push_back(j);
				return result;
			}
		}
	}        
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	vector<int> result;
	vector<int> &large =  (nums1.size() >= nums2.size()) ? nums1 : nums2;
	vector<int> &small =  (nums1.size() < nums2.size()) ? nums1 : nums2;

	map<int, int> keyMap;
	
	for(int i=0;i<large.size();i++){
		for(int j=0;j<small.size();j++){
			int key1 = j;
			int key2 = small.size() + i;

			if((large[i] == small[j]) && (keyMap.find(key1) == keyMap.end()) && (keyMap.find(key2) == keyMap.end())) {
				result.push_back(large[i]);
				keyMap[key1] = 1;
				keyMap[key2] = 1;
			}			
		}
	}
	return result;        
}


void rotate(vector<vector<int>>& matrix) {
	int src_i;
	int src_j;
	int dest = 0;
	int dim = matrix.size();
	int dest_i;
	int dest_j;

	int count = 0;
	int total_element = dim * dim;
	int count2;
	int count3;
	int src;

	while(count < total_element) {		
		count2 = 0;
		count3 = count;

		src_i = count3 / dim;
		src_j = count3 % dim;
		
		src = matrix[src_i][src_j];

		count3 = ((count3 + 1) * dim) -1;

		while(count2 < 4) {
			count3 = count3 % total_element;
			
			/*
			dest_i = count3 / dim;
			dest_j = count3 % dim;
			int next_src = matrix[dest_i][dest_j];			
			matrix[dest_i][dest_j] = src;
			src =  next_src;
			*/
			cout<< count3 << " ";
			
			count3 = ((count3 + 1) * dim) -1;
			count2++;
		}

		cout<<endl;
		
		count++;
	}
}

void print(vector<int> nums) {
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	
	cout<<endl;
}

void print_2D(vector<vector<int>> &nums) {
	for(int i=0;i<nums.size();i++){
		for(int j=0;j<nums[i].size();j++){
			cout << nums[i][j] << " ";
		}
		cout << endl;
	}
	
	cout<<endl;
}


int main(int argc, char** argv) {
	/*
	vector<int> nums = {0,0,1};
	vector<int> nums2 = {1,0,1};
	vector<int> nums3 = {0,1,0,3,12};
	vector<int> nums4 = {0};

	cout<< "nums2 = " << endl;
	moveZeroes(nums2);
	print(nums2);

	cout<< "nums = " << endl;
	moveZeroes(nums);
	print(nums);

	cout<< "nums3 = " << endl;	
	moveZeroes(nums3);
	print(nums3);

	cout<< "nums4 = " << endl;
	moveZeroes(nums4);
	print(nums4);

	*/

	vector<int> nums1 = {1,2,3};
	vector<int> nums2 = {4,5,6};
	vector<int> nums3 = {7,8,9};
	vector<vector<int>> nums;
	nums.push_back(nums1);
	nums.push_back(nums2);
	nums.push_back(nums3);

	rotate(nums);
	print_2D(nums);

	return 0;
}
