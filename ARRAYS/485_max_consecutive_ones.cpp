// LeetCode 485: Max Consecutive Ones
// Approach: Array Traversal (Counting)
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int count = 0;
        int maximum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                count++;
                maximum = max(maximum, count);
            }
            else
            {
                count = 0;
            }
        }

        return maximum;
    }
};

int main()
{
    Solution obj;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter binary elements (0/1): ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int result = obj.findMaxConsecutiveOnes(nums);

    cout << "Maximum consecutive ones: " << result << endl;

    return 0;
}