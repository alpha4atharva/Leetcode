class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> sieve(right+1,true);
        sieve[0]=sieve[1]=false;

        for(int i=2;i*i<=right;i++){
            if(sieve[i]){
                for(int j=i*i;j<=right;j+=i){
                    sieve[j]=false;
                }
            }
        }

        vector<int> primes;
        for(int i=left;i<=right;i++){
            if(sieve[i]) primes.push_back(i);
        }
        
        if(primes.size()<2) return {-1,-1};

        int min_gap=INT_MAX;
        vector<int> result={-1,-1};
        for(int i=0;i<primes.size()-1;i++){
            if(primes[i+1]-primes[i]<min_gap){
                min_gap=primes[i+1]-primes[i];
                result[0]=primes[i];
                result[1]=primes[i+1];
            }
        }

        return result;
    }
};