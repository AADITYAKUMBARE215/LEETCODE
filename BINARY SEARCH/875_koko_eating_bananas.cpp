// LeetCode 875: Koko Eating Bananas
// Approach: Binary Search on Answer
// Time: O(n log(max(piles)))
// Space: O(1)

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    int find_maximum(vector<int>& v)
    {
        int maxi = INT_MIN;

        for (int i = 0; i < v.size(); i++)
        {
            maxi = max(maxi, v[i]);
        }

        return maxi;
    }

    int calculate_total_hours(vector<int>& v, int hourly)
    {
        int total_hours = 0;

        for (int i = 0; i < v.size(); i++)
        {
            total_hours += ceil((double)v[i] / (double)hourly);
        }

        return total_hours;
    }

    int minEatingSpeed(vector<int>& piles, int h)
    {
        int low = 1;
        int high = find_maximum(piles);

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            int total_hours = calculate_total_hours(piles, mid);

            if (total_hours <= h)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main()
{
    Solution obj;

    int n;

    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);

    cout << "Enter bananas in each pile: ";
    for (int i = 0; i < n; i++)
    {
        cin >> piles[i];
    }

    int h;

    cout << "Enter available hours: ";
    cin >> h;

    int result = obj.minEatingSpeed(piles, h);

    cout << "Minimum Eating Speed: " << result << endl;

    return 0;
}