Easy

// Given two binary strings, return their sum (also a binary string).

// The input strings are both non-empty and contains only characters 1 or 0.

// Example 1:
// Input: a = "11", b = "1"
// Output: "100"

// Example 2:
// Input: a = "1010", b = "1011"
Output: "10101"
 
// Constraints:

// Each string consists only of '0' or '1' characters.
// 1 <= a.length, b.length <= 10^4
// Each string is either "0" or doesn't contain any leading zero.

class Solution {
  public String addBinary(String a, String b) {
    return Integer.toBinaryString(Integer.parseInt(a, 2) + Integer.parseInt(b, 2));
  }
}

// Approach 1: Bit-by-Bit Computation
class Solution {
    public String addBinary(String a, String b) {
       int n = a.length(), m = b.length();
        if (n < m) return addBinary(b, a);
        int L = Math.max(n, m);
        StringBuilder sb = new StringBuilder();
        int carry = 0, j = m - 1;
        
        for (int i = L - 1; i > -1; --i) {
            if (a.charAt(i) == '1') ++carry;
            if (j > -1 && b.charAt(j--) == '1') ++carry;
            
            if (carry % 2 == 1) sb.append('1');
            else sb.append('0');
            
            carry /= 2;
        }
        
        if (carry == 1) sb.append('1');
        sb.reverse();
        
        return sb.toString();
    }
}

// Approach 2: Bit Manipulation
import java.math.BigInteger;

class Solution {
    public String addBinary(String a, String b) {
        BigInteger x = new BigInteger(a, 2);
        BigInteger y = new BigInteger(b, 2);
        BigInteger zero = new BigInteger("0", 2);
        BigInteger answer, carry;
        
        while (y.compareTo(zero) != 0) {
            answer = x.xor(y);
            carry = x.and(y).shiftLeft(1);
            x = answer;
            y = carry;
        }
        return x.toString(2);
    }
}

// Success
// Details 
// Runtime: 7 ms, faster than 12.36% of Java online submissions for Add Binary.
// Memory Usage: 40.6 MB, less than 5.29% of Java online submissions for Add Binary.
