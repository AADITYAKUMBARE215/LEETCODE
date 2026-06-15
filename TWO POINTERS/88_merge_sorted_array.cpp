// LeetCode 88: Merge Sorted Array
// Approach: Three Pointers (Merge from the End)
// Time: O(m + n)
// Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int pos = m + n - 1;
        int l1 = m - 1;
        int l2 = n - 1;

        while (l1 >= 0 && l2 >= 0)
        {
            if (nums1[l1] >= nums2[l2])
            {
                nums1[pos] = nums1[l1];
                l1--;
            }
            else
            {
                nums1[pos] = nums2[l2];
                l2--;
            }

            pos--;
        }

        while (l2 >= 0)
        {
            nums1[pos] = nums2[l2];
            l2--;
            pos--;
        }
    }
};

int main()
{
    Solution obj;

    int m, n;

    cout << "Enter number of elements in nums1 (m): ";
    cin >> m;

    cout << "Enter number of elements in nums2 (n): ";
    cin >> n;

    vector<int> nums1(m + n);
    vector<int> nums2(n);

    cout << "Enter " << m << " sorted elements of nums1: ";
    for (int i = 0; i < m; i++)
    {
        cin >> nums1[i];
    }

    cout << "Enter " << n << " sorted elements of nums2: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }

    obj.merge(nums1, m, nums2, n);

    cout << "Merged Array: ";

    for (int num : nums1)
    {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}