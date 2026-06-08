// LeetCode 2161: Partition Array According to Given Pivot
// Approach: Stable Partitioning
// Time: O(n)
// Space: O(n)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot)
    {
        int n = nums.size();
        int count = 0;

        vector<int> final;
        final.reserve(n);

        // Elements smaller than pivot
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < pivot)
            {
                final.push_back(nums[i]);
            }

            if (nums[i] == pivot)
            {
                count++;
            }
        }

        // Pivot elements
        while (count--)
        {
            final.push_back(pivot);
        }

        // Elements greater than pivot
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > pivot)
            {
                final.push_back(nums[i]);
            }
        }

        return final;
    }
};

int main()
{
    Solution obj;

    int n, pivot;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter pivot: ";
    cin >> pivot;

    vector<int> result = obj.pivotArray(nums, pivot);

    cout << "Partitioned Array: ";

    for (int x : result)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}