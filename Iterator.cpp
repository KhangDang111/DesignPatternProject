#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node(int val) : value(val) {}
};
class Iterator {
public:
    virtual Node* getNext () =0;
    virtual bool hasNext () =0;
};
class List {
public:
    virtual Iterator* createI()  = 0;
};
class NodeIterator :public Iterator{
private:
    Node *a[100];
    int index;
    int num;
public:
    NodeIterator(Node* node[],int m){
        num=m;
        for(int i=0;i<m;i++){
            a[i]=node[i];
        }
        index=0;
    }
    Node* getNext(){
        return a[index++];
    }
    bool hasNext(){
        if(index<num) return true;
        else return false;
    }
};
class NodeList : public List{
private:
    Node* a[100];
    int num;
public:
    void add(Node* node){
        a[num++]=node;
    }
    Iterator* createI(){
        return new NodeIterator(a,num);
    }
};

int main(){
    NodeList *list=new NodeList();
    list->add(new Node(1));
    list->add(new Node(2));
    list->add(new Node(3));
    Iterator*i =list->createI();
    while(i->hasNext()){
        cout<<i->getNext()->value<<endl;
    }
}
