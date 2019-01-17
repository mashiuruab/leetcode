#include<iostream>
#include<vector>

using namespace std;

vector<int> merge_sorted(vector<int> &left, vector<int>& right, int &count) {
	vector<int> result;

	int i = 0;
	int j = 0;
	int left_length = left.size();
	int right_length = right.size();

	while(true) {
		if(i == left_length && j == right_length) {
			break;
		}

		if(i == left_length) {
			for(int c=j;c<right_length;c++) {
				result.push_back(right[c]);
			}
			break;
		} else if(j == right_length) {
			for(int c=i;c<left_length;c++) {
				result.push_back(left[c]);
			}
			break;
		}

		if(left[i] <= right[j]) {
			result.push_back(left[i]);
			i++;
		} else {
			count += left_length - i;
			result.push_back(right[j]);
			j++;
		}
	}

	return result;
}

vector<int> get(vector<int> &nums, int start, int end) {
	vector<int> result;

	for(int i=start;i<=end;i++){
		result.push_back(nums[i]);
	}

	return result;
}

vector<int> traverse(vector<int>& nums, int start, int end, int &result_count) {
	if(start == end) {
		return get(nums, start, start);
	}

	int count = 0;
	int mid  = (start + end) / 2;

	vector<int> left = traverse(nums, start, mid, result_count);
	vector<int> right  = traverse(nums, mid+1, end, result_count);

	vector<int> sorted_result = merge_sorted(left, right, count);

	result_count += count;

	return sorted_result;
}

int reversePairs(vector<int>& nums) {
	if(nums.size() == 0) {
		return 0;
	}

	int result_count = 0;
	vector<int> result = traverse(nums, 0, nums.size()-1, result_count);

	for(int i=0;i<result.size();i++) cout << result[i] << ", ";

	cout << endl;
	cout << "count = " << result_count << endl;

	return result_count;
}

int main(int argc, char** argv) {
	vector<int> nums1 = {1,3,2,3,1};
	vector<int> nums2 = {2,4,3,5,1};
	vector<int> nums3 = {2,4,1,3,5};
	vector<int> nums4 = {1,20,6,4,5};

	reversePairs(nums1);
	reversePairs(nums2);
	reversePairs(nums3);
	reversePairs(nums4);

	return 0;
}
