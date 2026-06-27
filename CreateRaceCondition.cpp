// in this code we are creating race condition
#include<iostream>
#include<thread>
#include<vector>
using namespace std;

int shared_value=0;

// so if lock will not present then we can't able determine the shared value result 
void counter(){
    int temp=shared_value; // read happen
    for(int i=0;i<1000;i++){
        int k=i+k;           //some wait 
    }
    shared_value=temp+1;   // then write 
}

int main(){
    vector<thread> th;
    for(int i=0;i<40000;i++){
        th.push_back(thread(counter));
    }

    for (auto& it : th){
        it.join();     // it will wait until the respective thread will end 
    }
     
    cout<<"current counter value:"<<shared_value<<endl;
    return 0;
}