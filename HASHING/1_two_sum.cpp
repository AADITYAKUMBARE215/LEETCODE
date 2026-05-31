// LeetCode 1: Two Sum
// Approach: Hashing
// Time: O(n log n) using map
// Space: O(n)

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        map<int, int> mpp;

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            int more = target - num;

            if (mpp.find(more) != mpp.end())
            {
                return {mpp[more], i};
            }

            mpp[num] = i;
        }

        return {-1, -1};
    }
};

int main()
{
    Solution obj;

    int n, target;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter target: ";
    cin >> target;

    vector<int> result = obj.twoSum(nums, target);

    cout << "Indices: ";

    for (int x : result)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}