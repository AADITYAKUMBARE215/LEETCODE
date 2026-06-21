// LeetCode 153: Find Minimum in Rotated Sorted Array
// Approach: Binary Search
// Time: O(log n)
// Space: O(1)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& arr)
    {
        int low = 0;
        int high = arr.size() - 1;
        int ans = INT_MAX;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // Entire search space is sorted
            if (arr[low] <= arr[high])
            {
                ans = min(ans, arr[low]);
                break;
            }

            // Left half is sorted
            if (arr[low] <= arr[mid])
            {
                ans = min(ans, arr[low]);
                low = mid + 1;
            }
            // Right half is sorted
            else
            {
                ans = min(ans, arr[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter rotated sorted array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int result = obj.findMin(nums);

    cout << "Minimum Element: " << result << endl;

    return 0;
}