#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	if(m == 0) {
		for(int j=0;j<n;j++) nums1[j] = nums2[j];
		return;
	} else if(n ==  0) {
		return;
	}

	int i = 0;
	int j = 0;

	while((i + j) < (m + n)) {
		if((i < m+j) && nums1[i] < nums2[j]) {
			i++;
			continue;
		} else if (i == m+j) {
			for(int count=j;count<n;count++) {
				nums1[m+count] = nums2[count];
			}
			return;
		}
		
		
		for(int count = m + j;count > i + 1;count--) {
			nums1[count] = nums1[count-1];
		}

		nums1[i+1] = nums2[j];

		i++;
		j++;
	}
}

int main(int argc, char** argv) {
	/*
		[-48,-46,-46,-46,-45,-45,-44,-42,-38,-36,-35,-34,-33,-32,-32,-32,-30,-29,-28,-28,-26,-25,-23,-19,-15,-13,-12,-10,-8,-7,-6,-4,-2,0,0,0,1,1,2,4,4,5,6,8,11,11,16,16,22,23,23,24,25,25,26,28,29,30,32,33,34,34,35,35,36,36,38,40,41,42,42,42,42,45,48,0,0,0,0,0,0,0]
75
[-36,-27,-24,-14,-13,2,9]
7
	*/
	
/*
	vector<int> nums1 = {1,2,3,0,0,0};
	vector<int> nums2 = {2,5,6};
*/

	vector<int> nums1 = {-48,-46,-46,-46,-45,-45,-44,-42,-38,-36,-35,-34,-33,-32,-32,-32,-30,-29,-28,-28,-26,-25,-23,-19,-15,-13,-12,-10,-8,-7,-6,-4,-2,0,0,0,1,1,2,4,4,5,6,8,11,11,16,16,22,23,23,24,25,25,26,28,29,30,32,33,34,34,35,35,36,36,38,40,41,42,42,42,42,45,48,0,0,0,0,0,0,0};
	vector<int> nums2 = {-36,-27,-24,-14,-13,2,9};

	cout << "nums1.size() = " << nums1.size() << ", nums2.size() = " << nums2.size() << endl;
	merge(nums1, 75, nums2, 7);

	for(int i=0;i<nums1.size();i++) cout<<"i = " << i << ", " << nums1[i]<<endl;
	
	return 0;
}
