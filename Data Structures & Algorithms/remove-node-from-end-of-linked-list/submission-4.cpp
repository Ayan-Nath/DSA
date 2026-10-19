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
    ListNode* reverseLL(ListNode* &head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* f=curr->next;
            curr->next=prev;
            prev=curr;
            curr=f;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL) return NULL;
       ListNode* rev=reverseLL(head); 
       if(n==1){
        ListNode* temp=rev;
        rev=rev->next;
        temp->next=NULL;
        delete temp;
        return reverseLL(rev);
       }
       ListNode* temp=rev;
      int i=0;
      ListNode* prev=temp;
      while(i<n-1){
         prev=temp;
        temp=temp->next;
        i++;
      }
      ListNode* f=temp->next;
      temp->next=NULL;
      prev->next=f;
      delete temp;
      
      return reverseLL(rev);
    }
};
