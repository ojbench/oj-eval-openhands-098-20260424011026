#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertBST(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

int result = 0;
int count = 0;

void reverseInorder(TreeNode* root, int k) {
    if (root == nullptr || count >= k) {
        return;
    }
    
    reverseInorder(root->right, k);
    
    count++;
    if (count == k) {
        result = root->val;
        return;
    }
    
    reverseInorder(root->left, k);
}

int kthLargest(TreeNode* root, int k) {
    count = 0;
    result = 0;
    reverseInorder(root, k);
    return result;
}

int main() {
    vector<int> nodes(7);
    for (int i = 0; i < 7; i++) {
        cin >> nodes[i];
    }
    int cnt;
    cin >> cnt;
    
    TreeNode* root = nullptr;
    for (int i = 0; i < 7; i++) {
        root = insertBST(root, nodes[i]);
    }
    
    cout << kthLargest(root, cnt) << endl;
    
    return 0;
}
