// LeetCode 232: Implement Queue using Stacks
// Approach: Two Stacks
// Time:
// Push: O(1)
// Pop: Amortized O(1)
// Peek: Amortized O(1)
// Empty: O(1)
// Space: O(n)

#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
    stack<int> s1, s2;

    MyQueue()
    {

    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int x = s2.top();
        s2.pop();

        return x;
    }

    int peek()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

int main()
{
    MyQueue q;

    int n;

    cout << "Enter number of elements to push: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    cout << "Front Element: " << q.peek() << endl;

    cout << "Popped Element: " << q.pop() << endl;

    if (!q.empty())
        cout << "Front After Pop: " << q.peek() << endl;
    else
        cout << "Queue is empty." << endl;

    cout << "Is Queue Empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}