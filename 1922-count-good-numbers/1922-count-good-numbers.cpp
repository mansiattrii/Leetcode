class Solution {
public:
    const int mod = 1e9 + 7; 
    long long pow(long long base, long long exp){
        if(exp == 0)    return 1;
        long long half = pow(base, exp/2);
        long long halfSquared = ( half * half ) % mod;

        if(exp % 2)
            return(halfSquared * (base % mod)) % mod;
        return(halfSquared) % mod;
    }
    int countGoodNumbers(long long n) {
        long long even, odd;

        if(n%2){
            even = n/2 + 1;
            odd = n/2;
        }
        else{
            even = n/2;
            odd = n/2;
        }
        long long res = ((pow(5, even)%mod) * (pow(4, odd)%mod)) % mod;
        return (int) res;
    }
};