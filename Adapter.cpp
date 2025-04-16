#include <iostream>
#include <memory>
using namespace std;
enum color{red, blue, yellow, green};
class remote{
public:
    void ContractRed(string st) const;
    void ContractBlue(string st) const;
    void ContractYellow(string st) const;
    void ContractGreen(string st) const;
};
void remote::ContractRed(string st ) const{
    cout<<"R: "<<st<<endl;
}
void remote::ContractBlue(string st ) const{
    cout<<"B: "<<st<<endl;
}
void remote::ContractYellow(string st ) const{
    cout<<"Y: "<<st<<endl;
}
void remote::ContractGreen(string st ) const{
    cout<<"G: "<<st<<endl;
}
class local{
public:
    virtual void messages(color c,string st)=0;
};
class adapter: public remote, public local{
public:
    void messages(color c, string st){
        if(c==red) ContractRed(st);
        else if(c==blue) ContractBlue(st);
        else if(c==yellow) ContractYellow(st);
        else ContractGreen(st);
    }
};
int main(){
    unique_ptr<local> displayptr(new adapter);
    displayptr->messages(red,"Hello, I am Red");
    displayptr->messages(blue,"Hello, I am Blue");
    displayptr->messages(yellow,"Hello, I am Yellow");
    displayptr->messages(green,"Hello, I am Green");
    return 0;
}