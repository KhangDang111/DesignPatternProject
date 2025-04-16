#include <iostream>
using namespace std;
class Singleton{
protected:
    Singleton(){}
public:
    int data;
    static Singleton& get_in(){
        static Singleton i;
        return i;
    }
};
int main(){
    Singleton& s1=Singleton::get_in();
    s1.data=10;
    cout<<"s1.data="<<s1.data<<endl;
    Singleton& s2=Singleton::get_in();
    cout<<"s2.data="<<s2.data<<endl;
    s2.data=20;
    cout<<"s1.data="<<s1.data<<endl;
    cout<<"s2.data="<<s2.data<<endl;
    Singleton s_copy=s1;
    s_copy.data=30;
    cout<<"s_copy.data="<<s_copy.data<<endl;
    cout<<"s1.data="<<s1.data<<endl;
    cout<<"s2.data="<<s2.data<<endl;
    return 0;
}