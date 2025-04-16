#include <iostream>
#include<queue>
using namespace std;

class train{
public:
    virtual void checktogo() = 0;
};

class Mediator{
    virtual bool PermitGo(train* tr)=0;
    virtual bool Waiting(train *tr)=0;
    virtual void Changetrain(train *tr) = 0;
};

class Station:public Mediator{
private:
    queue<train*> q;
public:
    bool PermitGo(train* tr){
        if(q.empty()) {
            q.push(tr);
            return true;
        }
        return false;
    }
    bool Waiting(train* tr){
        if(q.front()!=tr) return true;
        return false;
    }
    void Changetrain(train*tr){
        q.pop();
        q.push(tr);
    }
};

class Redtrain:public train{
private:
    Station *med;
public:
    Redtrain(Station *m ):med(m){}
    void checktogo(){
        if(med->PermitGo(this)) cout<<"Red train ready to go"<<endl;
        else if(med->Waiting(this)){
            med->Changetrain(this);
            cout<<"The blue train will finish"<<endl;
        }
        else{
            cout<<"The red train is running"<<endl;
        }
    }
};

class Bluetrain:public train{
private:
    Station *med;
public:
    Bluetrain(Station *m ):med(m){}
    void checktogo(){
        if(med->PermitGo(this)) cout<<"Blue train ready to go"<<endl;
        else if(med->Waiting(this)){
            med->Changetrain(this);
            cout<<"The red train will be finish"<<endl;
        }
        else{
            cout<<"The blue train is running"<<endl;
        }
    }
};

int main(){
    Station * sta=new Station();
    Redtrain *r=new Redtrain(sta);
    Bluetrain *b=new Bluetrain(sta);
    r->checktogo();
    b->checktogo();
    b->checktogo();
}
