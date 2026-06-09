// LeetCode 560: Subarray Sum Equals K
// Approach: Prefix Sum + Hash Map
// Time: O(n)
// Space: O(n)

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        map<int, int> mpp;
        mpp[0] = 1;

        int presum = 0, count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            presum += nums[i];

            int remove = presum - k;

            count += mpp[remove];

            mpp[presum] += 1;
        }

        return count;
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

    int k;
    cout << "Enter value of k: ";
    cin >> k;

    int result = obj.subarraySum(nums, k);

    cout << "Number of subarrays with sum " << k << ": " << result << endl;

    return 0;
}