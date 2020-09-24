#include<sys/socket.h>
#include<iostream>

using namespace std;

class Client
{
private:
    string IP_addr;
    string Port;


public:
    Client(string ip,string port);
    ~Client();
};

Client::Client(string ip,string port):IP_addr(ip),Port(port)
{
    
}

Client::~Client()
{
}
