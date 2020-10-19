#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#include "Buyer.h"
#include "Seller.h"
#include "Goods.h"

vector<Buyer*> b1;
vector<Seller*> s1;
vector<Goods*> g;
vector<Goods*> special_goods; 
vector<Goods*> goods_sold; 
vector<Goods*> best_sold;

int convert(string b){
  int x = 0;
  for(int i=0 ; i<b.length() ; i++){
    for(int j=0 ; j<=9 ; j++){
      if(j == (int)b[i] - 48)
        x = x*10 + j;
    }  
  }
  return x;
}

void swap(string *xp, string *yp) { 
    string temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void check_count() {

  for(int i = 0; i < g.size(); i++) {
    int count_holder = 0;
    for(int j = 0; j < g.size(); j++) {
        if( g[i]->get_name() == g[j]->get_name() ) {
            count_holder += g[j]->get_count();
        }
    }
    if( count_holder >= 30 && g[i]-> get_being_special() == false && g[i]-> get_discount() == false) {
        g[i]-> set_count_holder(count_holder);
        g[i] -> set_too_many (true);
        g[i]-> set_discount_price();
      }
    else g[i] ->set_too_many (false);

  }
}

void add_user ( ) {

  string str;
  getline ( cin , str );

  stringstream iss ( str );

  string x,y;
  
  iss >> x >> x >> x >> y >> y >> y;

  if ( y == "buyer" ) {

  bool b = false; 
  for ( int i = 0; i < b1.size ( ); i++ )
    if ( b1[i] -> get_username ( ) == x )
      b = true;
    
    if ( b == false ) {
      b1.push_back ( new Buyer ( str ) );
      cout << "Command Ok\n";
    }
    else 
      cout << "Command Failed\n";

  }

  else if ( y == "seller" ) {
  bool b = false;
  for ( int i = 0; i < s1.size ( ); i++ )    
    if ( s1[i] -> get_username ( ) == x )
      b = true;
    // //
    if ( b == false ) {
      s1.push_back ( new Seller ( str ) );
      cout << "Command Ok\n";
    }
    else
      cout << "Command Failed\n";

  }    
}

void add_goods ( ) { 

  string str;
  getline ( cin , str );

  stringstream iss ( str );

    string x,y;
    bool flag1 = false;
    bool flag2 = true;
    iss >> x >> y;

    for(int i=0; i<s1.size(); i++){
      if(x == s1[i] -> get_username ()){
        flag1 = true;
      break;
      }
    }

   for( int i=0; i<g.size(); i++){
      if(x == g[i] -> get_seller_username ())
        { 
            if( y == g[i] -> get_name() ) {flag2 = false; break;}
        }
    }

      if(flag1 == true && flag2 == true){
        g.push_back ( new Goods ( str ) );
        cout << "Command Ok\n";
        check_count();
        }
    else cout<<"Command Failed\n";
}

void search_goods ( ) {

  string x1,x2;
  cin >> x1 >> x2;

  vector<string> out;

  for ( int i = 0; i < g.size( ); i++ )
      if ( g[i] -> get_name () == x1  ){
          if(g[i]->get_being_special() == true) {
            if(g[i]-> get_count() + g[i]->get_special_count() >= convert(x2)){
              if(g[i]-> get_count() != 0)
                out.push_back ( x1 + " " + to_string(g[i] -> get_count ( )) + " " + to_string(g[i] -> get_price ()) + " " + g[i] -> get_seller_username () );
              out.push_back ( x1 + " " + to_string(g[i] -> get_special_count ( )) + " " + to_string(g[i] -> get_special_price ()) + " " + g[i] -> get_seller_username () );
            }
          }
          else if(g[i]->get_discount() == true) {
            if( g[i]->get_discount_sugguest_count() >= convert(x2)){
              out.push_back ( x1 + " " + to_string(g[i] -> get_discount_sugguest_count()) + " " + to_string(g[i] -> get_discount_sugguest_price()) + " " + g[i] -> get_seller_username () );
            }
          }             
          else if(g[i]->get_too_many() == true) {
            out.push_back ( x1 + " " + to_string(g[i] -> get_count ( )) + " " + to_string(g[i] -> get_discount_goods_price()) + " " + g[i] -> get_seller_username () );
          }
          else {
            if(g[i]-> get_count()>= convert(x2))
              out.push_back ( x1 + " " + to_string(g[i] -> get_count ( )) + " " + to_string(g[i] -> get_price ()) + " " + g[i] -> get_seller_username () );
          }
          
      }


  int n = out.size ();
   int i, j;for (i = 0; i < n-1; i++)       
       for (j = 0; j < n-i-1; j++)   {

    stringstream iss1 ( out[j] );
    stringstream iss2 ( out[j+1] );

    string x1,x2;

    iss1 >> x1 >> x1;
    iss2 >> x2 >> x2;

           if ( convert(x1) > convert(x2) ) 
              swap(&out[j], &out[j+1]); 
       }



   for (i = 0; i < n-1; i++)       
       for (j = 0; j < n-i-1; j++)   {
           
    stringstream iss1 ( out[j] );
    stringstream iss2 ( out[j+1] );

    string x1,x2;

    iss1 >> x1 >> x1;
    iss2 >> x2 >> x2;

         if ( x1 == x2 ) {

    iss1 >> x1;
    iss2 >> x2;

           if ( convert(x1) > convert(x2) ) 
              swap(&out[j], &out[j+1]); 

        }
      }


   for (i = 0; i < n-1; i++)       
       for (j = 0; j < n-i-1; j++)   {
           
         stringstream iss1 ( out[j] );
         stringstream iss2 ( out[j+1] );

    string x1,x2,x3,x4;

    iss1 >> x1 >> x3 >> x1;
    iss2 >> x2 >> x4 >> x2;

         if ( x1 == x2 && x3 == x4 ) {

    iss1 >> x1;
    iss2 >> x2;
    if ( x1 > x2 ) 
              swap(&out[j], &out[j+1]); 

        }
      }

  for ( int i = 0; i < out.size( ); i++ )
    cout << i+1 << ". " << out[i] << '\n';
}

void best_seller(Goods* g) {
  int counter = 1;
    if(g->get_best_sold() == false) {
  for(int i = 0; i < goods_sold.size(); i++ ) {
      if(g->get_name() == goods_sold[i]->get_name()) {
        counter++;
        if(counter>=10) {
          best_sold
.push_back(g);
          g->set_best_sold(true);
        }
      }
    }
  } 
}

void buy_goods() {
  string str;
  getline ( cin , str );

  stringstream iss ( str );

  string x,y,z,w;
  int holder;

  bool flag1 = false;
  
  iss >> w;
  for(int i=0;i<b1.size();i++)
  {
      if( w == b1[i]->get_username() ){
          flag1 = true;
          break;
      }
  }

  if( flag1 == false ) {cout<<"Command Failed\n"; return;}
  iss >> x >> y >> z;
    bool xxx = false;
    for(int i=0; i < g.size(); i++ )
    {
      check_count();
      
      if( x == g[i] -> get_name() && g[i]->get_seller_username () == z.substr(0,z.length()-1) && g[i]->get_being_special() == true ) 
      {
        xxx = true;
        for(int j=0;j<b1.size();j++) {
          if(b1[j]->get_username() == w) {holder = j;break;}
          }

        if(g[i]->get_special_count() >= convert(y) && b1[holder]->get_money() >= g[i]->get_special_price()*convert(y)){
            g[i] -> set_special_count(g[i] -> get_special_count() - convert(y));
            b1[holder]->set_money( b1[holder]->get_money()-g[i]->get_special_price()*convert(y) );
          }
        
         else
         { 
            
            int m = convert(y);
            if(g[i]->get_special_count() + g[i]->get_count() >= convert(y) && b1[holder]->get_money() >= g[i]->get_special_price()*g[i]->get_special_count() + g[i]->get_price()*(g[i]->get_count()-(convert(y) - g[i]-> get_special_count() ) ) )
              {
                m -= g[i] -> get_special_count();
                g[i] -> set_special_count(0);
                g[i]->set_count(g[i]->get_count()-m);
              }
          }
        }

      
      else if( x == g[i] -> get_name() && g[i]->get_seller_username () == z.substr(0,z.length()-1) && g[i]->get_discount() == true ) {
        xxx = true;
        for(int j=0;j<b1.size();j++) {
          if(b1[j]->get_username() == w) {holder = j;break;}
          }

          if(g[i]->get_discount_sugguest_count() >= convert(y) && b1[holder]-> get_money() >= g[i]->get_discount_goods_price()*convert(y))
          {
           g[i] -> set_count(g[i]->get_discount_sugguest_count() - convert(y));
           g[i]->set_discount_sugguest_count();
           b1[holder]-> set_money( b1[holder]-> get_money() - g[i]->get_discount_sugguest_price()*convert(y) ); 
           goods_sold.push_back(g[i]);
           best_seller(g[i]);
          }
      }

      else if( x == g[i] -> get_name() && g[i]->get_seller_username () == z.substr(0,z.length()-1) && g[i]->get_too_many() == true) {
        xxx = true;
        for(int j=0;j<b1.size();j++) {
          if(b1[j]->get_username() == w) {holder = j;break;}
          }

          
            int m = convert(y);
          if(g[i]-> get_count() >= convert(y) && b1[holder]-> get_money() >= g[i]->get_discount_goods_price()*(g[i]->get_count_holder()-29) + g[i]-> get_price()* (convert(y) -(g[i]->get_count_holder()-29))  ){
              while(g[i]->get_too_many() == true) {
                g[i]->set_count(g[i]->get_count() - 1);
                b1[holder]-> set_money( b1[holder]-> get_money() - g[i]->get_discount_goods_price() ); 
                m--; 
                check_count();  
            }
              if(g[i]->get_too_many() == false){
                g[i]->set_count(g[i]->get_count() - m); 
                b1[holder]-> set_money( b1[holder]-> get_money() - (g[i]->get_price()*m) );
              }
            
          }
        }

        
      else if( x == g[i] -> get_name() &&  g[i]->get_count() >= convert(y) && g[i]->get_seller_username () == z.substr(0,z.length()-1) )
      {
        xxx = true;
        for(int j=0;j<b1.size();j++) {
          if(b1[j]->get_username() == w) {holder = j;break;}
        }

          if(b1[holder]-> get_money() >= g[i]->get_price()*convert(y))
          {
           g[i]->set_count(g[i]->get_count() - convert(y));
           b1[holder]-> set_money( b1[holder]-> get_money() - g[i]->get_price()*convert(y) ); 
           goods_sold.push_back(g[i]);
           best_seller(g[i]);

          }
      }
    }

    if(xxx == false){
      cout<<"Command Failed\n"; return;
    }
    string str1;
     if(z.substr(z.length()-1,z.length()) == ";"){ cout<<"Command Ok\n"; check_count(); return; }
  
  while(z.substr(z.length()-1,z.length()) == ","){
    getline(cin,str1); 
    stringstream iss ( str1 );
    iss >> x >> y >> z;
    xxx= false;
    for(int i=0; i < g.size(); i++ )
    {
      check_count();
      
      if( x == g[i] -> get_name() && g[i]->get_seller_username () == z.substr(0,z.length()-1) && g[i]->get_being_special() == true ) 
      {
        xxx = true;
        for(int j=0;j<b1.size();j++) {
          if(b1[j]->get_username() == w) {holder = j;break;}
          }

        if(g[i]->get_special_count() >= convert(y) && b1[holder]->get_money() >= g[i]->get_special_price()*convert(y)){
            g[i] -> set_special_count(g[i] -> get_special_count() - convert(y));
            b1[holder]->set_money( b1[holder]->get_money()-g[i]->get_special_price()*convert(y) );
          }
        
         else
         { 
            
            int m = convert(y);
            if(g[i]->get_special_count() + g[i]->get_count() >= convert(y) && b1[holder]->get_money() >= g[i]->get_special_price()*g[i]->get_special_count() + g[i]->get_price()*(g[i]->get_count()-(convert(y) - g[i]-> get_special_count() ) ) )
              {
                m -= g[i] -> get_special_count();
                g[i] -> set_special_count(0);
                g[i]->set_count(g[i]->get_count()-m);
              }
          }
        }

       
      else if( x == g[i] -> get_name() && g[i]->get_seller_username () == z.substr(0,z.length()-1) && g[i]->get_discount() == true ) {
        xxx = true;
        for(int j=0;j<b1.size();j++) {
          if(b1[j]->get_username() == w) {holder = j;break;}
          }

          if(g[i]->get_discount_sugguest_count() >= convert(y) && b1[holder]-> get_money() >= g[i]->get_discount_goods_price()*convert(y))
          {
           g[i] -> set_count(g[i]->get_discount_sugguest_count() - convert(y));
           g[i]->set_discount_sugguest_count();
           b1[holder]-> set_money( b1[holder]-> get_money() - g[i]->get_discount_sugguest_price()*convert(y) ); 
           goods_sold.push_back(g[i]);
           best_seller(g[i]);
          }
      }

      else if( x == g[i] -> get_name() && g[i]->get_seller_username () == z.substr(0,z.length()-1) && g[i]->get_too_many() == true) {
        xxx = true;
        for(int j=0;j<b1.size();j++) {
          if(b1[j]->get_username() == w) {holder = j;break;}
          }

          
            int m = convert(y);
          if(g[i]-> get_count() >= convert(y) && b1[holder]-> get_money() >= g[i]->get_discount_goods_price()*(g[i]->get_count_holder()-29) + g[i]-> get_price()* (convert(y) -(g[i]->get_count_holder()-29))  ){
              while(g[i]->get_too_many() == true) {
                g[i]->set_count(g[i]->get_count() - 1);
                b1[holder]-> set_money( b1[holder]-> get_money() - g[i]->get_discount_goods_price() ); 
                m--; 
                check_count();  
            }
              if(g[i]->get_too_many() == false){
                g[i]->set_count(g[i]->get_count() - m); 
                b1[holder]-> set_money( b1[holder]-> get_money() - (g[i]->get_price()*m) );
              }
            
          }
        }

        
      else if( x == g[i] -> get_name() &&  g[i]->get_count() >= convert(y) && g[i]->get_seller_username () == z.substr(0,z.length()-1) )
      {
        xxx = true;
        for(int j=0;j<b1.size();j++) {
          if(b1[j]->get_username() == w) {holder = j;break;}
        }

          if(b1[holder]-> get_money() >= g[i]->get_price()*convert(y))
          {
           g[i]->set_count(g[i]->get_count() - convert(y));
           b1[holder]-> set_money( b1[holder]-> get_money() - g[i]->get_price()*convert(y) ); 
           goods_sold.push_back(g[i]);
           best_seller(g[i]);

          }
      }
    
    }
    
    if(xxx == false){
      cout<<"Command Failed\n"; return;
    }
    
    if(z.substr(z.length()-1,z.length()) == ";"){ 
      cout<<"Command Ok\n";
       return;
    }
   }
}

void buyer_sugguest ( ) {
  string str;
  getline ( cin , str );

  stringstream iss ( str );
  bool flag = true;
  string x,y,z;
  iss>> x >> y >> z;
  for(int i = 0; i<b1.size(); i++) {
    if(x == b1[i]->get_username()) {
      flag = false;
    }
  }
    if(flag == true ) {cout << "Command Failed\n"; return;}

    else {
      for(int i = 0; i<g.size(); i++) {
      if(y == g[i]-> get_name() && z == g[i]-> get_seller_username () ){
        g[i]->set_buyer_request(x);  
      }
      if(g[i]-> get_buyer_request() >= 10 && g[i]-> get_discount() == false){
         if(g[i]-> get_being_special() == false && g[i]-> get_too_many() == false ){
            g[i]->set_discount_sugguest_price();
            g[i]->set_discount_sugguest_count();
            bool d = true;
            g[i]->set_discount(d);
          }  
      }

      }

      cout << "Command Ok\n"; return;
    }
}

void add_special_goods ( ){
  string str;
  getline ( cin , str );
  stringstream iss ( str );
  string x,y,z;
  iss >> x >> y >> z;
  for(int i = 0; i<g.size();i++) {
    if(x == g[i]->get_seller_username() && y == g[i]->get_name() && convert(z) <= g[i]->get_count() ) {
        if(g[i]-> get_discount() == false && g[i]-> get_too_many() == false ){
          g[i]->set_special_count(convert(z));
          g[i]->set_being_special (true);
          cout<<"Command Ok\n";
          return;
        }
      }
  }
  cout<<"Command Failed\n"; return;
}

void remove_special_goods ( ){
  
  string str;
  getline ( cin , str );
  stringstream iss ( str );
  string x,y,z;
  iss >> x >> y >> z;
  int holder;
  for(int i = 0; i<g.size(); i++) {
    if(x == g[i]->get_seller_username() && y == g[i]->get_name()) {
        if( convert(z) < g[i]->get_special_count() ) {
          g[i] -> set_count( g[i]->get_count() + convert(z) );
          g[i] -> set_special_count_d(convert(z));
          if(g[i]->get_special_count() == 0) { g[i] -> set_being_special(false);}
          cout<<"Command Ok\n";
        }
        
        if( convert(z) == g[i]->get_special_count() ) {
          g[i] -> set_count( g[i]->get_count() + convert(z) );
          g[i] -> set_special_count_d(convert(z));
          g[i]-> set_being_special(false);
          cout<<"Command Ok\n";
    }

  }
}
}
void search_sale ( ) {

    vector<string> out;

    for ( int i = 0; i < g.size( ); i++ ){
            if(g[i]->get_being_special() == true) {
                out.push_back ( g[i]->get_name() + " " + to_string(g[i] -> get_special_count ( )) + " " + to_string(g[i] -> get_special_price ()) + " " + g[i] -> get_seller_username () );
              }
  
            else if(g[i]->get_discount() == true) {
                out.push_back ( g[i]->get_name() + " " + to_string(g[i] -> get_discount_sugguest_count()) + " " + to_string(g[i] -> get_discount_sugguest_price()) + " " + g[i] -> get_seller_username () );
              
            }             
            else if(g[i]->get_too_many() == true) {
              out.push_back ( g[i]->get_name() + " " + to_string(g[i] -> get_count ( )) + " " + to_string(g[i] -> get_discount_goods_price()) + " " + g[i] -> get_seller_username () );
            }
         }

          int n = out.size ();
     int i, j; 


       for (i = 0; i < n-1; i++)       
         for (j = 0; j < n-i-1; j++)   {
             
           stringstream iss1 ( out[j] );
           stringstream iss2 ( out[j+1] );

      string x1,x2;

      iss1 >> x1;
      iss2 >> x2;
      
      if ( x1 > x2 ) 
          swap(&out[j], &out[j+1]); 

        }

     for (i = 0; i < n-1; i++)       
         for (j = 0; j < n-i-1; j++)   {

      stringstream iss1 ( out[j] );
      stringstream iss2 ( out[j+1] );

      string x1,x2;

      iss1 >> x1;
      iss2 >> x2;

          if(x1==x2){
            iss1 >> x1;
            iss2 >> x2;
          
             if ( convert(x1) > convert(x2) ) 
                swap(&out[j], &out[j+1]); 
         }
         }


  
     for (i = 0; i < n-1; i++)       
         for (j = 0; j < n-i-1; j++)   {
             
      stringstream iss1 ( out[j] );
      stringstream iss2 ( out[j+1] );

      string x1,x2,x3,x4;

      iss1 >> x1 >> x2;
      iss2 >> x3 >> x4;

           if ( x1 == x3 && x2 == x4 ) {
  
      iss1 >> x2;
      iss2 >> x4;

             if ( convert(x2) > convert(x4) ) 
                swap(&out[j], &out[j+1]); 

          }
        }


     for (i = 0; i < n-1; i++)       
         for (j = 0; j < n-i-1; j++)   {
             
           stringstream iss1 ( out[j] );
           stringstream iss2 ( out[j+1] );

      string x1,x2,x3,x4,x5,x6;

      iss1 >> x1 >> x3 >> x5;
      iss2 >> x2 >> x4 >> x6;

           if ( x1 == x2 && x3 == x4 && x5 == x6) {

      iss1 >> x5;
      iss2 >> x6;
      if ( x5 > x6 ) 
          swap(&out[j], &out[j+1]); 

          }
        }

    for ( int i = 0; i < out.size( ); i++ )
      cout << i+1 << ". " << out[i] << '\n';
}

void search_bestseller ( ) {

    vector<string> out;

    for ( int i = 0; i < best_sold.size( ); i++ ){
            if(best_sold[i]->get_being_special() == true) {
                out.push_back ( best_sold[i]->get_name() + " " + to_string(best_sold[i] -> get_special_count ( )) + " " + to_string(best_sold[i] -> get_special_price ()) + " " + best_sold[i] -> get_seller_username () );
                if(best_sold[i] -> get_count ( ) !=0 )
                  out.push_back ( best_sold[i]->get_name() + " " + to_string(best_sold[i] -> get_count ( )) + " " + to_string(best_sold[i] -> get_price ()) + " " + best_sold[i] -> get_seller_username () );
              }
  
            else if(best_sold[i]->get_discount() == true) {
                out.push_back ( best_sold[i]->get_name() + " " + to_string(best_sold[i] -> get_discount_sugguest_count()) + " " + to_string(best_sold[i] -> get_discount_sugguest_price()) + " " + best_sold[i] -> get_seller_username () );
                
            }             
            else if(best_sold[i]->get_too_many() == true) {
              out.push_back ( best_sold[i]->get_name() + " " + to_string(best_sold[i] -> get_count ( )) + " " + to_string(best_sold[i] -> get_discount_goods_price()) + " " + best_sold[i] -> get_seller_username () );
            }
            else 
              out.push_back ( best_sold[i]->get_name() + " " + to_string(best_sold[i] -> get_count ( )) + " " + to_string(best_sold[i] -> get_price ()) + " " + best_sold[i] -> get_seller_username () );
         }

         int n = out.size ();
         int i, j; 


       for (i = 0; i < n-1; i++)       
         for (j = 0; j < n-i-1; j++)   {
             
           stringstream iss1 ( out[j] );
           stringstream iss2 ( out[j+1] );

      string x1,x2;

      iss1 >> x1;
      iss2 >> x2;
      
      if ( x1 > x2 ) 
            swap(&out[j], &out[j+1]); 

        }

     for (i = 0; i < n-1; i++)       
         for (j = 0; j < n-i-1; j++)   {

      stringstream iss1 ( out[j] );
      stringstream iss2 ( out[j+1] );

      string x1,x2;

      iss1 >> x1;
      iss2 >> x2;

          if(x1==x2){
            iss1 >> x1;
            iss2 >> x2;
          
             if ( convert(x1) > convert(x2) ) 
                swap(&out[j], &out[j+1]); 
         }
         }


  
     for (i = 0; i < n-1; i++)       
         for (j = 0; j < n-i-1; j++)   {
             
      stringstream iss1 ( out[j] );
      stringstream iss2 ( out[j+1] );

      string x1,x2,x3,x4;

      iss1 >> x1 >> x2;
      iss2 >> x3 >> x4;

           if ( x1 == x3 && x2 == x4 ) {
  
      iss1 >> x2;
      iss2 >> x4;

             if ( convert(x2) > convert(x4) ) 
                swap(&out[j], &out[j+1]); 

          }
        }


     for (i = 0; i < n-1; i++)       
         for (j = 0; j < n-i-1; j++)   {
             
           stringstream iss1 ( out[j] );
           stringstream iss2 ( out[j+1] );

      string x1,x2,x3,x4,x5,x6;

      iss1 >> x1 >> x3 >> x5;
      iss2 >> x2 >> x4 >> x6;

           if ( x1 == x2 && x3 == x4 && x5 == x6) {

      iss1 >> x5;
      iss2 >> x6;
      if ( x5 > x6 ) 
                swap(&out[j], &out[j+1]); 

          }
        }

    for ( int i = 0; i < out.size( ); i++ )
      cout << i+1 << ". " << out[i] << '\n';
}

void add_money ( ){
  string str;
  getline ( cin , str );

  stringstream iss ( str );
  string x,y;
  iss>> x >> y;
  for(int i = 0; i<b1.size(); i++) {
      if(x == b1[i]->get_username()){
        b1[i]-> set_money(b1[i]-> get_money()+convert(y));
      }
    }  
}

void menu ( string str ) {

  if ( str == "add_user" )
    add_user ( );

  else if ( str == "add_goods" ) {
    add_goods ( );

  }

  else if ( str == "search" ) {
    search_goods ( );

  }

  else if ( str == "buy" ) {
    buy_goods ( );

  }

  else if ( str == "sale" ) {
    buyer_sugguest ( );

  }

  else if ( str == "add_special" ) {
    add_special_goods ( );

  }

  else if ( str == "remove_special" ) {
    remove_special_goods ( );

  }

  else if ( str == "add_money" ) {
    add_money ( );

  }

  else if ( str == "search_sale" ) {
    search_sale ( );

  }

  else if ( str == "search_bestseller" ) {
    search_bestseller ( );

  }

  else 
   { 
    string x; 
    getline(cin,x);
    cout << "Command Failed\n";
  }
}