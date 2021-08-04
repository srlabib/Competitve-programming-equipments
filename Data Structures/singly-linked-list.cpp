#include <bits/stdc++.h>

using namespace std;

typedef struct node Node;
struct node
{
    int data;
    Node *next;
};

Node *create_node(int item, Node *next)
{
    Node *new_node;
    new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("error! could not create a node!\n");
        exit(1);
    }
    //printf("Node Created\n");
    new_node->data = item;
    new_node->next = next;

    return new_node;
}

Node *prepend(Node *head, int item)
{
    Node *new_node;
    new_node = create_node(item, head);
    return new_node;
}


Node *append(Node *head, int item)
{
    Node *new_node = create_node(item, NULL);

    if (head == NULL)
        return new_node;

    Node *curr_node = head;

    while (curr_node->next != NULL)
    {
        curr_node = curr_node->next;
    }
    curr_node->next = new_node;

    return head;
}


Node *remove_node(Node *head, Node *node)
{
    if (node == head)
    {
        head = node->next;
        free(node);
        return head;
    }
    if (node == NULL)
        return head;
    Node *curr_node = head;
    while (curr_node != NULL)
    {
        if (curr_node->next == node)
            break;
        curr_node = curr_node->next;
    }
    if (curr_node == NULL)
    {
        return head;
    }
    curr_node->next = node->next;
    free(node);
    return head;
}


Node *search_node(Node *head, int item)
{
    Node *curr_node = head;
    while (curr_node != NULL)
    {
        if (curr_node->data == item)
        {
            return curr_node;
        }
        curr_node = curr_node->next;
    }
    return NULL;
}


void print_linked_list(Node *head)
{
    Node *curr_node = head;
    while (curr_node != NULL)
    {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("\n");
}

int main()
{
    Node *mynode = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char command;
        cin >> command;
        int inp;
        switch (command)
        {
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

        default:
            break;
        }
        print_linked_list(mynode);
    }
    return 0;
}
