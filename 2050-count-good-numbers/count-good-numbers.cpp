// class Solution {
// public:
//     const int MOD = 1e9 + 7;
//     long long binpow(long long a, long long b) {
//         long long res=1;
//         while (b>0){
//             if (b%2==1){
//                 res=(res*a)%MOD;
//             }
//             a=(a*a)%MOD;
//             b=b/2;
//         }
//         return res;
//     }
    
//     int countGoodNumbers(long long n) {
//         long long evenPos=(n+1)/2;
//         long long oddPos=n/2;
//         // 5^evenPos * 4^oddPos
//         return (binpow(5, evenPos) * binpow(4, oddPos)) % MOD;
//     }
// };
class Solution {
public:
    const int MOD = 1e9 + 7;
    long long power(long long base, long long exp){

        if(exp == 0) return 1;
        if(exp == 1) return base;
        long long half = power(base, exp/2);
        long long result = (half * half) % MOD;
        if(exp%2==1) {
            result=(result*base)%MOD;
        }
        
        return result;
    }
    
    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;
        
        // Calculate 5^evenPos * 4^oddPos
        return (power(5, evenPos) * power(4, oddPos)) % MOD;
    }
};