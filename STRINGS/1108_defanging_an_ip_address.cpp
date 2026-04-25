// LeetCode 1108: Defanging an IP Address
// Approach: String Traversal
// Time: O(n)
// Space: O(n)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) 
    {
        string res = "";

        for (char c : address)
        {
            if (c == '.')
            {
                res += "[.]";
            }
            else
            {
                res += c;
            }
        }

        return res;
    }
};

int main()
{
    Solution obj;

    string address;
    cout << "Enter IP address: ";
    cin >> address;

    string result = obj.defangIPaddr(address);

    cout << "Defanged IP: " << result << endl;

    return 0;
}