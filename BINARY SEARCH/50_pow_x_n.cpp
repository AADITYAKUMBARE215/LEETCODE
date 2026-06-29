// LeetCode 50: Pow(x, n)
// Approach: Binary Exponentiation
// Time: O(log n)
// Space: O(1)

#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n)
    {
        // Edge Cases
        if (n == 0) return 1.0;
        if (x == 0) return 0.0;
        if (x == 1) return 1.0;
        if (x == -1 && n % 2 == 0) return 1.0;
        if (x == -1 && n % 2 != 0) return -1.0;

        long long binform = n;

        if (binform < 0)
        {
            binform = -binform;
            x = 1 / x;
        }

        double ans = 1.0;

        while (binform > 0)
        {
            if (binform % 2 == 1)
            {
                ans *= x;
            }

            x *= x;
            binform /= 2;
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    double x;
    int n;

    cout << "Enter base (x): ";
    cin >> x;

    cout << "Enter exponent (n): ";
    cin >> n;

    double result = obj.myPow(x, n);

    cout << "Result: " << result << endl;

    return 0;
}