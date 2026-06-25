// LeetCode 169: Majority Element
// Approach: Moore's Voting Algorithm
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int freq = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (freq == 0)
            {
                ans = nums[i];
            }

            if (ans == nums[i])
            {
                freq++;
            }
            else
            {
                freq--;
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

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int result = obj.majorityElement(nums);

    cout << "Majority Element: " << result << endl;

    return 0;
}