#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

int main() {
   
   ItemToPurchase item1= ItemToPurchase();
   ItemToPurchase item2= ItemToPurchase();
   string tempname;
   int tempprice;
   int tempquan;
   
  //item one
  cout << "Item 1" << endl << "Enter the item name:" << endl;
  getline(cin, tempname);
  item1.SetName(tempname);
  
  cout << "Enter the item price:"<< endl;
  cin >> tempprice; 
  item1.SetPrice(tempprice);
  
  cout << "Enter the item quantity:"<< endl << endl;
  cin >> tempquan;
  item1.SetQuantity(tempquan);
  
   cin.ignore();
  
//item two
  cout << "Item 2" << endl << "Enter the item name:"<< endl;
  getline(cin, tempname);
  item2.SetName(tempname);
  
  cout << "Enter the item price:"<< endl;
  cin >> tempprice; 
  item2.SetPrice(tempprice);
  
  cout << "Enter the item quantity:"<< endl << endl;
  cin >> tempquan;
  item2.SetQuantity(tempquan);


   
//math
   int totalitem1;
   int totalitem2;
   totalitem1 = (item1.GetQuantity() * item1.GetPrice());
   totalitem2 = (item2.GetQuantity() * item2.GetPrice());
   
   cout << "TOTAL COST" << endl;
   cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << totalitem1 << endl;
   cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << totalitem2 << endl;
   cout << endl << "Total: $" << totalitem1 + totalitem2 << endl;
   /* Type your code here */
   
   
   
   return 0;
}