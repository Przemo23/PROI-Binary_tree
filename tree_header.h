#ifndef TREE_HEADER_H_INCLUDED
#define TREE_HEADER_H_INCLUDED
#include "node_header.h"

class tree
{
    public:

    tree(int);
    ~tree() { destroy_tree(root);}

    void add_node(int);
    node* remove_node(node*,int);
    int get_lenght(node*);
    bool check_if_member(int);
    node* find_parent_node(int,node*);
    int get_size(node*);
    node* get_node(int);
    int get_value(int);
    void destroy_tree(node*);
     node* min_value_node( node*);


        int counter;
        node *root;



};

#endif // TREE_HEADER_H_INCLUDED
