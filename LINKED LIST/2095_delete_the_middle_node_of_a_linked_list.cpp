// LeetCode 2095: Delete the Middle Node of a Linked List
// Approach: Fast & Slow Pointer
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
    ListNode* deleteMiddle(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete del;

        return head;
    }
};

void printList(ListNode* head)
{
    while (head != NULL)
    {
        cout << head->val;

        if (head->next != NULL)
            cout << " -> ";

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

    head = obj.deleteMiddle(head);

    cout << "Updated Linked List: ";
    printList(head);

    return 0;
}