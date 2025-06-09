class Solution {
public:
    int func(long num,int n){
        long count=0;
        long next=num+1;
        while(num<=n){
            count+=min((long)n+1,next)-num;
            num*=10;
            next*=10;
        }
        return count;
    }
    
    int findKthNumber(int n, int k) {
        long num=1;
        k--;
        while(k>0){
            int req=func(num,n);
            if(req<=k){
                k-=req;
                num++;
            }
            else{
                k--;
                num*=10;
            }
        }
        return num;
    }
}; 