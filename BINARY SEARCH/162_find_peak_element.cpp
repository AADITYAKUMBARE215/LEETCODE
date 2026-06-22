// LeetCode 162: Find Peak Element
// Approach: Binary Search
// Time: O(log n)
// Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& arr)
    {
        int n = arr.size() - 1;

        if (n == 0)
            return 0;

        if (arr[0] > arr[1])
            return 0;

        if (arr[n] > arr[n - 1])
            return n;

        int low = 1;
        int high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] > arr[mid - 1] &&
                arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            else if (arr[mid + 1] > arr[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return -1;
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

    int result = obj.findPeakElement(nums);

    cout << "Peak Element Index: " << result << endl;

    return 0;
}