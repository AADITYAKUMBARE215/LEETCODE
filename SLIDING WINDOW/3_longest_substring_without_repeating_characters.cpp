// LeetCode 3: Longest Substring Without Repeating Characters
// Approach: Sliding Window + Last Seen Index
// Time: O(n)
// Space: O(256)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> lastSeen(256, -1);

        int maxLen = 0;
        int n = s.size();

        int left = 0;
        int right = 0;

        while (right < n)
        {
            if (lastSeen[s[right]] != -1)
            {
                if (lastSeen[s[right]] >= left)
                {
                    left = lastSeen[s[right]] + 1;
                }
            }

            int len = right - left + 1;
            maxLen = max(maxLen, len);

            lastSeen[s[right]] = right;
            right++;
        }

        return maxLen;
    }
};

int main()
{
    Solution obj;

    string s;

    cout << "Enter string: ";
    getline(cin, s);

    cout << "Length of Longest Substring Without Repeating Characters: "
         << obj.lengthOfLongestSubstring(s) << endl;

    return 0;
}