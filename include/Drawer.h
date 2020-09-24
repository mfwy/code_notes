#include<iostream>
#include<pangolin/pangolin.h>
#include<queue>

using namespace std;
struct Pxyz
{
    GLfloat X;
    GLfloat Y;
    GLfloat Z;
};
class Drawer
{
private:
    queue<pair<Pxyz,Pxyz>> Lines;
    
public:
    Drawer();
    void setPoints(queue<pair<Pxyz,Pxyz>> P) { Lines = P; };
    void doDraw();
    ~Drawer();
};

Drawer::Drawer()
{
}

Drawer::~Drawer()
{
}
