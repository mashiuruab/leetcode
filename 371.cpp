#include<iostream>

using namespace std;

int getSum(int a, int b) {
	int carry;
	while(b != 0) {
		carry = a & b;
		a = a ^ b;
		b = carry<<1;
	}

	return a;
}

int main(int argc, char** argv) {
	cout<<getSum(1,2)<<endl;
	return 0;
}
