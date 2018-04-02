#ifndef NODE_HEADER_H_INCLUDED
#define NODE_HEADER_H_INCLUDED

class tree;

class node
{
    friend class tree;

    public:
    int value;
    node *left_leaf,*right_leaf;

    node(int);
   // ~node();





};

#endif // NODE_HEADER_H_INCLUDED
