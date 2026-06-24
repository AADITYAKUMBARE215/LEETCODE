// LeetCode 1482: Minimum Number of Days to Make m Bouquets
// Approach: Binary Search on Answer
// Time: O(n * log(maxBloomDay))
// Space: O(1)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool possible(vector<int>& arr, int day, int m, int k)
    {
        int count = 0;
        int noofb = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= day)
            {
                count++;
            }
            else
            {
                noofb += (count / k);
                count = 0;
            }
        }

        noofb += (count / k);

        return noofb >= m;
    }

    int minDays(vector<int>& arr, int m, int k)
    {
        long long val = 1LL * m * k;

        if (val > arr.size())
            return -1;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = 0; i < arr.size(); i++)
        {
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }

        int low = mini;
        int high = maxi;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (possible(arr, mid, m, k))
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

    cout << "Enter number of flowers: ";
    cin >> n;

    vector<int> bloomDay(n);

    cout << "Enter bloom days: ";
    for (int i = 0; i < n; i++)
    {
        cin >> bloomDay[i];
    }

    int m, k;

    cout << "Enter number of bouquets (m): ";
    cin >> m;

    cout << "Enter flowers required per bouquet (k): ";
    cin >> k;

    int result = obj.minDays(bloomDay, m, k);

    cout << "Minimum Days Required: " << result << endl;

    return 0;
}