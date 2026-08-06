// LeetCode 61: Rotate List
// Approach: Circular Linked List
// Time: O(n)
// Space: O(1)

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        int count = 1;
        ListNode* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }

        k = k % count;

        if (k == 0)
            return head;

        temp->next = head;

        temp = head;

        for (int i = 1; i < count - k; i++)
            temp = temp->next;

        head = temp->next;
        temp->next = NULL;

        return head;
    }
};

void printList(ListNode* head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n == 0)
    {
        cout << "Empty List\n";
        return 0;
    }

    int x;
    cin >> x;
    ListNode* head = new ListNode(x);
    ListNode* temp = head;

    for (int i = 1; i < n; i++)
    {
        cin >> x;
        temp->next = new ListNode(x);
        temp = temp->next;
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    head = obj.rotateRight(head, k);

    cout << "Rotated List: ";
    printList(head);

    return 0;
}