#include <iostream>

using namespace std;

class Mouse{

	private:
		string name;
		string breed;
		float weight;
		char gender;
		string fav_food;
		string color;
		string comments;	

	public:
		Mouse();
		Mouse(string n, string b, float w, char g, string f, string co, string com);

		void setName(string n);
		void setBreed(string b);
		void setWeight(float w);
		void setGender(char g);
		void setFood(string f);
		void setColor(string co);
		void setComments(string com);

		string getName();
		string getBreed();
		float getWeight();
		char getGender();
		string getFood();	
		string getColor();
		string getComments();

		void print();


};