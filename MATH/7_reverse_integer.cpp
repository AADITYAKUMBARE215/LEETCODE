// Problem: LeetCode 7 - Reverse Integer
// Approach:
// 1. Extract digits one by one and build reversed number.
// 2. Before adding digit, check for overflow conditions.

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int reverse_number = 0; // stores final reversed value

        // process until all digits are extracted
        while (x != 0) {
            int digit = x % 10;   // get last digit
            x = x / 10;           // remove last digit

            // check overflow for positive limit
            if (reverse_number > INT_MAX / 10 || (reverse_number == INT_MAX / 10 && digit > 7))
                return 0;

            // check overflow for negative limit
            if (reverse_number < INT_MIN / 10 || (reverse_number == INT_MIN / 10 && digit < -8))
                return 0;

            // append digit to reversed number
            reverse_number = (reverse_number * 10) + digit;
        }

        return reverse_number; // return final result
    }
};

int main() {
    Solution obj;

    int x;
    cout << "Enter number: ";
    cin >> x;

    int result = obj.reverse(x);

    // display output
    cout << "Reversed number: " << result << endl;

    return 0;
}