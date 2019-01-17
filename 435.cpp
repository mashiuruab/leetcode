#include<iostream>
#include<vector>

using namespace std;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

int eraseOverlapIntervals(vector<Interval>& intervals) {
	int count = 0;

	Interval prev = {-1,-1};

	for(int i=0;i<intervals.size();i++) {
		if(prev.start != -1 && prev.end != -1) {
			if(prev.end != intervals[i].start) {
				count++;
				continue;
			} else {
				prev =  intervals[i];
			}
		} else {
			prev = intervals[i];
		}
	}

	return count;        
}

int main(int argc, char** argv) {
	return 0;
}
