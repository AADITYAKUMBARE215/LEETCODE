// LeetCode 15: 3Sum
// Approach: Sorting + Two Pointers
// Time: O(n²)
// Space: O(1) (excluding output)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> final;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0)
                {
                    while (j < k && nums[j] == nums[j + 1])
                        j++;

                    j++;
                }
                else if (sum > 0)
                {
                    while (j < k && nums[k] == nums[k - 1])
                        k--;

                    k--;
                }
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    final.push_back(temp);

                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1])
                        j++;

                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
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

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<vector<int>> result = obj.threeSum(nums);

    cout << "Triplets with sum 0:" << endl;

    if (result.empty())
    {
        cout << "No triplets found." << endl;
    }
    else
    {
        for (auto triplet : result)
        {
            cout << "[";
            for (int i = 0; i < triplet.size(); i++)
            {
                cout << triplet[i];

                if (i != triplet.size() - 1)
                    cout << ", ";
            }
            cout << "]" << endl;
        }
    }

    return 0;
}