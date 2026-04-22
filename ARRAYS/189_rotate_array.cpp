// LeetCode 189: Rotate Array
// Approach: Reverse Technique (In-place)
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        if (n == 0) return;

        k = k % n;  // handle large k

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main()
{
    Solution obj;

    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter k: ";
    cin >> k;

    obj.rotate(nums, k);

    cout << "Rotated array: ";
    for (int x : nums)
        cout << x << " ";

    cout << endl;

    return 0;
}