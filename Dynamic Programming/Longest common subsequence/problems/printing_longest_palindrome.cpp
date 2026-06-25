class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len <= 1) return s; // Handled 0 and 1 length safely up front

        string k = s;
        reverse(k.begin(), k.end());

        vector<vector<int>> t(len+1, vector<int>(len+1, 0 ));

        int max_len = 0;
        int max_i = 0; // To track where the longest valid palindrome ends in s

        for(int i = 1; i < len + 1; i++){
            for(int j = 1; j < len + 1; j++){
                if(s[i-1] == k[j-1]){
                    t[i][j] = t[i-1][j-1] + 1;
                    
                    // CRITICAL PALINDROME CHECK:
                    // The substring in s ends at index (i-1). 
                    // In the reversed string k, this same substring must map back to the same physical characters.
                    // This condition ensures the common substring hasn't just matched a random reversed copy elsewhere.
                    if(t[i][j] > max_len){
                        if((i - 1) - t[i][j] + 1 == (len - 1) - (j - 1)){ 
                            max_len = t[i][j];
                            max_i = i;
                        }
                    }
                } else {
                    // Reset to 0 because substrings must be contiguous!
                    t[i][j] = 0; 
                }
            }
        }

        // No messy backtracking loop needed anymore. 
        // We know exactly where it ends (max_i) and how long it is (max_len).
        return s.substr(max_i - max_len, max_len);
    }
};

/*
 * Explanation:
 * This file prints the Longest Palindromic Substring using an approach similar to Longest Common Substring between the string and its reverse.
 * To ensure the matched substring is genuinely a palindrome (and not just a reversed matching segment somewhere else),
 * it performs a critical check: `((i - 1) - t[i][j] + 1 == (len - 1) - (j - 1))`. This validates that the matched indices map to the exact same physical characters in the original string.
 * It tracks `max_len` and the ending index `max_i` to efficiently extract the final palindrome without backtracking.
 */
