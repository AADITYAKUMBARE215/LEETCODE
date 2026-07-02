// LeetCode 141: Linked List Cycle
// Approach: Floyd's Cycle Detection (Tortoise and Hare)
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
    bool hasCycle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
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

    bool result = obj.hasCycle(head);

    cout << "Cycle Present: " << (result ? "true" : "false") << endl;

    return 0;
}