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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *lTmp = new ListNode(0);
        int sum = 0;
        ListNode *cur= lTmp;
        ListNode *p1 = l1, *p2 = l2;
        while((p1 != NULL)||(p2 != NULL)){
            if(p1 != NULL){
                sum += p1->val;
                p1 = p1->next;
            }
            if(p2 != NULL){
                sum += p2->val;
                p2 = p2->next;                
            }
            cur->next = new ListNode(0);
            cur = cur->next;            
            cur->val = sum%10;
            sum = sum/10;
        }
        if(sum){
            cur->next = new ListNode(sum);
        }
        return lTmp->next;
    }
};


/*使用下面的写法耗时减少接近50%*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        int carry = 0;
        while (l1 || l2) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) cur->next = new ListNode(1);
        return dummy->next;
    }
};
