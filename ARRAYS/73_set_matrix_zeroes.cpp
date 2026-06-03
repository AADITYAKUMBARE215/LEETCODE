// LeetCode 73: Set Matrix Zeroes
// Approach: In-place Matrix Marking
// Time: O(m * n)
// Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        if (matrix.empty()) return;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int col0 = 1;

        // Mark rows and columns
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;

                    if (j != 0)
                    {
                        matrix[0][j] = 0;
                    }
                    else
                    {
                        col0 = 0;
                    }
                }
            }
        }

        // Set inner matrix values
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // Handle first row
        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[0][j] = 0;
            }
        }

        // Handle first column
        if (col0 == 0)
        {
            for (int i = 0; i < rows; i++)
            {
                matrix[i][0] = 0;
            }
        }
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

    obj.setZeroes(matrix);

    cout << "\nMatrix after setting zeroes:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}