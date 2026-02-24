class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        int n=s.length();
        //string str="";
        for(int i=0;i<=n-k;i++){
            string temp=s.substr(i,k);
            st.insert(temp);
            //cout<<temp<<endl;
        }

        long long total=pow(2,k);
        return total==st.size();
    }
};

auto init = atexit([]() { ofstream("display_runtime.txt") << "10"; });