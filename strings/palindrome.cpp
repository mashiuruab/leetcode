#include<iostream>

using namespace std;

string pre_process_str(string s){
	string  str;

	for(int i=0;i<s.length();i++){
		if(s[i] >= 'A' && s[i] <= 'Z') str +=  s[i] + 32;
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) str += s[i];
	}
	return str;
}

bool is_palindrome(string s) {
	string str = pre_process_str(s);
	//cout << "str = " << str.length() << " s = " << s.length() << endl;
	int check_upto = str.length() / 2;

	for(int i=0;i<check_upto;i++){
		if(str[i] != str[str.length() - 1 - i]) return false;
	}

	return true;
}

int main(int argc, char** argv){
	cout<< is_palindrome("A man, a plan, a canal: Panama") << endl;
	cout<< is_palindrome("race a car") << endl;
}
