// LeetCode 1539: Kth Missing Positive Number
// Approach: Binary Search
// Time: O(log n)
// Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k)
    {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int missing = arr[mid] - (mid + 1);

            if (missing < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low + k;
    }
};

int main()
{
    Solution obj;

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;

    cout << "Enter k: ";
    cin >> k;

    int result = obj.findKthPositive(arr, k);

    cout << "Kth Missing Positive Number: " << result << endl;

    return 0;
}
