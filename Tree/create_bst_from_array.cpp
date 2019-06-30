#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> generateTreesCore(int *nums, int lo, int hi) { //[lo, hi]
    vector<TreeNode*> result;
    if (lo > hi) {
        result.push_back(nullptr);
        return result;
    }
    for (int i = lo; i <= hi; i ++) {
        vector<TreeNode*> left_children = generateTreesCore(nums, lo, i - 1);
        vector<TreeNode*> right_children = generateTreesCore(nums, i + 1, hi);
        for (int j = 0; j < left_children.size(); j ++) {
            for (int k = 0; k < right_children.size(); k ++) {
                TreeNode *p_root = new TreeNode(nums[i]);
                p_root->left = left_children[j];
                p_root->right = right_children[k];
                result.push_back(p_root);
            }
        }
    }
    return result;
}

vector<TreeNode*> generateTrees(int n) {
    int *nums = new int[n];
    for (int i = 0; i < n; i ++)
        nums[i] = i + 1;
    return generateTreesCore(nums, 0, n - 1);
}

int main() {
    generateTrees(3);
    return 0;
}