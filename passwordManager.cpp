// PasswordManager: manages passwords for different websites
// Data (attributes):
//   - masterPassword : main admin/master password
//   - webPasswords   : mapping from website name to its password
//
// Behaviour (methods):
//   - addPassword(website, password)   : save a new password for a site (with basic validation)
//   - getPassword(website, masterPass) : show password only if master password is correct
//   - allSavedSites() 
#include<iostream>
#include<unordered_map>
using namespace std;

class PasswordManager{
    private:
     string masterPassword;
     unordered_map<string,string> webPasswords;
     
    public:
      
      void addPassword(string website, string password){
          string p=password,w=website;
          if(p.empty() || w.empty())
          {
              cout<<"Webiste or password can't be empty"<<endl;
              return;
          }
              
          else if(p.size()<8){
              cout<<"Password is too short it should be more than 8 characters"<<endl;
              return;
          }
          
          webPasswords[w]=p;
          cout<<"Password successfully saved!"<<endl;
      }
      
      void getPassword(string website, string adminPassword){
          string w=website, m=adminPassword;
          string pass;
          if(m!=masterPassword){
              cout<<"wrong admin password!" <<endl;
              return;
          }
          else if(w.empty()|| adminPassword.size()<0){
              cout<<"website name or adminPassword can't be empty!"<<endl;
              return;
          }
          else if(m==masterPassword){
              pass=webPasswords[w];
              cout<<"your "<< w <<" password is: "<<pass<<endl;
              return;
          }
          else{
              cout<<"unknown error";
              return;
          }
      }
      
      void allSavedSites(){
          cout<<"List of saved sites:"<<endl;
          for (auto it : webPasswords){
              cout<< it.first <<endl;
              cout<< it.second <<endl;
          }
          return;
      }
      
      PasswordManager(string masterPassword){
         if(masterPassword.size()<8){
              cout<<"masterPassword is too short it should be more than 8 characters"<<endl;
              return;
         }
         this->masterPassword=masterPassword;
      }
};


int main(){
    PasswordManager pm("demo@123");
    pm.allSavedSites();
    pm.addPassword("facebook.com", "facebook@123");
    pm.allSavedSites();
    pm.getPassword("facebook.com","demo@123");
    
    return 0;
}  
