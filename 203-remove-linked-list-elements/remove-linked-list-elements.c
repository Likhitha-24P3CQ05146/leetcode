/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* insert_at_tail(struct ListNode* new_head, int x){
    //node creation
    	struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        new_node->val=x;
        new_node->next=NULL;
        	if (new_head == NULL) 
	{
		new_head = new_node;
	}
	else
	{
        //reach the last node
		struct ListNode *temp =new_head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new_node;
	}
    return new_head;
 }
struct ListNode* removeElements(struct ListNode* head, int val) {
    		struct ListNode *temp=head;
            struct ListNode *new_head=NULL;
            while(temp!=NULL){
                if(temp->val!=val)
                    new_head=insert_at_tail(new_head,temp->val);
                    temp=temp->next;
                
            }
            return new_head;
}