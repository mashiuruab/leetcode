#include<iostream>
#include<map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void traverse(ListNode* head, map<int, int> &k_map){
	if(head == NULL) return;

	auto it = k_map.find(head->val);
	if(it == k_map.end()){
		k_map[head->val] = 1;
	} else {
		it->second++;
	}

	traverse(head->next, k_map);
	
	if(head->next != NULL) {
		//cout << "looking >...." << head->next->val << endl;
		auto it1 = k_map.find(head->next->val);
		if(it1->second > 1) head->next = head->next->next;
	}
}

ListNode* deleteDuplicates(ListNode* head) {
	if(head == NULL) return NULL;

	ListNode* result = head;

	map<int, int> k_map;

	traverse(head, k_map);

	auto it1 = k_map.find(result->val);
	if(it1->second > 1) result = result->next;

	return result;
}

int main(int argc, char** argv){
	ListNode* one = new ListNode(1);
	ListNode* two = new ListNode(2);
	ListNode* three = new ListNode(3);
	ListNode* three1 = new ListNode(3);
	ListNode* four = new ListNode(4);
	ListNode* four1 = new ListNode(4);
	ListNode* five = new ListNode(5);
	

	one->next = two;
	two->next = three;
	three->next = three1;
	three1->next = four;
	four->next = four1;
	four1->next = five;

	ListNode* result = deleteDuplicates(one);

	ListNode* head = result;

	while(head != NULL) {
		cout<< head->val << ", ";
		head = head->next;
	}

	cout<< endl;
	
	return 0;
}
