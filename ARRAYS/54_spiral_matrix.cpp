// LeetCode 54: Spiral Matrix
// Approach: Boundary Traversal
// Time: O(m × n)
// Space: O(1) excluding output array

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int top = 0;
        int left = 0;
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;

        vector<int> final;

        while (top <= bottom && left <= right)
        {
            // Left -> Right
            for (int i = left; i <= right; i++)
            {
                final.push_back(matrix[top][i]);
            }
            top++;

            // Top -> Bottom
            for (int i = top; i <= bottom; i++)
            {
                final.push_back(matrix[i][right]);
            }
            right--;

            // Right -> Left
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    final.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Bottom -> Top
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    final.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return final;
    }
};

int main()
{
    Solution obj;

    int rows, cols;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<int> result = obj.spiralOrder(matrix);

    cout << "\nSpiral Order: ";

    for (int x : result)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}