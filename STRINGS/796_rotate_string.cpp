// LeetCode 796: Rotate String
// Approach: String Doubling
// Time: O(n)
// Space: O(n)

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.length() != goal.length())
            return false;

        string doubledS = s + s;

        return doubledS.find(goal) != string::npos;
    }
};

int main()
{
    Solution obj;

    string s, goal;

    cout << "Enter original string: ";
    cin >> s;

    cout << "Enter goal string: ";
    cin >> goal;

    if (obj.rotateString(s, goal))
        cout << "Rotation Possible" << endl;
    else
        cout << "Rotation Not Possible" << endl;

    return 0;
}