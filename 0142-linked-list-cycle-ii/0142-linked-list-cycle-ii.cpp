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
    ListNode *detectCycle(ListNode *head) {

        map<ListNode*,int>omap;

        ListNode * temp=head;

        while(temp!=NULL && omap.count(temp)==0){
            omap[temp]++;
            temp=temp->next;
        }

        return temp;

    }
};