class MyLinkedList {
public:
    ListNode* head;
    int num_elems;
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        num_elems = 0;
    }
    
    void printList() {
        for (ListNode* idx = head; idx != NULL; idx = idx->next)
            cout << idx->val << " , ";
        cout << endl;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= num_elems || index < 0) return -1;
        int counter = 0;
        ListNode* idx = head;
        while (counter < index) {
            counter++;
            idx = idx->next;
        }
        return idx->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        num_elems++;
        if (head == NULL) {
            head = new ListNode(val);
            return;
        }
        ListNode* node = new ListNode(val);
        node->next = head;
        head = node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        num_elems++;
        if (head == NULL) {
            head = new ListNode(val);
            return;
        }
        ListNode* idx = head;
        while(idx->next != NULL)
            idx = idx->next;
        idx->next = new ListNode(val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > num_elems)
            return;
        num_elems++;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == num_elems) {
            addAtTail(val);
            return;
        }
        
        int counter = 0;
        ListNode* idx = head;
        while (counter + 1 < index) {
            idx = idx->next;
            counter++;
        }
        ListNode* last = idx->next;
        ListNode* next = new ListNode(val);
        idx->next = next;
        next->next = last;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= num_elems)
            return;
        num_elems--;
        if (index == 0) {
            head = head->next;
            return;
        }
        int counter = 0;
        ListNode* idx = head;
        while (counter + 1 < index) {
            idx = idx->next;
            counter++;
        }
        ListNode* del = idx->next;
        idx->next = del->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */