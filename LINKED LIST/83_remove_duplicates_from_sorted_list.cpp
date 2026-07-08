// LeetCode 83: Remove Duplicates from Sorted List
// Approach: Single Traversal
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* temp = head;

        while (temp->next != NULL)
        {
            int prev = temp->val;

            if (prev == temp->next->val)
            {
                if (temp->next->next)
                {
                    temp->next = temp->next->next;
                    continue;
                }

                temp->next = NULL;
                continue;
            }

            temp = temp->next;
        }

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

    head = obj.deleteDuplicates(head);

    cout << "Updated Linked List: ";
    printList(head);

    return 0;
}