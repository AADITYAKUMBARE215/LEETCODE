// LeetCode 205: Isomorphic Strings
// Approach: Last Seen Position Mapping
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int m1[256] = {0};
        int m2[256] = {0};

        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (m1[s[i]] != m2[t[i]])
                return false;

            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }

        return true;
    }
};

int main()
{
    Solution obj;

    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if (obj.isIsomorphic(s, t))
        cout << "Strings are Isomorphic." << endl;
    else
        cout << "Strings are Not Isomorphic." << endl;

    return 0;
}