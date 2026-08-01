// LeetCode 76: Minimum Window Substring
// Approach: Sliding Window + Frequency Array
// Time: O(m + n)
// Space: O(256)

#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int m = s.length();
        int n = t.length();

        int hash[256] = {0};

        int count = 0;
        int left = 0;
        int right = 0;

        int minLen = INT_MAX;
        int startIndex = -1;

        for (int i = 0; i < n; i++)
        {
            hash[t[i]]++;
        }

        while (right < m)
        {
            if (hash[s[right]] > 0)
            {
                count++;
            }

            hash[s[right]]--;

            while (count == n)
            {
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    startIndex = left;
                }

                hash[s[left]]++;

                if (hash[s[left]] > 0)
                {
                    count--;
                }

                left++;
            }

            right++;
        }

        return (startIndex == -1) ? "" : s.substr(startIndex, minLen);
    }
};

int main()
{
    Solution obj;

    string s, t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    cout << "Minimum Window Substring: "
         << obj.minWindow(s, t) << endl;

    return 0;
}