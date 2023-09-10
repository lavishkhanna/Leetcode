/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,int>omap;
        ListNode * temp=head;
        if(head==NULL || head->next==NULL){
            return false;
        }
        ListNode * slow=head;
        ListNode * fast=head;
        
        while(fast && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }

        // while(temp!=NULL){
        //     if(omap.count(temp)>0){
        //         return true;
        //     }
        //     omap[temp]=1;
        //     temp=temp->next;
        // }
        return false;
    }

};