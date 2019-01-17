#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<string, int> occ;

bool exists(int a, int b,  int c) {
	int min, middle, max;
	
	if(a < b) {
		if (a < c) {
			min = a;

			if(b < c) {
				max = c;
				middle = b;
			} else if (b >= c) {
				middle = c;
				max = b;
			}
		} else if (a >= c) {
			middle = a;
			max = b;
			min = c;
		}
		
	} else if (a >=b) {
		if(b >= c) {
			max = a;
			middle = b;
			min = c;						
		} else if (b < c) {
			if(c >= a) {
				min =  b;
				middle = a;
				max = c;
			} else if (c < a) {
				min = b;
				middle = c;
				max = a;
			}
		}
	}

	string temp = to_string(min) + to_string(middle) + to_string(max);

	if(occ.find(temp) == occ.end()) {
		occ[temp] = 1;
		return false;
	}

	return true;
}

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> result;

	int length = nums.size();

	for(int i=0;i<length;i++){
		for(int j=i+1;j<length;j++) {
			for(int k=j+1;k<length;k++) {
				if(nums[i] + nums[j] + nums[k] == 0) {
					if(exists(nums[i], nums[j], nums[k])) continue;
					vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[j]);
					temp.push_back(nums[k]);
					result.push_back(temp);
				}
			}
		}
	}
	return result;     
}

int main(int argc, char** argv) {
	vector<int> nums = {-1, 0, 1, 2, -1, -4};
	vector<vector<int>> result = threeSum(nums);

	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[j].size();j++) {
			cout<< result[i][j] << " "; 
		}
		cout<< endl;
	}
}
