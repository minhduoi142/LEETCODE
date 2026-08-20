#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void inserListNode(ListNode *&head, int val)
{
    ListNode *newNode = new ListNode(val);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    ListNode *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printListNode(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void solve()
{

    int n;
    int x;

    cin >> n;
    cin >> x;
    ListNode *head = nullptr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        inserListNode(head, x);
    }

    ListNode *temp = head;
    vector<int> moveValues;
    vector<int> fixedValues;

    while (temp != nullptr)
    {
        if(temp->val < x){
            moveValues.push_back(temp->val);
        }
        else{
            fixedValues.push_back(temp->val);
        }
        temp = temp->next;
    }

    sort(moveValues.begin(), moveValues.end());

    ListNode *newHead = nullptr;
    for (int val : moveValues)
    {
        inserListNode(newHead, val);
    }
    for(int val : fixedValues)
    {
        inserListNode(newHead, val);
    }

    printListNode(newHead);
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