// LeetCode 237: Delete Node in a Linked List
// Approach: Copy Next Node's Data
// Time: O(1)
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
    void deleteNode(ListNode* node)
    {
        node->val = node->next->val;

        ListNode* temp = node->next;
        node->next = node->next->next;

        delete temp;
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
    // Creating linked list: 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Original Linked List: ";
    printList(head);

    Solution obj;

    // Delete node with value 5
    obj.deleteNode(head->next);

    cout << "After Deletion: ";
    printList(head);

    return 0;
}