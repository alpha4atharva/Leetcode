class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end(),cmp);
        int ans=0;
        for(int i=0;i<n;i++){
            int maxY=INT_MIN;
            for(int j=i+1;j<n;j++){
                // Example condition: y[i] >= y[j] && y[j] > maxY
                if (points[i][1]>=points[j][1] && points[j][1]>maxY) {
                    ans++;
                    maxY=points[j][1];
                }
            }
        }

        return ans;
    }
};