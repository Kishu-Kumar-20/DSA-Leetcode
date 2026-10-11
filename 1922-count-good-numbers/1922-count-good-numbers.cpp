class Solution {
public:
    long long power(long long x, long long y) {
        const long long MOD = 1000000007;
        long long ans = 1;

        while (y > 0) {
            if (y % 2 == 1)
                ans = (ans * x) % MOD;

            x = (x * x) % MOD;
            y /= 2;
        }
        return ans;
    }
    int countGoodNumbers(long long n) { 
        long long odd = n / 2, even = n - odd;
        return (power(4,odd)*power(5,even))%1000000007;
    }
};