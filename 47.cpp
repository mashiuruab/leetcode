#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<string, int> key_map;
vector<int> numbers;
vector<vector<int>> result;
int length;

void traverse(int index, string path, vector<int> seen_index, vector<int> container) {
	seen_index[index] =  5;
	container.push_back(numbers[index]);
	path = path + to_string(numbers[index]);

	int count = 0;

	for(int i=0;i<length;i++) {
		if(seen_index[i] != 5) {
			traverse(i,path,seen_index, container);
		} else {
			count++;
		}
	}

	if((count == length) && (key_map.find(path) == key_map.end())) {
		//cout << path << endl;
		key_map[path] = 1;
		result.push_back(container);
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
	length = nums.size();
	numbers = nums;

        for(int i=0;i<nums.size();i++) {
		vector<int> seen_index;
		vector<int> container;
		seen_index.resize(length);
		traverse(i, "", seen_index, container);
	}

	return result;

}

int main(int argc, char** argv) {
	vector<int> nums = {1,1,2};

	permuteUnique(nums);
	
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<< result[i][j] << " ";			
		}
		
		cout<< endl;
	}

	return 0;
}
