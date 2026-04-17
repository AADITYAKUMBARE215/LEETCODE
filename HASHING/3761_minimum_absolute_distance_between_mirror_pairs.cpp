// LeetCode 3761: Minimum Absolute Distance Between Mirror Pairs
// Approach: Hashing + Reverse Integer
// Time: O(n * d)  (d = digits in number)
// Space: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x)
    {
        int rev = 0;
        while (x != 0)
        {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        int min_distance = INT_MAX;

        for (int j = 0; j < nums.size(); j++)
        {
            if (mp.find(nums[j]) != mp.end()) // finds mp[nums[j]] without creation in unoedered_map
            {
                min_distance = min(min_distance, j - mp[nums[j]]);
            }
            mp[reverse(nums[j])] = j;
        }

        return (min_distance == INT_MAX) ? -1 : min_distance;
    }
};

int main()
{
    Solution obj;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int result = obj.minMirrorPairDistance(nums);

    cout << "Minimum Mirror Pair Distance: " << result << endl;

    return 0;
}