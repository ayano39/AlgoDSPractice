#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
};

void visit(TreeNode *p_node) {
	cout << p_node->val << " ";
}

void preorderTraverseR(TreeNode *p_node) {
	if (p_node == nullptr)
		return;
	visit(p_node);
	preorderTraverseR(p_node->left);
	preorderTraverseR(p_node->right);
}

void inorderTraverseR(TreeNode *p_node) {
	if (p_node == nullptr)
		return;
	inorderTraverseR(p_node->left);
	visit(p_node);
	inorderTraverseR(p_node->right);
}

void postorderTraverseR(TreeNode *p_node) {
	if (p_node == nullptr)
		return;
	postorderTraverseR(p_node->left);
	postorderTraverseR(p_node->right);
	visit(p_node);
}

void preorderTraverseI(TreeNode *p_node) {
	if (p_node == nullptr)
		return;
	stack<TreeNode*> rchild_stack;
	while (true) {
		while (p_node != nullptr) {
			visit(p_node);
			if (p_node->right != nullptr)
				rchild_stack.push(p_node->right);
			p_node = p_node->left;
		}
		if (rchild_stack.empty())
			break;
		p_node = rchild_stack.top();
		rchild_stack.pop();
	}
}

void inorderTraverseI(TreeNode *p_node) {
	if (p_node == nullptr)
		return;
	stack<TreeNode*> node_stack;
	while (true) {
		while (p_node != nullptr) {
			node_stack.push(p_node);
			p_node = p_node->left;
		}
		if (node_stack.empty())
			break;
		p_node = node_stack.top();
		node_stack.pop();
		visit(p_node);
		p_node = p_node->right;
	}
}

void gotoLeaf(stack<TreeNode*> &node_stack) { //Highest visible leaf on the left
	if (node_stack.empty())
		return;
	TreeNode *p_node = node_stack.top();
	while (true) {
		if (p_node->left != nullptr) {
			if (p_node->right != nullptr)
				node_stack.push(p_node->right);
			node_stack.push(p_node->left);
			p_node = p_node->left;
		}
		else if (p_node->right != nullptr) {
			node_stack.push(p_node->right);
			p_node = p_node->right;
		}
		else
			break;
	}
}

void postorderTraverseI(TreeNode *p_node) {
	if (p_node == nullptr)
		return;
	stack<TreeNode*> node_stack;
	node_stack.push(p_node);
	while (!node_stack.empty()) {
		if (node_stack.top()->left != p_node && node_stack.top()->right != p_node)
			gotoLeaf(node_stack);
		p_node = node_stack.top();
		node_stack.pop();
		visit(p_node);
	}
}


void layerwiseTraverse(TreeNode *p_node) {
	if (p_node == nullptr)
		return;
	queue<TreeNode*> node_queue;
	node_queue.push(p_node);
	while (!node_queue.empty()) {
		p_node = node_queue.front();
		node_queue.pop();
		visit(p_node);
		if (p_node->left != nullptr)
			node_queue.push(p_node->left);
		if (p_node->right != nullptr)
			node_queue.push(p_node->right);
	}
}

TreeNode* creatTree() {
	TreeNode *p_root = new TreeNode();
	p_root->val = 2;
	TreeNode *p_1 = new TreeNode();
	p_1->val = 1;
	TreeNode *p_2 = new TreeNode();
	p_2->val = 6;
	p_root->left = p_1;
	p_root->right = p_2;
	TreeNode *p_3 = new TreeNode();
	p_3->val = 4;
	TreeNode *p_4 = new TreeNode();
	p_4->val = 7;
	p_2->left = p_3;
	p_2->right = p_4;
	TreeNode *p_5 = new TreeNode();
	p_5->val = 3;
	TreeNode *p_6 = new TreeNode();
	p_6->val = 5;
	p_3->left = p_5;
	p_3->right = p_6;
	return p_root;
}

int main(int argc, char *argv[]) {
	TreeNode *p_root = creatTree();
	cout << "Preorder Traverse:" << endl;
	preorderTraverseR(p_root);
	cout << endl;
	preorderTraverseI(p_root);
	cout << endl;

	cout << "Inorder Traverse:" << endl;
	inorderTraverseR(p_root);
	cout << endl;
	inorderTraverseI(p_root);
	cout << endl;
	
	cout << "Postorder Traverse:" << endl;
	postorderTraverseR(p_root);
	cout << endl;
	postorderTraverseI(p_root);
	cout << endl;

	cout << "Layerwise Traverse:" << endl;
	layerwiseTraverse(p_root);
	cout << endl;
	return 0;
}