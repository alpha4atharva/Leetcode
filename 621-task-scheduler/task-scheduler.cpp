class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        for(auto &c:tasks)  mp[c-'A']++;

        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(mp[i])   pq.push(mp[i]);
        }

        int time=0;
        while(!pq.empty()){
            vector<int> remaining;
            int cycle=n+1;
            while(!pq.empty() && cycle){
                int freq=pq.top();
                pq.pop();
                if(freq>1){
                    remaining.push_back(freq-1);
                }
                time++;
                cycle--;
            }

            for(auto it:remaining)  pq.push(it);
            
            if(pq.empty())  break;
            time+=cycle;
        }

        return time;
    }
};