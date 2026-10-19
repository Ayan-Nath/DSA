class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (!head) return NULL;

        unordered_map<Node*, Node*> mp;

        Node* temp = head;

        // 1. Create copy nodes (no pointers yet)
        while (temp) {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        // 2. Assign next and random pointers
        temp = head;
        while (temp) {
            mp[temp]->next = mp[temp->next];      // handles NULL automatically
            mp[temp]->random = mp[temp->random];  // handles NULL automatically
            temp = temp->next;
        }

        return mp[head];
    }
};
