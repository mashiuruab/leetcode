#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	int max_profit  = 0;
	int temp;

	for(int i=0;i<prices.size();i++){
		for(int j=i+1;j<prices.size();j++) {
			temp  = prices[j] - prices[i];
			if((temp > 0) && (temp > max_profit)) {
				max_profit = temp;
			}
		}
	}
	
	return max_profit;
}

int main(int argc, char** argv) {
	vector<int> p1 = {7,1,5,3,6,4};
	vector<int> p2 = {7,6,4,3,1};

	cout<<maxProfit(p1)<<endl;
	cout<<maxProfit(p2)<<endl;

	return 0;
}
