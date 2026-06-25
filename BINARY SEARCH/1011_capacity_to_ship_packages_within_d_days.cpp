// LeetCode 1011: Capacity To Ship Packages Within D Days
// Approach: Binary Search on Answer
// Time: O(n * log(sum(weights)))
// Space: O(1)

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int days_required(vector<int>& arr, int capacity)
    {
        int day = 1;
        int load = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (load + arr[i] > capacity)
            {
                day++;
                load = arr[i];
            }
            else
            {
                load += arr[i];
            }
        }

        return day;
    }

    int shipWithinDays(vector<int>& weights, int days)
    {
        int low = INT_MIN;
        int high = 0;

        for (int i = 0; i < weights.size(); i++)
        {
            low = max(low, weights[i]);
            high += weights[i];
        }

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (days_required(weights, mid) <= days)
            {
                high = mid - 1;
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

    cout << "Enter number of packages: ";
    cin >> n;

    vector<int> weights(n);

    cout << "Enter package weights: ";
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    int days;

    cout << "Enter number of days: ";
    cin >> days;

    int result = obj.shipWithinDays(weights, days);

    cout << "Minimum Ship Capacity: " << result << endl;

    return 0;
}