// LeetCode 155: Min Stack
// Approach: Stack with Encoding Technique
// Time:
// Push: O(1)
// Pop: O(1)
// Top: O(1)
// GetMin: O(1)
// Space: O(n)

#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack
{
public:
    stack<long long> st;
    long long mini;

    MinStack()
    {
        mini = INT_MAX;
    }

    void push(int val)
    {
        if (st.empty())
        {
            mini = val;
            st.push(val);
        }
        else
        {
            if (val >= mini)
            {
                st.push(val);
            }
            else
            {
                st.push(2LL * val - mini);
                mini = val;
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return;

        long long x = st.top();
        st.pop();

        if (x < mini)
        {
            mini = 2 * mini - x;
        }
    }

    int top()
    {
        if (st.empty())
            return -1;

        long long x = st.top();

        if (x >= mini)
            return x;

        return mini;
    }

    int getMin()
    {
        return mini;
    }
};

int main()
{
    MinStack st;

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

    cout << "Current Top: " << st.top() << endl;
    cout << "Current Minimum: " << st.getMin() << endl;

    st.pop();

    cout << "\nAfter one pop:" << endl;

    if (!st.st.empty())
    {
        cout << "Top: " << st.top() << endl;
        cout << "Minimum: " << st.getMin() << endl;
    }
    else
    {
        cout << "Stack is empty." << endl;
    }

    return 0;
}