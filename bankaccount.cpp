#include<iostream>
using namespace std;


class BankAccount{
    private:
      int balance;
      
    public:
      void creditMoney(int money){
          if(money>0){
          balance+=money;
          cout<< "your "<< money <<" sucesfully credited"<<endl;
          }
          else{
          cout<< "Invalid amount!"<<endl;
          }
      }
      void deductMoney(int money){
          if(balance>0 and money>0 ){
             balance-=money;
             cout<< "your "<< money <<"sucesfully deducted"<<endl;
          }
          else{
          cout<< "Invalid amount and insufficient funds!"<<endl;
          }
      }
      void checkBalance(){
          cout<<"Hey your balance is:"<<balance<<endl;
      }
};

int main(){
    BankAccount b;
    
    b.checkBalance();
    
    b.creditMoney(0);
     
    b.checkBalance();
    
    b.deductMoney(100);
    
    b.checkBalance();
    
    // b.balance=2000;
    // b.balance=4000;
    
    // cout <<"bank balance:"<<b.balance;
    return 0;
}