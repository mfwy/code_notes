#include<boost/serialization/vector.hpp>
#include<boost/archive/text_oarchive.hpp>
#include<boost/archive/text_iarchive.hpp>
#include<boost/archive/binary_oarchive.hpp>
#include<fstream>
#include<iostream>
#include<sstream>

using namespace boost::archive;
using namespace std;

class Newtype
{
// private:
public:
    int a;
    double b;
    string s;

public:
    void setElement(int _a, double _b, string _ss) { a = _a, b = _b, s = _ss; }
    Newtype() = default;
    Newtype(int _a, double _b, string _ss) : a(_a), b(_b), s(_ss) {}
    ~Newtype(){}
    
    friend boost::serialization::access;
    template<typename Archive>
    void serialize(Archive &ar,const unsigned int version)
    {
        ar &a;
        ar &b;
        ar &s;
    }
};
class Ser
{
private:
    ifstream ifs;
    ofstream ofs;
    stringstream ss;
    Newtype T;
    Newtype S;
    string Path;


public:
    void store();
    void restore();
    void storeAsBinary();
    Ser(string path) : Path(path) {}
    ~Ser();
};

Ser::~Ser()
{
    ofs.close();
    ifs.close();
    
}
void Ser::store()
{
    ofs.open(Path.c_str());
    if(!ofs.is_open())
        cout << "error1" << endl;

    text_oarchive oa(ofs);
    T.setElement(56, 89., "serialization function");
    oa &T;
}
void Ser::restore()
{
    ifs.open(Path.c_str());
    if(!ifs.is_open())
        cout << "error2" << endl;
    text_iarchive ia(ifs);
    int i;
    double d;
    string out;
    ia &S;
    // ia & i;
    // ia &d;
    // ia &out;
    cout << S.a<<S.b<<S.s << endl;
}
void Ser::storeAsBinary()
{
    binary_oarchive bo(ss);
    T.setElement(9, 10., "serialization to binary");
    bo &T;
    cout << (ss.str()).c_str()<< endl;

}