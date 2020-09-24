#include<iostream>
#include<string>
#include<opencv2/opencv.hpp>

using namespace std;

class Parameter
{
private:
    cv::FileStorage fs;
    bool flag;
    std::string Path;

    double fx, fy;

public:
    void setParameter();
    void readParameter();
    Parameter(std::string path):flag(true),Path(path){}
    ~Parameter(){fs.release();}
};

void Parameter::setParameter()
{
    fs.open(Path.c_str(), cv::FileStorage::WRITE);
    if(!fs.isOpened())
    {
        cout << "FileStorage Write open Failed!!!" << endl;
        flag = false;
    }
    if(flag)
    {
        fs << "model_type" << "pinhole";
        double fx=640, fy=480;
        fs << "fx" << fx;
        fs << "fy" << fy;

        double cx = 320, cy = 240;
        fs << "cx" << cx;
        fs << "cy" << cy;

        cv::Mat m = (cv::Mat_<double>(3,4) <<1,0,0,1,0,1,0,1,0,0,1,1);
        fs << "intrinc matrix" << m;

        fs << "count"
           << "["
           << "one"
           << "two"
           << "three"
           << "]";
        fs << "frequence" << int(30);
    }
}
void Parameter::readParameter()
{
    fs.open(Path.c_str(), cv::FileStorage::READ);
    if(!fs.isOpened())
    {
        cout << "FileStorage Write open Failed!!!" << endl;
        flag = false;
    }
    if(flag)
    {
        fs["fx"] >> fx;
        fs["fy"] >> fy;
        cout << fx << " " << fy << endl;
        cv::FileNode n = fs["count"];
        if(n.empty())
        {
            cout << "error" << endl;
        }

        cv::FileNodeIterator it = n.begin(), it_end = n.end();
        for (; it != it_end;++it)
        {
            cout << (string)*it << endl;
        }
    }
}
