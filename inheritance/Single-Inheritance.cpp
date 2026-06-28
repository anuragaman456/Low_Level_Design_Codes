// #1Single Inheritance
// One parent, one child
// Animal
//    ↓
//   Dog


#include<iostream>
using namespace std;
//this code explain inheritance 

class Animal{
    protected:
        string name;
        int age;
    public:
       Animal(string name, int age){
           this->name=name;
           this->age=age;
       }
       void eat(){
           cout<<name<<" is eating food"<<endl;
       }
       void sleep(){
           cout<<name<<" is sleeping"<<endl;
       }
       virtual void make_sound(){
           cout<<name<<" is making sound"<<endl;
       }
};

class Dog : public Animal{
    private:
        string color;
    public:
        Dog(string name, int age, string color)
            : Animal(name,age){
            this->color=color;
        }
        
        void make_sound(){
            cout<< name<< " sound woof woof!"<<endl;
        }
        void fetch(){
            cout<<name<<" is fetching the ball"<<endl;
        }
    
};

class Cat : public Animal{// protected Animal or private Animal also present
    private:             // but for protected->all public methods and attributes
        string color;    // of Animal calss become protected and cant be called from
    public:     //outside same in privte all become privte so mostly we use public
        Cat(string name, int age, string color)
            :Animal(name, age){//inherint this constructor from animal class
                this->color=color;
            }
        
        void make_sound(){
            cout<< name<< " sound meow meow!"<<endl;
        }
        void climb(){
            cout<<name<<" is climbing the wall"<<endl;
        }
};


int main(){
    Dog d("bulldog",12,"brown");
    Cat c("persian",3,"white");

    d.sleep();   // parent class method used by inherited class
    d.eat();
    d.fetch();
    d.make_sound(); 
    c.make_sound();
    c.eat();
    c.sleep();
    c.climb();
    return 0;
}