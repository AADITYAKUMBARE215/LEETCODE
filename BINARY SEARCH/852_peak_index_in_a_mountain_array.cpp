// LeetCode 852: Peak Index in a Mountain Array
// Approach: Binary Search
// Time: O(log n)
// Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A)
    {
        int st = 1;
        int end = A.size() - 2;

        while (st <= end)
        {
            int mid = st + (end - st) / 2;

            if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1])
            {
                return mid;
            }
            else if (A[mid - 1] < A[mid]) // Peak lies to the right
            {
                st = mid + 1;
            }
            else // Peak lies to the left
            {
                end = mid - 1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution obj;

    int n;

    cout << "Enter size of mountain array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = obj.peakIndexInMountainArray(arr);

    cout << "Peak Index: " << result << endl;

    return 0;
}