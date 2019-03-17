#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
};

bool findANodeOfLoop(ListNode *p_head, ListNode **p_result) {
	if (p_head == nullptr || p_head->next == nullptr)
		return false;
	ListNode *p_slow = p_head, *p_fast = p_head->next;
	while (p_fast != nullptr && p_fast->next != nullptr && p_fast != p_slow) {
		p_slow = p_slow->next;
		p_fast = p_fast->next->next;
	}
	if (p_fast == p_slow){
		*p_result = p_fast;
		return true;
	}
	else {
		*p_result = nullptr;
		return false;
	}
}

int findLoopSize(ListNode *p_head) {
	ListNode *p_in_loop = nullptr;
	if (!findANodeOfLoop(p_head, &p_in_loop))
		return 0;
	ListNode *p_cur = p_in_loop->next;
	int count = 1;
	while (p_cur != p_in_loop) {
		count ++;
		p_cur = p_cur->next;
	}
	return count;
}

ListNode* findLoopEntry(ListNode *p_head) {
	int loop_size = findLoopSize(p_head);
	if (loop_size == 0)
		return nullptr;
	ListNode *p_slow = p_head, *p_fast = p_head;
	for (int i = 0; i < loop_size; i ++)
		p_fast = p_fast->next;
	while (p_fast != p_slow) {
		p_fast = p_fast->next;
		p_slow = p_slow->next;
	}
	return p_fast;
}

void printList(ListNode *p_head) {
	while(p_head != nullptr) {
		cout << p_head->val << " ";
		p_head = p_head->next;
	}
	cout << endl;
}

ListNode* createLoopList(int num[], int length) {
	ListNode* dummy_head = new ListNode();
	ListNode* p_cur = dummy_head;
	for (int i = 0; i < length; i ++) {
		ListNode* p_new = new ListNode();
		p_new->val = num[i];
		p_new->next = nullptr;
		p_cur->next = p_new;
		p_cur = p_new;
	}
	ListNode *loop_start = p_cur;
	for (int i = 0; i < length; i ++) {
		ListNode* p_new = new ListNode();
		p_new->val = num[i];
		p_new->next = nullptr;
		p_cur->next = p_new;
		p_cur = p_new;
	}
	p_cur->next = loop_start;
	p_cur = dummy_head->next;
	delete dummy_head;
	return p_cur;
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
	cout << "No loop: " << endl;
	ListNode *p_head = (num == nullptr)? nullptr : createList(num, length);
	cout << findLoopSize(p_head) << endl;
	cout << "Loop size: " << length + 1 << endl;
	p_head = (num == nullptr)? nullptr : createLoopList(num, length);
	cout << findLoopSize(p_head) << endl;
	cout << "Entry Node " << num[length - 1] << endl;
	cout << findLoopEntry(p_head)->val << endl;
}

int main(int argc, char* argv[]) {
	int a[] = {1,2,3,4,5};
	int b[] = {1,2,2,3,3,3,4,5,5,5,5};
	int c[] = {4,4,4,4};
	int d[] = {1,1};
	int e[] = {2};
	Test(a, 5);
	Test(b, 11);
	Test(c, 4);
	Test(d, 2);
	Test(e, 1);
	Test(nullptr, -1);
	return 0;
}