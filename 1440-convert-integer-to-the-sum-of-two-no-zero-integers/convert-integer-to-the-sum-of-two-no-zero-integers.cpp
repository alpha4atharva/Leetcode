class Solution {
public:
    bool isValid(int x,int y){
        string a=to_string(x);
        string b=to_string(y);
        for(auto it:a){
            if(it=='0') return false;
        }
        for(auto it:b){
            if(it=='0') return false;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            if(isValid(i,n-i)){
                return {i,n-i};
            }
        }
        return {};
    }
};