// LeetCode 1423: Maximum Points You Can Obtain from Cards
// Approach: Sliding Window
// Time: O(k)
// Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int>& cardPoints, int k)
    {
        int n = cardPoints.size();

        int sum = 0;
        int maxSum = 0;

        // Take first k cards
        for (int i = 0; i < k; i++)
        {
            sum += cardPoints[i];
        }

        maxSum = sum;

        // Replace cards from left with cards from right
        for (int i = k - 1; i >= 0; i--)
        {
            sum -= cardPoints[i];
            sum += cardPoints[n - 1];
            n--;

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};

int main()
{
    Solution obj;

    int n, k;

    cout << "Enter number of cards: ";
    cin >> n;

    vector<int> cardPoints(n);

    cout << "Enter card points: ";
    for (int i = 0; i < n; i++)
    {
        cin >> cardPoints[i];
    }

    cout << "Enter k: ";
    cin >> k;

    cout << "Maximum Score: "
         << obj.maxScore(cardPoints, k) << endl;

    return 0;
}