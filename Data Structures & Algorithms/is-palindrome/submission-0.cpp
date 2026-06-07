class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // Move the left pointer to the next alphanumeric character
            while (left < right && !std::isalnum(s[left])) {
                left++;
            }
            
            // Move the right pointer to the previous alphanumeric character
            while (left < right && !std::isalnum(s[right])) {
                right--;
            }
            
            // Compare the characters after converting them to lowercase
            if (std::tolower(s[left]) != std::tolower(s[right])) {
                return false;
            }
            
            // Move both pointers inward
            left++;
            right--;
        }
        
        return true; 
    }
};
