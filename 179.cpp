#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> merge(vector<int> &num1, vector<int> &num2) {
	vector<int> result;

	int count1 = 0;
	int count2 = 0;

	while(count1 < num1.size() || count2 < num2.size()) {
		if((count1 == num1.size()) && (count2 < num2.size())) {
			for(int j=count2;j<num2.size();j++){
				result.push_back(num2[j]);
			}

			break;
		}

		if((count2 == num2.size()) && (count1 < num1.size())) {
			for(int i=count1;i<num1.size();i++){
				result.push_back(num1[i]);
			}

			break;
		}
		
		if(num1[count1] > num2[count2]) {
			result.push_back(num1[count1]);
			count1++;
		} else {
			result.push_back(num2[count2]);
			count2++;
		}
	}

	return result;
}

vector<int> merge_s(vector<int> &num1, vector<int> &num2) {
	vector<int> result;

	int count1 = 0;
	int count2 = 0;

	while(count1 < num1.size() || count2 < num2.size()) {
		if((count1 == num1.size()) && (count2 < num2.size())) {
			for(int j=count2;j<num2.size();j++){
				result.push_back(num2[j]);
			}

			break;
		}

		if((count2 == num2.size()) && (count1 < num1.size())) {
			for(int i=count1;i<num1.size();i++){
				result.push_back(num1[i]);
			}

			break;
		}

		
		string temp = to_string(num1[count1]) + to_string(num2[count2]);
		string temp2 = to_string(num2[count2]) + to_string(num1[count1]);

		if(stoll(temp) > stoll(temp2)) {
			result.push_back(num1[count1]);
			count1++;	
		} else {
			result.push_back(num2[count2]);
			count2++;
		}
		
		/*
		if(stoi(num1[count1]) > stoi(num2[count2])) {
			string temp1 = num1[count1] + num2[count2];
			string temp2 = num2[count2] + num1[count1]; 
			result.push_back(num1[count1]);
			count1++;
		} else {
			result.push_back(num2[count2]);
			count2++;
		}

		*/
	}

	return result;
}

vector<int> divide(vector<int> &nums, int start, int end) {
	if(start >= end) {
		vector<int> result;
		result.push_back(nums[start]);
		return result;
	}

	int mid = (start + end) / 2; // this is the floor

	vector<int> left = divide(nums, start, mid);
	vector<int> right = divide(nums, mid + 1, end);

	return merge_s(left, right); 
}

string largestNumber(vector<int>& nums) {
        string result = "";

	vector<int> result_int = divide(nums, 0, nums.size() - 1);

	int count = 0;
	
	for(int i=0;i<result_int.size();i++){
		//cout<< result_int[i] << endl;
		if(result_int[i] == 0) {
			count++;
		}
		
		result += to_string(result_int[i]);
	}

	if(count == result_int.size()) {
		return "0";
	}

	return result;
}

int main(int argc, char** argv) {
	vector<int> num1 = {4,5,6};
	vector<int> num2 = {1,2,3};
	vector<int> nums = {1,911,2,80,3,7,4,6,5, 945};
	vector<int> num3 = {54, 546, 548, 60};
	vector<int> num4 = {1,34,3,98,9,76,45,4};
	vector<int> num5 = {10,2};
	vector<int> num6 = {999999998,999999997,999999999};
	vector<int> num7 = {999999998,999999997,999999999};
 
	//vector<int> result = divide(num1, num2);
	/*
	vector<int> result2 = divide(num3, 0, 4);

	for(int i=0;i<result2.size();i++){
		cout<< result2[i] << ", ";
	}

	cout << endl;

	*/

	cout<< "#############################" << endl;
	cout << largestNumber(num3) << endl;
	
	cout<< "#############################" << endl;
	cout << largestNumber(num4) << endl;
	
	cout<< "#############################" << endl;
	cout << largestNumber(num5) << endl;

	cout<< "#############################" << endl;
	cout << largestNumber(num6) << endl;
	

	return 0;
}
