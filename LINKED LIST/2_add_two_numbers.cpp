// LeetCode 2: Add Two Numbers
// Approach: Digit-by-Digit Addition with Carry
// Time: O(max(m, n))
// Space: O(max(m, n))

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int x = 0)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;

        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry)
        {
            int sum = 0;

            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum / 10;

            ListNode* node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }

        ListNode* head = dummy->next;
        delete dummy;

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

ListNode* createList(int n)
{
    if (n == 0)
        return NULL;

    int value;
    cin >> value;

    ListNode* head = new ListNode(value);
    ListNode* temp = head;

    for (int i = 1; i < n; i++)
    {
        cin >> value;
        temp->next = new ListNode(value);
        temp = temp->next;
    }

    return head;
}

int main()
{
    int n1, n2;

    cout << "Enter number of nodes in first linked list: ";
    cin >> n1;

    cout << "Enter first linked list values: ";
    ListNode* l1 = createList(n1);

    cout << "Enter number of nodes in second linked list: ";
    cin >> n2;

    cout << "Enter second linked list values: ";
    ListNode* l2 = createList(n2);

    Solution obj;

    ListNode* result = obj.addTwoNumbers(l1, l2);

    cout << "Sum Linked List: ";
    printList(result);

    return 0;
}