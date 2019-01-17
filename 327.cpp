#include<iostream>
#include<vector>

using namespace std;

int m_lower;
int m_upper;

void traverse(vector<int>& nums, int start, int end,  long int &sum, int &count) {
	if(start == end) {
		if(nums[start] >= m_lower && nums[start] <= m_upper) {			
			count += 1;			
		}
		sum += nums[start];
		return;
	}

	int mid = (start + end) / 2;

	long int left_sum = 0;
	int left_count = 0;
	long int right_sum = 0;
	int right_count = 0;

	traverse(nums, start, mid, left_sum, left_count);
	count += left_count;
	traverse(nums, mid+1, end, right_sum, right_count);
	count += right_count;

	sum += left_sum + right_sum;

	if(sum >= m_lower && sum <= m_upper) {
		count += 1;
	}

	//cout << "sum = " << sum << ", left_sum = " << left_sum << ", right_sum = " << right_sum << ", count = " << count <<endl;
}

int countRangeSum(vector<int>& nums, int lower, int upper) {
	if(nums.size() == 0) {
		return 0;
	}

	m_lower = lower;
	m_upper = upper;

	int count = 0;
	long int sum = 0;

	traverse(nums, 0, nums.size()-1, sum, count);

	//cout<< "final sum = " << sum << endl;

	cout<< count << endl; 

	return count;
}

int main(int argc, char** argv) {
	vector<int> nums1 = {-2,5,-1};
	vector<int> nums2 = {2147483647,-2147483648,-1,0};
	
	countRangeSum(nums1, -2, 2);
	countRangeSum(nums2, -1, 0);
	return 0;
}
