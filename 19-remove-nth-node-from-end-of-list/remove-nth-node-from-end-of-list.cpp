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
        int count=0;
        ListNode * temp=head;

        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        
        ListNode * tmp=head;
        int st=count-n;
        if(n==1){
            for(int i=0;i<count-2;i++){
                tmp=tmp->next;
            }
            if(count==1){
                return NULL;
            }
            tmp->next=NULL;
            return head; 
        }

        if(n==count){
            return head->next;
        }

        ListNode * cur=head;
        int ch=st-1;

        while(ch>0){
            cur=cur->next;
            ch--;
        }

        cur->next=(cur->next)->next;
        return head;
        
    }
};