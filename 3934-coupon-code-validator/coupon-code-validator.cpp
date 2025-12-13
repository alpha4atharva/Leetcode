class Solution {
public: 
    static int func(string s){
        if(s=="electronics") return 1;
        if(s=="grocery") return 2;
        if(s=="pharmacy") return 3;
        return 4;
    }

    static bool compare(const vector<string> &a,const vector<string> &b){
        if(a[1]==b[1]) return a[0]<b[0];
        else{
            return func(a[1])<func(b[1]);
        }
    }

    bool isAlnum(string &s){
        if(s.length()==0) return false;
        for(auto &c:s){
            if((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9') || c=='_'){

            }
            else
                return false;
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
        vector<vector<string>> valid;
        for(int i=0;i<n;i++){
            if(isValid(code[i],bl[i],isAct[i])){
                valid.push_back({code[i],bl[i]});
            }
        }

        sort(valid.begin(),valid.end(),compare);
        vector<string> ans;
        for(auto &it:valid) ans.push_back(it[0]);

        return ans;
    }
};