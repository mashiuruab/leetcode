#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isSubsequence(string s, string t) {
	int s_len = s.length();
	int t_len = t.length();

	int s_i = 0;
	int t_i = 0;

	while(s_i < s_len) {
		if(t_i == t_len) {
			break;
		}

		if(s[s_i] == t[t_i]) {
			//cout << t[t_i] << ", ";
			s_i++;
		}
		t_i++;
	}

	return (s_i == s_len);
}

int main(int argc, char** argv){
	string s = "abc";
	string t = "ahbgdc";

	cout << isSubsequence(s,t) << endl;

	return 0;
}
