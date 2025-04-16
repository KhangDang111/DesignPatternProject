#include <iostream>

using namespace std;   

class House {
private:
    string Shoe, door;
    int floor;
public:
    void setShoe(string typeShoe){
        Shoe=typeShoe;
    }
    void setdoor(string typedoor){
        door=typedoor;
    }
    void setfloor(int num){
        floor=num;
    }
    void getinf(){
        cout<<"Shoe:"<<Shoe<<endl<<"Door:"<<door<<endl<<"Floor:"<<floor<<endl;
    }
};

class iBuilder {
protected:
    House * mybuilder;
public:
    void createBuilder(){
        mybuilder=new House;
    }
    House* getBuilder() {
        return mybuilder;
    }
    virtual void getShoe() =0;
    virtual void getdoor() =0;
    virtual void getfloor() =0;
};

class WoodHouse: public iBuilder {
public:
    void getShoe(){
        mybuilder->setShoe("red wood");
    }
    void getdoor(){
        mybuilder->setdoor("brown wood");
    }
    void getfloor(){
        mybuilder->setfloor(2);
    }
};

class IceHouse: public iBuilder {
public:
    void getShoe(){
        mybuilder->setShoe("ice-cream");
    }
    void getdoor(){
        mybuilder->setdoor("ice flower");
    }
    void getfloor(){
        mybuilder->setfloor(1);
    }
};

class Director {
private:
    iBuilder * newhouse;
public:
    void createHouse(iBuilder *tam) {
        newhouse=tam;
    }
    House* getHouse(){
        return newhouse->getBuilder();
    }
    void sethouse(){
        newhouse->createBuilder();
        newhouse->getShoe();
        newhouse->getdoor();
        newhouse->getfloor();
    }
};

int main(){
    Director build;
    WoodHouse whouse;
    IceHouse ihouse;
    //Create WoodHouse
    build.createHouse(&whouse);
    build.sethouse();
    House* woodhouse=build.getHouse();
    woodhouse->getinf();

    //Create IceHouse
    build.createHouse(&ihouse);
    build.sethouse();
    House* icehouse=build.getHouse();
    icehouse->getinf();
}