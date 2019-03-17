#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
};

ListNode* reverseList(ListNode *p_head) {
	ListNode *p_cur = p_head, *p_prev = nullptr, *p_next = nullptr;
	while (p_cur != nullptr) {
		p_next = p_cur->next;
		p_cur->next = p_prev;
		p_prev = p_cur;
		p_cur = p_next;
		
	}
	return p_prev;
}

ListNode* reverseListRecursively(ListNode *p_head) {
	if (p_head == nullptr || p_head->next == nullptr)
		return p_head;
	ListNode *new_head = reverseListRecursively(p_head->next);
	p_head->next->next = p_head;
	p_head->next = nullptr;
	return new_head;
}

void printList(ListNode *p_head) {
	while(p_head != nullptr) {
		cout << p_head->val << " ";
		p_head = p_head->next;
	}
	cout << endl;
}

ListNode* createList(int num[], int length) {
	ListNode* dummy_head = new ListNode();
	ListNode* p_cur = dummy_head;
	for (int i = 0; i < length; i ++) {
		ListNode* p_new = new ListNode();
		p_new->val = num[i];
		p_new->next = nullptr;
		p_cur->next = p_new;
		p_cur = p_new;
	}
	p_cur = dummy_head->next;
	delete dummy_head;
	return p_cur;
}

void Test(int num[], int length) {
	cout << "Test case begins:" << endl;
	ListNode *p_head = (num == nullptr)? nullptr : createList(num, length);
	cout << "Before:" << endl;
	printList(p_head);
	p_head = reverseListRecursively(p_head);
	cout << "After:" << endl;
	printList(p_head);
}

int main(int argc, char* argv[]) {
	int a[] = {1,2,3,4,5};
	int b[] = {4};
	Test(a, 5);
	Test(b, 1);
	Test(nullptr, 0);
	return 0;
}