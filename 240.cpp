#include<iostream>
#include<vector>

using namespace std;

int m_target;
int nrow;
int ncol;
bool found = false;

void traverse(vector<vector<int>> &matrix, int start, int end) {
	if(start > end) {
		cout <<  "start greater than  end " << start << " and  " << end << endl;
		return;
	}

	if(start ==  end) {
		int row = start / nrow;
		int col = start % nrow;
		cout << "nrow = " << nrow << ", ncol = " << ncol << endl;
		cout << "start = " << start << ", row = " << row << ", col  = " << col << endl;
		if(matrix[row][col] == m_target) {
			found = true;
		}
		
		return;
	}

	int middle_element =  (start + end)  / 2;

	cout << "start = " << start << ", middle = " << middle_element <<  ", end = " << end << endl;

	int middle_r = middle_element / nrow;
//	int middle_c = (end  -  (middle_r * nrow)) % ncol;
	int middle_c = middle_element % nrow;

/*
	cout << "middle = " << middle_element << endl;
	cout<< "m_row = " << middle_r << ", m_col = " <<  middle_c << endl;
*/

	if(matrix[middle_r][middle_c] == m_target) {
		found =  true;
		return;
	}

	traverse(matrix, start, middle_element);

	if(found) return;

	traverse(matrix, middle_element+1, end);
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if(matrix.size() == 0) {
		return false;
	}

	found = false;
	m_target = target;
	nrow = matrix.size();
	ncol = matrix[0].size();
	int total_element = nrow * ncol;

	traverse(matrix, 0, total_element - 1);

	return  found;
}


int main(int argc, char** argv) {
	/*
	vector<vector<int>>  matrix = {{1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22}, {10,13,14,17,24}, {18,21,23,26,30}};

	cout << "5 = " << searchMatrix(matrix, 5) << endl;
	cout << "20 = " << searchMatrix(matrix, 20) << endl;
	*/
	
	vector<vector<int>> m2 = {{5}, {6}};

	cout << "6 = " << searchMatrix(m2, 6) << endl;
	return  0;
}
