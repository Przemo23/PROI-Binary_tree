#include <iostream>
#include "node_header.h"
#include "tree_header.h"
#include <vector>

using namespace std;


tree::tree(int number)
{
    root=new node(number);
    counter=1;
}

node* tree::find_parent_node(int number,node *present_node) //present_node is at the beginning the root of the whole tree
{
    if(present_node->value==number) return present_node;

    if(!present_node->left_leaf && !present_node->right_leaf) return present_node;

    if(present_node->left_leaf && present_node->value>number)
    {
        present_node=present_node->left_leaf;
        return find_parent_node(number,present_node);
    }
    if(present_node->right_leaf && present_node->value<number)
    {
        present_node=present_node->right_leaf;
        return find_parent_node(number,present_node);
    }
    return present_node;
}

void tree::add_node(int number)//adds value to tree
{
    node *temp=find_parent_node(number,root);

    if(temp->value==number) return;

    if(number>temp->value)
    {

        temp->right_leaf=new node(number);
        counter++;
        return;
    }
    else
    {

        temp->left_leaf=new node(number);
        counter++;
        return;
    }

}

node* find_node(int number,node* node) //function looks for a node with the same value as the given number, the node which we provide is preferred to root, but it will work anyway
{
    if(number==node->value) return node;
    if(number>node->value && node->right_leaf) return find_node(number,node->right_leaf);
    if(number<node->value && node->left_leaf) return find_node(number,node->left_leaf);
    return nullptr;
}

int tree::get_size(node *node) // calculates the number of nodes below the given node +1, not used in project
{
    int size_tree = 1;
    if(!node) return 0;
    size_tree+=get_size(node->left_leaf);
    size_tree+=get_size(node->right_leaf);
    return size_tree;

}




void tree::destroy_tree(node* node) //deletes the given node and all below it
{
    if(node)
    {
        destroy_tree(node->left_leaf);
        destroy_tree(node->right_leaf);
        delete node;
    }
}
 node* tree::min_value_node(node* given_node)
{
    node* temp=given_node;

    // loop down to find the leftmost leaf
    while (temp->left_leaf != NULL) temp = temp->left_leaf;

    return temp;
}

node* tree::remove_node( node* root, int number)
{
    if(!find_node(number,root)) // Checks if there is such number in the tree
    {
        cout<<"There is no such number in the tree like the one you ask."<<endl;
        return root;
    }
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (number < root->value)
        root->left_leaf = remove_node(root->left_leaf, number);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (number > root->value)
        root->right_leaf= remove_node(root->right_leaf, number);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left_leaf == NULL)
        {
            node *temp = root->right_leaf;
            delete root;
            return temp;
        }
        else if (root->right_leaf == NULL)
        {
            node *temp = root->left_leaf;
            delete root;
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
       node* temp = min_value_node(root->right_leaf);

        // Copy the inorder successor's content to this node
        root->value = temp->value;

        // Delete the inorder successor
        root->right_leaf = remove_node(root->right_leaf, temp->value);
    }
    counter--;
    return root;

}
int tree::get_lenght(node* node) // gets the lenght of the longest branch
{
    if(!node) return 0;

    return 1+max(get_lenght(node->left_leaf),get_lenght(node->right_leaf));

}
bool tree::check_if_member(int number) // checks if given value is in the tree
{
    if(find_node(number,root)) return 1;
    else return 0;
}
node* tree::get_node(int number)//gets the node with the called number, if the number isn't in tree returns nothing, otherwise returns the pointer to the node
{
    node* temp=find_node(number,root);
    if(temp) return temp;
    return nullptr;

}
int tree::get_value(int number) // the same as the method above, but returns value
{
    node* temp=find_node(number,root);
    if(temp) return temp->value;
    return -1;
}
void tree::print_tree(node* node)//  prints all values from trees ascending
{
    if(!node) return;
    print_tree(node->left_leaf);
    cout<<node->value<<" ";
    print_tree(node->right_leaf);
}
void tree::add_trees(node* node) // adds a tree to the current tree (adds only those values that haven't been already in the tree)
{
    if(!node) return;
    if(check_if_member(node->value)==0) add_node(node->value);
    add_trees(node->left_leaf);
    add_trees(node->right_leaf);

}
void tree::substract_trees(node* node)//remove from the current tree nodes that are both in current tree and in the given one
{
    if(!node) return;
    substract_trees(node->left_leaf);
    if(check_if_member(node->value)==1) remove_node(root,node->value);
    substract_trees(node->right_leaf);

}
bool tree::compare_nodes(node* current,node* compared)
{

    if(!current && !compared) return true;
    else if(current && compared) return (current->value==compared->value
                                         &&compare_nodes(current->left_leaf,compared->left_leaf)
                                         &&compare_nodes(current->right_leaf,compared->right_leaf));
    else return false;


}

bool tree::compare_trees(tree* temp)//checks if to trees are exactly the same
{
    //if(counter!=temp->counter) return false;
   // if(get_lenght(root)!=temp->get_lenght(temp->root)) return false;
    if(true==compare_nodes(root,temp->root)) return true;
    else return false;



}

