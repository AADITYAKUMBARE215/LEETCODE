// LeetCode 31: Next Permutation
// Approach: Lexicographical Permutation
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int index = -1;
        int n = nums.size();

        if (n <= 1) return;

        // Step 1: Find breakpoint
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                index = i;
                break;
            }
        }

        // Step 2: If no breakpoint, reverse whole array
        if (index == -1)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            // Step 3: Find next greater element
            for (int i = n - 1; i > index; i--)
            {
                if (nums[i] > nums[index])
                {
                    swap(nums[i], nums[index]);
                    break;
                }
            }

            // Step 4: Reverse suffix
            reverse(nums.begin() + index + 1, nums.end());
        }
    }
};

int main()
{
    Solution obj;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    obj.nextPermutation(nums);

    cout << "Next Permutation: ";

    for (int x : nums)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}