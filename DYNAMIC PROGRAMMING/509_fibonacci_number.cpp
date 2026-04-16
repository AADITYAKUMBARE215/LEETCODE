// LeetCode 509: Fibonacci Number
// Approach: Iterative (Bottom-Up DP)
// Time: O(n)
// Space: O(1)

#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) 
    {
        if (n <= 1) return n;

        int prev2 = 0; // F(0)
        int prev1 = 1; // F(1)

        for (int i = 2; i <= n; i++)
        {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main()
{
    Solution obj;

    int n;
    cout << "Enter n ('n' must be greater than 1): ";
    cin >> n;

    int result = obj.fib(n);
    cout << "Fibonacci of " << n << " is: " << result << endl;

    return 0;
}