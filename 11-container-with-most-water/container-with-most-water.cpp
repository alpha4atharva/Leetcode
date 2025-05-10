class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int curr=0,maxarea=0;
        while(i<j)
        {
            curr=min(height[i],height[j])*(j-i);
            maxarea=max(maxarea,curr);
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return maxarea;
    }
};