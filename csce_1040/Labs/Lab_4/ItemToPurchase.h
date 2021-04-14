#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase
{
 private:
	int itemPrice;
	int itemQuantity;
	string itemName;
	//NEW
	string itemDescription;
 
 public:
	ItemToPurchase(string name, string desc, int price, int quan);
	void SetPrice(int num);
	int GetPrice();
	void SetQuantity(int num);
	int GetQuantity();
	void SetName(string str);
	string GetName();
	//NEW
	void SetDescription(string desc);
	string GetDescription();
	void PrintItemCost();
	void PrintItemDescription();
};

#endif