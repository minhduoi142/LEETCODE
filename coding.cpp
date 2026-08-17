#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

void insert(Node *&root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return;
    }
    if (val < root->val)
    {
        insert(root->left, val);
    }
    else
    {
        insert(root->right, val);
    }
}


void levelOrder(Node *root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        if(curr->next != NULL){
            cout << curr->val  << " ";
        }
        else{
            cout << curr->val << " #" << " ";
        }
        
        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
}

void connect(Node *root){

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int len = q.size();
        Node *prev = NULL;

        for( int i = 0 ; i < len ; i++){

            Node *curr = q.front();
            q.pop();

            if(prev != NULL){
                prev -> next = curr;
            }
            
            prev = curr;

            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }

        }
    }
}


void solve()
{

    int n;
    cin >> n;

    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insert(root, val);
    }
    connect(root);
    levelOrder(root);



}

signed main()
{
    // CODEGOD;
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        /* code */
        solve();
    }
}