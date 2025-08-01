class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>pascal;
        int size=1;
        pascal.push_back({1});
        for(int i=1;i<numRows;i++)
        {
            int j=0;
            vector<int>temp(size+1,1);
            while(j<size-1)
            {
                temp[j+1]=pascal[i-1][j]+pascal[i-1][j+1];
                j++;
            }
            size++;
            pascal.push_back(temp);
        }
        return pascal;
    }
};