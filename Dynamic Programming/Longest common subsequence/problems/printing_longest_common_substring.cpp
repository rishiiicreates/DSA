#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Function to find and print the Longest Common Substring of two strings.
 * Unlike Longest Common Subsequence, the characters must be continuous.
 */
string getLongestCommonSubstring(const string& s1, const string& s2) {
    int n = s1.length();
    int m = s2.length();

    // t[i][j] stores the length of the longest common substring ending at s1[i-1] and s2[j-1]
    vector<vector<int>> t(n + 1, vector<int>(m + 1, 0));

    int maxLen = 0;
    int endPos = 0; // Ending index of the longest common substring in s1

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                t[i][j] = 1 + t[i - 1][j - 1];
                if (t[i][j] > maxLen) {
                    maxLen = t[i][j];
                    endPos = i;
                }
            } else {
                t[i][j] = 0; // Reset if characters don't match (substring must be continuous)
            }
        }
    }

    if (maxLen == 0) return "";

    // Extract the substring from s1 using the ending position and maximum length
    return s1.substr(endPos - maxLen, maxLen);
}

int main() {
    string s1 = "abedgh";
    string s2 = "abfhrgh";

    string result = getLongestCommonSubstring(s1, s2);

    cout << "String 1: " << s1 << endl;
    cout << "String 2: " << s2 << endl;
    if (result.empty()) {
        cout << "No common substring found." << endl;
    } else {
        cout << "Longest Common Substring: " << result << endl;
        cout << "Length: " << result.length() << endl;
    }

    return 0;
}

/*
 * Explanation:
 * This file implements an algorithm to both find and print the Longest Common Substring.
 * It builds the DP table similarly to the standard substring algorithm but keeps track of `maxLen` and `endPos` (the ending index in `s1` where the maximum length was found).
 * If characters don't match, the DP cell is reset to 0.
 * Finally, the substring is extracted directly from `s1` using `s1.substr(endPos - maxLen, maxLen)`.
 */
