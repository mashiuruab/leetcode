#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<vector<int>> result;
int length;
vector<int> numbers;

void traverse(int index, vector<int> container, vector<int> seen_idx) {
	//cout<< index << " ";
	seen_idx[index] = 5;
	container.push_back(numbers[index]);

	bool seen_once  = false;

	int count = 0;
	for(int i=0;i<length;i++){
		if(seen_idx[i] != 5) {
			//cout << i << " ";
			traverse(i, container, seen_idx);
			//cout << endl;
		} else {
			count++;
		}
	}

	if(count == length) result.push_back(container);
}

vector<vector<int>> permute(vector<int>& nums) {
	length = nums.size();
	numbers = nums;

	for(int i=0;i<length;i++) {
		vector<int> container;
		vector<int> seen_idx;
		//container.resize(length);
		seen_idx.resize(length);
				
		traverse(i, container, seen_idx);
		//cout << endl;
	}

        return result;
}

int main(int argc, char** argv) {
	vector<int> nums = {1,2,3};

	permute(nums);

	
	
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<< result[i][j] << " ";			
		}
		
		cout<< endl;
	}
	

	return 0;
}
