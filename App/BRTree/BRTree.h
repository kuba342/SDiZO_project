#pragma once

#include "Node.h"

class BRTree
{
private:
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
    void addElement(int value);
    void deleteElement(int value);

    //GETTERY
    Node* getRoot();
    int getSize();
    //SETTERY
    void setRoot(Node* Root);
    //void setSize(int Size);
};

BRTree::BRTree(){
    this->size = 0;
    this->root = nullptr;
}

BRTree::~BRTree(){
    delete this->root;
}


//Operacje jak dla normalnego drzewa BST
void BRTree::inorderTreeWalk(Node* node){
    if(node != nullptr){
        inorderTreeWalk(node->getLeft());
        std::cout << " " << node->getColor() << node->getKey() << " ";
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

//Nie mam pojęcia czy to zadziała
void BRTree::addElement(int value){
    Node* x;
    Node* y;

    x = new Node();
    x->setLeft(nullptr);
    x->setRight(nullptr);
    x->setParent(this->getRoot());
    //x->setColor('B');
    x->setKey(value);

    if(x->getParent() == nullptr){
        this->setRoot(x);
    }
    else{
        while(true){
            if(value < x->getParent()->getKey()){
                if(x->getParent()->getLeft() == nullptr){
                    x->getParent()->setLeft(x);
                    break;
                }

                x->setParent(x->getParent()->getLeft());
            }
            else if(value > x->getParent()->getKey()){
                if(x->getParent()->getRight() == nullptr){
                    x->getParent()->setRight(x);
                    break;
                }

                x->setParent(x->getParent()->getRight());
            }
            else{
                delete x;
                return;
            }
        }

        //Kolorowanie na czerwono
        x->setColor('R');
        while((x != this->getRoot()) && (x->getParent()->getColor() == 'R')){
            if(x->getParent() == x->getParent()->getParent()->getLeft()){
                y = x->getParent()->getParent()->getRight();

                //Przypadek 1
                if(y->getColor() == 'R'){
                    x->getParent()->setColor('B');
                    y->setColor('B');
                    x->getParent()->getParent()->setColor('R');
                    x = x->getParent()->getParent();
                    continue;
                }

                //Przypadek 2
                if(x == x->getParent()->getRight()){
                    x = x->getParent();
                    leftRotate(x);
                }

                //Przypadek 3
                x->getParent()->setColor('B');
                x->getParent()->getParent()->setColor('R');
                rightRotate(x->getParent()->getParent());
                break;
            }
            else{
                y->getParent()->getParent()->getLeft();

                //Przypadek 1
                if(y->getColor() == 'R'){
                    x->getParent()->setColor('B');
                    y->setColor('B');
                    x->getParent()->getParent()->setColor('R');
                    x = x->getParent()->getParent();
                    continue;
                }

                //Przypadek 2
                if(x == x->getParent()->getLeft()){
                    x = x->getParent();
                    rightRotate(x);
                }

                //Przypadek 3
                x->getParent()->setColor('B');
                x->getParent()->getParent()->setColor('R');
                leftRotate(x->getParent()->getParent());
                break;
            }
        }
    }

    this->getRoot()->setColor('B');
    this->size++;
}

//Nie mam pojęcia czy to zadziała...
void BRTree::deleteElement(int value){
    Node* node;
    Node* x;
    Node* y;
    Node* z;

    node = treeSearch(this->getRoot(), value);

    if((node->getLeft() == nullptr) || (node->getRight() == nullptr)){
        y = node;
    }
    else{
        y = treeSuccessor(node);
    }

    if(y->getLeft() != nullptr){
        z = y->getLeft();
    }
    else{
        z = y->getRight();
    }

    z->setParent(y->getParent());

    if(y->getParent() == nullptr){
        this->setRoot(z);
    }
    else if(y = y->getParent()->getLeft()){
        y->getParent()->setLeft(z);
    }
    else{
        y->getParent()->setRight(z);
    }

    if(y != node){
        node->setKey(y->getKey());
    }


    //Odbudowa struktury drzewa czerwono-czarnego
    if(y->getColor() == 'B'){
        while((z != this->getRoot()) && (z->getColor() == 'B')){
            if(z == z->getParent()->getLeft()){
                
                x = z->getParent()->getRight();

                //Przypadek 1
                if(x->getColor() == 'R'){
                    x->setColor('B');
                    z->getParent()->setColor('R');
                    leftRotate(z->getParent());
                    x = z->getParent()->getRight();
                }

                //Przypadek 2
                if((x->getLeft()->getColor() == 'B') && (x->getRight()->getColor() == 'B')){
                    x->setColor('R');
                    z = z->getParent();
                    continue;
                }

                //Przypadek 3
                if(x->getRight()->getColor() == 'B'){
                    x->getLeft()->setColor('B');
                    x->setColor('R');
                    rightRotate(x);
                    x = z->getParent()->getRight();
                }

                //Przypadek 4
                x->setColor(z->getParent()->getColor());
                z->getParent()->setColor('B');
                x->getRight()->setColor('B');
                leftRotate(z->getParent());

                z = this->getRoot();
            }
            else{
                x = z->getParent()->getLeft();

                //Przypadek 1
                if(x->getColor() == 'R'){
                    x->setColor('B');
                    z->getParent()->setColor('R');
                    leftRotate(z->getParent());
                    x = z->getParent()->getLeft();
                }

                //Przypadek 2
                if((x->getLeft()->getColor() == 'B') && (x->getRight()->getColor() == 'B')){
                    x->setColor('R');
                    z = z->getParent();
                    continue;
                }

                //Przypadek 3
                if(x->getLeft()->getColor() == 'B'){
                    x->getRight()->setColor('B');
                    x->setColor('R');
                    leftRotate(x);
                    x = z->getParent()->getLeft();
                }

                //Przypadek 4
                x->setColor(z->getParent()->getColor());
                z->getParent()->setColor('B');
                x->getLeft()->setColor('B');
                rightRotate(z->getParent());

                z = this->getRoot();
            }
        }
        z->setColor('B');
        delete y;
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
