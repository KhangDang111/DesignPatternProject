#include <iostream>
#include <vector>
using namespace std;

class CPU;

class Arlo {
public:
    virtual void quit(CPU* c) = 0;
};

class FCFS :public Arlo {
public:
    void quit(CPU* c){
        cout<<"Call FCFS";
    }
};

class SJF :public Arlo {
public:
    void quit(CPU* c){
        cout<<"Call SJF";
    }
};

class RR :public Arlo {
public:
    void quit(CPU* c){
        cout<<"Call RR";
    }
};

class CPU {
private:
    vector<string> queue;
    Arlo *a;
    int cap;
    int maxcap;
public:
    CPU(int a, int b, Arlo *c):cap(a),maxcap(b),a(c){}
    void add(string st){
        queue.push_back(st);
        cap++;
    }
    void setArlo(Arlo* ar){
        a=ar;
    }
    void checkcap(){
        if(cap>=maxcap){
            a->quit(this);
            cap--;
        }
    }
};

int main(){
    FCFS *arlo1= new FCFS();
    CPU* cpu= new CPU(0,2,arlo1);
    RR *arlo2=new RR();
    cpu->setArlo(arlo2);
    cpu->add("a");
    cpu->add("b");
    cpu->checkcap();
}