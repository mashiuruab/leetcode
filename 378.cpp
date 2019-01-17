#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Compare {
public:
	bool operator()(int value1, int value2){
		return value1 > value2;
	}
};

void create_queue(priority_queue<int, vector<int>, Compare> &p_queue,  vector<vector<int>> &matrix) {
	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[i].size(); j++) {
			p_queue.push(matrix[i][j]);
		}
	}
}

int kthSmallest(vector<vector<int>>& matrix, int k) {
	priority_queue<int, vector<int>, Compare> p_queue;
	create_queue(p_queue, matrix);

	while(!p_queue.empty() && k > 1) {
		p_queue.pop();
		k--;	
	}

	return p_queue.top();
}

int main(int argc, char** argv) { //  time complexity O(nlogn)
	/*
	vector<int> r1 = {1,5,9};
	vector<int> r2 = {10, 11, 13};
	vector<int> r3 = {12, 13, 15};

	vector<vector<int>> matrix = {r1, r2, r3};
	int k = 8;
	*/

	vector<int> r1 = {10,20,30,40};
	vector<int> r2 = {15,25,35,45};
	vector<int> r3 = {24,29,37,48};
	vector<int> r4 = {32,33,39,50};

	vector<vector<int>> matrix = {r1, r2, r3, r4};
	int k1 = 3;
	int k2 = 7;

	cout<< kthSmallest(matrix, k1) << endl;
	cout<< kthSmallest(matrix, k2) << endl;
	
	return 0;
}
