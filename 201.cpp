#include<iostream>

using namespace std;

int rangeBitwiseAnd(int m, int n) {
	if(m  == n) {
		cout << ".............." << endl;
		return  m;
	}

        int result = m;

        for(long int i=m+1;i<=n;i++){
            if(i == 0 || result == 0) {
		//cout << "returned........." << endl;
                return 0;
            }
            result = result & i;
	    //cout << result << endl;
        }

	//cout << result << endl;

        return result;
}

int main(int argc, char** argv) {
	int m = 2147483647;
	int n = 2147483647;

	cout<< rangeBitwiseAnd(m , n) << endl;
	return 0;
}
