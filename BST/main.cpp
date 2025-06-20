#include <iostream>
#include "BST.hpp"
#include "listBST.hpp"
#include<ctime>
using namespace std;


int randkey()
{
    return rand() % 100;
}

int main()
{
    srand(static_cast<unsigned>(time(0)));
    freopen("output.txt", "w", stdout);

    BST<int, int>* bst = new ListBST<int, int>();
    int key, val;

    cout << "Initializing..." << endl;
    for (int i = 0; i < 20; i++)
    {
        key = randkey();

        
        if (!bst->insert(key, rand() % 10)) cout << key << " already exists" << endl;
        bst->print('I');

    }
    bst->print('I');
    cout << "Size: " << bst->size() << endl;
    cout << endl;

}