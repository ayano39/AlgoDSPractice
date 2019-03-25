#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {}
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

void ConvertCore(TreeNode *p_root, TreeNode **p_last) {
    if (p_root == nullptr)
        return;
    
    ConvertCore(p_root->left, p_last);
    p_root->left = *p_last;
    if (*p_last != nullptr)
        (*p_last)->right = p_root;
    *p_last = p_root;
    ConvertCore(p_root->right, p_last);
}

TreeNode* Convert(TreeNode* p_root) {
    TreeNode *p_last = nullptr;
    ConvertCore(pRootOfTree, &p_last);
    TreeNode *p_head = p_root;
    while (p_head->left != nullptr) {
        p_head = p_head->left;
    }
    return p_head;
}

TreeNode* creatTree() {
    TreeNode *p_root = new TreeNode(2);
    TreeNode *p_1 = new TreeNode(1);
    TreeNode *p_2 = new TreeNode(6);
    p_root->left = p_1;
    p_root->right = p_2;
    TreeNode *p_3 = new TreeNode(4);
    TreeNode *p_4 = new TreeNode(7);
    p_2->left = p_3;
    p_2->right = p_4;
    TreeNode *p_5 = new TreeNode(3);
    TreeNode *p_6 = new TreeNode(5);
    p_3->left = p_5;
    p_3->right = p_6;
    return p_root;
}

int main(int argc, char *argv[]) {
    TreeNode *p_root = creatTree();
    cout << "Before:" << endl;
    preorderTraverseR(p_root);
    cout << endl;
    TreeNode *p_head = Convert(p_root);
    cout << "After:" << endl;
    while (p_head != nullptr) {
        cout << p_head->val << " ";
        p_head = p_head->right;
    }
    cout << endl;
    return 0;
}