#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void rec(TreeNode* node, int level, std::vector<int>& answer) {
        if (node == NULL)
            return;
        if (level == answer.size())
            answer.push_back(node->val);
   
        rec(node->right, ++level, answer);
        rec(node->left, ++level, answer);
    }

    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;
        rec(root, 0, result);
        return result;
    }
};

int main()
{
    Solution sl;


    auto leftLeaf = new TreeNode(5);
    auto leftBranch = new TreeNode(2, nullptr, leftLeaf);

    auto rightLeaf = new TreeNode(4);
    auto rightBranch = new TreeNode(3, nullptr, rightLeaf);

    auto root = new TreeNode(1, leftBranch, rightBranch);

    sl.rightSideView(root);

    return 0;
}

//Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
//
//Example 1:
//Input: root = [1, 2, 3, null, 5, null, 4]
//Output : [1, 3, 4]
//
//Example 2:
//Input: root = [1, 2, 3, 4, null, null, null, 5]
//Output : [1, 3, 4, 5]
//
//Example 3:
//Input: root = [1, null, 3]
//Output : [1, 3]
//
//Example 4 :
//Input : root = []
//Output : []
//
//Constraints:
//The number of nodes in the tree is in the range[0, 100].
//- 100 <= Node.val <= 100
