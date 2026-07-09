// LeetCode 225: Implement Stack using Queues
// Approach: Two Queues
// Time:
// Push: O(n)
// Pop: O(1)
// Top: O(1)
// Empty: O(1)
// Space: O(n)

#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
public:
    queue<int> q1, q2;

    MyStack()
    {

    }

    void push(int x)
    {
        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    int pop()
    {
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    MyStack st;

    int n;

    cout << "Enter number of elements to push: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }

    cout << "Top Element: " << st.top() << endl;

    cout << "Popped Element: " << st.pop() << endl;

    if (!st.empty())
        cout << "Top After Pop: " << st.top() << endl;
    else
        cout << "Stack is empty." << endl;

    cout << "Is Stack Empty? " << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}