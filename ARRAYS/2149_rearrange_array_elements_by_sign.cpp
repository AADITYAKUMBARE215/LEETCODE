// LeetCode 2149: Rearrange Array Elements by Sign
// Approach: Alternate Index Placement
// Time: O(n)
// Space: O(n)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums)
    {
        int pos = 0;
        int neg = 1;

        vector<int> final(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                final[pos] = nums[i];
                pos += 2;
            }
            else
            {
                final[neg] = nums[i];
                neg += 2;
            }
        }

        return final;
    }
};

int main()
{
    Solution obj;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> result = obj.rearrangeArray(nums);

    cout << "Rearranged Array: ";

    for (int x : result)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}