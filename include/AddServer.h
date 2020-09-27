#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<sstream>
#include<csignal>
#include<functional>
typedef int (*pfun)(int, int);

using namespace std;
using namespace std::placeholders;  

class AddServer
{
private:
    string ip;
    int port;

    char buffer[1024];
    struct sockaddr_in server_addr;
    struct sockaddr client_addr;
    int count;

    int a;
    int b;
    int sum;
public:
    static int sock_server;
    static int sock_client;
    int bind_flag;
    int listen_flag;
    int accept_flag;

public:
    AddServer();
    ~AddServer();
    bool Server_wait();
    bool Server_connect();
    void process(pfun callback);
    static void handler(int signum);

};
int AddServer::sock_server=0;
int AddServer::sock_client = 0;
void AddServer::handler( int signum)
{
    cout << "Interupt!" << endl;
    close(sock_client);
    close(sock_server);
}
AddServer::AddServer()
{
    signal(SIGINT, handler);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8888);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    sock_server = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_server==-1)
    {
        cout << "Create socket error!" << endl;
    }
    else
    {
        count = 0;
        do
        {
            cout << "Binding" << endl;
            bind_flag = bind(sock_server, (struct sockaddr *)&server_addr, sizeof(server_addr));
            count++;
            if(count==10)
            {
                cout << "Bind server addr error!" << endl;
                break;
            }
        } while (bind_flag == -1);
    }

}

AddServer::~AddServer()
{
    close(sock_server);
}
bool AddServer::Server_wait()
{
    listen_flag = listen(sock_server,10);
    if(listen_flag==-1)
    {
        cout << "Wait error!" << endl;
        return false;
    }
    return true;
}
bool AddServer::Server_connect()
{
    struct sockaddr client_addr;
    socklen_t len = sizeof(client_addr);
    sock_client = accept(sock_server, (struct sockaddr *)&client_addr, &len);

    if(sock_client==-1)
    {
        cout << "Connect error!" << endl;
        return false;
    }
    return true;
}
void AddServer::process(pfun callback)
{
    int recv_flag, send_flag;
    int size = 10;
    while(1)
    {
        string tips = "Input a and b separeted by space:\n";
        send_flag=send(sock_client, tips.c_str(), 35, 0);
        if(send_flag<=0)
        {
            cout << "Tips send error!" << endl;
            break;
        }
        memset(buffer,0,1024);
        recv_flag = recv(sock_client, buffer, size, 0);
        if(recv_flag==0)
        {
            cout << "Disconnect!" << endl;
            break;
        }
        if(recv_flag==-1)
        {
            cout << "Recv error!" << endl;
            break;
        }

        stringstream ss(buffer);
        string A,B;
        ss >> A >> B;

        a = atoi(A.c_str());
        b = atoi(B.c_str());

        sum=callback(a, b);
        string out =to_string(sum)+"\n";
        send_flag = send(sock_client, out.c_str(), 5, 0);
        if(send_flag<=0)
        {
            cout << "Result send error!" << endl;
            break;
        }

    }
    close(sock_client);

}
