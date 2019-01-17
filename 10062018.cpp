#include<iostream>
#include<map>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* sum = new ListNode(-1);
	ListNode* head = sum;
	int carry = 0;
	int temp;

	while((l1 != NULL) && (l2 != NULL)) {
		temp = l1->val + l2->val + carry;
		sum->val = temp % 10;
		carry = temp / 10;
		if((l1->next != NULL) || (l2->next != NULL) || carry  == 1) {
			sum->next = new ListNode(-1);				
		}

		sum = sum->next;
		l1 = l1->next;
		l2 = l2->next;
	}	
	
	if(l1 == NULL) {
		l1 = l2;
	}

	while(l1 != NULL) {
		temp = l1->val + carry;
		sum->val = temp % 10;
		carry = temp / 10;
		if(l1->next != NULL || carry  == 1) sum->next = new ListNode(-1);
		sum = sum->next;
		l1 = l1->next;
	}

	if(carry == 1) {
		sum->val  = carry;
		sum->next = NULL;
	}

	
	return  head;        
}

void print_LL(ListNode* root) {
	while(root != NULL) {
		cout << root->val << " ";
		root = root->next;
	}
	cout<< endl;
}

int lengthOfLongestSubstring(string s) {
	map<char, int> key;
	int count;
	int max = 0;

	for(int i=0;i<s.length();i++){
		key.clear();
		count = 0;
	
		for(int j=i;j<s.length();j++){
			if(key.find(s[j]) != key.end()) {
				break;
			}
			count++;
			if(count > max) {
				max = count;
			}

			key[s[j]] =  1;
		}
	}

	return max;      
}

bool isPalindrome(string s,int start, int end) { //  end exclusive here
	bool check = true;
	int length = end - start;
	
	int count = 0;
	for(int i = start;i < end, count < length / 2;i++) {
		if(s[i] != s[end - count - 1]) {
			return false;
		}
		count++;
	}

	return  check;
}

string  get(string s, int start, int end) {
	string temp = "";
	
	for(int i=start;i<end;i++){
		temp += s[i];
	}

	return temp;
}

string longestPalindrome(string s) {
	string result = "";
	int max = 0;
	int count = s.length();

	while(count >= 0) {

		for(int pos=0;pos + count <= s.length();pos++) {
			int start =  pos;
			int end = pos + count;

			if(isPalindrome(s, start, end) && max < count) {
				max = count;
				result = get(s, start, end);
				return result;
				//cout<< "result = " << result << ", start = " << start << ", end = " << end << endl;
			}
			
		}

		count--;
	}

	return result;
}

int main(int argc, char** argv){
	/*
	ListNode* root = new ListNode(1);
	ListNode* newNode = new ListNode(8);
	newNode->next = NULL;
	root->next = newNode;

	ListNode* root2 = new ListNode(0);
	root2->next = NULL;

	ListNode* result = addTwoNumbers(root, root2);

	print_LL(result);
	*/

	string s = "babad";
	string s2 = "cbbd";

	cout << longestPalindrome(s) << endl;
	cout << "........................." << endl;
	cout << longestPalindrome(s2) << endl;
		
	return  0;
}
