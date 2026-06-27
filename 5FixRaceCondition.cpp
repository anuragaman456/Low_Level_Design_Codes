#include<iostream>
#include<thread>
#include<mutex>
#include<vector>

using namespace std;

// in this code we are trying to fix race condition using mutex in c++

int shared_value;

mutex mu;

void counter(){
    mu.lock();
    int temp=shared_value;
    for(int i=0;i<1000;i++){
        int k=k+i;
    }
    shared_value=temp+1;
    mu.unlock();
}

int main(){
    vector<thread> th1;
    for(int i=0;i<50000;i++){
        th1.push_back(thread(counter));
    }
    
    for(auto& it : th1){
          it.join();
    }

    cout<<"actual value:"<<shared_value<<endl;
    return 0;
}