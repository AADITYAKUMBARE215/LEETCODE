// LeetCode 704: Binary Search
// Approach: Iterative Binary Search
// Time: O(log n)
// Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            if (target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        return -1;
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

    int result = obj.search(nums, target);

    cout << "Target Index: " << result << endl;

    return 0;
}