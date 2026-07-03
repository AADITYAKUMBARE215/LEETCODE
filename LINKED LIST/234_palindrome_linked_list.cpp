// LeetCode 234: Palindrome Linked List
// Approach: Reverse Second Half of Linked List
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
    ListNode* reverse_ll(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* new_head = reverse_ll(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return new_head;
    }

    bool isPalindrome(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* new_head = reverse_ll(slow->next);

        ListNode* first = head;
        ListNode* second = new_head;

        while (second != NULL)
        {
            if (first->val != second->val)
            {
                reverse_ll(new_head);
                return false;
            }

            first = first->next;
            second = second->next;
        }

        reverse_ll(new_head);

        return true;
    }
};

int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n == 0)
    {
        cout << "Is Palindrome: false" << endl;
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

    bool result = obj.isPalindrome(head);

    cout << "Is Palindrome: " << (result ? "true" : "false") << endl;

    return 0;
}