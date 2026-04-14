// Problem: LeetCode 9 - Palindrome Number
#include <iostream>
using namespace std;

bool isPalindrome(int x) 
{
    // Negative numbers are not palindrome
    // Numbers ending with 0 (but not 0 itself) cannot be palindrome
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    
    int half_reverse = 0; // will store reversed second half of number
    
    while (x > half_reverse)
    {
        half_reverse = (half_reverse * 10) + (x % 10);
        x /= 10;
    }

    // For even digits: x == half_reverse
    // For odd digits: ignore middle digit using half_reverse / 10
    return (x == half_reverse || x == half_reverse / 10);
}

int main()
{
    int num;
    cout << "Enter number: ";
    cin >> num;

    if (isPalindrome(num))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    return 0;
}