#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

/* Type your code here */
ItemToPurchase::ItemToPurchase(){
   itemPrice=0;
   itemQuantity=0;
   itemName="None";
}
void ItemToPurchase::SetPrice(int num) {
      itemPrice = num;
   }
void ItemToPurchase::SetQuantity(int num) {
      itemQuantity = num;
   }
void ItemToPurchase::SetName(string str) {
      itemName = str;
   }
int ItemToPurchase::GetPrice() {
      return itemPrice;
   }
int ItemToPurchase::GetQuantity() {
      return itemQuantity;
   }
string ItemToPurchase::GetName() {
      return itemName;
   }