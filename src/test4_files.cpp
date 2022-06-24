#include<iostream>
#include<fstream>

int main(){
    std::fstream bifile;
    char bufred[20];
    bifile.open("../files/test.binary",std::ios::binary|std::ios::in);
    bifile.read(bufred,6);
    std::cout<<bufred;
    bifile.read(bufred,6);
    std::cout<<bufred;
    bifile.read(bufred,6);
    std::cout<<bufred;
    bifile.read(bufred,6);
    std::cout<<bufred;
    //1. 读取是覆盖一部分的buff  2. cout遇到buff里nul就不输出了，但实际上是读取进去了，应该遍历buff依次输出
    bifile.close();

    // std::fstream bifile;
    // char buff[9] = "end";
    // bifile.open("../files/test.binary",std::ios::binary|std::ios::out|std::ios::app);
    // bifile.write(buff,sizeof(buff));
    // bifile.close();

    // std::fstream file;
    // file.open("../files/test.txt",std::ios::in);
    // char buf[20];
    // while(!file.eof()){
    //     file.getline(buf,20);   //无需计数，getline自动会忽略已经读取过的部分
    //     std::cout<<buf<<std::endl;
    // }
    // file.getline(buf,20);       //这表明已经到了文件结束的位置，不会自动回到开头
    // std::cout<<buf<<std::endl;

    // file.seekg(0,std::ios::beg);//seekg回到初始位置但是为什么没用呢？算了不管TODO
    // file.getline(buf,20);
    // std::cout<<buf<<std::endl;
    // file.close();
    // std::fstream file("../files/test.txt",std::ios::out|std::ios::app);
    // file << "fdfghjhtrgd";
    // file.close();
}