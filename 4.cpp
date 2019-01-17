#include<iostream>
#include<vector>

using namespace std;

int max(int a, int  b) {
	return  a>b ? a : b;
}

int min(int a, int b) {
	return a<b ? a : b;
}

double get_median(vector<int>& nums) {
	if(nums.size() == 0) {
		return 0;
	} else if (nums.size() == 1) {
		return nums[0];
	}

	int length = nums.size();

	if(length % 2 == 0) {
		int m = nums.size() / 2;
		double result = (double)(nums[m] + nums[m+1]) / (double) 2;
		return result;
	} else {
		int m = nums.size() / 2;
		return nums[m];
	}
}

double get_median(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2) {
	int length1 = end1-start1+1;
	int length2 = end2-start2+1;
	double median1 = 0;
	double median2 = 0;

	if((length1 == 1) && (length2 == 2)) {
		if(nums1[start1] < nums2[start2]) {
			return nums2[start2];
		} else {
			return nums1[start1];
		}
	} else if ((length1 == 2) && (length2 == 1)) {
		if(nums2[start2] < nums1[start1]) {
			return nums1[start1];
		} else {
			return nums2[start2];
		}
	}

	if((length1 == 2) && (length2 == 2)) {
		int m1 = max(nums1[start1], nums2[start2]);
		int m2 = min(nums1[end1],  nums2[end2]);
		double result = double(m1 + m2) / double(2);
		return result;
	}
	
	if(length1 % 2 == 0) {
		int m = (start1 + end1) / 2;
		median1 = double (nums1[m] + nums1[m+1]) / double (2);
	} else {
		int m = (start1 + end1) / 2;
		median1 = nums1[m];
	}

	if(length2 % 2 == 0) {
		int m = (start2 + end2) / 2;
		median2 = double (nums2[m] + nums2[m+1]) / double (2);
	} else {
		int m = (start2 + end2) / 2;
		median2 = nums2[m];
	}

	if(median1 == median2) {
		return median1;
	}

	if(median1 < median2) {
		int middle1 = (start1 + end1) / 2;
		int middle2 = (start2 + end2) / 2;
		if(length1 > 2 && length2 > 2) {
			return get_median(nums1, middle1+1, end1, nums2, start2, middle2);		
		} else if (length1 == 2 && length2 > 2) {
			return get_median(nums1, start1, end1, nums2, start2, middle2);
		} else  if (length1 > 2 && length2 == 2) {
			return get_median(nums1, middle1+1, end1, nums2, start2, end2);
		}
	}

	if(median1 > median2) {
		int middle1 = (start1 + end1) / 2;
		int middle2 = (start2 + end2) / 2;

		if(length1 > 2 && length2 > 2) {
			return get_median(nums1, start1, middle1, nums2, middle2+1,end2);
		} else if (length1 == 2 && length2 > 2) {
			return get_median(nums1, start1, end1, nums2, middle2+1,end2);
		} else  if (length1 > 2 && length2 == 2) {
			return get_median(nums1, start1, middle1, nums2, start2,end2);
		}
	}
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	if(nums1.size() == 0) {
		return get_median(nums2);
	} else if (nums2.size() == 0) {
		return get_median(nums1);
	} else if (nums1.size() + nums2.size() == 2) {
		return (double) (get_median(nums1) + get_median(nums2)) /  (double) 2;
	} else {
		return get_median(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1);
	}
}

int main(int argc, char** argv) {
	vector<int> nums1 = {1,3};
	vector<int> nums2 = {2};

	vector<int> nums3 = {1,2};
	vector<int> nums4 = {3,4};
	cout << findMedianSortedArrays(nums1, nums2) << endl;
	cout << findMedianSortedArrays(nums3, nums4) << endl;
	return 0;
}
