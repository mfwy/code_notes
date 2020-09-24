#include<iostream>
#include"Drawer.h"
void Drawer::doDraw()
{
    pangolin::CreateWindowAndBind("Sketch", 640, 480);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    pangolin::OpenGlRenderState scam(
        pangolin::ProjectionMatrix(640,480,460,460,230,230,0.2,200),
        pangolin::ModelViewLookAt(5,5,5,0,0,0,pangolin::AxisZ)
    );
    pangolin::Handler3D h(scam);
    pangolin::View &dcam = pangolin::CreateDisplay()
                               .SetBounds(0.0, 1.0, 0.0, 1.0, -640.0f / 480.0f)
                               .SetHandler(&h);
    
    pair<Pxyz, Pxyz> temp;
    temp = Lines.front();
    Lines.pop();
    while (!pangolin::ShouldQuit())
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        dcam.Activate(scam);

        pangolin::glDrawAxis(1);
        glLineWidth(3.0f);
        glBegin(GL_LINES);
        glColor3f(1.f, 1.f, 0.f);
        // while(Lines.size()!=0)
        //  {
            glVertex3f(temp.first.X, temp.first.Y, temp.first.Z);
            glVertex3f(temp.second.X,temp.second.Y,temp.second.Z);
        //             glVertex3f(0,0,0);
        // glVertex3f(1,1,1);
            // std::cout << "hh" <<temp.second.Y<< std::endl;
        //  }
        // glVertex3f(0,0,0);
        // glVertex3f(1,1,1);
         
         glEnd();
         pangolin::FinishFrame();
    }
}