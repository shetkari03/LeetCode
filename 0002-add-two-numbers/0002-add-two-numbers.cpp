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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur1=l1;
        ListNode* cur2=l2;
        ListNode* ans= new ListNode(0);
        ListNode* c=ans;
        int carry=0;
        while(cur1!=NULL && cur2!=NULL){
            int d=cur1->val;
            d+=cur2->val;
            d+=carry;
            carry=d/10;
            d=d%10;
            ListNode* n= new ListNode(d);
            c->next=n;
            c=n;
            cur1=cur1->next;
            cur2=cur2->next;
        }
        while(cur1!=NULL){
            int d=cur1->val;
            d+=carry;
            carry=d/10;
            d=d%10;
            ListNode* n= new ListNode(d);
            c->next=n;
            c=n;
            cur1=cur1->next;
        }
        while(cur2!=NULL){
            int d=cur2->val;
            d+=carry;
            carry=d/10;
            d=d%10;
            ListNode* n= new ListNode(d);
            c->next=n;
            c=n;
            cur2=cur2->next;
        }
        if(carry!=0){
            ListNode* n= new ListNode(carry);
            c->next=n;
            c=n;
        }
        ans=ans->next;
        return ans;
    }
};