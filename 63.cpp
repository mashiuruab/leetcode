#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> grid;
vector<vector<int>> cache;
int r_len;
int c_len;

int traverse2(int row, int col) {
	//if((row >= r_len) || (col >=  c_len)) return 0;

	if(cache[row][col] != -1) return cache[row][col];

	if(grid[row][col] == 1) return 0;

	if((row == r_len - 1) && (col == c_len - 1)) {
		return 1;
	}

	int down_r = row + 1;
	int down_c = col;

	int right_r = row;
	int right_c = col + 1;

	int down_val = 0;
	int right_val= 0;

	if((down_r < r_len) && (down_c <  c_len)) {
		down_val = traverse2(down_r, down_c);
	}

	if((right_r < r_len) && (right_c <  c_len)) {
		right_val = traverse2(right_r, right_c);
	}

	if(down_val + right_val > 0) {
		cache[row][col] = down_val + right_val;
	}

	return down_val + right_val;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	grid = obstacleGrid;
	r_len = obstacleGrid.size();
	c_len = obstacleGrid[0].size();

	for(int i = 0; i < r_len; i++) {
		vector<int> temp;
		for(int j = 0; j < c_len; j++) {
			temp.push_back(-1);
		}

		cache.push_back(temp);
	}

	//cout<< "worked here" << endl;

	return traverse2(0, 0);
}

int main(int argc, char** argv) {
	vector<int> row1 = {0,0,0};
	vector<int> row2 = {0,1,0};
	vector<int> row3 = {0,0,0};

	grid.push_back(row1);
	grid.push_back(row2);
	grid.push_back(row3);

	
	/*
	traverse("", 0, 0);
	*/

	cout << "count = " << uniquePathsWithObstacles(grid) << endl;

	return 0;
}
