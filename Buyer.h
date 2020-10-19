#ifndef Buyer_H
#define Buyer_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;



class Buyer {  

  public :

    Buyer(string str);
    string get_first_name (){return first_name;}
    string get_last_name (){return last_name;}
    string get_username (){return username;}
    string get_phone_number (){return phone_number;}
    double get_money (){return money;}
    void   set_money (double m){money = m; }

  private : 
    string first_name;
    string last_name;
    string username;
    string phone_number;
    double money;

};

#endif