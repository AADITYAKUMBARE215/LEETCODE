// LeetCode 1614: Maximum Nesting Depth of the Parentheses
// Approach: Depth Counter
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int count = 0;
        int maxi = 0;

        for (char ch : s)
        {
            if (ch == '(')
            {
                count++;
                maxi = max(maxi, count);
            }
            else if (ch == ')')
            {
                count--;
            }
        }

        return maxi;
    }
};

int main()
{
    Solution obj;

    string s;

    cout << "Enter expression: ";
    getline(cin, s);

    cout << "Maximum Nesting Depth: " << obj.maxDepth(s) << endl;

    return 0;
}