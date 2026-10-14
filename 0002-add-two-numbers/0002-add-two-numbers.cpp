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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1, *temp2 = l2;
        int carry = 0;
        ListNode *ans = new ListNode(), *temp = ans;
        while(temp1 != NULL && temp2 != NULL){
            int x1 = temp1->val, x2 = temp2->val;
            int sum = x1+x2+carry;
            if(sum > 9){
                sum = sum%10;
                carry = 1;
            }else{
                carry = 0;
            }
            ListNode *dig = new ListNode(sum);
            temp->next = dig;
            temp = dig;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1 != NULL){
            int sum = carry+temp1->val;
            if(sum > 9){
                sum = sum%10;
                carry = 1;
            }else{
                carry = 0;
            }
            ListNode *dig = new ListNode(sum);
            temp->next = dig;
            temp = dig;
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            int sum = carry+temp2->val;
            if(sum > 9){
                sum = sum%10;
                carry = 1;
            }else{
                carry = 0;
            }
            ListNode *dig = new ListNode(sum);
            temp->next = dig;
            temp = dig;
            temp2 = temp2->next;
        }
        if(carry == 1){
            ListNode *dig = new ListNode(1);
            temp->next = dig;
            temp = dig;
        }
        return ans->next;
    }
};