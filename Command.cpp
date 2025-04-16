#include <iostream>
using namespace std;

class Command{
public:
    virtual void execute ()= 0;
};

class Device {
public:
    virtual void on () = 0;
    virtual void off() = 0;
}; 

class Button {
private:
    Command* c;
public:
    Button(Command *co):c(co){}
    void press(){
        this->c->execute();
    }
};

class Oncommand : public Command{
private:
    Device * d;
public:
    Oncommand(Device *de):d(de){}
    void execute() {
        d->on();
    }
};

class Offcommand : public Command{
private:
    Device * d;
public:
    Offcommand(Device *de):d(de){}
    void execute() {
        d->off();
    }
};

class TV : public Device {
private:
    bool isTurn;
public:
    void on(){
        isTurn=true;
        cout<<"TV on"<<endl;
    }
    void off(){
        isTurn=false;
        cout<<"TV off"<<endl;
    }
};

int main(){
    TV* t=new TV();
    Oncommand* on=new Oncommand(t);
    Button* OnButton=new Button(on);
    OnButton->press();
    Offcommand* off=new Offcommand(t);
    Button* OffButton=new Button(off);
    OffButton->press();
}