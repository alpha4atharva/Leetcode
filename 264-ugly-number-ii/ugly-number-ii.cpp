typedef long long ll;
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<ll,vector<ll>,greater<>> pq;
        set<ll> st;
        st.insert(1);
        pq.push(1);
        ll ans=1;
        for(int i=0;i<n;i++){
            ans=pq.top();
            pq.pop();
            if(st.find(2*ans)==st.end()){
                st.insert(2*ans);
                pq.push(2*ans);
            }
            if(st.find(3*ans)==st.end()){
                st.insert(3*ans);
                pq.push(3*ans);
            }
            if(st.find(5*ans)==st.end()){
                st.insert(5*ans);
                pq.push(5*ans);
            }
        }

        return ans;
    }
};