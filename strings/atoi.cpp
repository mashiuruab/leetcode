#include<iostream>

using namespace std;

int myAtoi(string str) {
	long  int result = 0;
	bool negative = false;
	bool non_wp_found  =  false;
	bool sign_seen = false;

	for(int i=0;i<str.length();i++){
		if(str[i] == ' ' && !non_wp_found)  continue;
		if((str[i] == '-' || str[i] == '+') && !sign_seen && !non_wp_found)  {
			negative = str[i] == '-';
			non_wp_found = true;
			sign_seen = true;
			continue;
		} else if((str[i] == '-' || str[i] == '+') && non_wp_found) {
			if(negative && result != 0) result = -result;
			if(result > 2147483647) return 2147483647;
			if(result < -2147483648) return -2147483648;
			return result;
		}

		if(!(str[i] >= '0'  &&  str[i] <= '9') && non_wp_found){
			if(negative && result != 0) result = -result;
			if(result > 2147483647) return 2147483647;
			if(result < -2147483648) return -2147483648;
			return result;
		}

		if (str[i] >= '0'  &&  str[i] <= '9') {
			non_wp_found = true;
			result *=  10;
			result += str[i]  -  '0';

			if(negative) {
				if(-result < -2147483648) return -2147483648;				
			} else 	if(result > 2147483647) return 2147483647;

		}  else {
			return result;
		}
	}

	if(negative) result = -result;

	if(result > 2147483647) return 2147483647;

	if(result < -2147483648) return -2147483648;

	return result;
}

int main(int argc,char** argv){
	cout<< myAtoi("42")<<  endl;
	cout<< myAtoi("   -42")<<  endl;
	cout<< myAtoi("4193 with words")<<  endl;
	cout<< myAtoi("words and 987")<<  endl;
	cout<< myAtoi("-91283472332")<<  endl;

	cout<< myAtoi("3.14159") <<  endl;

	cout<< myAtoi("  -0012a42") <<  endl;

	cout<< myAtoi("0-1") <<  endl;
}
