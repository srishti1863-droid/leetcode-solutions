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
int getlength(ListNode* head){
    int l=0;
    while(head!=NULL){
        head=head->next;
        l++;
    }
    return l;
}
    ListNode* swapNodes(ListNode* head, int k) {
        int L=getlength(head);
        int k_1=k;
        ListNode* Node1=head;
        while(k_1>1){
            Node1=Node1->next;
            k_1--;
        }
        int k_2=L-k+1;
        ListNode* Node2=head;
        while(k_2>1){
            Node2=Node2->next;
            k_2--;
        }
        swap(Node1->val,Node2->val);
        return head;
    }
};