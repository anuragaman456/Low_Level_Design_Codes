#include<iostream>
#include<thread> //importing thread 
#include<vector>
using namespace std;

int shared_value=0;

void counter(){
    int temp=shared_value; 
}

int main(){
    vector<thread> th;
    thread t1(counter); // it will create a seperate thread which call counter function
    thread t2(counter);

    t1.join();  //it will wait t1 thread will finish its task
    t2.join();     
    cout<<"current counter value:"<<shared_value<<endl;
    return 0;
}