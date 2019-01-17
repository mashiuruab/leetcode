#include<iostream>
#include<climits>

using namespace std;

int divide(int dividend, int divisor) {
	if(divisor == 1) {
		return dividend;
	}

	if(divisor == -1) {
		if(dividend == INT_MIN) {
			return INT_MAX;
		} else {
			return -1 * dividend;
		}
	}

	long int t1 = dividend;
	long int t2 = divisor;
	bool positive = true;

	if(t1 < 0) {
		positive = !positive;
		t1 *= -1;
	}

	if(t2 < 0) {
		positive = !positive;
		t2 *= -1;
	}

	//cout<< "t1 = " << t1 << ", t2 = " << t2 << endl;

	long int count = 0;
	while(t1 >= t2) {
		t1 -= t2;
		count++;
	}

	//cout << "count = " << count << endl;

	if (positive) {
		return count > INT_MAX ? INT_MAX : count;
	} else {
		return -count < INT_MIN ? INT_MIN : -count;
	} 
}

int main(int argc, char** argv) {

	cout << divide(-2147483648, -1) << endl;
	return 0;
}
