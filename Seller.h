#ifndef Seller_H
#define Seller_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;



class Seller{

  public :

    Seller(string str);
    string get_first_name (){return first_name;}
    string get_last_name (){return last_name;}
    string get_username (){return username;}
    string get_phone_number (){return phone_number;}
    double get_money (){return money;}
    void set_money (double m){money = m; }


  private :
    string username;
    string first_name;
    string last_name;
    string phone_number;
    double money;

};

#endif