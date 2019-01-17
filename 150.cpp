#include<iostream>
#include<string>
#include<vector>
#include<cassert>

using namespace std;

class m_stack {
public:
	vector<int> mem;

	void push(int value) {
		mem.push_back(value);
	}

	int pop() {
		int back = mem.back();
		mem.pop_back();
		return back;
	}

	bool empty() {
		return mem.size() == 0;
	}
};

int evalRPN(vector<string>& tokens) {
	m_stack stack;
	string value  = "";

        for(int i=0;i<tokens.size();i++){
		value =  tokens[i];
		if(value  == "+") {
			int value1 = stack.pop();
			int value2 = stack.pop();
			int result = value2 + value1;
			stack.push(result);
		} else if(value  == "-") {
			int value1 = stack.pop();
			int value2 = stack.pop();
			int result = value2 - value1;
			stack.push(result);
		} else if(value  == "*") {
			int value1 = stack.pop();
			int value2 = stack.pop();
			int result = value2 * value1;
			stack.push(result);
		} else if(value  == "/") {
			int value1 = stack.pop();
			int value2 = stack.pop();
			int result = value2 / value1;
			stack.push(result);
		} else {
			stack.push(stof(value));
		}
	}

	int final_result =  stack.pop();

	assert(stack.empty());

	return final_result;
}

int main(int argc, char** argv) {
	vector<string> num1 = {"2", "1", "+", "3", "*"};
	vector<string> num2 = {"4", "13", "5", "/", "+"};
	vector<string> num3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

	cout<< evalRPN(num1) << endl;
	cout<< evalRPN(num2) << endl;
	cout<< evalRPN(num3) << endl;

	return 0;
}
