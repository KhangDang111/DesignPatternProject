#include <iostream>
using namespace std;

class Account{
private:
    string name;
public:
    Account(string st):name(st){}
    void checkaccount(string st){
        if(name==st) cout<<"Hi "<<name<<endl;
        else throw "Error";
    }
};

class Code{
private:
    int code;
public:
    Code(int x):code(x){}
    void checkcode(int x){
        if(x==code) cout<<"Pass succesful"<<endl;
        else throw "Error";
    }
};

class UserWallet{
private:
    int credit;
public:
    UserWallet(int x): credit(x){}
    void incrcredit(int x){
        credit+=x;
    }
    void decrcredit(int x){
        if(x>credit) throw "Error";
        credit-=x;
    }
};

class Notify{
public:
    void notifyincr(int x){
        cout<<"Wallet increase "<<x<<endl;
    }
    void notifydecr(int x){
        cout<<"Wallet decrease "<<x<<endl;
    }
};

class Wallet {
private:
    Account* a;
    Code* c;
    UserWallet* w;
    Notify* n;
public:
    Wallet(string st, int x, int credit){
        a=new Account(st);
        c=new Code(x);
        w=new UserWallet(credit);
        n=new Notify();
    }
    void SendMoney(string st, int x, int money){
        a->checkaccount(st);
        c->checkcode(x);
        w->incrcredit(money);
        n->notifyincr(money);
    }
    void GetMoney(string st, int x, int money){
        a->checkaccount(st);
        c->checkcode(x);
        w->decrcredit(money);
        n->notifydecr(money);
    }
};

int main(){
    Wallet *w=new Wallet("No name",1111,100000);
    w->GetMoney("No name",1111,50000);
    w->GetMoney("No name",1111,60000);
}


