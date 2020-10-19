#ifndef Goods_H
#define Goods_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector> 
using namespace std;



class Goods {

  public :

      Goods ( string str );

      string get_name () {
        return goods_name;
      }
      int get_count () {
        return goods_count;
      }
      int get_price () {
        return goods_price;
      }
      string get_seller_username () {return seller_username;}
      int get_buyer_request(){return buyer_request.size(); }
      void set_count(int c) {goods_count = c;}
      void set_price(int p) {goods_price = p;}
      void set_buyer_request(string b) {
      bool flag = true;
      if(buyer_request.size() == 0){buyer_request.push_back(b);}
      for(int i=0; i<buyer_request.size(); i++)
      if(b == buyer_request[i]){flag = false;}
      if(flag == true){buyer_request.push_back(b);}
        }
      bool get_discount(){
        return discount;
      }  
      void set_discount(bool d) {discount = d;}
      int get_discount_sugguest_count(){return discount_sugguest_count;}
      void set_discount_sugguest_count(){discount_sugguest_count = goods_count; goods_count = 0;}

      void set_special_count (int sp) { 
        goods_count -= sp;
        special_goods_count = sp;
        special_goods_price = (goods_price*0.9); 
        } 
      void set_special_count_d(int sp) {special_goods_count -= sp;}
      int get_special_count() {return special_goods_count;}
      int get_special_price() {return special_goods_price;}
      void set_discount_price() {discount_goods_price = goods_price*0.9;}
      int get_discount_goods_price(){return discount_goods_price;}
      void set_discount_sugguest_price(){discount_sugguest_price = goods_price*0.9;}
      int get_discount_sugguest_price(){return discount_sugguest_price;}
      void set_best_sold(bool d){best_sold = d;}
      bool get_best_sold(){return best_sold;}
      void set_too_many(bool d){too_many = d;}
      bool get_too_many(){return too_many;}
      void set_being_special(bool d){being_special = d;}
      bool get_being_special(){return being_special;}
      void set_count_holder(int h) { count_holder = h;}
      int get_count_holder() { return count_holder;}

  private : 

    vector <string> buyer_request;

    bool best_sold = false;
    bool discount = false;
    bool too_many = false;
    bool being_special = false;string seller_username;
    string goods_name;

    int goods_price;
    int special_goods_price;
    int discount_goods_price;
    int discount_sugguest_price;
    int goods_count;
    int special_goods_count;
    int discount_sugguest_count;
    int count_holder;
    

};

#endif