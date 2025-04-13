class Solution {
public:
    const int MOD = 1e9 + 7;

// Function to perform fast exponentiation (a^b % mod)
long long power(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1)  // if b is odd
            result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;  // divide b by 2
    }
    return result;
    }
    int countGoodNumbers(long long n) {
         long long even_count = (n + 1) / 2; // even indices
    long long odd_count = n / 2;        // odd indices

    long long even_ways = power(5, even_count, MOD);
    long long odd_ways = power(4, odd_count, MOD);

    return (even_ways * odd_ways) % MOD;
    }
};