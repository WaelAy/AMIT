

typedef struct node{
    int data;
    struct node *next;
} node;




node create_LL(int data);
void add_node(node *head,int data);
void printLinkedList(node *head);
void insertAtPos(node *head,int n,int data);
int sizeLL(node *head);
void sortLinkedList(node *head);
void reverseLinkedList(node *head);
int pop(node *head);