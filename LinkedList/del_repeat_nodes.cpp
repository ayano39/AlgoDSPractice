#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
};

void delRepeateNodes(ListNode **p_head) {
	if (p_head == nullptr || *p_head == nullptr)
		return;
	ListNode *p_prev = nullptr, *p_cur = *p_head, *to_be_del = nullptr;
	int repeat_val;
	while (p_cur != nullptr && p_cur->next != nullptr) {
		if (p_cur->val == p_cur->next->val) {
			repeat_val = p_cur->val;
			while (p_cur != nullptr && p_cur->val == repeat_val) {
				to_be_del = p_cur;
				p_cur = p_cur->next;
				delete to_be_del;
				to_be_del = nullptr;
			}
			if (p_prev == nullptr)
				*p_head = p_cur;
			else
				p_prev->next = p_cur;
		}
		else {
			p_prev = p_cur;
			p_cur = p_cur->next;
		}
	}
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
	delRepeateNodes(&p_head);
	cout << "After:" << endl;
	printList(p_head);
	
}

int main(int argc, char* argv[]) {
	int a[] = {1,2,3,4,5};
	int b[] = {1,2,2,3,3,3,4,5,5,5,5};
	int c[] = {4,4,4,4};
	int d[] = {2,2,2,1,1,3};
	int e[] = {2,2,2,1,1,3,3,3};
	int f[] = {1};
	Test(a, 5);
	Test(b, 11);
	Test(c, 4);
	Test(d, 6);
	Test(e, 8);
	Test(f, 1);
	Test(nullptr, 0);
	return 0;
}