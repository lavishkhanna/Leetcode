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
    ListNode* middleNode(ListNode* head) {
        ListNode * temp1=head;
        int count=0;
        while(temp1!=NULL){
            count++;
            temp1=temp1->next;
        }

        ListNode * temp=head;


        int req=count/2;

        for(int i=1;i<=req;i++){
            temp=temp->next;
        }
        return temp;
    }
};