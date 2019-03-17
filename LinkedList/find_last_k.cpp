#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
};

ListNode* findLastK(ListNode *p_head, int k) {
	if (p_head == nullptr || k <= 0)
		return nullptr;
	ListNode *p_slow = p_head, *p_fast = p_head;
	for (int i = 0; i < k - 1 && p_fast != nullptr; i ++) 
		p_fast = p_fast->next;
	if (p_fast == nullptr)
		return nullptr;
	while (p_fast->next != nullptr) {
		p_fast = p_fast->next;
		p_slow = p_slow->next;
	}
	return p_slow;
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

void Test(int num[], int length, int k) {
	cout << "Test case begins:" << endl;
	ListNode *p_head = (num == nullptr)? nullptr : createList(num, length);
	cout << "List Content: " << endl;
	printList(p_head);
	cout << "The last " << k << " item is:" << endl;
	ListNode *result = findLastK(p_head, k);
	if (result != nullptr)
		cout << result->val << endl;
	else
		cout << "Do not exist." << endl;
}

int main(int argc, char* argv[]) {
	int a[] = {1,2,3,4,5};
	int b[] = {4};
	Test(a, 5, 2);
	Test(a, 5, 1);
	Test(a, 5, 5);
	Test(a, 5, 6);
	Test(b, 1, 3);
	Test(b, 1, 1);
	Test(nullptr, 0, 0);
	return 0;
}