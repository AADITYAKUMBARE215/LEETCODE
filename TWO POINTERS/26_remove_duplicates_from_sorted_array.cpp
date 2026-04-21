// LeetCode 26: Remove Duplicates from Sorted Array
// Approach: Two Pointer (in-place)
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = nums.size();
        int j = 0;

        for (int i = 1; i < k; i++) 
        {
            if (nums[i] != nums[j]) 
            {
                nums[++j] = nums[i];
            } 
        }
        return j + 1;
    }
};

int main()
{
    Solution obj;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k = obj.removeDuplicates(nums);

    cout << "Number of unique elements: " << k << endl;
    cout << "Array after removing duplicates: ";

    for (int i = 0; i < k; i++)
        cout << nums[i] << " ";

    cout << endl;

    return 0;
}