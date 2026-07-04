// LeetCode 328: Odd Even Linked List
// Approach: Separate Odd and Even Indexed Nodes
// Time: O(n)
// Space: O(1)

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode* oddEvenList(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_head = even;

        while (even != NULL && even->next != NULL)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = even_head;

        return head;
    }
};

void printList(ListNode* head)
{
    while (head != NULL)
    {
        cout << head->val;

        if (head->next != NULL)
        {
            cout << " -> ";
        }

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
        cout << "Linked List is empty." << endl;
        return 0;
    }

    int value;

    cout << "Enter node values: ";
    cin >> value;

    ListNode* head = new ListNode(value);
    ListNode* temp = head;

    for (int i = 1; i < n; i++)
    {
        cin >> value;
        temp->next = new ListNode(value);
        temp = temp->next;
    }

    Solution obj;

    head = obj.oddEvenList(head);

    cout << "Reordered Linked List: ";
    printList(head);

    return 0;
}