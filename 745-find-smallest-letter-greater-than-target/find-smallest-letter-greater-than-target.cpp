class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans=CHAR_MAX;
        for(int i=0;i<letters.size();i++)
        {
            if(letters[i]> target && ans>letters[i])
                ans=letters[i];
        }
        if(ans==CHAR_MAX)
            return letters[0];
        return ans;
    }
};