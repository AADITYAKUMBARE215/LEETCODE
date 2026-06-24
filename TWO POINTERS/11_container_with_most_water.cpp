// LeetCode 11: Container With Most Water
// Approach: Two Pointers
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int maxwater = 0;

        int lp = 0;
        int rp = height.size() - 1;

        while (lp < rp)
        {
            int w = rp - lp;
            int ht = min(height[lp], height[rp]);

            int currentwater = w * ht;

            maxwater = max(maxwater, currentwater);

            height[lp] < height[rp] ? lp++ : rp--;
        }

        return maxwater;
    }
};

int main()
{
    Solution obj;

    int n;

    cout << "Enter number of heights: ";
    cin >> n;

    vector<int> height(n);

    cout << "Enter heights: ";
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    int result = obj.maxArea(height);

    cout << "Maximum Water Stored: " << result << endl;

    return 0;
}