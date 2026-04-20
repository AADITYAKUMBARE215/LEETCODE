// LeetCode 2078: Two Furthest Houses With Different Colors
// Approach: Array Traversal
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) 
    {
        int n = colors.size();
        int maximum = 0;

        // Check from left
        for (int i = 0; i < n; i++)
        {
            if (colors[i] != colors[n - 1])
            {
                maximum = max(maximum, n - 1 - i);
                break;
            }
        }

        // Check from right
        for (int j = n - 1; j >= 0; j--)
        {
            if (colors[j] != colors[0])
            {
                maximum = max(maximum, j);
                break;
            }
        }

        return maximum;
    }
};

int main()
{
    Solution obj;

    int n;
    cout << "Enter number of houses: ";
    cin >> n;

    vector<int> colors(n);
    cout << "Enter colors: ";
    for (int i = 0; i < n; i++)
        cin >> colors[i];

    int result = obj.maxDistance(colors);

    cout << "Maximum Distance: " << result << endl;

    return 0;
}