/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* 
    主要考察了链表,不追求算法效率=.=
    62ms
    Your runtime beats 14.81% of cpp submissions

*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int tmp,c=0;
        //ListNode head(0);
        ListNode *head=new ListNode(0);
        ListNode *tail;
        //tail=&head;
        tail=head;
        while(l1!=NULL && l2!=NULL){
            tmp=l1->val+l2->val+c;
            tail->next=new ListNode(tmp%10);
            tail=tail->next;
            c=tmp/10;
            l1=l1->next;
            l2=l2->next;
        }
        
        ListNode* l=(l1==NULL)?l2:l1;
        while(l!=NULL){
            tmp=l->val+c;
            tail->next=new ListNode(tmp%10);
            tail=tail->next;
            c=tmp/10;
            l=l->next;
        }
        /*
        while(l1!=NULL){
            tmp=l1->val+c;
            tail->next=new ListNode(tmp%10);
            tail=tail->next;
            c=tmp/10;
            l1=l1->next;
        }
        
        while(l2!=NULL){
            tmp=l2->val+c;
            tail->next=new ListNode(tmp%10);
            tail=tail->next;
            c=tmp/10;
            l2=l2->next;
        }
        */
        if (c!=0){
           tail->next=new ListNode(c);
        }
        //return head.next;
        return head->next;
    }
};