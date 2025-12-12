class Solution {
public:
    static bool compare(const vector<string> &a,const vector<string> &b){
        int x=stoi(a[1]);
        int y=stoi(b[1]);
        if(a[1]==b[1]){
            return a[0]>b[0];
        }
        return x<y;
    }

    vector<int> retrieve(string &s){
        vector<int> ids;
        string cur;
        for(char c:s){
            if(c==' '){
                if(!cur.empty()){
                    if(cur.size()>2 && cur.rfind("id",0)==0){ //starts with "id"
                        int x=stoi(cur.substr(2));                // part after "id"
                        ids.push_back(x);
                    }
                    cur.clear();
                }
            } 
            else{
                cur.push_back(c);
            }
        }
        // handle last token
        if(!cur.empty() && cur.size()>2 && cur.rfind("id",0)==0){
            int x=stoi(cur.substr(2));
            ids.push_back(x);
        }
        return ids;
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> ans(numberOfUsers,0);
        int all=0;
        map<int,int> offline;
        sort(events.begin(),events.end(),compare);
        //for(int i=0;i<events.size();i++) cout<<events[i][1];
        for(auto &it:events){
            if(it[0]=="MESSAGE"){
                if(it[2]=="ALL") all++;
                else if(it[2]=="HERE"){
                    for(int i=0;i<numberOfUsers;i++){
                        if(offline.count(i)){
                            int time=stoi(it[1]);
                            if(time>=offline[i]){
                                ans[i]++;
                                offline.erase(i);
                            }
                        }
                        else{
                            ans[i]++;
                        }
                    }
                }
                else{
                    //mentioned users
                    vector<int> ids=retrieve(it[2]);
                    for(auto &itr:ids) ans[itr]++;
                }
            }
            else{
                int id=stoi(it[2]);
                int time=stoi(it[1]);
                offline[id]=time+60;
            }
        }

        if(all==0) return ans;

        for(int i=0;i<numberOfUsers;i++){
            ans[i]+=all;
        }

        return ans;
    }
};