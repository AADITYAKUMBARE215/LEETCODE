// LeetCode 14: Longest Common Prefix
// Approach: Prefix Comparison
// Time: O(n × m)
// Space: O(1)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int size = strs.size();

        if (size == 0)
            return "";

        string resultant = strs[0];

        for (string n : strs)
        {
            if (resultant == "")
                return resultant;

            int i = 0;

            while (i < resultant.size() &&
                   i < n.size() &&
                   resultant[i] == n[i])
            {
                i++;
            }

            resultant = resultant.substr(0, i);
        }

        return resultant;
    }
};

int main()
{
    Solution obj;

    int n;

    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);

    cout << "Enter strings:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }

    cout << "Longest Common Prefix: " << obj.longestCommonPrefix(strs) << endl;

    return 0;
}