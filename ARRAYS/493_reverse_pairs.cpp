// LeetCode 493: Reverse Pairs
// Approach: Merge Sort + Counting Reverse Pairs
// Time: O(n log n)
// Space: O(n)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high)
    {
        vector<int> temp;

        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }

    int countpairs(vector<int>& arr, int low, int mid, int high)
    {
        int count = 0;
        int right = mid + 1;

        for (int i = low; i <= mid; i++)
        {
            while (right <= high &&
                   (long long)arr[i] > 2LL * arr[right])
            {
                right++;
            }

            count += right - (mid + 1);
        }

        return count;
    }

    int mergesort(vector<int>& arr, int low, int high)
    {
        if (low >= high)
            return 0;

        int mid = low + (high - low) / 2;

        int count = 0;

        count += mergesort(arr, low, mid);
        count += mergesort(arr, mid + 1, high);

        count += countpairs(arr, low, mid, high);

        merge(arr, low, mid, high);

        return count;
    }

    int reversePairs(vector<int>& nums)
    {
        return mergesort(nums, 0, nums.size() - 1);
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

    int result = obj.reversePairs(nums);

    cout << "Number of reverse pairs: " << result << endl;

    return 0;
}