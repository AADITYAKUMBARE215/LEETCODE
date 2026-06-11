// LeetCode 229: Majority Element II
// Approach: Boyer-Moore Voting Algorithm
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int count1 = 0, count2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        // Find potential candidates
        for (int i = 0; i < nums.size(); i++)
        {
            if (count1 == 0 && nums[i] != el2)
            {
                count1 = 1;
                el1 = nums[i];
            }
            else if (count2 == 0 && nums[i] != el1)
            {
                count2 = 1;
                el2 = nums[i];
            }
            else if (nums[i] == el1)
            {
                count1++;
            }
            else if (nums[i] == el2)
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        // Verify candidates
        vector<int> ls;
        count1 = 0;
        count2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == el1)
                count1++;
            else if (nums[i] == el2)
                count2++;
        }

        int minimum = nums.size() / 3;

        if (count1 > minimum)
            ls.push_back(el1);

        if (count2 > minimum)
            ls.push_back(el2);

        return ls;
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

    vector<int> result = obj.majorityElement(nums);

    cout << "Majority elements (> n/3 times): ";

    if (result.empty())
    {
        cout << "None";
    }
    else
    {
        for (int num : result)
        {
            cout << num << " ";
        }
    }

    cout << endl;

    return 0;
}