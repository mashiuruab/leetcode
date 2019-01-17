#include<iostream>
#include<vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	string str = "";

	if (strs.size() == 0) {
		return str;
	}

	bool temp = true;
	int max_length = strs[0].length();

	int j = 0;
	while (j < max_length) {
		temp = true;
		char ch = strs[0][j];

		for(int i=0;i<strs.size();i++){
			if(max_length < strs[i].length()) {
				max_length = strs[i].length();
			}

			temp &= (ch == strs[i][j]);
		}

		
		if(temp) {
			str += ch;
		} else {
			break;
		}

		j++;
	}

	return str;
}

int main(int argc, char** argv) {
	vector<string> strs;
	/*strs.push_back("flower");
	strs.push_back("flow");
	strs.push_back("flight");*/

	strs.push_back("dog");
	strs.push_back("racecar");
	strs.push_back("car");

	cout << longestCommonPrefix(strs) << endl;
}
