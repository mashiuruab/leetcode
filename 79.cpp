#include<iostream>
#include<vector>
#include<string>
#include<ctype.h>

using namespace std;

vector<vector<char>> m_board;
int nRow;
int nCol;
string m_word = "";
bool found = false;

void traverse(int rIdx, int cIdx, vector<vector<int>> seen_idx, string path) {
	char ch = m_board[rIdx][cIdx];
	seen_idx[rIdx][cIdx] = 5;
	string prev_path = path;
	path += tolower(ch);

	if(path == m_word) {
		found = true;
		return;
	} 

	if(path.length() == m_word.length()) {
		path = prev_path;
	}

	if((rIdx + 1 < nRow) && (seen_idx[rIdx+1][cIdx] != 5)) {
		traverse(rIdx+1, cIdx, seen_idx, path);
	}

	if(found) return;

	if((rIdx - 1 >= 0) && (seen_idx[rIdx-1][cIdx] != 5)) {
		traverse(rIdx-1, cIdx, seen_idx, path);
	}

	if(found) return;

	if((cIdx + 1 < nCol) && (seen_idx[rIdx][cIdx + 1] != 5)) {
		traverse(rIdx, cIdx+1, seen_idx, path);
	}

	if(found) return;

	if((cIdx - 1 >= 0) && (seen_idx[rIdx][cIdx - 1] != 5)) {
		traverse(rIdx, cIdx-1, seen_idx, path);
	}	
}

bool exist(vector<vector<char>>& board, string word) {
	m_board = board;

	for(int i=0;i<word.length();i++) {
		m_word += tolower(word[i]);
	}

	//cout << m_word << endl;

	nRow = board.size();
	nCol = board[0].size();
	
	vector<vector<int>> seen_idx;

	for(int i=0;i<nRow;i++) {
		vector<int> row;
		row.resize(nCol);
		seen_idx.push_back(row);
	}

	for(int i=0;i<nRow;i++) {
		for(int j=0;j<nCol;j++){
			char ch = tolower(board[i][j]);
			if(ch != m_word[0]) {
				continue;
			}
			
			traverse(i,j,seen_idx, "");
			if(found) {
				return true;
			}
		}
	}	

	return found;
}

int main(int argc, char** argv) {
	/*
	vector<char> a = {'A','B','C','E'};
	vector<char> b = {'S','F','C','S'};
	vector<char> c = {'A','D','E','E'};

	vector<vector<char>> board = {a,b,c};

	cout << "ABCCED" << " = " << exist(board, "ABCCED") << endl;
	found = false;
	m_word = "";
	cout << "SEE" << " = " << exist(board, "SEE") << endl;
	found = false;
	m_word = "";
	cout << "ABCB" << " = " << exist(board, "ABCB") << endl;
	*/
	
	


	/*
	[["F","Y","C","E","N","R","D"],["K","L","N","F","I","N","U"],["A","A","A","R","A","H","R"],["N","D","K","L","P","N","E"],["A","L","A","N","S","A","P"],["O","O","G","O","T","P","N"],["H","P","O","L","A","N","O"]]
"poland"
*/
	
	vector<char> a = {'F','Y','C','E','N','R','D'};
	vector<char> b = {'K','L','N','F','I','N','U'};
	vector<char> c = {'A','A','A','R','A','H','R'};
	vector<char> d = {'N','D','K','L','P','N','E'};
	vector<char> e = {'A','L','A','N','S','A','P'};
	vector<char> f = {'O','O','G','O','T','P','N'};
	vector<char> g = {'H','P','O','L','A','N','O'};

	vector<vector<char>> board = {a,b,c,d,e,f,g};

	cout<< "poland" << " = " << exist(board, "poland") << endl;
	

	return  0;
}
