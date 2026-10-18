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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *n1 = head, *n2 = n1->next;
        ListNode *last, *first = n2; 
        while(n1 != nullptr || n2 != nullptr){
            if(n1&&n2) n1->next = n2->next;
            if(n1) last = n1;
            if(n1) n1 = n1->next;
            if(n2&&n1) n2->next = n1->next;
            if(n2) n2 = n2->next;
        }
        last->next = first;
        return head;
    }
};