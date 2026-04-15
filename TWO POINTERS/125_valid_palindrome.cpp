// LeetCode 125: Valid Palindrome
// Approach: Two Pointers + Skip Non-Alphanumeric + Case Normalization
// Time: O(n), Space: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) 
    {
        int left = 0;
        int right = s.length() - 1;

        while (left < right)
        {
            if (!isalnum((unsigned char)s[left])) 
            {
                left++;
                continue;
            }
            if (!isalnum((unsigned char)s[right])) 
            {
                right--;
                continue;
            }
            if (tolower((unsigned char)s[left]) != tolower((unsigned char)s[right])) 
                return false;

            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution obj;
    string s = "A man, a plan, a canal: Panama";
    cout << (obj.isPalindrome(s) ? "true" : "false");
    return 0;
}