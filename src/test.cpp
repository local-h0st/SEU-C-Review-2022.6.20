//2022.6.23 一部分关于类的测试
#include<iostream>

class A{
public:
    A(){
        this->var = 0;
    }
    A(int i):var(i){}
    ~A(){
        std::cout<<"this->var : "<<this->getVar()<<" --calling destruct()"<<std::endl;
    }
    int getVar(){
        return this->var;
    }
    void setVar(int i){
        this->var = i;
    }
private:
    int var;
};

class B{
public:
    B(std::string i):var(i){
        std::cout<<"class B construct func()  --var : "<<this->var<<std::endl;
    }
    ~B(){
        std::cout<<"class B destruct func()  --var : "<<this->var<<std::endl;
    }
    std::string getVar(){
        return this->var;
    }
private:
    std::string var;
};

class C{
public:
    C():varB("Initial constructng lists for varB in class C"){
        std::cout<<"class C construct func()  --varB : "<<this->varB.getVar()<<std::endl;
    }
    ~C(){
        std::cout<<"class C destruct func()  --varB : "<<this->varB.getVar()<<std::endl;
    }
private:
    B varB;
};

class D{
public:
    D(){
        std::cout<<"no args offered, this is D()"<<std::endl;
        this->ptrB = new B("initial");
    }
    D(std::string str){
        std::cout<<"Construct : this->ptrB = new B("<<str<<");"<<std::endl;
        this->ptrB = new B(str);
    }
    ~D(){
        std::cout<<"Destruct : this->ptrB->getVar() = "<<this->ptrB->getVar()<<std::endl;
        delete ptrB;
    }
private:
    B* ptrB;
};

class E{
public:
    E():a("dfghjk"),b(this->var),varB("varB"){
        this->var = 0;
    }
    void pri(){
        std::cout<< var << "  " << a << "  " << b << "  " << varB.getVar() <<std::endl;
    }
private:
    int var;
    const std::string a;
    int & b;
    B varB;
};

class F{
public:
    F(){
        ++this->count;
    }
    ~F(){
        --this->count;
    }
    int getCnt(){
        return this->count;
    }
    static int f(){
        return count + var;
    }
    static int count;
private:
    static int var;
};
int F::count = 0;
int F::var = 16;

class G{
public:
    G(int v):var(v){}
    friend std::ostream& operator<<(std::ostream& out,const G& g);
    friend bool operator==(const G& g1,const G& g2);
    bool operator>(const G& g);
    bool operator<(const G& g){
        if(this->var<g.var)
            return true;
        else
            return false;
    }
private:
    int var;
};
std::ostream& operator<<(std::ostream& out,const G& g){
    out<<g.var;
    return out;
}
bool operator==(const G& g1,const G& g2){
    if(g1.var==g2.var)
        return true;
    else
        return false;
}
bool G::operator>(const G& g){
    if(this->var>g.var)
        return true;
    else
        return false;
}

class H{
public:
    H(std::string s):str(s){}
    H(const H &h){      //TODO explicit?
        this->str = h.str;
    }
    void printcontent(){
        std::cout<<this->str<<std::endl;
    }
    friend class I;
private:
    std::string str;
};

class I{
public:
    I(const H& h):s(h.str){}
    void printcontent(){
        std::cout<<this->s<<std::endl;
    }
    operator H() const{
        std::cout<<"static_cast<H>() or H() ... "<<std::endl;
        return H(this->s);
    }
private:
    std::string s;
};

int main(){
    // A *p = new A(16);
    // std::cout<<p->getVar()<<std::endl;
    // delete p;

    // A *pArr = new A[3];
    // for(int i = 0; i < 3; ++i)
    //     pArr[i].setVar(i);
    // delete [] pArr;

    // A** px = new A*[3];
    // px[0] = new A[2];
    // px[1] = new A[2];
    // px[2] = new A[2];
    // for(int i = 0; i < 3; ++i){
    //         delete [] px[i];
    // }
    //delete [] px;         !!!!!!!!!

    // C c;

    // D d("peace&love");

    // D* pD = new D[3];
    // delete [] pD;

    // B* pB = new B("dfghj");
    // delete pB;

    // E e;
    // e.pri();

    // std::cout<<F::count <<std::endl;
    // std::cout<<F::f()<<std::endl;
    // F* pF = new F[6];
    // std::cout<<pF[0].getCnt() <<std::endl;
    // std::cout<<F::count <<std::endl;
    // std::cout<<F::f()<<std::endl;
    // delete [] pF;
    // std::cout<<F::count <<std::endl;
    // std::cout<<F::f()<<std::endl;

    // G g(16);
    // std::cout<<g<<std::endl;
    // G g2(2);
    // std::cout<<(g2<g?"g2<g":"g2>=g")<<std::endl;
    // std::cout<<(g>g2?"g>g2":"g2=g2")<<std::endl;
    // G g3(2);
    // std::cout<<(g2==g3?"g2==g3":"g2!=g3")<<std::endl;

    // H h("peace");
    // H h2("test");
    // h.printcontent();
    // h2.printcontent();
    // h2 = h;
    // h2.printcontent();
    // H h3(h);
    // h3.printcontent();

    // H hh("sergb");
    // hh.printcontent();
    // I i(hh);
    // i.printcontent();
    // H hhh = static_cast<H>(i);
    // H hhhh = H(i);
    // hhh.printcontent();
    // hhhh.printcontent();


    return 0;
}