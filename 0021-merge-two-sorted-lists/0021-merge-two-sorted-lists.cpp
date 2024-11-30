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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans=new ListNode(0);
        ListNode* cur=ans;
        while(list1 && list2){
            int d;
            if(list1->val<list2->val){
                d=list1->val;
                list1=list1->next;
            }
            else{
                 d=list2->val;
                list2=list2->next;
            }
            ListNode* newn=new ListNode(d);
            cur->next=newn;
            cur=newn;
        }
        while(list1){
            int d=list1->val;
                list1=list1->next;
                ListNode* newn=new ListNode(d);
            cur->next=newn;
            cur=newn;
        }
        while(list2){
            int d=list2->val;
                list2=list2->next;
                ListNode* newn=new ListNode(d);
            cur->next=newn;
            cur=newn;
        }
        ans=ans->next;
        return ans;
    }
};