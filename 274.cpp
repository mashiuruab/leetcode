#include<iostream>
#include<algorithm>

using namespase std;

int hIndex(vector<int>& citations) {
	sort(citations.begin(), citations.end());

	int h_index = 0;

	for(int i=0;i<citations.size();i++){
		if(citations[i] == (citations.size() - i)) {
			if(citations[i] > h_index) {
				h_index = citations[i];
			}
		}
	}

	return h_index;
}

int main(int argc, char** argv) {
	return 0;
}
