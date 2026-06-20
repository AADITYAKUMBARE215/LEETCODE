// LeetCode 81: Search in Rotated Sorted Array II
// Approach: Modified Binary Search with Duplicates
// Time: O(log n) Average, O(n) Worst Case
// Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return true;

            // Handle duplicates
            if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
                continue;
            }

            // Left half is sorted
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else
            {
                if (nums[mid] <= target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return false;
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

    int target;

    cout << "Enter target element: ";
    cin >> target;

    bool result = obj.search(nums, target);

    cout << "Target Found: " << (result ? "true" : "false") << endl;

    return 0;
}