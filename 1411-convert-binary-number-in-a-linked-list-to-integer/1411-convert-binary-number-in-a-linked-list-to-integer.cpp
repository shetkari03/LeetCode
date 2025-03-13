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
        int a=1,ans=0;
        ListNode*cur=head;
        while(cur){
            a=a*2;
            cur=cur->next;
        }
        a=a/2;
        cur=head;
        while(cur){
            if(cur->val)ans+=a;
            a=a/2;
            cur=cur->next;
        }
        return ans;
    }
};