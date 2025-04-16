#include <iostream>
#include <vector>
using namespace std;

class Component {
public:
    virtual void search(string key) = 0;
};

class File : public Component {
private:
    string name;
public:
    File(string st ):name(st){}
    void search(string key){
        cout<<"Search "<<key<<" in "<<name<<endl;
    }
};

class Folder: public Component{
private:
    string name;
    vector<File*> f;
public:
    Folder(string st): name(st){}
    void add(File *f){
        this->f.push_back(f);
    }
    void search(string key){
        for(File* ite:f){
            ite->search(key);
        }
    }
};

int main(){
    Folder* fol=new Folder("Tree");
    fol->add(new File("leaf 1"));
    fol->add(new File("leaf 2"));
    fol->add(new File("leaf 3"));
    fol->search("Money");
}