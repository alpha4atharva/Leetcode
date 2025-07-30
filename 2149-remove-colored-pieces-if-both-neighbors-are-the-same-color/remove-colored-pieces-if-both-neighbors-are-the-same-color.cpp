class Solution {
public:
    bool winnerOfGame(string colors) {
        int a=0,b=0;
        int i=1,c=0;
        while(i<colors.length()){
            while(colors[i-1]==colors[i]){
                c++;
                i++;
            }
            if(colors[i-1]=='A'){
                a+=max(0,c-1);
            }
            else{
                b+=max(0,c-1);
            }
            i++;
            c=0;
        }

        return a>b;
    }
};