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
void printList(ListNode *head)
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
    cin >> n;
    ListNode *head = nullptr;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        inserListNode(head, val);
    }

    int left;
    int right;
    cin >> left >> right;

    ListNode *dummy = new ListNode(0);
    ListNode *prev = dummy;
    prev->next = head;

    for( int i = 0 ; i < left - 1; i ++){
        prev = prev->next;
    }

    ListNode *curr = prev->next;

    for( int i = 0 ; i < right - left; i ++){
        ListNode *temp = curr->next;
        curr->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }
    printList(dummy->next);
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