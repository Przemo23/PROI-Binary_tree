#include <iostream>
#include "node_header.h"


using namespace std;




node::node(int number)
{
    value=number;
    left_leaf = NULL;
    right_leaf = NULL;
}


