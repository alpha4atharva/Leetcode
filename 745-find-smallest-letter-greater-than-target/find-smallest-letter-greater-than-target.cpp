class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans=CHAR_MAX;
        int i=0,j=letters.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(letters[mid]>target){
                ans=letters[mid];
                j=mid-1;
            }
            else i=mid+1;
        }
        return ans==CHAR_MAX?letters[0]:ans;
    }
};