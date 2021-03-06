/*
Remove K Digits


Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

// Idea: Greedy approach when you find the peek element delete element to its right until you find another peek.

// Solved in O(N + k) & O(1)
class Solution {
   public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) {
            return "0";
        }

        int idx = 0;
        while (k > 0) {
            if (idx > 0) idx -= 1;
            while (idx <= num.length() - 1 && num[idx] <= num[idx + 1]) idx += 1;
            num.erase(num.begin() + idx);
            k -= 1;
        }

        auto non_zero = num.find_first_not_of("0");
        num.erase(0, non_zero);

        if (num.length() == 0) return "0";
        return num;
    }
};