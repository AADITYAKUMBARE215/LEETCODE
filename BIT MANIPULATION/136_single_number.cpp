// LeetCode 136: Single Number
// Approach: Bit Manipulation (XOR)
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int ans = 0;

        for (int val : nums)
        {
            ans ^= val;
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

    int result = obj.singleNumber(nums);

    cout << "Single Number: " << result << endl;

    return 0;
}