class Solution {
public:
    string countAndSay(int n) {
    if (n == 1) return \1\;
    string prev = countAndSay(n - 1);
    string result = \\;

    for (int i = 0; i < prev.length(); ) {
        char currentChar = prev[i];
        int count = 0;
        while (i < prev.length() && prev[i] == currentChar) {
            count++;
            i++;
        }
        result += to_string(count) + currentChar;
    }

    return result;
    }
};