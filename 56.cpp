#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class m_stack {
public:
	vector<Interval> mem;

	void push(Interval value) {
		mem.push_back(value);
	}

	void pop() {
		mem.pop_back();
	}

	Interval top() {
		return mem.back();
	}

	bool isEmpty() {
		return mem.size() == 0;
	}
};

vector<Interval> merge_i(vector<Interval> &first, vector<Interval> &second) {
	vector<Interval> result;

	int count1 = 0;
	int count2 = 0;

	while (count1 < first.size() || count2 < second.size()) {
		if((count1 == first.size()) && (count2 < second.size())) {
			for(int j=count2;j<second.size();j++) {
				result.push_back(second[j]);
			}
			break;
		}

		if((count2 == second.size()) && (count1 < first.size())) {
			for(int i=count1;i<first.size();i++){
				result.push_back(first[i]);
			}
			break;
		}


		if(first[count1].start < second[count2].start) {
			result.push_back(first[count1]);
			count1++;
		} else {
			result.push_back(second[count2]);
			count2++;
		}
	}

	return result;
}

vector<Interval> divide(vector<Interval> &intervals, int start, int end) {
	if(start >= end) {
		vector<Interval> result;
		result.push_back(intervals[start]);
		return result;
	}

	int mid =  (start + end) / 2;

	vector<Interval> left = divide(intervals, start, mid);
	vector<Interval> right =  divide(intervals, mid+1, end);

	return merge_i(left, right);
}

vector<Interval> merge(vector<Interval>& intervals) {
	if(intervals.size() == 0) {
		return intervals;
	}

        vector<Interval> s_result = divide(intervals,  0, intervals.size() - 1);

	m_stack stack;

	for(int i=0;i<s_result.size();i++){
		if(!stack.isEmpty()) {
			Interval top =  stack.top();
			if(top.end >= s_result[i].start) {
				Interval n_interval;
				n_interval.start = (top.start < s_result[i].start) ? top.start : s_result[i].start;
				n_interval.end = (top.end < s_result[i].end) ? s_result[i].end : top.end;

				stack.pop();
				stack.push(n_interval);
			} else {
				stack.push(s_result[i]);
			}
		} else {
			stack.push(s_result[i]);
		}
	}

	return stack.mem;
}

int main(int argc, char** argv) {
	Interval one(1,3);
	Interval two(2,6);
	Interval three(8,10);
	Interval four(15, 18);

	vector<Interval> intervals = {four, three, one, two};

	Interval a(1,4);
	Interval b(4,5);

	vector<Interval> ivals = {b,a};

	vector<Interval> result = merge(ivals);

	for(int i=0;i<result.size();i++){
		cout << "count " << i << endl;
		cout<< "<" << result[i].start << ", " << result[i].end << ">" << endl;
	}

	cout<<endl;

	return 0;
}
