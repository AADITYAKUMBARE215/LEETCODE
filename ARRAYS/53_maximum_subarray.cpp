// LeetCode 53: Maximum Subarray
// Approach: Kadane's Algorithm
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int cs = 0;
        int ms = INT_MIN;

        for (int var : nums)
        {
            cs += var;

            ms = max(ms, cs);

            if (cs < 0)
            {
                cs = 0;
            }
        }

        return ms;
    }
};

int main()
{
    Solution obj;

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int result = obj.maxSubArray(nums);

    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}