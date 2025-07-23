class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Prioritize the higher score pattern
        char c1='a',c2='b';
        if(y>x){
            swap(x,y);
            swap(c1,c2); 
        }

        // First pass: remove all c1c2
        int ans=0;
        string t;
        for(char ch:s){
            if(!t.empty() && t.back()==c1 && ch==c2){
                t.pop_back();
                ans+=x;
            } 
            else{
                t.push_back(ch);
            }
        }

        // Second pass: remove all c2c1 (the other pattern) from the remaining string
        string u;
        for(char ch:t){
            if(!u.empty() && u.back()==c2 && ch==c1){
                u.pop_back();
                ans+=y;
            } 
            else{
                u.push_back(ch);
            }
        }

        return ans;
    }
};
