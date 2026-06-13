// LeetCode 18: 4Sum
// Approach: Sorting + Two Pointers
// Time: O(n³)
// Space: O(1) (excluding output)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++)
        {
            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++)
            {
                // Skip duplicate second elements
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int k = j + 1;
                int l = n - 1;

                while (k < l)
                {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);

                        k++;
                        l--;

                        while (k < l && nums[k] == nums[k - 1])
                            k++;

                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum < target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
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

    int target;
    cout << "Enter target value: ";
    cin >> target;

    vector<vector<int>> result = obj.fourSum(nums, target);

    cout << "Quadruplets with sum " << target << ":" << endl;

    if (result.empty())
    {
        cout << "No quadruplets found." << endl;
    }
    else
    {
        for (auto quad : result)
        {
            cout << "[";

            for (int i = 0; i < quad.size(); i++)
            {
                cout << quad[i];

                if (i != quad.size() - 1)
                    cout << ", ";
            }

            cout << "]" << endl;
        }
    }

    return 0;
}