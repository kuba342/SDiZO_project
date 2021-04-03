#pragma once

#include "Node.h"

class BRTree
{
private:
    Node* guardian;
    Node* root;
    int size;

public:
    BRTree();
    ~BRTree();
    void inorderTreeWalk(Node* node);
    Node* treeSearch(Node* node, int k);
    Node* treeMinimum(Node* node);
    Node* treeMaximum(Node* node);
    Node* treeSuccessor(Node* node);
    Node* treePredecessor(Node* node);
    void treeInsert(Node* input);
    void treeDelete(Node* out);
    void leftRotate(Node* node);
    void rightRotate(Node* node);

    //GETTERY
    Node* getRoot();
    int getSize();
    //SETTERY
    void setRoot(Node* Root);
    //void setSize(int Size);
};

BRTree::BRTree(){
    //Inicjalizacja strażnika
    this->guardian->setColor('B');
    this->guardian->setParent(this->guardian);
    this->guardian->setLeft(this->guardian);
    this->guardian->setRight(this->guardian);
    //Korzeń wskazuje na strażnika
    this->root = this->guardian;
}

BRTree::~BRTree(){

}


//Operacje jak dla normalnego drzewa BST
void BRTree::inorderTreeWalk(Node* node){
    if(node != nullptr){
        inorderTreeWalk(node->getLeft());
        std::cout << " " << node->getKey() << " ";
        inorderTreeWalk(node->getRight());
    }
}

Node* BRTree::treeSearch(Node* node, int k){
    if(node == nullptr || k == node->getKey()){
        return node;
    }

    if(k < node->getKey()){
        return treeSearch(node->getLeft(), k);
    }
    else{
        return treeSearch(node->getRight(), k);
    }
}

Node* BRTree::treeMinimum(Node* node){
    while(node->getLeft() != nullptr){
        node = node->getLeft();
    }
    return node;
}

Node* BRTree::treeMaximum(Node* node){
    while(node->getRight() != nullptr){
        node = node->getRight();
    }
    return node;
}

Node* BRTree::treeSuccessor(Node* node){
    if(node->getRight() != nullptr){
        return treeMinimum(node->getRight());
    }
    Node* y = node->getParent();
    while(y!=nullptr && node == y->getRight()){
        node = y;
        y = y->getParent();
    }
    return y;
}

Node* BRTree::treePredecessor(Node* node){
    Node* y;
    if(node->getLeft() != nullptr){
        return treeMaximum(node);
    }
    y = node->getParent();
    while(y != nullptr && node == y->getLeft()){
        node = y;
        y = y->getParent();
    }
    return y;
}

void BRTree::treeInsert(Node* input){
    Node* y = nullptr;
    Node* x = this->getRoot();

    while(x != nullptr){
        y = x;
        if(input->getKey() < x->getKey()){
            x = x->getLeft();
        }
        else{
            x = x->getRight();
        }
    }
    
    input->setParent(y);

    if(y == nullptr){
        this->setRoot(input);
    }
    else{
        if(input->getKey() < y->getKey()){
            y->setLeft(input);
        }
        else{
            y->setRight(input);
        }
    }
}

void BRTree::treeDelete(Node* out){
    Node* y = nullptr;
    Node* x;

    if(out->getLeft() == nullptr || out->getRight() == nullptr){
        y = out;
    }
    else{
        y = treeSuccessor(out);
    }

    if(y->getLeft() != nullptr){
        x = y->getLeft();
    }
    else{
        x = y->getRight();
    }

    if(x != nullptr){
        x->setParent(y->getParent());
    }

    //Od tego momentu Cormen inny algorytm wskazuje
    if(y->getParent() != nullptr){
        this->setRoot(x);
    }
    else{
        if(y == y->getParent()->getLeft()){
            y->getParent()->setLeft(x);
        }
        /*else{
            y->getParent()->setRight(x);
        }*/
    }

    /*if(y!=out){
        out->setKey(y->getKey());
    }
    return y;*/
}

void BRTree::leftRotate(Node* node){
    Node* y;
    Node* x;

    y = node->getRight();
    if(y != nullptr){
        x = node->getParent();
        node->setRight(y->getLeft());

        if(node->getRight() != nullptr){
            node->getRight()->setParent(node);
        }

        y->setLeft(node);
        y->setParent(x);
        node->setParent(y);

        if(x != nullptr){
            if(x->getLeft() == node){
                x->setLeft(y);
            }
            else{
                x->setRight(y);
            }
        }
        else{
            this->setRoot(y);
        }
    }
}

void BRTree::rightRotate(Node* node){
    Node* y;
    Node* x;

    y = node->getLeft();
    if(y != nullptr){
        x = node->getParent();
        node->setLeft(y->getRight());

        if(node->getLeft() != nullptr){
            node->getLeft()->setParent(node);
        }

        y->setRight(node);
        y->setParent(x);
        node->setParent(y);

        if(x != nullptr){
            if(x->getLeft() == node){
                x->setLeft(y);
            }
            else{
                x->setRight(y);
            }
        }
        else{
            this->setRoot(y);
        }
    }
}

//GETTERY
Node* BRTree::getRoot(){
    return this->root;
}

int BRTree::getSize(){
    return this->size;
}
//SETTERY
void BRTree::setRoot(Node* Root){
    this->root = Root;
}
