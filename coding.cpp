#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Node{
    TreeNode* node;
    int min;
    int max;
};

void insertBST(TreeNode *&root, int val)
{
    if (root == nullptr)
    {
        root = new TreeNode(val);
        return;
    }

    if (val < root->val)
    {
        insertBST(root->left, val);
    }
    else
    {
        insertBST(root->right, val);
    }
}


bool validate(TreeNode * root){
    queue<Node> q;

    q.push({root, INT_MIN, INT_MAX});

    while(!q.empty()){
        Node current = q.front();
        q.pop();
        TreeNode* node = current.node;
        int min_val = current.min;
        int max_val = current.max;

        if(node->left){
            if(node->left-> val >= node -> val || node -> left -> val <= min_val){
                return false;
            }
            q.push({node->left, min_val, node->val});
        }
        if(node->right){
            if(node->right->val <= node->val || node->right->val >= max_val){
                return false;
            }
            q.push({node->right, node->val, max_val});
        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        TreeNode *root = nullptr;
        insertBST(root, x);
    }


}

signed main()
{
    CODEGOD;
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        /* code */
        solve();
    }
}