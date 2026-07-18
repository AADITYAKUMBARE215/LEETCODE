// LeetCode 242: Valid Anagram
// Approach: Frequency Array
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        int freq[26] = {0};

        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }

        for (int i = 0; i < t.length(); i++)
        {
            freq[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != 0)
                return false;
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

    if (obj.isAnagram(s, t))
        cout << "Strings are Anagrams." << endl;
    else
        cout << "Strings are Not Anagrams." << endl;

    return 0;
}
