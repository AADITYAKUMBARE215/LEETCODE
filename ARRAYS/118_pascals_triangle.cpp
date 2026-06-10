// LeetCode 118: Pascal's Triangle
// Approach: Generate Each Row Using Binomial Coefficient
// Time: O(n²)
// Space: O(1) Auxiliary Space (excluding output)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> generaterow(int row)
    {
        long long ans = 1;
        vector<int> ansrow;

        ansrow.push_back(1);

        for (int col = 1; col < row; col++)
        {
            ans = ans * (row - col);
            ans = ans / col;

            ansrow.push_back(ans);
        }

        return ansrow;
    }

    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;

        for (int i = 1; i <= numRows; i++)
        {
            ans.push_back(generaterow(i));
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    int numRows;

    cout << "Enter number of rows: ";
    cin >> numRows;

    vector<vector<int>> result = obj.generate(numRows);

    cout << "Pascal's Triangle:" << endl;

    for (auto row : result)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}