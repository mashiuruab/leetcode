#include<iostream>
#include<vector>

using namespace std;

bool searchInRow(vector<int> &vec, int start, int end, int target) {
	if(start >= end) {
		return false;	
	}

	int middle = (start + end) / 2;

	if(vec[middle] == target) {
		return true;
	}

	if(vec[middle] < target) {
		return searchInRow(vec, middle+1, end, target);
	} else {
		return searchInRow(vec, start, middle, target);
	}
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool found = false;

	for(int i=0;i<matrix.size();i++){
		vector<int> &vec = matrix[i];
		found = found || searchInRow(vec, 0, vec.size(), target);
		if(found) return found;
	}

	return found;
}


int main(int argc, char** argv){
	
	return 0;
}
