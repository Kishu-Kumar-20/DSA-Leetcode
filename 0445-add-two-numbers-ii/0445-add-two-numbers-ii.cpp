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
    ListNode* addTwo(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1, *temp2 = l2;
        int carry = 0;
        ListNode *ans = new ListNode(), *temp = ans;
        while(temp1 != NULL || temp2 != NULL){
            int sum = carry;
            if(temp1) sum += temp1->val;
            if(temp2) sum += temp2->val;
            carry = sum/10;
            ListNode *dig = new ListNode(sum%10);
            temp->next = dig;
            temp = dig;
            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }
        if(carry == 1){
            ListNode *dig = new ListNode(1);
            temp->next = dig;
            temp = dig;
        }
        return ans->next;
    }
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
        return reverseList(addTwo(reverseList(l1), reverseList(l2)));
    }
};