a.out: main.o Buyer.o Seller.o Goods.o Function.o
	g++ main.o Buyer.o Seller.o Goods.o Function.o 
main.o:main.cpp 
	g++ -c main.cpp 
Buyer.o:Buyer.cpp
	g++ -c Buyer.cpp
Seller.o:Seller.cpp
	g++ -c Seller.cpp
Goods.o:Goods.cpp
	g++ -c Goods.cpp 
Function.o:Function.cpp 
	g++ -c Function.cpp 

