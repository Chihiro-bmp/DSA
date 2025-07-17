#include <iostream>
#include <fstream>
#include "listBST.hpp"

using namespace std;

int main(int argc, char **argv) {
    if (argc != 2) {
        cerr << "Usage: filename" << "\n";
        return 1;
    }
    ifstream in_file(argv[1]);
    if (!in_file) {
        cerr << "Unable to open file\n";
        return 2;
    }
    char c, str[5];
    int val;
    BST<int, int> *bst = new ListBST<int, int>();
    if (!bst) {
        cerr << "Memory allocation failed\n";
        return 3;
    }
    while (in_file >> c) {
        // TODO: Implement the logic to read commands from the file and output accordingly
        // After every insertion and removal, print the BST in nested parentheses format
        // Handle exceptions where necessary and print appropriate error messages

        // Start your code here

        try{
        switch(c){

            case 'I':

                in_file>> val;

                if(bst->insert(val,val)){

                    cout<<"Key "<<val<<" inserted into BST, BST (Default): ";
                    bst->print('D');

                }else{

                    cout<<"Insertion failed! Key "<< val<<" already exists in BST, BST (Default): ";
                    bst->print('D');

                }

                break;
            
            case 'D':
                
             in_file>> val;

             if(bst->remove(val)){

                cout<<"Key "<<val<<" removed from BST, BST (Default): ";
                bst->print('D');
             }else{

                cout<<"Removal failed! Key "<<val<<" not found in BST, BST (Default): ";
                bst->print('D');
             }

             break;

            case 'F':

                in_file>>val;

                if(bst->find(val)){

                    cout<<"Key "<<val<<" found in BST.\n";

                }else{

                    cout<<"Key "<<val<<" not found in BST.\n";
                }

                break;

            case 'E':

                if(bst->empty()){

                    cout<<"Empty"<<endl;
                }else{

                    cout<<"Not Empty"<<endl;
                }

                break;

            case 'S':

                cout<<"Size: "<<bst->size()<<endl;
                break;

            
            case 'M':

                in_file>>str;

                if(str[1]=='i'){

                    cout<<"Minimum value: "<<bst->find_min()<<endl;

                }else if(str[1]=='a'){

                    cout<<"Maximum value: "<<bst->find_max()<<endl;
                }
                break;

            case 'T':

                in_file>>str;

                if(str[1]=='n'){

                    cout<<"BST (In-order): ";
                    bst->print('I');

                }else if(str[1]=='r'){

                    cout<<"BST (Pre-order): ";
                    bst->print('P');

                }else if(str[1]=='o'){

                    cout<<"BST (Post-order): ";
                    bst->print('O');
                }

                break;
            
            case 'H':
                 cout<<"Height: "<<bst->height()<<endl;

                 break;
            default:
                cerr<< "Unknown command: "<<c<<endl;

        }

    }catch(const exception& e){

        cerr<<"Error: "<<e.what()<<endl;
    }
        // End your code here
    } 

    in_file.close();
    delete bst;
    return 0;
}

//g++ -std=c++11 task1.cpp -o task1
//./task1 in_task1.txt > myout_task1.txt