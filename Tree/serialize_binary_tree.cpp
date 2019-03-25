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

void addNumberToStr(char **seq, int number) {
    stack<char> char_stack;
    while (number != 0) {
        int x = number % 10;
        number = number / 10;
        char_stack.push(x + '0');
    }
    while (!char_stack.empty()) {
        *((*seq)++) = char_stack.top();
        char_stack.pop();
    }
    *((*seq)++) = ',';
}

void SerializeCore(TreeNode *root, char **seq) {
    if (root == nullptr) {
        *((*seq)++) = '$';
        *((*seq)++) = ',';
        return;
    }
    addNumberToStr(seq, root->val);
    SerializeCore(root->left, seq);
    SerializeCore(root->right, seq);
}

char* Serialize(TreeNode *root) {
    char *seq = new char[1024], *p_seq = seq;
    memset(seq, '\0', 1024);
    SerializeCore(root, &p_seq);
    return seq;
}

int TransStrToInt(char **seq) {
    int sum = 0;
    while (**seq != ',') {
        sum = sum * 10 + (**seq) - '0';
        (*seq)++;
    }
    (*seq)++;
    return sum;
}

TreeNode* DeserializeCore(char **seq) {
    if (**seq == '\0')
        return nullptr;
    if (**seq == '$') {
        (*seq) += 2;
        return nullptr;
    }
    TreeNode *root = new TreeNode(TransStrToInt(seq));
    root->left = DeserializeCore(seq);
    root->right = DeserializeCore(seq);
    return root;
}

TreeNode* Deserialize(char *str) {
    return DeserializeCore(&str);
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
    char* seq = Serialize(p_root);
    TreeNode* new_root = Deserialize(seq);
    cout << "After:" << endl;
    preorderTraverseR(new_root);
    cout << endl;
    return 0;
}