#include <iostream>
using namespace std;

class OTP {
public:
    virtual void getandsaveOTP(int num) = 0;
    virtual void sendOTP() = 0;
    virtual bool enterOTP()= 0;
};

class Email : public OTP{
private:
    int otp;
public:
    void getandsaveOTP(int num){
        int mod=pow(10,num);
        otp=rand()%mod;
    }
    void sendOTP(){
        cout<<"Send message OTP to email: "<<otp;
    }
    bool enterOTP(){
        int n;
        cout<<"Enter OTP:";
        cin>>n;
        if(n==otp) return true;
        else return false;
    }
};

class SMS : public OTP{
private:
    int otp;
public:
    void getandsaveOTP(int num){
        int mod=pow(10,num);
        otp=rand()%mod;
    }
    void sendOTP(){
        cout<<"Send message OTP to SMS: "<<otp;
    }
    bool enterOTP(){
        int n;
        cout<<"Enter OTP:";
        cin>>n;
        if(n==otp) return true;
        else return false;
    }
};

class iOTP {
private:
    OTP *o;
public:
    iOTP(OTP*otp):o(otp){}
    void getandcheckOTP(int num){
        o->getandsaveOTP(num);
        o->sendOTP();
        cout<<endl;
        if(o->enterOTP()) cout<<"succesful";
        else cout<<"unsuccesful";
    }
};

int main(){
    OTP *sms=new SMS();
    iOTP *i=new iOTP(sms);
    i->getandcheckOTP(4);
}