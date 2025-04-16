#include <iostream>
#include <string>
using namespace std;

class Image {
public:
    virtual void display() = 0;
};

class RealImage : public Image {
private:
    string filename;

    void loadFromDisk() {
        cout << "Loading " << filename << endl;
    }

public:
    RealImage(const string& filename) : filename(filename) {
        loadFromDisk();
    }

    void display() override {
        cout << "Displaying " << filename << endl;
    }
};

class ProxyImage : public Image {
private:
    string filename;
    RealImage* realImage;

public:
    ProxyImage(const string& filename) : filename(filename), realImage(nullptr) {}

    ~ProxyImage() {
        delete realImage;
    }

    void display() override {
        if (!realImage) {
            realImage = new RealImage(filename);
        }
        realImage->display();
    }
};

int main() {
    Image* image1 = new ProxyImage("test_image_1.jpg");
    Image* image2 = new ProxyImage("test_image_2.jpg");

    cout << "Calling display on image1 first time:" << endl;
    image1->display();

    cout << "Calling display on image1 second time:" << endl;
    image1->display();

    cout << "Calling display on image2 first time:" << endl;
    image2->display();

    delete image1;
    delete image2;

    return 0;
}
