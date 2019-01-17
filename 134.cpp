#include<iostream>
#include<vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int length = gas.size();
	int tank_cost = 0;

	for(int start=0;start<length;start++) {
		if(cost[start] > gas[start]) {
			continue;
		}

		tank_cost = gas[start] - 0;
		//cout << "start = " << start << endl;
		for(int pos=start+1;pos<=(start+length);pos++) {
			int c_pos = pos % length;
			int prev_pos = (pos - 1) % length;

			tank_cost -= cost[prev_pos];

			if(tank_cost < 0) {
				break;
			}

			tank_cost += gas[c_pos];
			//cout << "index = " << c_pos << ", cost = " << tank_cost << endl;

			if((c_pos == start) && (tank_cost >= 0)) {
				return start;
			} else if(c_pos == start) {
				break;
			}			
		}
	}

	return  -1;
}

int main(int argc, char** argv) {
	/*
	gas  = [1,2,3,4,5]
	cost = [3,4,5,1,2]
	*/
	vector<int> gas = {1,2,3,4,5};
	vector<int> cost = {3,4,5,1,2};

	cout << canCompleteCircuit(gas, cost) << endl;

	/*
	gas  = [2,3,4]
	cost = [3,4,3]
	*/

	vector<int> gas1 = {2,3,4};
	vector<int> cost1 = {3,4,3};

	cout << canCompleteCircuit(gas1, cost1) << endl;

	return  0;
}
