// LeetCode 992: Subarrays with K Different Integers
// Approach: Sliding Window (At Most K Distinct)
// Time: O(n)
// Space: O(k)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraysWithKDistinct(vector<int>& nums, int k)
    {
        int n = nums.size();

        int count = 0;
        int left = 0;
        int right = 0;

        unordered_map<int, int> freq;

        while (right < n)
        {
            freq[nums[right]]++;
            right++;

            while (freq.size() > k)
            {
                freq[nums[left]]--;

                if (freq[nums[left]] == 0)
                {
                    freq.erase(nums[left]);
                }

                left++;
            }

            count += right - left;
        }

        int count2 = 0;

        left = 0;
        right = 0;
        freq.clear();

        while (right < n)
        {
            freq[nums[right]]++;
            right++;

            while (freq.size() > k - 1)
            {
                freq[nums[left]]--;

                if (freq[nums[left]] == 0)
                {
                    freq.erase(nums[left]);
                }

                left++;
            }

            count2 += right - left;
        }

        return count - count2;
    }
};

int main()
{
    Solution obj;

    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array: ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    cout << "Number of Subarrays with Exactly "
         << k << " Distinct Integers: "
         << obj.subarraysWithKDistinct(nums, k) << endl;

    return 0;
}