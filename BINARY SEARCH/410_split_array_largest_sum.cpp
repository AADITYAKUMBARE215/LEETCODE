// LeetCode 410: Split Array Largest Sum
// Approach: Binary Search on Answer
// Time: O(n * log(sum(nums)))
// Space: O(1)

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int condition(vector<int>& nums, int mid)
    {
        int count = 1;
        int tot = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (tot + nums[i] > mid)
            {
                count++;
                tot = nums[i];
            }
            else
            {
                tot += nums[i];
            }
        }

        return count;
    }

    int splitArray(vector<int>& nums, int k)
    {
        int maxi = INT_MIN;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            maxi = max(maxi, nums[i]);
            sum += nums[i];
        }

        int low = maxi;
        int high = sum;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (condition(nums, mid) <= k)
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

    int k;

    cout << "Enter number of subarrays (k): ";
    cin >> k;

    int result = obj.splitArray(nums, k);

    cout << "Minimum Largest Sum: " << result << endl;

    return 0;
}