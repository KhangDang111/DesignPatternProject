#include <iostream>
#include <vector>
using namespace std;    
class animal{
public:
    virtual void callname()=0;
};
class dog:public animal {
public:
    void callname(){
        cout<<"It's Dog"<<endl;
    }
};
class cat:public animal {
public:
    void callname(){
        cout<<"It's Cat"<<endl;
    }
};
class butterfly:public animal {
public:
    void callname(){
        cout<<"It's Butterfly"<<endl;
    }
};
enum type{Dog,Cat,Butterfly};
class factory{
public:
    animal* callit(type t){
        if(t==Dog) return new dog();
        else if(t==Cat) return new cat();
        else return new butterfly();
    }
};
int main(){
    vector<animal*> a;
    factory f;
    a.push_back(f.callit(Dog));
    a.push_back(f.callit(Cat));
    a.push_back(f.callit(Butterfly));
    for(animal*& s:a){
        s->callname();
    }
    for(animal*& s:a){
        delete s;
    }
    a.clear();
    return 0;
}