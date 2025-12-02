class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(); // Get the length of the string
        if (n == 0) return ""; // If string is empty, return empty string

        int start = 0; // Start index of the longest palindrome
        int maxLen = 1; // Maximum length of palindrome found

        // Helper lambda to expand around center
        auto expand = [&](int left, int right) {
            // Expand as long as left and right are within bounds and characters match
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--; // Move left pointer to the left
                right++; // Move right pointer to the right
            }
            // Return the length of the palindrome
            return right - left - 1; // Subtract 1 because last increment/decrement went out of bounds
        };

        for (int i = 0; i < n; ++i) { // Loop through each character
            int len1 = expand(i, i); // Odd length palindrome
            int len2 = expand(i, i + 1); // Even length palindrome
            int len = max(len1, len2); // Take the maximum length

            if (len > maxLen) { // If found longer palindrome
                maxLen = len; // Update maxLen
                start = i - (len - 1) / 2; // Update start index
            }
        }
        return s.substr(start, maxLen); // Return the longest palindromic substring
    }
};