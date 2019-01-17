#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

map<string, int> f_map;

int hamming_distance(int num1, int num2) {
	string key =  to_string(num1) + to_string(num2);

	if(f_map.find(key) != f_map.end()) {
		return f_map[key];
	}

	int count = 0;

	int temp1 = num1 & 1;
	int temp2 = num2 & 1;
	int temp3 = num1 | num2;

	while(temp3) {
		if(temp1 ^ temp2) {
			//cout<< "temp1 = " << temp1 <<", temp2 = " << temp2 << endl;
			count++;
		}
		num1 = num1>>1;
		num2 = num2>>1;
		temp1 = num1 & 1;
		temp2 = num2 & 1;
		temp3 = num1 | num2;
	}

	f_map[key] = count;

	return count;
}

int totalHammingDistance_ne(vector<int>& nums) {
	int result = 0;
	int temp;

	for(int i=0;i<nums.size();i++){
		for(int j=i+1;j<nums.size();j++){
			temp  = hamming_distance(nums[i], nums[j]);			
			result += temp;
		}
	}

	return result;
}


int totalHammingDistance(vector<int>& nums) {
	int ith_bit =  1;
	int temp;
	int b_count;
	int diff = 0;
	int break_num = 0;

	for(int i=0;i<32;i++) {
		ith_bit = 1<<i;
		b_count = 0;
		break_num  = 0;

		for(int j=0;j<nums.size();j++) {
			temp = nums[j] & ith_bit;
			if(temp) {
				b_count++;
			}

			break_num = break_num | nums[j];
		}		

		diff += b_count * (nums.size() - b_count);
		
		if(!break_num) {
			break;
		}
	}

	return diff;
}

int findComplement(int num) {
        
}

int main(int argc, char** argv) {
	vector<int> nums = {4,14,2};
	cout << totalHammingDistance(nums) << endl;
	return  0;
}
