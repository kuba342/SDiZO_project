#pragma once

#include <iostream>

class Node
{
private:
    Node* parent;
    Node* left;
    Node* right;
    int key;
    char color;

public:
    Node();
    ~Node();

    //GETTERY
    Node* getParent();
    Node* getLeft();
    Node* getRight();
    int getKey();
    char getColor();

    //SETTERY
    void setParent(Node* Parent);
    void setLeft(Node* leftSon);
    void setRight(Node* rightSon);
    void setKey(int Key);
    void setColor(char Color);
};

Node::Node(){

}

Node::~Node(){

}

//GETTERY
Node* Node::getParent(){
    return this->parent;
}

Node* Node::getLeft(){
    return this->left;
}

Node* Node::getRight(){
    return this->right;
}

int Node::getKey(){
    return this->key;
}

char Node::getColor(){
    return this->color;
}

//SETTERY
void Node::setParent(Node* Parent){
    this->parent = Parent;
}

void Node::setLeft(Node* leftSon){
    this->left = leftSon;
}

void Node::setRight(Node* rightSon){
    this->right = rightSon;
}

void Node::setKey(int Key){
    this->key = Key;
}

void Node::setColor(char Color){
    this->color = Color;
}