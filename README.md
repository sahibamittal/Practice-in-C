# DS-in-C
I'm practicing data structures in C, will continue uploading more for reference. 

*Single Linked List*
- use of double pointers
- edge cases included
- follow link https://www.learn-c.org/en/Linked_lists for step-wise understanding (good tutorial)

Basic Operations :
- void printList(node * head);
- void push_in_end(node ** head, int n);
- void push_in_beg(node ** head, int n);
- void push_after_value(node * head, int curr, int n);
- void push_before_value(node ** head, int curr, int n);
- int pop_beg(node ** head);
- int pop_end(node ** head);
- int pop_by_val(node ** head, int val);
- int pop_by_index(node ** head, int i);
- void reverse_list(node ** head);
- int fib(int n); // factorial
- void recursive_reverse(node ** head);

*BST - Binary Search Tree*
- use of recursion
- edge cases covered
- re-usability using method 'initiate_node'

Basic Operations :
- void initiate_node(node ** new_node, int val);
- void insert(node ** root, int val);
- void printDFS(node * root);
- struct node * search(node * root, int val);
- void remove_node(node ** root, int val);
- struct node * find_min(node * root);
- struct node * find_max(node * root);
- struct node * search_next_highest(node * root, int val);
- bool isBST(node * root, int min, int max);
