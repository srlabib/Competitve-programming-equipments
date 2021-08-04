#include<bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node {
    int data;
    Node * previous;
    Node * next;
};

Node * create_node(int item, Node * previous, Node * next) {
    Node * new_node = (Node * ) malloc(sizeof(Node));
    new_node -> data = item;
    new_node -> next = next;
    new_node -> previous = previous;
    return new_node;
}

Node * prepend(Node * head, int item) {
    Node * new_node = create_node(item, NULL, head);
    if (head != NULL)
        head -> previous = new_node;
    return new_node;
}
Node * append(Node * head, int item) {
    Node * new_node = create_node(item, NULL, NULL);
    if (head != NULL) {
        Node * curr = head;
        while (curr -> next != NULL) {
            curr = curr -> next;
        }
        curr -> next = new_node;
        new_node -> previous = curr;
        return head;
    }
    return new_node;
}
Node * search_node(Node * head, int item) {
    Node * curr = head;
    while (curr != NULL) {
        if (curr -> data == item) break;
        curr = curr -> next;
    }
    return curr;
}
Node * get_index(Node * head, int index) {
    Node * curr = head;
    int indx = 0;
    while (curr != NULL) {
        if (indx == index) break;
        curr = curr -> next;
        indx++;
    }
    return curr;
}
void insert_node(Node * node, int item) {
    Node * new_node = create_node(item, node, node -> next);
    node -> next = new_node;
    new_node -> next -> previous = new_node;
}
Node * remove_node(Node * head, Node * node) {
    if (node == NULL) return head;
    if (head == node) {
        head = node -> next;
        head -> previous = NULL;
        free(node);
        return head;
    }
    node -> previous -> next = node -> next;
    if (node -> next != NULL)
        node -> next -> previous = node -> previous;

    free(node);
    return head;
}

void print_linked_list(Node * head) {
    Node * curr = head;
    while (curr != NULL) {
        cout << curr -> data << " ";
        curr = curr -> next;
    }
    cout << endl;
}
void print_reversed_linked_list(Node * head) {
    Node * curr = head;
    while (curr -> next != NULL)
        curr = curr -> next;
    while (curr != NULL) {
        cout << curr -> data << " ";
        curr = curr -> previous;
    }
    cout << endl;
}

int main() {
    Node * mynode = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char command;
        cin >> command;
        int inp, ind;
        switch (command) {
        case 'a':
            cin >> inp;
            mynode = append(mynode, inp);
            break;

        case 'p':
            cin >> inp;
            mynode = prepend(mynode, inp);
            break;
        case 'r':
            cin >> inp;
            mynode = remove_node(mynode, search_node(mynode, inp));
            break;

        case 's':
            cin >> inp;
            if (search_node(mynode, inp) != NULL)
                printf("Node found!\n");
            else
                printf("Node doesn't exist!\n");
            break;

        case 'i':
            cin >> ind >> inp;
            insert_node(get_index(mynode, ind), inp);
            break;

        default:
            break;
        }
        print_linked_list(mynode);
    }
    return 0;
}
