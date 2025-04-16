#include <iostream>
using namespace std;

class Printer{
public:
    virtual void printaction() = 0;
};

class Epson: public Printer{
public:
    void printaction(){
        cout<<"Print by Epson"<<endl;
    }
};

class HP: public Printer{
public:
    void printaction(){
        cout<<"Print by HP"<<endl;
    }
};

class Computer{
public:
    virtual void print() = 0;
    virtual void setprint(Printer *p) = 0;
};

class Win :public Computer{
private:
    Printer *p;
public:
    void print(){
        cout<<"Win ";
        p->printaction();
    }
    void setprint(Printer *p){
        this->p=p;
    }
};

class Mac :public Computer{
private:
    Printer *p;
public:
    void print(){
        cout<<"Mac ";
        p->printaction();
    }
    void setprint(Printer *p){
        this->p=p;
    }
};

int main(){
    Epson* e=new Epson();
    HP* hp=new HP();
    Mac *m1=new Mac();
    m1->setprint(hp);
    m1->print();
}
