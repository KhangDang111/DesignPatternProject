#include <iostream>
using namespace std;

class Emoji {
public:
    string state;
    Emoji(string s):state(s){}
};

class Face {
private:
    string state;
public:
    Face(string s):state(s){}
    Emoji * create(){
        return new Emoji(state);
    }
    string getstate(){ return state;}
    void setstate(Emoji *e){
        this->state=e->state;
    }
    void setstate(string st){
        this->state=st;
    }
};

class caretaker{
private:
    Emoji* states[100];
    int m;
public:
    caretaker():m(0){}
    Emoji* get(int index){
        return states[index];
    }
    void add(Emoji* e){
        states[m++]=e;
    }
};

int main(){
    caretaker* a=new caretaker();
    Face *face=new Face("Happy");
    a->add(face->create());
    face->setstate("Sad");
    a->add(face->create());
    face->setstate("Angry");
    face->setstate(a->get(0));
    cout<<face->getstate();
}