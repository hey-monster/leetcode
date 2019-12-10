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
