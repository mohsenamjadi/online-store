#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Goods.h"  
using namespace std;


     Goods::Goods ( string str ) {


      stringstream iss ( str );
      
      string x;

      iss >> x;
      seller_username = x;

      iss >> x;
      goods_name = x;

      iss >> x;
      goods_price = stoi(x);

      iss >> x;      
      goods_count = stoi(x);

    }
