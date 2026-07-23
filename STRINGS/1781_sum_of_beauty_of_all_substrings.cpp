// LeetCode 1781: Sum of Beauty of All Substrings
// Approach: Frequency Counting
// Time: O(n² × 26)
// Space: O(26)

#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution
{
public:
    int beautySum(string s)
    {
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            vector<int> freq(26, 0);

            for (int j = i; j < n; j++)
            {
                freq[s[j] - 'a']++;

                int maxFreq = 0;
                int minFreq = INT_MAX;

                for (int k = 0; k < 26; k++)
                {
                    if (freq[k] > 0)
                    {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                ans += (maxFreq - minFreq);
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Sum of Beauty of All Substrings: " << obj.beautySum(s) << endl;

    return 0;
}