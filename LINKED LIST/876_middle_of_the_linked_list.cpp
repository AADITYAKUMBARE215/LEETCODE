// LeetCode 876: Middle of the Linked List
// Approach: Slow and Fast Pointers
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
    ListNode* middleNode(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
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

    if (n <= 0)
        return 0;

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

    ListNode* middle = obj.middleNode(head);

    cout << "Middle Node onwards: ";
    printList(middle);

    return 0;
}