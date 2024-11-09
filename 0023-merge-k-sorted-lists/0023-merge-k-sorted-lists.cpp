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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<lists.size();i++){
            ListNode*cur=lists[i];
            while(cur){
                pq.push(cur->val);
                cur=cur->next;
            }
        }
        ListNode* head=new ListNode(0);
        ListNode* cur=head;
        while(!pq.empty()){
            ListNode* n=new ListNode(pq.top());
            pq.pop();
            cout<<n->val<<" ";
            // if(cur==NULL){
            //     cur=n;
            //     continue;
            // }
            cur->next=n;
            cur=n;
        }
        return head->next;
    }
};