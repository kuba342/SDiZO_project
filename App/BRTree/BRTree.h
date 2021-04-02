#pragma once

struct Node
{
    Node* up;
    Node* left;
    Node* right;
    int key;
    char color;
};


class BRTree
{
private:
    Node* guardian;
    Node* root;


public:
    BRTree();
    ~BRTree();
};

BRTree::BRTree(){
    //Inicjalizacja strażnika
    this->guardian->color = 'B';
    this->guardian->up = this->guardian;
    this->guardian->left = this->guardian;
    this->guardian->right = this->guardian;
    //Korzeń wskazuje na strażnika
    this->root = this->guardian;
}

BRTree::~BRTree()
{
}
