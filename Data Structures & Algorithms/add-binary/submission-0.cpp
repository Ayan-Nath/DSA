class Solution {
public:
    string addBinary(string a, string b) {
       int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        string result = "";
        
        // Process from right to left
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            
            // Add digit from string a if available
            if (i >= 0) {
                sum += a[i] - '0';  // Convert char to int
                i--;
            }
            
            // Add digit from string b if available
            if (j >= 0) {
                sum += b[j] - '0';  // Convert char to int
                j--;
            }
            
            // Calculate current digit and carry
            result.push_back((sum % 2) + '0');  // Convert int to char
            carry = sum / 2;
        }
        
        // Reverse the result since we built it backwards
        reverse(result.begin(), result.end());
        return result;  
    }
};