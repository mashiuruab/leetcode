#include<iostream>

using namespace std;

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	vector<Interval> result;
	bool flag  =  false;

	for(int i=0;i<intervals.size();i++){
		if(!flag && (intervals[i].start < newInterval.start) && (intervals[i].end < newInterval.start)) {
			result.push_back(intervals[i]);
		} else if (!flag && (newInterval.start < intervals[i].start) && (newInterval.end < intervals[i].start)) {
            flag = true;
            result.push_back(newInterval);
			result.push_back(intervals[i]);
		} else if (!flag) {
			int start = (newInterval.start < intervals[i].start) ? newInterval.start : intervals[i].start;
			int end = (newInterval.end > intervals[i].end) ? newInterval.end : intervals[i].end;
			while(((newInterval.end > intervals[i].end) || (newInterval.end >= intervals[i].start)) && (i < intervals.size())) {
				end = (newInterval.end > intervals[i].end) ? newInterval.end :  intervals[i].end;
				i++;
			}

			Interval temp(start, end);

			result.push_back(temp);
			i--;
			flag = true;
		} else {
			result.push_back(intervals[i]);
		}
	}

	if(!flag) {
		result.push_back(newInterval);
	}

	return result;
}

int main(int argc, char** argv) {
	return  0;
}
