class Solution {
public:
    //compute previous smaller element and next smaller element
    void computePSE(vector<int>&heights,vector<int>&pse){
        int n=heights.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()) pse[i]=st.top();
            st.push(i);
        }
    }

    void computeNSE(vector<int>&heights,vector<int>&nse){
        int n=heights.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()) nse[i]=st.top();
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>pse(n,-1),nse(n,n);
        computePSE(heights,pse);
        computeNSE(heights,nse);

        int ans=0;
        for(int i=0;i<n;i++){
            int width=nse[i]-pse[i]-1;
            ans=max(ans,width*heights[i]);
        }
        return ans;
    }
};