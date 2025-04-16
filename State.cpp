#include <iostream>
using namespace std;

class Switch;

class State {
public:
    virtual void On(Switch *s)  = 0;
    virtual void Off(Switch *s) = 0;
};

class Switch {
private:
    State *s;
public:
    Switch (State *state):s(state){}
    void SetState(State *state){
        s=state;
    }
    void On(){
        s->On(this);
    }
    void Off(){
        s->Off(this);
    }
};

class off: public State{
public:
    void On(Switch*s) {
        cout<<"Switch return from Off to On";
        delete s;
        s->SetState(new on());
    }
    void Off(Switch*s){
        cout<<"Switch already Off";
    }
};

class on: public State{
public:
    void On(Switch*s){
        cout<<"Switch already On";
    }
    void Off(Switch*s){
        cout<<"Switch return from On to Off";
        delete s;
        s->SetState(new off());
    }
};

int main(){
    on* o= new on();
    Switch* s =new Switch(o);
    s->On();
    s->Off();
}

