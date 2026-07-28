// LeetCode 930: Binary Subarrays With Sum
// Approach: Sliding Window (At Most K)
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int atMost(vector<int>& nums, int goal)
    {
        if (goal < 0)
            return 0;

        int left = 0;
        int sum = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];

            while (sum > goal)
            {
                sum -= nums[left];
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};

int main()
{
    Solution obj;

    int n, goal;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter binary array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter goal: ";
    cin >> goal;

    cout << "Number of Binary Subarrays With Sum = "
         << obj.numSubarraysWithSum(nums, goal) << endl;

    return 0;
}