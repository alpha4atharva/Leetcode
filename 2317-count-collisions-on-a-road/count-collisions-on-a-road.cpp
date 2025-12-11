class Solution {
public:
    int countCollisions(string dir) {
        int n=dir.size();
        int i=0,j=n-1;
        while(i<n && dir[i]=='L') i++;
        while(j>=0 && dir[j]=='R') j--;
        int ans=0;
        while(i<=j){
            if(dir[i]!='S'){
                ans++;
            }
            i++;
        }
        return ans;
    }
};