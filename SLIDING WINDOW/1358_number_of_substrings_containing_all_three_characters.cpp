// LeetCode 1358: Number of Substrings Containing All Three Characters
// Approach: Last Seen Indices
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int ans = 0;
        int n = s.length();

        int a = -1;
        int b = -1;
        int c = -1;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
                a = i;
            else if (s[i] == 'b')
                b = i;
            else
                c = i;

            if (a != -1 && b != -1 && c != -1)
            {
                int last = min(min(a, b), c);
                ans += last + 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Number of Valid Substrings: "
         << obj.numberOfSubstrings(s) << endl;

    return 0;
}