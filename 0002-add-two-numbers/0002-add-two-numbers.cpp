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
        ListNode* ans= new ListNode (-1);
        ListNode* temp=ans;
        int carry=0;
        int add=0;

        while(l1 && l2){
            add=(l1->val+l2->val+carry)%10;
            carry=(l1->val+l2->val+carry)/10;
            ListNode* nnode=new ListNode(add);
            temp->next=nnode;
            temp=temp->next;

            l1=l1->next;
            l2=l2->next;
        }

        while(l1){
            add=(l1->val+carry)%10;
            carry=(l1->val+carry)/10;
            ListNode* nnode=new ListNode(add);
            temp->next=nnode;
            temp=temp->next;

            l1=l1->next;
        }
        while(l2){
            add=(l2->val+carry)%10;
            carry=(l2->val+carry)/10;
            ListNode* nnode=new ListNode(add);
            temp->next=nnode;
            temp=temp->next;

            l2=l2->next;
        }
        if(carry!=0){
            ListNode* nnode=new ListNode(carry);
            temp->next=nnode;
        }

        if(ans->next) return ans->next;
        else return new ListNode(0);
    }
};