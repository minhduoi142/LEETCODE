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

ListNode *remove_duplicate(ListNode *&head)
{

    ListNode dummy(0, head);
    ListNode *prev = &dummy;
    ListNode *curr = head;

    while (head->next != nullptr)
    {
        if (head->val == head->next->val)
        {
            while (head->next != nullptr && head->val == head->next->val)
            {
                head = head->next;
                /* code */
            }
        }
        else
        {
            prev = head;
        }
        prev->next = head->next;
        head = head->next;
        /* code */
    }

    return dummy.next;
}

void solve()
{

    int n;
    cin >> n;
    ListNode *head = nullptr;
    ListNode *root = nullptr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (head == nullptr)
        {
            head = new ListNode(x);
            root = head;
        }
        else
        {
            root->next = new ListNode(x);
            root = root->next;
        }
    }

    head = remove_duplicate(head);

    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
        /* code */
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