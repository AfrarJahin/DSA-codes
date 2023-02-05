#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;

};

node *root = NULL;
///*************APPEND OPERATION****************

void append_node(int new_data)
{
    if(root == NULL) ///if the list is EMPTY
    {
        root = new node();///create a new node in root
        root -> data = new_data;
        root -> next = NULL;
    }
    else
    {
        node *current_node = root; ///make a copy of the root node

        while(current_node->next!= NULL)///until it finds the last node of the linked list
        {
            current_node = current_node->next; ///go to next address
        }
        node *new_node;
        new_node = new node();///create a new node to store new_data
        new_node -> data = new_data;
        new_node -> next = NULL;
        current_node -> next = new_node; ///link the new_node with current_node
    }
}


///******************DELETE OPERATION*******************

void delete_node(int dlt_data)
{
    node *current_node = root;
    node *previous_node = NULL;

    while(current_node->data != dlt_data) ///search which node to delete
    {
        previous_node = current_node; ///save the previous node
        current_node = current_node -> next;
    }
    if(current_node == root)
    {
        root = root->next;
        delete(current_node);///delete function is used to free memory
    }
    else
    {
        previous_node -> next = current_node -> next;
        delete(current_node);
    }
}

int main()
{
    append_node(10);
    append_node(2);
    append_node(9);
    append_node(8);

    ///****printing the nodes*******
    node *curr = root;
    while(curr -> next != NULL)
    {
        cout << curr -> data << " ";
        curr = curr->next;
    }
    cout<< curr -> data<<endl;

    delete_node(10);
    delete_node(9);

    ///****printing the nodes after deleting some nodes*******
    curr = root;
    if(root!=NULL)
    {
        while(curr -> next != NULL)
        {
            cout << curr -> data << " ";
            curr = curr->next;
        }
        cout<< curr -> data<<endl;
    }

}
