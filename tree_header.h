#ifndef TREE_HEADER_H_INCLUDED
#define TREE_HEADER_H_INCLUDED
#include "node_header.h"

class tree
{
    public:
    //constructor
    tree(int);
    //destructor
    ~tree() { destroy_tree(root);}

    //adding and removing nodes
    void add_node(int);
    node* remove_node(node*,int);

    //methods interacting with other trees
    void add_trees(node*);
    void substract_trees(node*);
    bool compare_trees(tree*);

    int counter;
    node *root;

    void print_tree(node*);

    private:
    //methods that are parts of other methods within other methods within other methods etc.
    int get_lenght(node*);
    bool check_if_member(int);
    node* find_parent_node(int,node*);
    int get_size(node*);
    node* get_node(int);
    int get_value(int);
    void destroy_tree(node*);
    node* min_value_node( node*);
    bool compare_nodes(node*,node*);





    //operators, not working yet
    tree* operator+=(const tree& temp)
    {add_trees(temp.root);
        return this;}
    tree* operator-=(const tree& temp)
     {substract_trees(temp.root);
     return this;}
     bool operator==( tree*& temp)
     {
         return compare_trees(temp);

     }








};

#endif // TREE_HEADER_H_INCLUDED
