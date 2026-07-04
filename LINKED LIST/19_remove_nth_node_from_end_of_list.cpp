// LeetCode 19: Remove Nth Node From End of List
// Approach: Two Pointers (One Pass)
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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while (n != 0)
        {
            fast = fast->next;
            n--;
        }

        // Handle deletion of head node
        if (fast == NULL)
        {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
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

    int removeNode;
    cout << "Enter N (Nth node from end to remove): ";
    cin >> removeNode;

    Solution obj;
    head = obj.removeNthFromEnd(head, removeNode);

    cout << "Updated Linked List: ";
    printList(head);

    return 0;
}