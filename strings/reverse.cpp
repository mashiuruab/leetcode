#include<iostream>
#include<map>

using namespace std;

string reverseString(string s) {
	int traverse_upto = s.length() / 2;
	char temp;
	
	for(int i=0;i<traverse_upto;i++){
		temp = s[i];
		s[i] = s[s.length() - 1 - i];
		s[s.length() - 1 - i] = temp;
	}
        return s;
}


int reverse_integer(int x) {
	if (x < -2147483648 || x > 2147483647) return 0;

	bool negative = false;

	if(x < 0) {
		negative = true;
		x = -x;
	}

	int temp;
	long int result = 0;

	while(x != 0) {
		temp = x % 10;
		x = x / 10;		

		if(negative) {
			if (-(result * 10) < -2147483648 || -(result * 10) > 2147483647) return 0;
		} else {
			if ((result * 10) < -2147483648 || (result * 10) > 2147483647) return 0;
		}

		result *=  10;		
		
		if(negative) {
			if (-(result + temp) < -2147483648 || -(result + temp) > 2147483647) return 0;
		} else {
			if ((result + temp) < -2147483648 || (result + temp) > 2147483647) return 0;
		}

		result +=  temp;

		//cout<< result << " and " << (result > 2147483647) << endl;
	}

	if(negative) result  = -result;

	return result;
}


int firstUniqChar(string s) {
	bool uniq = true;

	for(int i=0;i<s.length();i++){
		uniq = true;
		for(int j=0;j<s.length();j++){
			if(i != j && s[i]  ==  s[j]) {
				uniq = false;
				break;
			}			
		}
		if(uniq) return i;
	}

	return -1;        
}

bool isAnagram(string s, string t) {
	if(s.length() != t.length()) {
		return false;
	}

        std::map<char,int> first;
	std::map<char,int> second;

	for(int i=0;i<s.length();i++){
		if(first.find(s[i]) != first.end()) {
			first[s[i]] = first.find(s[i])->second + 1;
		} else {
			first[s[i]] = 1;
		}

		if(second.find(t[i]) != second.end()) {
			second[t[i]] = second.find(t[i])->second + 1;
		} else {
			second[t[i]] = 1;
		}
	}

	for(std::map<char,int>::iterator it = first.begin();it != first.end();it++){
		if(it->second != second.find(it->first)->second)  return false;
	}

	return true;
}

int main(int argc,char** argv){
	string test_str("teststring");
	//cout<< reverseString(test_str)<< endl;

	//cout<< reverse_integer(1534236469) << endl;

	//  cout<< firstUniqChar("loveleetcode") << endl;

	cout << isAnagram("anagram", "nagaram") << endl;
	cout << isAnagram("rat", "car") << endl;
	return 0;
}
