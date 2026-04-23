// LeetCode 283: Move Zeroes
// Approach: Two Pointer (in-place)
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& arr) 
    {
        int size = arr.size();
        int j = -1;

        // Find first zero
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == 0)
            {
                j = i;
                break;
            }
        }

        if (j == -1) return;

        // Move non-zero elements forward
        for (int i = j + 1; i < size; i++)
        {
            if (arr[i] != 0)
            {
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }
};

int main()
{
    Solution obj;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    obj.moveZeroes(arr);

    cout << "Array after moving zeroes: ";
    for (int x : arr)
        cout << x << " ";

    cout << endl;

    return 0;
}