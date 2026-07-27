// LeetCode 1248: Count Number of Nice Subarrays
// Approach: Sliding Window + Prefix Count
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int>& nums, int k)
    {
        int left = 0;
        int odd = 0;
        int prefix = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] % 2)
            {
                odd++;
                prefix = 0;
            }

            while (odd == k)
            {
                prefix++;

                if (nums[left] % 2)
                    odd--;

                left++;
            }

            ans += prefix;
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    cout << "Number of Nice Subarrays: "
         << obj.numberOfSubarrays(nums, k) << endl;

    return 0;
}