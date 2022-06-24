#include <iostream>
//virtual的作用就是不是看指针类型，而是看实际类型调用对应的函数

class BaseV{
public:
    BaseV(std::string s):str_in_base(s){
        std::cout<<"BaseV construct with { "<<s<<" }"<<std::endl;
    }
    virtual ~BaseV(){   //TODO 如果是作为基类要用继承则virtual一定要写不然delete出问题 析构函数特殊，允许不同名，成员函数要同名
        std::cout<<"BaseV destruct with { "<<this->str_in_base<<" }"<<std::endl;
    }
    virtual void echoSelf(){
        std::cout<<"BaseV"<<std::endl;
    }
    void f(){
        std::cout<<"f() in BaseV"<<std::endl;
    }
    virtual int purevirtual(int in) = 0;    //包含纯虚函数，BaseV变成了抽象类，不能再实例化
protected:
    std::string str_in_base;
};

class Deri :public BaseV{
public:
    Deri(std::string s):BaseV(s){
        std::cout<<"Deri construct with { "<<s<<" }"<<std::endl;
    }
    ~Deri(){
        std::cout<<"Deri destruct with { "<<this->str_in_base<<" }"<<std::endl;
    }
    void print_str_in_base_class(){
        std::cout<<this->str_in_base<<std::endl;
    }
    void echoSelf(){
        std::cout<<"Deri"<<std::endl;
    }
    void f(){
        std::cout<<"f() in Deri"<<std::endl;
    }
    int purevirtual(int in){
        return in*in;
    }
};

int main(){
    // BaseV base("dfghjk");
    // Deri* p = new Deri("Pelikan");
    // p->print_str_in_base_class();
    // p->echoSelf();
    // p->BaseV::echoSelf();
    // delete p;

    BaseV* p = new Deri("Pelikan");
    p->echoSelf();
    p->f();
    reinterpret_cast<Deri*>(p)->f();
    std::cout<<p->purevirtual(16)<<std::endl;
    delete p;
}