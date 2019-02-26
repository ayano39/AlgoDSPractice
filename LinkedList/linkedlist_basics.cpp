#include<iostream>
using namespace std;

struct ListNode {
	int value;
	ListNode* p_next;
};

void AddToTail(ListNode** p_head, int insert_value) {
	if (p_head == nullptr)
		return;
	
	ListNode* p_new = new ListNode();
	p_new->value = insert_value;
	p_new->p_next = nullptr;

	if (*p_head == nullptr) {
		*p_head = p_new;
	} 
	else {
		ListNode *p_node = *p_head;
		while (p_node->p_next != nullptr)
			p_node = p_node->p_next;
		p_node->p_next = p_new;
	}
}

void FindAndRemove(ListNode** p_head, int value) {
	if (p_head == nullptr || *p_head == nullptr)
		return;

	ListNode* p_to_be_del = nullptr;
	if ((*p_head)->value == value) {
		p_to_be_del = *p_head;
		*p_head = (*p_head)->p_next; // *p_head->p_next can be nullptr
	}
	else {
		ListNode* p_node = *p_head;
		while (p_node->p_next != nullptr) {
			if (p_node->p_next->value == value) {
				p_to_be_del = p_node->p_next;
				p_node->p_next = p_node->p_next->p_next;
				break;
			}
			else
				p_node = p_node->p_next;
		}
	}

	if (p_to_be_del != nullptr) {
		delete p_to_be_del;
		p_to_be_del = nullptr;
	}
}

void PrintLinkedList(const ListNode* p_head) {
	const ListNode* p_node = p_head;
	while (p_node != nullptr) {
		cout << p_node->value << " ";
		p_node = p_node->p_next;
	}
	cout << endl;
}

void Test() {
	ListNode *p_head = nullptr;
	AddToTail(&p_head, 2);
	AddToTail(&p_head, 5);
	AddToTail(&p_head, 8);
	AddToTail(&p_head, 1);
	PrintLinkedList(p_head);
	FindAndRemove(&p_head, 0);
	PrintLinkedList(p_head);
	FindAndRemove(&p_head, 2);
	PrintLinkedList(p_head);
	FindAndRemove(&p_head, 1);
	PrintLinkedList(p_head);
	FindAndRemove(&p_head, 5);
	PrintLinkedList(p_head);
}

int main(int argc, char* argv[]) {
	Test();
	return 0;
}