// LeetCode 3783: Mirror Distance of an Integer
// Approach: Math (Number Reversal)
// Time: O(d)  (d = number of digits)
// Space: O(1)

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int mirrorDistance(int n) 
    {
        int original = n;
        int reversed_number = 0;

        while (n != 0)
        {
            reversed_number = (reversed_number * 10) + (n % 10);
            n /= 10;
        }

        return abs(original - reversed_number);
    }
};

int main()
{
    Solution obj;

    int n;
    cout << "Enter number: ";
    cin >> n;

    int result = obj.mirrorDistance(n);

    cout << "Mirror Distance: " << result << endl;

    return 0;
}