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
    ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }



    void reorderList(ListNode* head) {
        //find middle of a ll
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next && fast->next->next){
         fast=fast->next->next;
         slow=slow->next;
        }
        ListNode* head1=slow->next;
        slow->next=NULL;
        ListNode* h2=reverseList(head1);
        //take one by one nodes
        ListNode* t1=head;
        ListNode* t2=h2;
        while(t2){
            ListNode* p=t2;
            t2=t2->next;
            p->next=NULL;
            ListNode* q=t1->next;
            p->next=q;
            t1->next=p;
            t1=q;
        }
    }
};
