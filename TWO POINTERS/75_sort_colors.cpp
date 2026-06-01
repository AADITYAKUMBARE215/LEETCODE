// LeetCode 75: Sort Colors
// Approach: Dutch National Flag Algorithm
// Time: O(n)
// Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& arr)
    {
        int low = 0;
        int mid = 0;
        int high = arr.size() - 1;

        while (mid <= high)
        {
            if (arr[mid] == 0)
            {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(arr[mid], arr[high]);
                high--;
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

    cout << "Enter elements (0, 1, 2): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    obj.sortColors(arr);

    cout << "Sorted Colors: ";

    for (int x : arr)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}