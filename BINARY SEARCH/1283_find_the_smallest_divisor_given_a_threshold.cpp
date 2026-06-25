// LeetCode 1283: Find the Smallest Divisor Given a Threshold
// Approach: Binary Search on Answer
// Time: O(n * log(max(nums)))
// Space: O(1)

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold)
    {
        int low = 1;
        int high = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            high = max(high, nums[i]);
        }

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int sum = 0;

            for (int i = 0; i < nums.size(); i++)
            {
                sum += (nums[i] + mid - 1) / mid;
            }

            if (sum <= threshold)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
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

    int threshold;

    cout << "Enter threshold: ";
    cin >> threshold;

    int result = obj.smallestDivisor(nums, threshold);

    cout << "Smallest Divisor: " << result << endl;

    return 0;
}