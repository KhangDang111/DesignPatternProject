#include <iostream>
using namespace std;

class Patient {
public:
    bool doctorcheck;
    bool receptioncheck;
    bool medicalcheck;
    bool cashiercheck;
};

class Chain {
public:
    virtual void check(Patient *p) = 0;
    virtual void setnext(Chain *next) = 0;
};

class Reception : public Chain{
private:
    Chain *next;
public:
    void check(Patient *p){
        if(p->receptioncheck){
            cout<<"Resgiter done!";
            this->next->check(p);
            return;
        }
        else {
            p->receptioncheck=true;
        }
        this->next->check(p);
    }
    void setnext(Chain* next){
        this->next=next;
    }
};

class Doctor : public Chain{
private:
    Chain *next;
public:
    void check(Patient *p){
        if(p->doctorcheck){
            cout<<"Doctor done!";
            this->next->check(p);
            return;
        }
        else {
            p->doctorcheck=true;
        }
        this->next->check(p);
    }
    void setnext(Chain* next){
        this->next=next;
    }
};

class Medical : public Chain{
private:
    Chain *next;
public:
    void check(Patient *p){
        if(p->medicalcheck){
            cout<<"Medical done!";
            this->next->check(p);
            return;
        }
        else {
            p->medicalcheck=true;
        }
        this->next->check(p);
    }
    void setnext(Chain* next){
        this->next=next;
    }
};

class Cashier : public Chain{
private:
    Chain *next;
public:
    void check(Patient *p){
        if(p->cashiercheck){
            cout<<"Pay done!";
            this->next->check(p);
            return;
        }
        else {
            p->cashiercheck=true;
        }
        cout<<"Done!";
    }
    void setnext(Chain* next){}
};

int main(){
    Cashier* pay=new Cashier();
    Medical* med=new Medical();
    med->setnext(pay);
    Doctor* doc=new Doctor();
    doc->setnext(med);
    Reception* reg=new Reception();
    reg->setnext(doc);
    Patient* p=new Patient;
    p->receptioncheck=false;
    p->doctorcheck=false;
    p->medicalcheck=false;
    p->cashiercheck=false;
    reg->check(p);
}