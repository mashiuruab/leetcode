#include<iostream>

using namespace std;


int strStr2(string haystack, string needle) {
	int j = 0;
	int start  = 0;
	for(int i=0;i<haystack.length();i++){
		if((haystack[i] ==  needle[j]) && (j != needle.length())) {
			start = i;
			j++;
		} else if (j != needle.length()) {
			cout  << "j  = " << j  << endl;
			j = 0;
		}
	}

	cout << "start = " << start << ", j = " << j  << endl;

	if(j ==  needle.length() && j != 0) {
		return start-j+1;
	} else if (needle.length() == 0) {
		return 0;
	} else return -1;
}

int strStr(string haystack, string needle) {
	int  start = 0;

	for(int i=0;i<haystack.length();i++){
		start = i;
		int count = 0;
		for(int j=0;j<needle.length();j++){
			if(haystack[i+j] == needle[j]) {
				count++;
			}
		}
		
		//cout << " start = " << start << " count = " << count << endl; 
		if(count == needle.length() && count != 0) {
			return start;
		} else if  (needle.length() == 0){
			return 0;
		}
	}

	return -1;
}

int main(int argc, char** argv){
	cout<< strStr("hello", "ll") << endl;
	cout<< strStr("aaaaa", "bba") << endl;
	cout<< strStr("mississippi","issip") << endl;
}
