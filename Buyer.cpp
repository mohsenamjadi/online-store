#include <iostream>
#include <string>
#include <sstream>
#include <vector> 
#include "Buyer.h"
using namespace std;


Buyer::Buyer(string str) {

      stringstream iss ( str );

      string x;

      iss >> x;
      first_name = x;

      iss >> x;
      last_name = x;

      iss >> x;
      username = x;

      iss >> x;      
      phone_number = x;

      iss >> x;      
      money = stoi(x);

} 


