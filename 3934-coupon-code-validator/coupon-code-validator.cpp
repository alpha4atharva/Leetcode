class Solution {
public: 
    int func(string s){
        if(s=="electronics") return 1;
        if(s=="grocery") return 2;
        if(s=="pharmacy") return 3;
        return 4;
    }

    // static bool compare(const vector<string> &a,const vector<string> &b){
    //     if(a[1]==b[1]) return a[0]<b[0];
    //     else{
    //         return func(a[1])<func(b[1]);
    //     }
    // }

    bool isAlnum(string &s){
        if(s.empty()) return false;
        for(auto &c:s){
            if(!isalnum(c) && c!='_') return false;
        }
        return true;
    }

    bool isValid(string &a,string &b,bool c){
        if(!c) return false;
        if(b=="electronics" || b=="grocery" || b=="pharmacy" || b=="restaurant"){
            if(isAlnum(a)) return true;
        }
        return false;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& bl, vector<bool>& isAct) {
        int n=code.size();
        vector<pair<int,string>> valid;
        for(int i=0;i<n;i++){
            if(isValid(code[i],bl[i],isAct[i])){
                valid.push_back({func(bl[i]),code[i]});
            }
        }

        sort(valid.begin(),valid.end());
        vector<string> ans;
        for(auto &it:valid) ans.push_back(it.second);

        return ans;
    }
};