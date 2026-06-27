// LeetCode 238: Product of Array Except Self
// Approach: Prefix and Suffix Products
// Time: O(n)
// Space: O(1) Extra Space (excluding output array)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> ans(n, 1);

        // Prefix products
        for (int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Suffix products
        int suffix = 1;

        for (int i = n - 2; i >= 0; i--)
        {
            suffix *= nums[i + 1];
            ans[i] *= suffix;
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

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> result = obj.productExceptSelf(nums);

    cout << "Product Except Self: ";

    for (int val : result)
    {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}
