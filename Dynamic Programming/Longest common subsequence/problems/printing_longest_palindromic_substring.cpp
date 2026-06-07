#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Function to find and print the Longest Palindromic Substring of a given string.
 * Uses Dynamic Programming with a boolean table.
 */
string getLongestPalindromicSubstring(string s) {
    int n = s.length();
    if (n == 0) return "";
    if (n == 1) return s;

    // dp[i][j] will be true if substring from index i to j is a palindrome
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    int maxLen = 1;
    int start = 0;

    // Every single character is a palindrome
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    // Check for substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }

    // Check for substrings of length 3 or more
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1; // Ending index

            // s[i...j] is a palindrome if outer characters match and inner part is a palindrome
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                if (len > maxLen) {
                    start = i;
                    maxLen = len;
                }
            }
        }
    }

    return s.substr(start, maxLen);
}

int main() {
    string s1 = "babad";
    string s2 = "cbbd";
    string s3 = "racecar";

    cout << "Input: " << s1 << " -> Longest Palindrome: " << getLongestPalindromicSubstring(s1) << endl;
    cout << "Input: " << s2 << " -> Longest Palindrome: " << getLongestPalindromicSubstring(s2) << endl;
    cout << "Input: " << s3 << " -> Longest Palindrome: " << getLongestPalindromicSubstring(s3) << endl;

    return 0;
}
