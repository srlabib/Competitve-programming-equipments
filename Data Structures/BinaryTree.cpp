/****Bismillahir rahmanir rahim****/

#include<bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node {
    int data;
    Node * left;
    Node * right;
};

Node * create_node(int item)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL)
    {
        printf("Error! Could not create a node\n");
        exit(1);
    }

    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void add_left_child(Node *node, Node *child)
{
    node->left = child;
}

void add_right_child(Node *node, Node *child)
{
    node->right = child;
}

void pre_order(Node *root)
{
    if(root == NULL)return;
    printf("%d ",root->data);
    pre_order(root->left);
    pre_order(root->right);
    return;
}

void post_order(Node *root)
{
    if(root == NULL)return;
    post_order(root->left);
    post_order(root->right);
    printf("%d ",root->data);
}

void in_order(Node *root)
{
    if(root == NULL)return;
    in_order(root->left);
    printf("%d ",root->data);
    in_order(root->right);
}

Node *create_tree()
{
    Node *two  = create_node(2);
    Node *seven = create_node(7);
    Node *nine = create_node(9);
    add_left_child(two,seven);
    add_right_child(two,nine);

    Node*one = create_node(1);
    Node *six = create_node(6);
    add_left_child(seven,one);
    add_right_child(seven,six);

    Node *five = create_node(5);
    Node *ten = create_node(10);
    add_left_child(six,five);
    add_right_child(six,ten);

    Node *eight = create_node(8);
    add_right_child(nine,eight);

    Node *three = create_node(3);
    Node *four = create_node(4);
    add_left_child(eight,three);
    add_right_child(eight,four);

    return two;

}

int main()
{

	Node *mynode = create_tree();

    pre_order(mynode);cout << endl;
    post_order(mynode);cout << endl;
    in_order(mynode);cout << endl;

    return 0;
}
