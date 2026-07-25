// LeetCode 1004: Max Consecutive Ones III
// Approach: Sliding Window
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int n = nums.size();
        int zeros = 0;
        int maxLen = 0;

        int left = 0;
        int right = 0;

        while (right < n)
        {
            if (nums[right] == 0)
            {
                zeros++;
            }

            if (zeros <= k)
            {
                int len = right - left + 1;
                maxLen = max(maxLen, len);
            }

            if (zeros > k)
            {
                while (nums[left] != 0 && left < n)
                {
                    left++;
                }

                left++;
                zeros--;
            }

            right++;
        }

        return maxLen;
    }
};

int main()
{
    Solution obj;

    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter binary array: ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    cout << "Maximum Consecutive Ones: "
         << obj.longestOnes(nums, k) << endl;

    return 0;
}