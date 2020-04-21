/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if (root == NULL) return 0;
    int len1 = maxDepth(root->left);
    int len2 = maxDepth(root->right);
    return (len1 > len2 ? (len1 + 1) : (len2 + 1));
}
