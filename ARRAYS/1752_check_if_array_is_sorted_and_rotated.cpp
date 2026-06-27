// LeetCode 1752: Check if Array Is Sorted and Rotated
// Approach: Count Rotation Break Points
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums)
    {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > nums[(i + 1) % n])
            {
                count++;
            }
        }

        return count <= 1;
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

    bool result = obj.check(nums);

    cout << "Is Sorted and Rotated: " << (result ? "true" : "false") << endl;

    return 0;
}