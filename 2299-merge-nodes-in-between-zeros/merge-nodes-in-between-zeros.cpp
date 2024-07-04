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
    ListNode* mergeNodes(ListNode* head) {
        int cur=0;
        ListNode * prev=head;
        ListNode * p_prev=prev;
        ListNode * temp=head->next;

        while(temp!=NULL){

            if(temp->val!=0){
                cur=cur+temp->val;
            }
            else{
                prev->val=cur;
                cur=0;
                p_prev=prev;
                prev=prev->next;
            }
            temp=temp->next;
        }
        p_prev->next=NULL;
        return head;
    }
};