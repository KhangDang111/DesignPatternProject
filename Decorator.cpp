#include <iostream>
#include <string>
using namespace std;

class Stream {
public:
    virtual void write(string data) = 0;
    virtual ~Stream() = default;
};

class FileStream : public Stream {
public:
    void write(string data) override {
        cout << "Writing data to file: " << data << endl;
    }
};

class StreamDecorator : public Stream {
protected:
    Stream* wrappee;
public:
    StreamDecorator(Stream* stream) : wrappee(stream) {}
    virtual ~StreamDecorator() {
        delete wrappee;
    }
};

class CompressedStream : public StreamDecorator {
public:
    CompressedStream(Stream* stream) : StreamDecorator(stream) {}

    void write(string data) override {
        data = compress(data);
        wrappee->write(data);
    }

    string compress(string data) {
        return "compressed(" + data + ")";
    }
};

class EncryptedStream : public StreamDecorator {
public:
    EncryptedStream(Stream* stream) : StreamDecorator(stream) {}

    void write(string data) override {
        data = encrypt(data);
        wrappee->write(data);
    }

    string encrypt(string data) {
        return "encrypted(" + data + ")";
    }
};

int main() {
    Stream* fileStream = new FileStream();
    fileStream->write("Hello, World!");

    Stream* compressedStream = new CompressedStream(new FileStream());
    compressedStream->write("Hello, World!");

    Stream* encryptedStream = new EncryptedStream(new FileStream());
    encryptedStream->write("Hello, World!");

    Stream* compressedEncryptedStream = new CompressedStream(new EncryptedStream(new FileStream()));
    compressedEncryptedStream->write("Hello, World!");

}
