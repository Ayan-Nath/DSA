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
    
    void reverseInKGroups(queue<int> &q,int count, int k){
        int n=q.size();
        //use stack
        if((count+k)>n){
         int remaining=n-count;
         for(int i=0; i<remaining; i++){
            int curr=q.front();
            q.pop();
            q.push(curr);
         }
         return;
        }
        else{
           //stack using
           stack<int> s;
           for(int i=0; i<k;i++){
            int curr=q.front();
            q.pop();
            s.push(curr);
           }
           //now enter datas from stack to queue
           while(!s.empty()){
            int curr=s.top();
            s.pop();
            q.push(curr);
           }
           reverseInKGroups(q,count+k,k);
        }
    }
   
    ListNode* reverseKGroup(ListNode* head, int k) {

        //create a queue to store 
        queue<int> q;
        ListNode* temp=head;
        while(temp!=NULL){
            int c=temp->val;
            q.push(c);
            temp=temp->next;
        }
        //queue is ready now
        //reverse in k grp
        reverseInKGroups(q,0,k);
        ListNode* dummy=new ListNode (-1);
        ListNode* t=dummy;
        while(!q.empty()){
            int curr=q.front();
            t->next=new ListNode (curr);
            t=t->next;
            q.pop();
        }
        return dummy->next;
    }
};