class Solution {
public:
    string func(int x){
        string s=to_string(x);
        sort(s.begin(),s.end());
        return s;
    }

    bool reorderedPowerOf2(int n) {
        string target=func(n);
        for(int i=0;i<31;i++){
            if(func(1<<i)==target) return true;
        }    
        return false;
    }
};