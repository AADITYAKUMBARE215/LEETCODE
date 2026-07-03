// LeetCode 142: Linked List Cycle II
// Approach: Floyd's Cycle Detection Algorithm
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
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                slow = head;

                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return NULL;
    }
};

int main()
{
    // Creating linked list: 3 -> 2 -> 0 -> -4
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    int pos;

    cout << "Enter position to create cycle (-1 for no cycle): ";
    cin >> pos;

    if (pos != -1)
    {
        ListNode* tail = head;
        ListNode* cycleNode = NULL;
        int index = 0;

        while (tail->next != NULL)
        {
            if (index == pos)
            {
                cycleNode = tail;
            }

            tail = tail->next;
            index++;
        }

        if (index == pos)
        {
            cycleNode = tail;
        }

        tail->next = cycleNode;
    }

    Solution obj;

    ListNode* result = obj.detectCycle(head);

    if (result != NULL)
    {
        cout << "Cycle starts at node with value: " << result->val << endl;
    }
    else
    {
        cout << "No cycle detected." << endl;
    }

    return 0;
}