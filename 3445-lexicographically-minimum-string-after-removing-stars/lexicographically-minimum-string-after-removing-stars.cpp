struct Compare{
    bool operator()(const pair<char,int>&a, const pair<char,int>&b){
        if(a.first==b.first)
            return a.second<b.second; // Max-heap on second
        return a.first>b.first;       // Min-heap on first
    }
};

class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,Compare> pq;
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                s[pq.top().second]='*';
                pq.pop();
            }
            else{
                pq.push({s[i],i});
            }
        }
        // vector<stack<int>> freq(26);
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='*'){
        //         for(int i=0;i<26;i++){
        //             if(!freq[i].empty()){
        //                 s[freq[i].top()]='*';
        //                 freq[i].pop();
        //                 break;
        //             }
        //         }
        //     }
        //     else{
        //         freq[s[i]-'a'].push(i);
        //     }
        // }

        string ans="";
        for(auto &c:s){
            if(c!='*'){
                ans+=c;
            }
        }

        return ans;
    }
};