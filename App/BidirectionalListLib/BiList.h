#pragma once

struct listElement{

    listElement* previous;
    int data;
    listElement* next;

};

class BiList
{
private:
    listElement* head;
    listElement* tail;
    int count;

public:
    BiList();
    ~BiList();

    //METODY OPERUJĄCE NA LIŚCIE
    void addAtTheBeginning(int number);
    void addAtTheEnd(int number);
    void addOnPosition(int index, int number);
    void removeAtTheBeginning();
    void removeAtTheEnd();
    void removeOnPosition();
    void showList();

    //SETTERY I GETTERY
    int getCount();
    listElement* getHead();
    listElement* getTail();
    void setHead(listElement* element);
    void setTail(listElement* element);
};

//KONSTRUKTOR
BiList::BiList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->count = 0;
}

//DESTRUKTOR
BiList::~BiList()
{
}


/*********METODY OPERUJĄCE NA LIŚCIE**********/
void BiList::addAtTheBeginning(int number){
    listElement* pointer;
    
    pointer = new listElement;
    pointer->data = number;
    pointer->previous = nullptr;
    pointer->next = this->head;

    this->head = pointer;
    this->count++;

    if(pointer->next){
        pointer->next = pointer;
        pointer->previous = pointer;
    }
    else{
        this->tail = pointer;
    }
}

void BiList::addAtTheEnd(int number){

}

void BiList::addOnPosition(int index, int number){

}

void BiList::removeAtTheBeginning(){

}

void BiList::removeAtTheEnd(){

}

void BiList::removeOnPosition(){

}

void BiList::showList(){

}

/*********SETTERY I GETTERY*******************/
int BiList::getCount(){
    return this->count;
}

listElement* BiList::getHead(){
    return this->head;
}

listElement* BiList::getTail(){
    return this->tail;
}

void BiList::setHead(listElement* element){
    this->head = element;
}

void BiList::setTail(listElement* element){
    this->tail = element;
}