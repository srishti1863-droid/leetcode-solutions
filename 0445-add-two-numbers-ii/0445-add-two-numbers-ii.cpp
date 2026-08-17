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
ListNode* reversell(ListNode* head){
    if(!head || !head->next) return head;
    ListNode* last=reversell(head->next);
    head->next->next=head;
    head->next=NULL;
    return last;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reversell(l1);
        l2=reversell(l2);
        int sum=0;
        int carry=0;
        ListNode* ans=new ListNode();
        while(l1!=NULL || l2!=NULL){
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            ans->val=sum%10;
            carry=sum/10;
            ListNode* newNode=new ListNode(carry);
            newNode->next=ans;
            ans=newNode;
            sum=carry;
        }
        if(carry==0){
            return ans->next;
        }
        return ans;
    }
};