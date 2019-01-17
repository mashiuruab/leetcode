#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int find_min_idx(string num, int start, int end) {
	//cout << start << endl;
	int min = INT_MAX;
	int min_idx = start;

	for(int i=start;i<=end;i++){
		int value = (int)num[i];
		if(value < min) {
			min = value;
			min_idx = i;
		}
	}

	return  min_idx;
}

string removeKdigits(string num, int k) {
	if(num.length() <= k) {
		return "0";
	}

	string result = "";

	int index = 0;

	while(index < num.length()) {
		if(k == 0) {
			for(int i=index;i<num.length();i++) {
				result += num[i];
			}
			break;
		} else if (index + k >= num.length()) {
			break;
		}

		int min_idx = find_min_idx(num, index, index + k);
		k -= min_idx - index;
		//cout << "k = " << k  << ", minIdx = " << min_idx << endl;
		result += num[min_idx];
		index = min_idx;
		index++;
	}

	if(result.length() == 1) {
		return result;
	} else {
		int start_from  = 0;
		while(result[start_from] == '0') {
			start_from++;
		}

		if(start_from == result.length()) {
			return  "0";
		} else {
			return result.substr(start_from, result.length()-start_from); 
		}
	}
}

int main(int argc, char** argv) {
	string num = "4325043";
	string num2 = "1432219";//k = 3
	string num3 = "10200";//k = 1
	string num4 = "10";//k = 2
	string num5 = "112";// k = 1

	cout << removeKdigits(num, 3) << endl;
	cout << removeKdigits(num2, 3) << endl;
	cout << removeKdigits(num3, 1) << endl;
	cout << removeKdigits(num4, 2) << endl;
	cout << removeKdigits(num5, 1) << endl;
	return 0;
}
