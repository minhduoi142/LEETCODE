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

void insertNode(ListNode *&head, int val)
{
    if (head == NULL)
    {
        head = new ListNode(val);
    }
    else
    {
        ListNode *curr = head;

        while (curr->next != NULL)
        {
            curr = curr->next;
        }

        curr->next = new ListNode(val);
    }
}

void print(ListNode *head)
{
    ListNode *curr = head;

    while (curr != NULL)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    ListNode *head = NULL;
    int len = 1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        insertNode(head, x);
    }

    ListNode *last = head;

    while (last->next != NULL)
    {
        last = last->next;
        len++;
    }

    k = k % len;

    if(k == 0){
        
        print(head);
        return;
    }
    ListNode *newHead = head;
    for (int i = 1; i < len - k; i++)
    {
        newHead = newHead->next;
    }
    ListNode *temp = newHead;

    newHead = newHead->next;
    last->next = head;

    temp->next = NULL;

    print(newHead);
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