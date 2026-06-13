#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int maxStep = 0;
public:
    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);
        return maxStep;
    }

    void dfs(TreeNode* root, bool isLeft, int step) {
        if (!root) 
            return;
        maxStep = std::max(maxStep, step);
        if (isLeft) {
            dfs(root->left, false, step + 1);
            dfs(root->right, true, 1);
        }
        else {
            dfs(root->right, true, step + 1);
            dfs(root->left, false, 1);
        }
    }
};

#ifdef ACTIVE_MAIN
int main() {
    Solution sl;

    TreeNode* node15 = new TreeNode(1);
    TreeNode* node14 = new TreeNode(1);
    TreeNode* node13 = new TreeNode(1);
    TreeNode* node12 = new TreeNode(1);
    TreeNode* node11 = new TreeNode(1);
    TreeNode* node10 = new TreeNode(1);
    TreeNode* node9 = new TreeNode(1, node14, node15);
    TreeNode* node8 = new TreeNode(1, node12, node13);
    TreeNode* node7 = new TreeNode(1, node10, node11);
    TreeNode* node6 = new TreeNode(1);
    TreeNode* node5 = new TreeNode(1, node8, node9);
    TreeNode* node4 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(1, node6, node7);
    TreeNode* node2 = new TreeNode(1, node4, node5);
    TreeNode* root = new TreeNode(1, nullptr, node2);

    sl.longestZigZag(root);

    return 0;
}
#endif

//You are given the root of a binary tree.
//
//A ZigZag path for a binary tree is defined as follow :
//
//Choose any node in the binary tree and a direction(right or left).
//If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
//Change the direction from right to left or from left to right.
//Repeat the second and third steps until you can't move in the tree.
//Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).
//
//Return the longest ZigZag path contained in that tree.
//
//Example 1:
//
//Input: root = [1, null, 1, 1, 1, null, null, 1, 1, null, 1, null, null, null, 1]
//Output: 3
//Explanation : Longest ZigZag path in blue nodes(right->left->right).
//
//Example 2:
//
//Input: root = [1, 1, 1, null, 1, null, null, 1, 1, null, 1]
//Output: 4
//Explanation : Longest ZigZag path in blue nodes(left->right->left->right).
//
//Example 3:
//
//Input: root = [1]
//Output: 0