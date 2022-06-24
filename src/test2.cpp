#include <iostream>

class Base{
public:
    Base(std::string s):str(s){
        std::cout<<"Base construct with { " << s << " }" <<std::endl;
    }
    ~Base(){
        std::cout<<"Base destruct with { " << this->str << " }" <<std::endl;
    }
    void print(){
        std::cout<<"print() in Base class"<<std::endl;
    }
protected:
    std::string str;
};

class Derived :public Base{
public:
    Derived(std::string ss):str_in_derived(ss),Base("Base class"),base("this is var base in derived"){
        std::cout<<"Derived construct with { " << ss << " }" <<std::endl;
    }
    ~Derived(){
        std::cout<<"Derived destruct with { " << this->str_in_derived << " }" <<std::endl;
    }
    void print(){
        std::cout<<"print() in Derived class"<<std::endl;
    }
    void print_str(){
        std::cout<<this->str<<std::endl;
    }
    void print_str_in_derived(){
        std::cout<<this->str_in_derived<<std::endl;
    }
private:
    std::string str_in_derived;
    Base base;
};

int main(){
    Base mybase("pure");
    mybase.print();
    mybase.~Base();
    Derived myderived("love");
    myderived.print();
    myderived.print_str();
    myderived.print_str_in_derived();
    myderived.Base::print();
    return 0;
}