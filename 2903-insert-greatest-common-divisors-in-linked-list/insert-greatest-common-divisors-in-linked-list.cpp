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
#include <algorithm>

ListNode * func(ListNode * head){
    if(head->next==NULL || head==NULL){
        return head;
    }
    
    ListNode * nxt=func(head->next);
    
    int gcd=__gcd(head->val,nxt->val);
    
    ListNode * mid=new ListNode(gcd);
    
    head->next=mid;
    mid->next=nxt;
    
    return head;
}

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        int n=0;
        ListNode * temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        if(n==1){
            return head;
        }
        
        ListNode * res=func(head);
        
        ListNode * tmps=res;
        while(tmps!=NULL){
            cout<<tmps->val<<" ";
            tmps=tmps->next;
        }
        return res;
        // return temp;
        
    }
};