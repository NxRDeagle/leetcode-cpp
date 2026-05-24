#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    std::string serialize(TreeNode* root) {
        if (!root) 
            return "null";
        std::queue<TreeNode*> queue;
        queue.push(root);
        std::string res;
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            if (node) {
                res += std::to_string(node->val) + ",";
                queue.push(node->left);
                queue.push(node->right);
            }
            else
                res += "null,";
        }
        return res;
    }

    TreeNode* deserialize(std::string data) {
        if (data == "null")
            return nullptr;
        std::stringstream ss(data);
        std::string token;
        getline(ss, token, ',');
        TreeNode* root = new TreeNode(stoi(token));
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            if (!getline(ss, token, ',')) 
                break;
            if (token != "null") {
                node->left = new TreeNode(stoi(token));
                queue.push(node->left);
            }
            if (!getline(ss, token, ',')) 
                break;
            if (token != "null") {
                node->right = new TreeNode(stoi(token));
                queue.push(node->right);
            }
        }
        return root;
    }
};

int main() {
    Codec ser, deser;

    auto root = new TreeNode(1);
    auto node2 = new TreeNode(2);
    auto node3 = new TreeNode(3);
    auto node4 = new TreeNode(4);
    auto node5 = new TreeNode(5);

    node3->left = node4;
    node3->right = node5;

    root->left = node2;
    root->right = node3;

    TreeNode* ans = deser.deserialize(ser.serialize(root));

    return 0;
}

// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer,
// or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
//
// Design an algorithm to serialize and deserialize a binary tree.There is no restriction on how your serialization / deserialization
// algorithm should work.You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
//
// Clarification: The input / output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format,
// so please be creative and come up with different approaches yourself.
//
// Example1:
// Input: root = [1, 2, 3, null, null, 4, 5]
// Output : [1, 2, 3, null, null, 4, 5]
//
// Example 2 :
// Input : root = []
// Output : []
//
// Constraints:
// The number of nodes in the tree is in the range[0, 104].
// - 1000 <= Node.val <= 1000