#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class iSoldier {
public:
    virtual void display(string id, int star, int weight, int height) = 0;
};

class Soldier : public iSoldier {
private:
    std::string color;

public:
    Soldier(const std::string& color) : color(color) {}

    void display(string id, int star, int weight, int height) {
        std::cout << "Display this soldier wear " << color << " with id: "
                  << id << ", " << star << " star(s), with weight " << weight
                  << " and height " << height << std::endl;
    }
};

class SoldierFactory {
private:
    std::unordered_map<std::string, iSoldier*> soldiers;

public:
    ~SoldierFactory() {
        for (auto& pair : soldiers) {
            delete pair.second;
        }
    }

    iSoldier* getSoldier(const string& color) {
        if (soldiers.find(color) == soldiers.end()) {
            soldiers[color] = new Soldier(color);
        }
        return soldiers[color];
    }
};

int main() {
    SoldierFactory fac;

    iSoldier* brownsoldier = fac.getSoldier("red");
    brownsoldier->display("MTX 65", 20, 30, 40);

    iSoldier* greensoldier = fac.getSoldier("blue");
    greensoldier->display("MMX 70", 60, 70, 80);

    iSoldier* brownsoldier2 = fac.getSoldier("red");
    brownsoldier2->display("MTX 70", 25, 35, 45);

    return 0;
}
