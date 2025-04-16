#include <iostream>
using namespace std;

class Inode {
public:
    virtual Inode* clone() = 0;
    virtual void print() = 0;
};

class File : public Inode {
private:
    string name;
public:
    File (string n):name(n){}
    Inode* clone(){
        return new File(this->name);
    }
    void print(){
        cout<<this->name;
    }
};

class Folder : public Inode{
private:
    string name;
    Inode* a[100];
    int m;
public:
    Folder(string n):name(n),m(0){}
    void InsertFile(Inode *f){
        a[m++]=f;
    }
    Inode* clone(){
        Folder *tam=new Folder(this->name);
        for(int i=0;i<this->m;i++){
            tam->InsertFile(this->a[i]->clone());
        }
        return tam;
    }
    void print(){
        cout<<this->name<<":"<<endl;
        for(int i=0;i<m;i++){
            a[i]->print();
            cout<<endl;
        }
    }
};

int main(){
    File *file1=new File("file 1");
    File *file2=new File("file 2");
    File *file3=new File("file 3");
    Folder *folder1=new Folder("folder 1");
    folder1->InsertFile(file1);
    Folder *folder2=new Folder("folder 2");
    folder2->InsertFile(folder1);
    folder2->InsertFile(file2);
    folder2->InsertFile(file3);
    Inode *copyfolder=folder2->clone();
    copyfolder->print();
    return 0;
}