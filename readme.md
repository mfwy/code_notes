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
