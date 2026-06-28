// LeetCode 1901: Find a Peak Element II
// Approach: Binary Search on Columns
// Time: O(n * log(m))
// Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxIndex(vector<vector<int>>& matrix, int n, int m, int col)
    {
        int max_val = -1;
        int index = -1;

        for (int i = 0; i < n; i++)
        {
            if (matrix[i][col] > max_val)
            {
                max_val = matrix[i][col];
                index = i;
            }
        }

        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int max_row_index = findMaxIndex(mat, n, m, mid);

            int left = (mid - 1 >= 0) ? mat[max_row_index][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[max_row_index][mid + 1] : -1;

            if (mat[max_row_index][mid] > left &&
                mat[max_row_index][mid] > right)
            {
                return {max_row_index, mid};
            }
            else if (mat[max_row_index][mid] < left)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return {-1, -1};
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

    vector<vector<int>> mat(rows, vector<int>(cols));

    cout << "Enter matrix elements:" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> mat[i][j];
        }
    }

    vector<int> result = obj.findPeakGrid(mat);

    cout << "Peak Element Position: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}