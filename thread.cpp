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
    thread t1(counter);
    thread t2(counter);

    for(int i=0;i<40000;i++){
        th.push_back(thread(counter));
    }

    t1.join();
    t2.join();

    for (auto& it : th){
        it.join();
    }

    // now creating race condition


     
    cout<<"current counter value:"<<shared_value<<endl;
    return 0;
}