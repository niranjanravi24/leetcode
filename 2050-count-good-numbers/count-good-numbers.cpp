class Solution {
    long long power(long long base, long long expo){
        const long long MOD = 1e9 + 7;
        if(expo == 0) return 1;
        if(expo == 1) return base;

        long long ans = 1;
        while(expo > 1){
            if(expo%2 == 0){
                base = (base*base)%MOD;
                expo = expo/2;
            }
            else{
                ans = (ans*base)%MOD;
                expo = expo - 1;
            }
        }

        return (ans*base)%MOD;
    }
public:

    int countGoodNumbers(long long n) {
        const long long MOD = 1e9 + 7;

        long long odd = n/2;
        long long even = (n+1)/2;

        long long evenWays = power(5, even);
        long long oddWays = power(4, odd);

        return (evenWays*oddWays)%MOD;
    }
};