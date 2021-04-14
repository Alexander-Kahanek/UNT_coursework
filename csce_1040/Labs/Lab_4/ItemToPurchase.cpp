#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

/* Type your code here */
ItemToPurchase::ItemToPurchase(string name="none", string desc="none", int price=0, int quan=0){
   itemPrice=price;
   itemQuantity=quan;
   itemName=name;
   itemDescription = desc;
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
void ItemToPurchase::SetDescription(string desc) {
      itemDescription = desc;
   }
string ItemToPurchase::GetDescription() {
      return itemDescription;
   }
void ItemToPurchase::PrintItemCost() {
      cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemPrice * itemQuantity << endl;
   }
void ItemToPurchase::PrintItemDescription() {
      cout << itemName << ": " << itemDescription << endl;
   }