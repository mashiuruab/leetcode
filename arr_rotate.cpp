#include<iostream>
#include<vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
	int temp;
	for(int i=0;i<matrix.size();i++){
		
	}	
}

void print(vector<vector<int>>& matrix) {
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<matrix[i][j]<<endl;
		}
	}
}

int main(int argc,char** argv){
	vector<vector<int>> matrix;

	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			matrix[i].push_back(j);
		}
	}

	print(matrix);
}
