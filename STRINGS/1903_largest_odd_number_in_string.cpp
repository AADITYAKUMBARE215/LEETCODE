// LeetCode 1903: Largest Odd Number in String
// Approach: Reverse Traversal
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string largestOddNumber(string num)
    {
        string result = "";

        for (int i = num.size() - 1; i >= 0; i--)
        {
            if ((num[i] - '0') % 2 != 0)
            {
                result = num.substr(0, i + 1);
                break;
            }
        }

        return result;
    }
};

int main()
{
    Solution obj;

    string num;

    cout << "Enter number: ";
    cin >> num;

    cout << "Largest Odd Number: " << obj.largestOddNumber(num) << endl;

    return 0;
}