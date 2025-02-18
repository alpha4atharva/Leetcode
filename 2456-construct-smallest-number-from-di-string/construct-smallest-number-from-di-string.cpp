class Solution {
public:
    string smallestNumber(string pattern) {
        pattern='I'+pattern;
        string ans="";
        char curr='1';
        for(int i=0;i<pattern.size();i++){
            int temp=0,j=i+1;
            while(j<pattern.size() && pattern[j]=='D')  temp++,j++;
            if(temp!=0){
                int x=temp;
                while(i<j){
                    ans+=(curr+temp);
                    temp--;
                    i++;
                }
                i--;
                curr+=x;
            }
            else    ans+=curr;
            curr++;
        }
        
        return ans;
    }
};