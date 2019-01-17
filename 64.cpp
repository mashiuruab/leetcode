#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int traverse2(vector<vector<int>>& grid, vector<vector<int>>& cache, int row, int col, int sum) {
	int r_len = grid.size();
	int c_len = grid[0].size();

	if((row >= r_len) || (col >=  c_len)) return INT_MAX;

	/*if(cache[row][col] != -1) {
		return sum + cache[row][col];
	}*/

	sum += grid[row][col];

	if((row == r_len - 1) && (col == c_len - 1)) {
		if(cache[row][col] == -1) {
			cache[row][col] =  sum;
		} else if (cache[row][col] > sum) {
			cache[row][col] = sum;
		}
		return sum;
	}

	int down_r = row + 1;
	int down_c = col;

	int right_r = row;
	int right_c = col + 1;

	int down_val = traverse2(grid, cache, down_r, down_c, sum);
	int right_val = traverse2(grid, cache, right_r, right_c, sum);

	if(down_val > right_val) {
		cache[row][col] = right_val;
		return right_val;
	} else {
		cache[row][col] = down_val;
		return down_val;
	}
}

int minPathSum(vector<vector<int>>& grid) {
	vector<vector<int>> cache;

	for(int i = 0; i < grid.size(); i++) {
		vector<int> temp;
		for(int j = 0; j < grid[i].size(); j++) {
			temp.push_back(-1);
		}

		cache.push_back(temp);
	}

	
	int result = traverse2(grid, cache, 0, 0, 0);
	
	for(int i = 0; i < cache.size(); i++){
		for(int j = 0; j < cache[i].size(); j++){
			cout << cache[i][j] <<" ";
		}
		cout << endl;
	}

	return result;
}

int main(int argc, char** argv) {
	vector<int> row1 = {1,3,1};
	vector<int> row2 = {1,5,1};
	vector<int> row3 = {4,2,1};
	vector<vector<int>> grid;

	grid.push_back(row1);
	grid.push_back(row2);
	grid.push_back(row3);

	cout << "count = " << endl;
	cout << minPathSum(grid) << endl;

	return 0;
}
