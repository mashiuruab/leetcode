#include<iostream>
#include<map>
#include<queue>

using namespace std;

struct Container {
	char key;
	int freq;
};

class Compare {
public:
	bool operator()(Container &c1, Container &c2){
		return c1.freq < c2.freq;
	}
};

void create_queue(string s, priority_queue<Container, vector<Container>, Compare> &p_queue){
	map<char, Container> k_map;

	for(int i = 0; i < s.length(); i++){
		auto it = k_map.find(s[i]);

		if(it == k_map.end()){
			Container cnt;
			cnt.key = s[i];
			cnt.freq = 1;
			k_map[s[i]] = cnt;
		} else {
			it->second.freq++;
		}
	}

	for(auto it = k_map.begin(); it != k_map.end(); it++){
		//cout<< "key = " <<  it->first <<  ", freq = " << it->second.freq << endl;
		p_queue.push(it->second);
	}	
}

string reorganizeString(string S) {
	priority_queue<Container, vector<Container>, Compare> p_queue;

	create_queue(S, p_queue);

	string result = "";
	bool added = true;

	while(!p_queue.empty() && added){
		//cout << "worked.........." << ", result = " << result <<endl;
		added = false;
		if(result.empty()) {
			Container cn = p_queue.top();
			p_queue.pop();
			result += cn.key;
			cn.freq--;
			added = true;
			if(cn.freq > 0) p_queue.push(cn);
		} else {
			Container cn1 = p_queue.top();
			p_queue.pop();
			if(result[result.length() - 1] != cn1.key && cn1.freq > 0) {
				added = true;
				result += cn1.key;
				cn1.freq--;
				p_queue.push(cn1);
			} else if(!p_queue.empty()) {
				Container cn2 = p_queue.top();
				p_queue.pop();
				p_queue.push(cn1);
				
				if(result[result.length() - 1] != cn2.key && cn2.freq > 0) {
					added = true;
					result += cn2.key;
					cn2.freq--;
					p_queue.push(cn2);
				} else {
					p_queue.push(cn2);
				}
			}
		}
	}

	//cout << result << endl;

	if(result.length() == S.length()) {
		return result;
	} else {
		//cout<< "returning ....empty "<<endl;
		//cout<< result << endl;
		return "";
	}
}

int main(int argc, char** argv) {
	string S1 = "aab";
	string S2 = "aaab";
	string S3 = "vvvlo";
	string s4 = "bbbbbbb";

	cout << S1 << " = " << reorganizeString(S1) << endl;
	cout << S2 << " = " << reorganizeString(S2) << endl;
	cout << S3 << " = " << reorganizeString(S3) << endl;
	cout << s4 << " = " << reorganizeString(s4) << endl;

	return 0;
}
