#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;

struct node{
    int data;
    Node *parent;
    Node *left;
    Node *right;
};

Node *create_Node(int item)
{
    Node *new_node = (Node*)malloc(sizeof(Node));

    if(new_node == NULL)
    {
        printf("Error! Could not create a new node\n");
        exit(1);
    }

    new_node->data  = item;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void add_left_child(Node *node, Node *child)
{
    node->left = child;
    if(child!=NULL){
        child->parent = node;
    }
}

void add_right_child(Node *node,Node *child)
{
    node->right = child;
    if(child!=NULL){
        child->parent = node;
    }
}

//This function needs Create_node(), add_left_child() and add_right child() funtion
Node *bst_insert(Node *root,Node *node)
{
    Node *parent_node, *current_node;
    if(root == NULL){
        root = node;
        return root;
        return root;
    }

    parent_node = NULL;
    current_node = root;
    while (current_node!= NULL)
    {
        parent_node = current_node;
        if(node->data < current_node->data)
            current_node = current_node->left;
        else current_node = current_node->right;
    }

    if(node->data < parent_node->data)
        add_left_child(parent_node,node);
    else add_right_child(parent_node,node);
    
    return root;
}

Node *bst_search(Node *root,int item)
{
    Node *node = root;
    while(node!=NULL)
    {
        if(node->data == item)return node;
        if(item<node->data)node = node->left;
        else node = node->right;
    }
    return node;
}


Node *bst_minimum(Node *root)
{
    Node *node = root;
    while (node->left!=NULL){
        node = node->left;
    }
    return node;
}

Node *bst_transplant(Node *root,Node* current_node, Node * new_node)
{
    if(current_node == root)
    {
        root = new_node;
    }
    else if(current_node == current_node->parent->left){
        add_left_child(current_node->parent,new_node);
    }
    else {
        add_right_child(current_node->parent,new_node);
    }
    return root;
}

Node *bst_delete(Node *root, Node * node)
{
    Node *smallest_node;
    if(node->left == NULL)
    {
        root = bst_transplant(root,node,node->right);
    }
    else if(node->right == NULL)
    {
        root  = bst_transplant(root,node,node->left);
    }
    else{
        smallest_node  = bst_minimum(node->right);
        if(smallest_node->parent!=node)
        {
            root = bst_transplant(root,smallest_node,smallest_node->right);
            add_right_child(smallest_node,node->right);
        }
        root = bst_transplant(root,node,smallest_node);
        add_left_child(smallest_node,node->left);
    }
    free(node);
    return root;
}


void travarse_tree(Node *tree)
{
    if(tree!=NULL)
    {
        travarse_tree(tree->left);
        cout << tree->data << " ";
        travarse_tree(tree->right);
    }
}


int main()
{
    Node *bst_tree = NULL;

    while(1)
    {
        string command;
        int input;
        cin>>command;
        if(command=="add"){
            cin >> input;
            Node *new_node = create_Node(input);
            bst_tree = bst_insert(bst_tree,new_node);
        }
        else if(command == "delete")
        {
            cin >> input;
            Node *node = bst_search(bst_tree,input);
            if(node!=NULL)bst_tree = bst_delete(bst_tree,node);
            else cout<<"Could not find the element"<<endl;
        }
        else if(command == "exit")break;
        else cout<<"invalid command!\n";
        travarse_tree(bst_tree);cout<<endl;
    }

    return 0;
}
