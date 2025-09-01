class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int ex) {
        int n=classes.size();
        priority_queue<pair<double,int>>pq;
        for(int i=0;i<n;i++){
            double gain=(double)(classes[i][0]+1)/(double)(classes[i][1]+1)-(double)(classes[i][0])/(double)(classes[i][1]);
            pq.push({gain,i});
        }
        while(ex--){
            auto [g,i]=pq.top();
            pq.pop();

            classes[i][0]++;
            classes[i][1]++;
            double gain=(double)(classes[i][0]+1)/(double)(classes[i][1]+1)-(double)(classes[i][0])/(double)(classes[i][1]);
            pq.push({gain,i});
        }

        double ans=0;
        for(int i=0;i<n;i++){
            ans+=(double)(classes[i][0])/(double)(classes[i][1]);
        }

        return ans/n;
    }
};