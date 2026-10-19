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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev, *curr;
        prev = nullptr;
        curr = head;
        while(curr != nullptr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> n1, n2;
        ListNode *p1 = l1, *p2 = l2;
        while(p1 != nullptr || p2 != nullptr){
            if(p1){
                n1.push(p1->val);
                p1 = p1->next;
            }
            if(p2){
                n2.push(p2->val);
                p2 = p2->next;
            }
        }
        int carry = 0;
        ListNode *ans = new ListNode(), *temp = ans;
        while(!n1.empty() || !n2.empty()){
            int sum = carry;
            if(!n1.empty()) sum += n1.top();
            if(!n2.empty()) sum += n2.top();
            carry = sum/10;
            ListNode *dig = new ListNode(sum%10);
            temp->next = dig;
            temp = dig;
            if(!n1.empty()) n1.pop();
            if(!n2.empty()) n2.pop();
        }
        if(carry == 1){
            ListNode *dig = new ListNode(1);
            temp->next = dig;
            temp = dig;
        }
        return reverseList(ans->next);
    }
};