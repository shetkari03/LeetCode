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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int ct=0;
        ListNode* cur=head;
        ListNode* pre=head;
        int m=0;
        while(cur){
            m++;
            cur=cur->next;
        }
        int k=m-n;
        cur=head;
        while(k--){
            pre=cur;
            cur=cur->next;
        }
        if(cur==head){
            head=cur->next;
            return head;
        }
        else{
            pre->next=cur->next;
            
            return head;
        }
        //cout<<(cur!=NULL?cur->val:1)<<endl;
        //cout<<m<<endl;
        return head;
    }

};