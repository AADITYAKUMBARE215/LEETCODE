// LeetCode 1021: Remove Outermost Parentheses
// Approach: Depth Counter
// Time: O(n)
// Space: O(n)

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string ans = "";
        int depth = 0;

        for (char ch : s)
        {
            if (ch == '(')
            {
                if (depth > 0)
                    ans += ch;

                depth++;
            }
            else
            {
                depth--;

                if (depth > 0)
                    ans += ch;
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    string s;

    cout << "Enter parentheses string: ";
    cin >> s;

    cout << "Result: " << obj.removeOuterParentheses(s) << endl;

    return 0;
}