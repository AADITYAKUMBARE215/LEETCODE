// LeetCode 3536: Maximum Product of Two Digits
// Approach: Find the two largest digits
// Time: O(log10(n))
// Space: O(1)

#include <iostream>
using namespace std;

class Solution
{
public:
    int maxProduct(int n)
    {
        int max1 = -1;
        int max2 = -1;

        while (n != 0)
        {
            int digit = n % 10;
            n /= 10;

            if (digit > max1)
            {
                max2 = max1;
                max1 = digit;
            }
            else if (digit > max2)
            {
                max2 = digit;
            }
        }

        return max1 * max2;
    }
};

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    Solution obj;

    cout << "Maximum Product: " << obj.maxProduct(n) << endl;

    return 0;
}