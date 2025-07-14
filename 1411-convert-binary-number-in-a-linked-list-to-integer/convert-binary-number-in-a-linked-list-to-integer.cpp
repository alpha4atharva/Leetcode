/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string str="";
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val==0) str+='0';
            else str+='1';
            temp=temp->next;
        }

        int ans=0,p=0;
        for(int i=str.length()-1;i>=0;i--){
            if(str[i]=='1'){
                ans+=pow(2,p);
            }
            p++;
        }
        return ans;

    }
};