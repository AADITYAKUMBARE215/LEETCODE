// LeetCode 35: Search Insert Position
// Approach: Binary Search (Lower Bound)
// Time: O(log n)
// Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int ans = nums.size();

        int low = 0;
        int high = ans - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
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

    int result = obj.searchInsert(nums, target);

    cout << "Search Insert Position: " << result << endl;

    return 0;
}