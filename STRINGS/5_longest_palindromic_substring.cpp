// LeetCode 5: Longest Palindromic Substring
// Approach: Expand Around Center
// Time: O(n²)
// Space: O(1)

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();

        if (n == 0)
        {
            return "";
        }

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++)
        {
            // Odd length palindrome
            int left = i;
            int right = i;

            while (left >= 0 && right < n && s[left] == s[right])
            {
                int len = right - left + 1;

                if (len > maxLen)
                {
                    maxLen = len;
                    start = left;
                }

                left--;
                right++;
            }

            // Even length palindrome
            left = i;
            right = i + 1;

            while (left >= 0 && right < n && s[left] == s[right])
            {
                int len = right - left + 1;

                if (len > maxLen)
                {
                    maxLen = len;
                    start = left;
                }

                left--;
                right++;
            }
        }

        return s.substr(start, maxLen);
    }
};

int main()
{
    Solution obj;

    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Longest Palindromic Substring: " << obj.longestPalindrome(s) << endl;

    return 0;
}