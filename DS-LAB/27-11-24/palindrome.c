bool isPalindrome(struct ListNode* head) {
    struct ListNode* temp=head;
    if(temp->next==NULL) return true;

    struct ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    temp=slow;
    struct ListNode* prev = NULL;
    struct ListNode* curr = temp;
    struct ListNode* next;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    temp=prev;
    struct ListNode* n1=head;
    struct ListNode* n2=temp;
    for(;n1&&n2;n1=n1->next,n2=n2->next)
    {
        if(n1->val!=n2->val)return false;
    }
    return true;
}
