// LeetCode 13: Roman to Integer
// Approach: Traverse and Handle Subtractive Notation
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int value(char ch)
    {
        if (ch == 'I') return 1;
        if (ch == 'V') return 5;
        if (ch == 'X') return 10;
        if (ch == 'L') return 50;
        if (ch == 'C') return 100;
        if (ch == 'D') return 500;
        return 1000;
    }

    int romanToInt(string s)
    {
        int ans = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (i + 1 < s.length() && value(s[i]) < value(s[i + 1]))
                ans -= value(s[i]);
            else
                ans += value(s[i]);
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    string s;

    cout << "Enter Roman Numeral: ";
    cin >> s;

    cout << "Integer Value: " << obj.romanToInt(s) << endl;

    return 0;
}