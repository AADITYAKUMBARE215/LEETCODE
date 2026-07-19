// LeetCode 451: Sort Characters By Frequency
// Approach: Hash Map + Sorting
// Time: O(n log n)
// Space: O(n)

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    static bool comparator(pair<char, int>& p1, pair<char, int>& p2)
    {
        return p1.second > p2.second;
    }

    string frequencySort(string s)
    {
        unordered_map<char, int> freq;

        for (char ch : s)
        {
            freq[ch]++;
        }

        vector<pair<char, int>> vec(freq.begin(), freq.end());

        sort(vec.begin(), vec.end(), comparator);

        string ans;

        for (auto& p : vec)
        {
            ans += string(p.second, p.first);
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

    cout << "Sorted String: " << obj.frequencySort(s) << endl;

    return 0;
}