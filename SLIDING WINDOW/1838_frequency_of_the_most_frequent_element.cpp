// LeetCode 1838: Frequency of the Most Frequent Element
// Approach: Sliding Window + Sorting
// Time: O(n log n)
// Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());

        long long sum = 0;
        int max_freq = 0;
        int l = 0; // l -> left 

        for (int r = 0; r < nums.size(); r++) // r -> right
        {
            sum += nums[r];
            // imagine (long long)nums[r] * (r - l + 1) as a cuboid
            while ((long long)nums[r] * (r - l + 1) - sum > k) // (r-l+1) = sliding window
            {
                sum -= nums[l];
                l++;
            }

            max_freq = max(max_freq, r - l + 1);
        }
        return max_freq;
    }
};

int main()
{
    Solution obj;

    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter k: ";
    cin >> k;

    int result = obj.maxFrequency(nums, k);

    cout << "Maximum Frequency: " << result << endl;

    return 0;
}