#include<iostream>
#include<cstdlib>
#include<chrono>
#include"Drawer.h"
#include"pangolin/pangolin.h"
#include<thread>
#include<mutex>
#include<Eigen/Eigen>
#include<string>
#include<config.h>
#include<CJsonObject.hpp>
#include<opencv2/opencv.hpp>
#include<Param.h>
#include<boost/archive/text_oarchive.hpp>
#include<boost/serialization/vector.hpp>
#include<ser.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include<AddServer.h>
#include<templateapp.h>

using namespace std;
using namespace cv;

int callback(int a,int b)
{
    cout << a + b << endl;
    return 2*a + b;
}
template<typename T>
T func(T a,T b)
{
    T c = a + b;
    cout << c << endl;
    return c;
}
void var_func(int cnt, ...)
{
    va_list ap;
    va_start(ap, cnt);
    int i = 0;
    while (i < cnt)
    {
        cout<<va_arg(ap,int)<<endl;
        i++;
    }

}
int main()
{

    var_func(5, 1, 4, 5, 6, 4);
    //**********************
    //template
    // try
    // {
    //     int a1 = 8, a2 = 9;
    //     double b1 = 12.4, b2 = 23.8;
    //     string c1("hello "), c2("world");
    //     Aclass<string> A1("good "), A2("moring!!!");
    //     func(a1, a2);
    //     func(b1, b2);
    //     func(c1, c2);
    //     func(A1, A2);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    //****************************
    //socket
    // AddServer s1;
    // if(s1.bind_flag!=-1)
    // {
    //     cout << "Binding succeed!!!" << endl;

    //     if(s1.Server_wait())
    //     {
    //         int flag=s1.Server_connect();
    //         if(flag)
    //         {
    //             s1.process(callback);
    //         }
    //     }
    // }
    
    
    // task1:Json文件
    //  config Param("../config/config.json");
    //  Param.readparam();
    // ********************************************************
    //task2;计时
    // std::chrono::time_point<chrono::system_clock> start,end;
    // start=std::chrono::system_clock::now();
    // for(int i=0;i<10000;i++)
    // {

    // }
    // end=std::chrono::system_clock::now();
    // std::chrono::duration<double> Dura=end - start;
    // cout<<"累加时间为： "<<Dura.count()*1000<<"s"<<endl;
    // ********************************************************
    //  task3;yaml文件
    //   Parameter p("../config/param.yml");
    //   p.setParameter();
    //   p.readParameter();
    //************************************************
    //task4:boost serializtion序列化与反序列化
    //  Ser St("../config/serial.txt");
    //  St.store();
    //  St.restore();
    //  St.storeAsBinary();
    //*********************************************************
    // char buffer[1024];
    // int sock_server; //套接字描述符
    // int sock_client;
    // int bind_flag;
    // int listen_flag;
    // struct sockaddr_in serve_addr; //ip地址、端口等的结构体
    // struct sockaddr_in client_addr;
    // memset(&serve_addr, 0, sizeof(serve_addr));
    // serve_addr.sin_family = AF_INET;
    // serve_addr.sin_port = htons(8888);
    // serve_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    //     //创建套接字
    // sock_server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    // if(sock_server==-1)
    // {
    //     cout << "SOCKET CREATE ERROR!" << endl;
    //     return -1;
    // }
    // //bind服务器套接字和ip地址等
    // bind_flag = bind(sock_server,(struct sockaddr *)&serve_addr,sizeof(serve_addr));
    // if(bind_flag==-1)
    // {
    //     cout << "SOCKET BIND ERROR!" << endl;
    //     return -1; 
    // }
    // //套接字监听
    // listen_flag = listen(sock_server, 1024);
    // if(listen_flag==-1)
    // {
    //     cout << "SOCKET LISTEN ERROR!" << endl;
    //     return -1; 
    // }
    // //accept
    // socklen_t len = sizeof(client_addr);
    
   
    // sock_client = accept(sock_server, (struct sockaddr *)&client_addr, &len);
    // if(sock_client==-1)
    // {
    //     cout << "SOCKET ACCEPT ERROR!" << endl;
    // }
    // while(1)
    // {
    //     memset(buffer,0,sizeof(buffer));
    //     int recv_len = recv(sock_client, buffer, 1024, 0);
    //     if(recv_len<=0)
    //     {
    //         cout << "no message!" << endl;
    //         close(sock_client);
    //     }else
    //     {
    //         cout << buffer << endl;
    //     }
    // }


    // close(sock_server);
    //**********************************************
    // int sock_client;
    // struct sockaddr_in server_addr;
    // memset(&server_addr, 0, sizeof(server_addr));
    // server_addr.sin_family = AF_INET;
    // server_addr.sin_port = htons(8888);
    // server_addr.sin_addr.s_addr = inet_addr("192.168.191.1");

    // sock_client = socket(AF_INET, SOCK_STREAM, 0);
    // if(sock_client==-1)
    // {
    //     cout << "CLIENT SOCKET ERROR!" << endl;
    //     return -1;
    // }
    // int connect_flag = connect(sock_client, (struct sockaddr *)&server_addr, sizeof(server_addr));
    // if(connect_flag==-1)
    // {
    //     cout << "CONNECT FAILED!" << endl;
    //     return -1;
    // }
    // char buffer[1024] = "hello server!";
    
    // while (1)
    // {
    //     // string buf = "tomorrow is a good day!!!";
    //     // int send_flag = send(sock_client, buf.c_str(), 10, 0);
    //     // if(send_flag==-1)
    //     // {
    //     //     cout << "SEND ERROR!" << endl;
    //     //     break;
    //     // }
    //     memset(buffer, 0, sizeof(buffer));
    //     int recv_flag = recv(sock_client, buffer, 1000, 0);
    //     cout << buffer << endl;
    //     usleep(5000000);
    // }

    // close(sock_client);


    
    return 0;
}   
  
    
    