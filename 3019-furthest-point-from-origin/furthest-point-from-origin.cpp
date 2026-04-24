class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int a=0,b=0,c=0;
        for(auto ch:moves){
            if(ch=='_') a++;
            else if(ch=='L') b++;
            else c++;
        }

        return abs(b-c)+a;
    }
};