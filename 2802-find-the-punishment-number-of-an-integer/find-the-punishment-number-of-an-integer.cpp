class Solution {
public:
    bool rec(string num,int idx,int target){
        if(idx==num.size()) return target==0;
        
        int sum=0;
        for(int i=idx;i<num.size();i++){
            sum=sum*10+(num[i]-'0');
            if(sum>target)  break;
            if(rec(num,i+1,target-sum)) return true;
        }

        return false;
    }

    int punishmentNumber(int n) {
       int sum=0;
       string temp;
       for(int i=1;i<=n;i++){
        temp=to_string(i*i);
        if(rec(temp,0,i)){
            sum+=(i*i);
        }
       }

       return sum;
    }
};