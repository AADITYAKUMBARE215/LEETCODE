// LeetCode 20: Valid Parentheses
// Approach: Stack
// Time: O(n)
// Space: O(n)

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                    return false;

                if ((c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '['))
                {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};

int main()
{
    Solution obj;

    string s;

    cout << "Enter parentheses string: ";
    cin >> s;

    if (obj.isValid(s))
        cout << "Valid Parentheses" << endl;
    else
        cout << "Invalid Parentheses" << endl;

    return 0;
}