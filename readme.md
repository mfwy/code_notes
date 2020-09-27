### 该例子代码测试了好些个库的应用
### 1.序列化配置文件：json，yaml，xml等格式
(1) json文件的读和写  config.h文件  
采用的库：CJsonObject(里面只包含四个文件，所以可以直接拷出来到一个新的项目工程中来使用)  
使用的类：CJsonObject  
定义：CJsonObject ojson  
>CJsonObject带参构造函数接受字符串参数,但在参数列表中json文件的全部内容写上是不美观的。  
>可将文件利用文件流读取，再用ojson.Parse(fs.rdbuf().str())读取  
>json中有字典对象{}，数组[]，以及他们的嵌套，访问元素字典元素可以利用键值访问，访问数组可以用数字索引访问。  
>典型的成员函数有访问的Get()，修改的Replace()，增加的Add()、AddEmptySubObject()等，输出的ToString()等。  

### **使用起来非常简单**
(2) yaml文件的读写 Param.h文件  
采用的库opencv：opencv提供了输出yaml格式配置参数文件的类接口，但opencv产生的yaml文件与标准的yaml文件有所差异，第一行必须包含 **%YAML:1.0**  
使用的类：cv::FileStorage  
>定义： cv::FileStorage fs(path,cv::FileStorage::WRITE)写  
&emsp; cv::FileStorage fs(path,cv::FileStorage::READ)读 无法同时读和写  
 >读：>>操作符 写：<<操作符 索引：[]操作符  &#160; e.g. &#160; fs["fx"]>>fx  
 >也比较简单    
 >遍历：cv::FileNode 和cv::FileNodeIterator &#160; e.g.&#160; cv::FileNode n = fs["count"];
 ### 2.序列化工具boost::serialization boost::archive  
ser.h头文件包含  
>#include<boost/serialization/vector.hpp>  
>#include<boost/archive/text_oarchive.hpp>  
>#include<boost/archive/text_iarchive.hpp>  
>#include<boost/archive/binary_oarchive.hpp>等,可面向文件，二进制字符流等 

>序列化和反序列化操作符：<< 、&和  >>、 &  这些可对内含的数据类型作用
>对于自定义的类对象的序列化，需在类内声明：  
>friend boost::serialization::access;  
>template\<typename Archive\>  
>void serialize(Archive &ar,const unsigned int version)  

### 3.Pangolin  Drawer.h
典型套路，具体还需要进一步学习opengl  
>渲染代码要包含在while循环中，不断地刷新图层

### 4. socket编程
头文件包含  
>#include<sys/socket.h>  
>#include<sys/types.h>  
>#include<netinet/in.h>  
>#include<arpa/inet.h>  
>#include\<iostream>  
>#include<unistd.h>  
>#include<stdlib.h>  
>#include\<sstream>    

![avatar](https://img-blog.csdnimg.cn/20190718154556909.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3Bhc2hhbmh1NjQwMg==,size_16,color_FFFFFF,t_70)
#### 5.chrono 时钟
>std::chrono::time_point<chrono::system_clock> start,end;//时间点  
>start=std::chrono::system_clock::now();//当前时刻  
>//任务    
>end=std::chrono::system_clock::now();  
>std::chrono::duration<double> Dura=end - start;//时间段  

### 6.template模板,函数模板,类模板,函数模板作为友元函数的问题
(1)template<typename T> ret_type fun_name(arg_type);
(2)template<class T> class class_name;
(3)重载操作符<<  >> 必须是友元函数,具有ostream& operator<<(ostream& output,classs_type& c);的形式
(4)函数模板作为友元函数:  
a.在类内定义的情况  
>   friend ostream& operator<< (ostream &output, Aclass &c)  
>    {
>
>   }  

b.在类外定义的情况  
>需提前声明:  
template \<typename T>  
class Aclass;  
template \<typename T>  
ostream& operator<< (ostream &output, Aclass<T> &c);  
>类内声明(加了\<T>):  
friend ostream& operator<< <T>(ostream &output, Aclass &c);  
>内外定义:  
>template<typename T>  
ostream& operator<<(ostream& output,Aclass<T> &c)

### 7. 可变参数(...) va_list va_start va_arg va_end(都是宏)
VA_LIST的用法：   
（1）首先在函数里定义一具VA_LIST型的变量，这个变量是指向参数的指针；   
（2）然后用VA_START宏初始化变量刚定义的VA_LIST变量；   
（3）然后用VA_ARG返回可变的参数，VA_ARG的第二个参数是你要返回的参数的类型（如果函数有多个可变参数的，依次调用VA_ARG获取各个参数）；   
（4）最后用VA_END宏结束可变参数的获取。  
> typedef char * va_list;       
> // TC中定义为void*  
>#define _INTSIZEOF(n)  ((sizeof(n)+sizeof(int)-1)&~(sizeof(int) - 1))  
 //为了满足需要内存对齐的系统  
>#define va_start(ap,v)  ( ap = (va_list)&v + _INTSIZEOF(v) )  
//ap指向第一个变参的位置，即将第一个变参的地址赋予ap  
>#define va_arg(ap,t)  ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )  
//获取变参的具体内容，t为变参的类型，如有多个参数，则通过移动ap的指针来获得变参的地址，从而获得内容 
>#define va_end(ap) ( ap = (va_list)0 )   //清空va_list，即结束变参的获取
