#ifndef LISTBST_H
#define LISTBST_H

#include "BST.hpp"
#include <iostream>
#include <stdexcept>

/**
 * Binary Search Tree implementation using linked list structure
 * 
 * @tparam Key - The type of keys stored in the BST
 * @tparam Value - The type of values associated with keys
 */
template <typename Key, typename Value>
class ListBST : public BST<Key, Value> {
private:
    /**
     * Node class for the binary search tree
     */
    class Node {
    public:
        Key key;
        Value value;
        Node* left;
        Node* right;
        
        Node(Key k, Value v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };
    
    Node* root;
    size_t node_count;
    
    // TODO: Implement private helper functions as needed
    // Start your private helper functions here
        Node* insert(Node* node, Key key, Value value){

            if(!node){
                

                Node* new_node=new Node(key,value);
                

                return new_node;
            }

            if(node->key>key){
                node->left=insert(node->left, key, value);
            }else if(node->key<key){
                node->right=insert(node->right,key,value);
            }
          

            return node;
        }

        Node* MinNode(Node* node)const{

            while(node && node->left){

                node= node->left;
            }

            return node;
        }

        Node* remove(Node* root, Key key){

            if(!root){
                return NULL;
            }

            if(root->key > key){
                root->left=remove(root->left,key);
                
            }else if(root->key < key){
                root->right=remove(root->right,key);

            }else{

                //no child

                if(!root->left && !root->right){
                    delete root;
                    //node_count--;
                    return NULL;
                }

                //1 child 

                else if(!root->left){

                    Node* temp=root->right;

                    delete root;
                    //node_count--;

                    return temp;
                }

                else if(!root->right){
                    Node* temp=root->left;

                    delete root;
                    //node_count--;

                    return temp;
                }

                //2 children 

                else{

                    Node* replace= MinNode(root->right);

                    root->key=replace->key;
                    root->value=replace->value;

                    root->right=remove(root->right, replace->key);
                }

            }

            return root;
        }

        bool isAvailable(Node* node, Key key)const{

          while(node!=NULL){

             if(key==node->key){
                return true;
             }
             else if(node->key > key){
                node=node->left;
             }else{
                node=node->right;
             }
          }

          return false;
        }

        
        Node* getNode(Node* node, Key key)const{

            while(node!=NULL){

                if(key==node->key){
                    return node;
                }
                else if(node->key > key){
                    node=node->left;
                }else{
                    node=node->right;
                }
            }

            throw std:: runtime_error("key not found");
        }

        void clear(Node* root){

            if(root){
                clear(root->left);
                clear(root->right);
                delete root;
            }
        }


        void printInOrder(Node* root)const{

            if(!root)
            return;

            printInOrder(root->left);
            std::cout<<"(" <<root->key<<":"<<root->value<<" )"<<" ";
            printInOrder(root->right);
        }

        void printPreOrder(Node* root)const{

            if(!root) return;

            std:: cout<<"("<<root->key<<":"<<root->value<<")";
            printPreOrder(root->left);
            printPreOrder(root->right);

        }

        void printPostOrder(Node* root)const{

            if(!root) return;

            printPostOrder(root->left);
            printPostOrder(root->right);

            std:: cout<<" ("<<root->key<<":"<<root->value<<")";

        }

        void printDefault(Node* root)const{

            if(!root) return;

            std:: cout<<"("<<root->key<<":"<<root->value;

            if(root->left || root->right){

                std:: cout<<" ";
                if(root->left){
                    printDefault(root->left);
                }else{
                    std:: cout<<"()";
                }

                if(root->right){

                    std:: cout<<" ";
                    printDefault(root->right);

                }
            }

            std::cout<<")";

        }
    // End your private helper functions here

public:
    /**
     * Constructor
     */
    ListBST() : root(nullptr), node_count(0) {}
    
    /**
     * Destructor
     */
    ~ListBST() {
        // TODO: Implement destructor to free memory
        clear();

    }
    
    /**
     * Insert a key-value pair into the BST
     */
    bool insert(Key key, Value value) override {
        // TODO: Implement insertion logic

        if(find(key)) return false; //already exists

        root=insert(root,key,value);
        node_count++;
        return true;


    }
    
    /**
     * Remove a key-value pair from the BST
     */
    bool remove(Key key) override {
        // TODO: Implement removal logic

       if(!find(key)) return false;

       root=remove(root,key);
       node_count--;
       return true;

    }
    
    /**
     * Find if a key exists in the BST
     */
    bool find(Key key) const override {
        // TODO: Implement find logic
        Node* current=root;

        while(current){

            if (key== current->key){

                return true;
            }

            current= current->key > key ? current->left: current->right;
        }

        return false;

    }

    /**
     * Find a value associated with a given key
     */
    Value get(Key key) const override {
        // TODO: Implement get logic

        Node* temp=getNode(root,key);

        return temp->value;

    }

    /**
     * Update the value associated with a given key
     */
    void update(Key key, Value value) override {
        // TODO: Implement update logic

        Node* temp= getNode(root,key);

        temp->value=value;
    }

    /**
     * Clear all elements from the BST
     */
    void clear() override {
        // TODO: Implement clear logic
        clear(root);
        root=NULL;
        node_count=0;

    }
    
    /**
     * Get the number of keys in the BST
     */
    size_t size() const override {
        // TODO: Implement size logic
        return node_count;

    }
    
    /**
     * Check if the BST is empty
     */
    bool empty() const override {
        // TODO: Implement empty check logic

        return node_count==0;

    }
    
    /**
     * Find the minimum key in the BST
     */
    Key find_min() const override {
        // TODO: Implement find_min logic

        if(!root) throw std::runtime_error("Tree is empty");

        Key k=MinNode(root)->key;

        return k;

    }
    
    /**
     * Find the maximum key in the BST
     */
    Key find_max() const override {
        // TODO: Implement find_max logic

        if(!root) throw std::runtime_error("tree is empty");

        Node* current=root;

        while(current->right){
            current=current->right;
        }

        return current->key;

    }

    /**
     * Print the BST using specified traversal method
     */
    void print(char traversal_type = 'D') const override {
        // TODO: Implement print logic

        if(traversal_type=='i' || traversal_type=='I'){

            //std::cout<<"BST (In-order): ";
            printInOrder(root);

        }else if(traversal_type=='d' || traversal_type=='D'){
           // std::cout<<"BST (Default): ";
            printDefault(root);

        }else if(traversal_type=='O' || traversal_type=='o'){
           // std:: cout<<"BST (Post-order): ";
           printPostOrder(root);

        }else if(traversal_type=='p' || traversal_type=='P'){
           // std::cout<<"BST (Pre-order): ";
            printPreOrder(root);
        }
        
        std::cout<<std::endl;
    }
    
};

#endif //LISTBST_H