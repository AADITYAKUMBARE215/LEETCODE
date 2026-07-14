// LeetCode 151: Reverse Words in a String
// Approach: Reverse Traversal
// Time: O(n)
// Space: O(n)

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string result = "";
        int i = s.size() - 1;

        while (i >= 0)
        {
            while (i >= 0 && s[i] == ' ')
                i--;

            if (i < 0)
                break;

            int end = i;

            while (i >= 0 && s[i] != ' ')
                i--;

            string word = s.substr(i + 1, end - i);

            if (!result.empty())
                result += ' ';

            result += word;
        }

        return result;
    }
};

int main()
{
    Solution obj;

    string s;

    cout << "Enter string: ";
    getline(cin, s);

    cout << "Reversed String: " << obj.reverseWords(s) << endl;

    return 0;
}