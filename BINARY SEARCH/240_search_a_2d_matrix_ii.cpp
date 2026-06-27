// LeetCode 240: Search a 2D Matrix II
// Approach: Staircase Search
// Time: O(m + n)
// Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0;
        int col = m - 1;

        while (row < n && col >= 0)
        {
            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (matrix[row][col] < target)
            {
                row++;
            }
            else
            {
                col--;
            }
        }

        return false;
    }
};

int main()
{
    Solution obj;

    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter matrix elements:" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int target;

    cout << "Enter target element: ";
    cin >> target;

    bool result = obj.searchMatrix(matrix, target);

    cout << "Target Found: " << (result ? "true" : "false") << endl;

    return 0;
}