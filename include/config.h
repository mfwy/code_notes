#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<CJsonObject.hpp>
#include<eigen3/Eigen/Eigen>

using namespace std;

class config
{
private:
    neb::CJsonObject ojson;
    double value;
    string buf;
    fstream fs;
    stringstream ss;

    Eigen::Vector3d P;
    Eigen::Vector3d Q;
    Eigen::Vector3d Pv;
    Eigen::Vector3d Qv;
    Eigen::Vector3d Pa;
    Eigen::Vector3d Qa;


public:
    config(std::string path);
    ~config();
    void readparam();
};

config::config(std::string path)
{
    fs.open(path.c_str(),fstream::in|fstream::out);
    if(!fs.is_open())
    {
        cout << "file open error!!!" << endl;
    }
    
    ss<<fs.rdbuf();
    // while (!fs.eof())
    // {
    //     getline(fs,buf);
    //     ss << buf;
    // }
    ojson.Parse(ss.str());
}

config::~config()
{
    fs.close();
}
void config::readparam()
{
    ojson["robot"]["position"].Get("X", value);
    P.x() = value;
    ojson["robot"]["position"].Get("Y", value);
    P.y() = value;
    ojson["robot"]["position"].Get("Z", value);
    P.z() = value;
    cout << "P:"<<P << endl;
    ojson["robot"]["angular"].Get("pitch", value);
    Q.x() = value;
    ojson["robot"]["angular"].Get("yaw", value);
    Q.y() = value;
    ojson["robot"]["angular"].Get("roll", value);
    Q.z() = value;
    cout << "Q:"<<Q << endl;
    for (int i = 0; i < 3;i++)
    {
        ojson["robot"]["linear_velocity"].Get(i,value);
        Pv[i] = value;
        ojson["robot"]["angular_velocity"].Get(i,value);
        Qv[i] = value;
        ojson["robot"]["linear_acceleration"].Get(i,value);
        Pa[i] = value;
        ojson["robot"]["angular_acceleration"].Get(i,value);
        Qa[i] = value;
    }
    cout << "Pv:" << Pv << endl;
    cout << "Qv:" << Qv << endl;
    cout << "Pa:" << Pa << endl;
    cout << "Qa:" << Qa << endl;


}