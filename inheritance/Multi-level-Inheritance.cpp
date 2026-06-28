// Multi-level Inheritance
// Chain of inheritance
// Animal
//   ↓
// Mammal
//   ↓
//   Dog

#include<iostream>
using namespace std;

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
            cout <<name<<" is currently eating!"<<endl;
        }
        void sleep(){
            cout <<name<<" is currently sleeping!"<<endl;
        }
        virtual void sound(){
            cout <<name<<" is making sound !"<<endl;
        }
};

class Mammal : public Animal{
    public:
        Mammal(string name, int age)
            : Animal(name, age){}
        void feedMilk(){
            cout<<name<<" can feed milk !"<<endl;
        }
};

class Dog : public Mammal{
    protected:
        string color;
    public:
        Dog(string name, int age, string color)
            : Mammal(name,age){
                this->color=color;
            }
        void Color(){
            cout<<name<<" color is "<<color<<endl;
        }
        
        void sound(){
            cout<<name<<" is barking !"<<endl;
        }
};


int main(){
    Dog d("bulldog", 7, "brown");
    d.Color();
    d.feedMilk();
    d.sound();
    d.sleep();
    d.eat();
    return 0;
}