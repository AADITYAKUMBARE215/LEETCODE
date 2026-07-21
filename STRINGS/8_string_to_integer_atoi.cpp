// LeetCode 8: String to Integer (atoi)
// Approach: Simulation
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <string>
#include <climits>
#include <cctype>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0;
        int n = s.length();

        // Skip leading spaces
        while (i < n && s[i] == ' ')
        {
            i++;
        }

        // Determine sign
        int sign = 1;

        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            if (s[i] == '-')
            {
                sign = -1;
            }
            i++;
        }

        long long num = 0;

        // Convert digits
        while (i < n && isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');

            // Handle overflow
            if (sign == 1 && num > INT_MAX)
            {
                return INT_MAX;
            }

            if (sign == -1 && -num < INT_MIN)
            {
                return INT_MIN;
            }

            i++;
        }

        return sign * num;
    }
};

int main()
{
    Solution obj;

    string s;

    cout << "Enter string: ";
    getline(cin, s);

    cout << "Integer Value: " << obj.myAtoi(s) << endl;

    return 0;
}