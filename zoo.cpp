#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Pasare
{
    protected:
    char tip;
    std::string nume;
    int dim;
    public:
    Pasare(char tip,std::string nume, int dim):
    tip(tip),nume(nume),dim(dim){}
    virtual void afisare()=0;
    int get_dim(){return this->dim;}
    char get_tip(){return this->tip;}
    virtual float sup(){return 0;}
    std::string get_nume(){return this->nume;}
};

class Zburatoare:public Pasare
{
    private:
    int batai;
    public:
    Zburatoare(char tip,std::string nume, int dim, int batai):
    Pasare(tip,nume, dim),batai(batai){}
    void afisare()
    {
        std::cout<<nume<<" "<<dim<<" "<<batai<<std::endl;
    }
    float sup()
    {
        return dim*110*batai/100;
    }
};

class Nezburatoare: public Pasare
{
    private:
    std::string culoare;
    public:
    Nezburatoare(char tip,std::string nume, int dim, std::string culoare):
    Pasare(tip,nume,dim), culoare(culoare){}
    void afisare()
    {
        std::cout<<nume<<" "<<dim<<" "<<culoare<<std::endl;
    }
    float sup()
    {
        return dim*30;
    }
};
    bool metoda(Pasare *p1, Pasare *p2)
    {
        return (p1->sup() < p2->sup());
    }
class Gestionare
{
    private:
    std::vector<Pasare*> vec;
    public:
    void vec_add(Pasare *p)
    {
        vec.push_back(p);
    }
    void test1()
    {
        for(int i=0;i<vec.size();i++)
        {
           vec[i]->afisare();
        }
    }
    void test2()
    {
        char tip1;
        int dim1;
        std::cin>>tip1;
        std::cin>>dim1;
         for(int i=0;i<vec.size();i++){
            if(vec[i]->get_tip()==tip1&&dim1<vec[i]->get_dim())
        {
            vec[i]->afisare();
        }
        
    
    }
}


void test3()
{
    for(int i=0;i<vec.size();i++)
    {
        
        std::cout<<vec[i]->get_nume()<<" "<<vec[i]->sup()<<std::endl;
    }
}
    
    void test4()
    {
        std::sort(vec.begin(),vec.end(),metoda);
    }
    void test5()
    {
        int s1,s2;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]->get_tip()=='z')s1+=vec[i]->sup();
            else if (vec[i]->get_tip()=='n')s2+=vec[i]->sup();
        }
        if (s1<s2)std::cout<<s2;
        else std::cout<<s1;
    }
};
int main()
{
    Gestionare obiect;
    std::string nume;
    char tip;
    int dim;
    int batai;
    std::string culoare;
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++)
    {
        std::cin>>tip>>nume>>dim;
        if(tip=='z')
        {
            std::cin>>batai;
            obiect.vec_add(new Zburatoare(tip,nume,dim,batai));
        }
        else
        {
            std::cin>>culoare;
            obiect.vec_add(new Nezburatoare(tip,nume,dim,culoare));
        }
        
    }
    
    int test;
    std::cin>>test;
    switch(test)
    {
        case 1:
        {
            obiect.test1();
            break;
        }
        case 2:
        {
            obiect.test2();
            break;
        }
        case 3:
        {
            obiect.test3();
            break;
        }
        case 4:
        {
            obiect.test4();
            obiect.test1();
            break;
        }
        case 5:
        {
            obiect.test5();
            break;
        }
    }
    return 0;
}
