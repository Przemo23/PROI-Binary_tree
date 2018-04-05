#include <iostream>
#include "node_header.h"
#include "tree_header.h"
#include <cstdlib>
#include<vector>
#include<limits>
#include<cstdio>
#include<conio.h>
using namespace std;

tree* initialize_tree()
{
    int n;
    cout<<"What's the number you want to use as the root"<<endl;
    cin>>n;
    bool check=cin.good();
    if(!check)
    {
        cin.clear();
        cin.sync();
        return nullptr;
    }
    tree* temp=new tree(n);

    cout<<"Write down the numbers you want to add to the tree"<<endl;
    do
    {
        cin>>n;
        bool check=cin.good();
        if(!check)
        {
            cin.clear();
            cin.sync();
            break;
        }
        temp->add_node(n);
    }while(true);
    return temp;

}

int main()
{
    vector<tree*> trees;
    trees.push_back(initialize_tree());

    int current = 0;

	bool exit = false;

	do
	{
		cout << "Choose what to do: " << endl;
		cout << "1. Initialize new tree (it will become your current tree)" << endl;
		cout << "2. Add nodes" << endl;
		cout << "3. Remove nodes" << endl;
		cout << "4. Create a copy of your current tree" << endl; // the copy will be placed at the and of the vector, your current tree will remain the same
		cout << "5. Show current tree" << endl;
		cout << "6. Switch trees" << endl;
		cout << "7. Add another tree to current tree" << endl;
		cout << "8. Subtract another tree from current tree" << endl;
		cout << "9. Compare another tree to the current one" << endl;
		cout << "Your current tree nr."<<current<<endl;

		int n;
		cin>>n;

		switch(n)
		{
		case 1:
			trees.push_back(initialize_tree());
			current = trees.size() - 1;
			break;
		case 2:
			cout<<"Write down the number you want to add to the tree."<<endl;
			int a;
			if(cin>>a) trees[current]->add_node(a);
			else cout<<"Wrong data"<<endl;
			break;
		case 3:
			cout<<"Write down the number you want to remove from the tree."<<endl;
			int b;
			if(cin>>b) trees[current]->remove_node(trees[current]->root,b);
			else cout<<"Wrong data"<<endl;
			break;
		case 4:
			{
                tree* temp=new tree(trees[current]->root->value);
                temp->add_trees(trees[current]->root);
                trees.push_back(temp);
                break;
			}
		case 5:

			trees[current]->print_tree(trees[current]->root);
			getch();
			break;
		case 6:
			{cout<<"Write the number of the tree you want to switch to (starting from 0)"<<endl;
			int index;
			cin>>index;
			bool check=cin.good();
            if(!check)
            {
                cin.clear();
                cin.sync();
                break;
            }
			if(index>=0 && index<=trees.size()-1) current=index;
			else cout<<"There is no tree with such index"<<endl;
			break;}
		case 7:
		    {
		        cout<<"Write the number of the tree you want to add to the current one"<<endl;
			int index;
			cin>>index;
			bool check=cin.good();
            if(!check)
            {
                cin.clear();
                cin.sync();
                break;
            }

                if(index>=0 && index<=trees.size()-1 && index!=current) trees[current]->add_trees(trees[index]->root);
                    //trees[current] += trees.at(index);
                break;
			}
		case 8:
		{
		    cout<<"Write the number of the tree you want to substract from the current one"<<endl;
			int index;
			cin>>index;
			bool check=cin.good();
            if(!check)
            {
                cin.clear();
                cin.sync();
                break;
            }
                if(index>=0 && index<=trees.size()-1 && index!=current) trees[current]->substract_trees(trees[index]->root);


                break;
        }
        case 9:
        {
             cout<<"Write the number of the tree you want to compare to the current one"<<endl;
			int index;
			cin>>index;
			bool check=cin.good();
            if(!check)
            {
                cin.clear();
                cin.sync();
                break;
            }
                if(index>=0 && index<=trees.size()-1 && index!=current)
                    {
                        if(true==/*trees[current]->compare_trees(trees[index])*/(trees[current]==trees[index])) cout<<"Those trees are the same."<<endl;
                        else cout<<"Those are two different trees"<<endl;
                    }
                    getch();
                    break;
        }
		default:
        exit = true;
		}
		system("cls");
	}while(!exit);
}





