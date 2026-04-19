// LeetCode 1855: Maximum Distance Between a Pair of Values
// Approach: Two Pointer
// Time: O(n + m)
// Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) 
    {
        int i = 0, j = 0;
        int max_distance = 0;

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] <= nums2[j])
            {
                max_distance = max(max_distance, j - i);
                j++;  // expand
            }
            else
            {
                i++;  // fix condition

                if (i > j) j = i; // maintain i <= j
            }
        }

        return max_distance;
    }
};

int main()
{
    Solution obj;

    int n, m;
    cout << "Enter size of nums1: ";
    cin >> n;

    vector<int> nums1(n);
    cout << "Enter elements of nums1 (non-increasing): ";
    for (int i = 0; i < n; i++)
        cin >> nums1[i];

    cout << "Enter size of nums2: ";
    cin >> m;

    vector<int> nums2(m);
    cout << "Enter elements of nums2 (non-increasing): ";
    for (int i = 0; i < m; i++)
        cin >> nums2[i];

    int result = obj.maxDistance(nums1, nums2);

    cout << "Maximum Distance: " << result << endl;

    return 0;
}