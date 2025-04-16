#include <iostream>
#include <vector>
using namespace std;

class Subject {
public:
    virtual void ReceiveInf() = 0;
};

class Customer : public Subject{
private:
    string name;
public:
    Customer(string st):name(st){}
    void ReceiveInf(){
        cout<<"Given mail to "<<name<<endl;
    }
};

class Observer {
    virtual void Register(Customer* c) = 0;
    virtual void DeRegister(Customer* c) = 0;
    virtual void NotifyAll() = 0;
};

class Item :public Observer{
private:
    vector<Customer*> cus;
    bool isStock;
    string name;
public:
    Item(string st,bool b):name(st), isStock(b){}
    void Register(Customer* c){
        cus.push_back(c);
    }
    void DeRegister(Customer* c){
        for(int i=0;i<cus.size();i++){
            if(cus[i]==c) cus.erase(cus.begin()+i);
        }
    }
    void NotifyAll(){
        for(int i=0;i<cus.size();i++) cus[i]->ReceiveInf();
    }
    void Check(){
        if(isStock) this->NotifyAll();
    }
};

int main(){
    Item * shoe=new Item("Adidas shoe",true);
    shoe->Register(new Customer("Brocklyn"));
    shoe->Register(new Customer("Dan"));
    shoe->Register(new Customer("Bronya"));
    shoe->Check();
}