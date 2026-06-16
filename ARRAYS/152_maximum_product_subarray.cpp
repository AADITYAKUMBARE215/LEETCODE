// LeetCode 152: Maximum Product Subarray
// Approach: Prefix and Suffix Product Traversal
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int maxx = INT_MIN;
        int prod = 1;

        // Prefix traversal
        for (int i = 0; i < nums.size(); i++)
        {
            prod = prod * nums[i];

            maxx = max(maxx, prod);

            if (nums[i] == 0)
            {
                prod = 1;
            }
        }

        // Suffix traversal
        prod = 1;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            prod = prod * nums[i];

            maxx = max(maxx, prod);

            if (nums[i] == 0)
            {
                prod = 1;
            }
        }

        return maxx;
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

    int result = obj.maxProduct(nums);

    cout << "Maximum Product Subarray: " << result << endl;

    return 0;
}