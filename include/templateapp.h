#include<iostream>

using namespace std;

template <typename T>
class Aclass;
template <typename T>
ostream& operator<< (ostream &output, Aclass<T> &c);

template<typename T>
class Aclass
{
public:
    T m;

public:
    Aclass()=default;
    Aclass(T n) : m(n){};
    Aclass operator+(Aclass<T> &c);
    friend ostream& operator<< <T>(ostream &output, Aclass &c);
};

template<typename T>
Aclass<T> Aclass<T>::operator+(Aclass<T> &c)
{
    T s;
    s = this->m + c.m;
    return Aclass(s);
}
template<typename T>
ostream& operator<<(ostream& output,Aclass<T> &c)
{
    output << c.m;
    return output;
}
