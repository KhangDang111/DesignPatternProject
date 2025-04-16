#include <iostream>
using namespace std;

class Shoe {
public:
    virtual void introduce() = 0;
    virtual ~Shoe() {}
};
class Short {
public:
    virtual void introduce() = 0;
    virtual ~Short() {}
};

class AdidasShoe : public Shoe{
public:
    void introduce()  {
        std::cout << "Introducing on a Adidas style Short." << std::endl;
    }
};

class AdidasShort : public Short {
public:
    void introduce() {
        std::cout << "Introducing on a Adidas style Short." << std::endl;
    }
};

class NikeShoe : public Shoe {
public:
    void introduce(){
        std::cout << "Introducing on a Nike style Short." << std::endl;
    }
};

class NikeShort : public Short {
public:
    void introduce() {
        std::cout << "Introducing on a Nike style Short." << std::endl;
    }
};

class Factory {
public:
    virtual Shoe* createShoe() = 0;
    virtual Short* createShort() = 0;
    virtual ~Factory() {}
};
class Adidas : public Factory {
public:
    Shoe* createShoe() {
        return new AdidasShoe();
    }
    Short* createShort(){
        return new AdidasShort();
    }
};
class Nike : public Factory {
public:
    Shoe* createShoe() {
        return new NikeShoe();
    }
    Short* createShort()  {
        return new NikeShort();
    }
};
int main() {
    Factory* adidas = new Adidas();
    Shoe* ShoesShoe = adidas->createShoe();
    Short* ShoesShort = adidas->createShort();
    ShoesShoe->introduce();
    ShoesShort->introduce();

    Factory* nike = new Nike();
    Shoe* linuxShoe = nike->createShoe();
    Short* linuxShort = nike->createShort();
    linuxShoe->introduce();
    linuxShort->introduce();

    delete ShoesShoe;
    delete ShoesShort;
    delete adidas;
    delete linuxShoe;
    delete linuxShort;
    delete nike;

    return 0;
}
