// LeetCode 34: Find First and Last Position of Element in Sorted Array
// Approach: Binary Search (First and Last Occurrence)
// Time: O(log n)
// Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> ans(2, -1);

        int low = 0;
        int high = nums.size() - 1;

        // Find first occurrence
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                ans[0] = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        low = 0;
        high = nums.size() - 1;

        // Find last occurrence
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                ans[1] = mid;
                low = mid + 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
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

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int target;

    cout << "Enter target element: ";
    cin >> target;

    vector<int> result = obj.searchRange(nums, target);

    cout << "First and Last Position: ["
         << result[0] << ", "
         << result[1] << "]" << endl;

    return 0;
}