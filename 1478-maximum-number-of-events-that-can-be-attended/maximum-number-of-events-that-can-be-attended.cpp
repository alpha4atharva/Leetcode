class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>>pq;

        int i=0,n=events.size(),day=0,ans=0;
        while(i<n || !pq.empty()){
            if(pq.empty()){
                day=events[i][0];
            }

            //add events
            while(i<n && day==events[i][0]){
                pq.push(events[i][1]);
                i++;
            }

            //remove ended events
            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }

            //attend the event
            if(!pq.empty()){
                ans++;
                pq.pop();
            }

            day++;
        }

        return ans;
    }
};