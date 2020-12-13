#include<iostream>
#include<string>
#include <iomanip>
using namespace std;


//constants
const int MAXNUMOFINGREDIENTS = 5;
const int MAXCARTCAPACITY = 20;
const int TOTALNUMOFITEMS = 25;
const int TOTALNUMOFRECIPES = 10;			

//item class
class Item
{
private:
	string name;
	double price;

public:
	void setItemPrice(double pricePar)
	{
		price = pricePar;
	}
	void setItemName(string namePar)
	{
		name = namePar;
	}

	string getItemName()
	{
		return name;
	}

	double getItemPrice()
	{
		return price;
	}

};

//Recipe Class
class Recipe
{
private:
	Item ingrdients[MAXNUMOFINGREDIENTS];
	string recipeName;
	double totalPrice;
	int currentNum = 0;

public:
	void setRecipeName(string recipeNamePar)
	{
		recipeName = recipeNamePar;
	}


	void getIngredients()
	{
		cout << "Items needed for " << recipeName << ": " << endl;
		for (int i = 0; i < MAXNUMOFINGREDIENTS; i++)
		{
			cout << ingrdients[i].getItemName() << endl;
		}
		cout << "\n";
	}

	void addIngredients(string ingredientNamePar)
	{
		ingrdients[currentNum].setItemName(ingredientNamePar);
		currentNum += 1;
	}

	void addIngredients(string ingredientNamePar, string ingredientNamePar2)
	{
		ingrdients[currentNum].setItemName(ingredientNamePar);
		currentNum += 1;
		ingrdients[currentNum].setItemName(ingredientNamePar2);
		currentNum += 1;
	}

	void addIngredients(string ingredientNamePar, string ingredientNamePar2, string ingredientNamePar3)
	{
		ingrdients[currentNum].setItemName(ingredientNamePar);
		currentNum += 1;
		ingrdients[currentNum].setItemName(ingredientNamePar2);
		currentNum += 1;
		ingrdients[currentNum].setItemName(ingredientNamePar3);
		currentNum += 1;
	}

	void addIngredients(string ingredientNamePar, string ingredientNamePar2, string ingredientNamePar3, string ingredientNamePar4)
	{
		ingrdients[currentNum].setItemName(ingredientNamePar);
		currentNum += 1;
		ingrdients[currentNum].setItemName(ingredientNamePar2);
		currentNum += 1;
		ingrdients[currentNum].setItemName(ingredientNamePar3);
		currentNum += 1;
		ingrdients[currentNum].setItemName(ingredientNamePar4);
		currentNum += 1;
	}

	void addIngredients(string ingredientNamePar, string ingredientNamePar2, string ingredientNamePar3, string ingredientNamePar4, string ingredientNamePar5)
	{
		ingrdients[currentNum].setItemName(ingredientNamePar);
		currentNum += 1;
		ingrdients[currentNum].setItemName(ingredientNamePar2);
		currentNum += 1;
		ingrdients[currentNum].setItemName(ingredientNamePar3);
		currentNum += 1;
		ingrdients[currentNum].setItemName(ingredientNamePar4);
		currentNum += 1;
		ingrdients[currentNum].setItemName(ingredientNamePar5);
		currentNum += 1;
	}

	bool isAnIngredient(string itemNamePar)
	{
		for (int i = 0; i < MAXNUMOFINGREDIENTS; i++)
		{
			if (itemNamePar == ingrdients[i].getItemName())
			{
				return true;
			}
		}
		return false;
	}

	string getRecipeName()
	{
		return recipeName;
	}

};

//Function Protocal
void addItemToCart(string itemNamePar, Item itemsInStockPar[TOTALNUMOFITEMS], Item itemsInCartPar[MAXCARTCAPACITY], int& currentItem, bool isInCartPar[TOTALNUMOFITEMS]);
void checkWhatsInCart(Item itemsInCartPar[MAXCARTCAPACITY]);
void checkWhatsInStock(string listOfItemNamesPar[TOTALNUMOFITEMS], bool isInCartPar[TOTALNUMOFITEMS], double listOfItemPrices[TOTALNUMOFITEMS]);
void checkAvailableRecipies(bool isInCartPar[TOTALNUMOFITEMS], Recipe menuePar[TOTALNUMOFRECIPES], string listOfItemNamesPar[TOTALNUMOFITEMS]);
double checkTotal(Item itemsInCartPar[MAXCARTCAPACITY], double currentTotalPar);
void setItemPrice(string listOfItemNamesPar[TOTALNUMOFITEMS], double listOfItemPrices[TOTALNUMOFITEMS], Item itemsInCartPar[MAXCARTCAPACITY]);
void ingredientsForRecipies(bool isInCartPar[TOTALNUMOFITEMS], Recipe  menuePar[TOTALNUMOFRECIPES], string listOfItemNamesPar[TOTALNUMOFITEMS]);


int main()
{
	//*******************************************************************Initialize Items, Recipies, and Prices*******************************************
	Item itemsInStock[TOTALNUMOFITEMS];
	string listOfRecipies[TOTALNUMOFRECIPES] = { "grilled cheese sandwich", "chicken alfredo", "pico de gallo", "pankae", "tuna salad", "coleslow", "crepe", "macaroni and cheese", "avocado tuna salad", "chicken fired rice" };
	Recipe menue[TOTALNUMOFRECIPES];
	string listOfItemNames[TOTALNUMOFITEMS] = { "bread", "cheese", "pasta", "chicken", "milk", "tomatoes", "onion", "lime", "cilantro", "flour", "sugar", "baking soda", "salt", "tuna", "mayonnaise", "celery", "carrots", "cabbage", "eggs", "vanilla", "avocado", "peas", "rice", "ginger", "garlic" };
	double listOfItemPrices[TOTALNUMOFITEMS] = { 3.64, 2.29, 1.29, 8.99, 3.19, 0.49, 0.85, 0.49, 1.59, 1.39, 2.49, 0.85, 0.89, 1.99, 3.19, 1.19, 0.99, 1.79, 1.39, 2.39, 0.55, 1.19, 7.99, 1.59, 1.37 };
	bool isInCart[TOTALNUMOFITEMS] = { false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false, false };

	//sets itemsInstock name and price
	for (int i = 0; i < TOTALNUMOFITEMS; i++)
	{
		itemsInStock[i].setItemName(listOfItemNames[i]);
		itemsInStock[i].setItemPrice(listOfItemPrices[i]);
	}

	//sets menue items name and price
	for (int i = 0; i < TOTALNUMOFRECIPES; i++)
	{
		menue[i].setRecipeName(listOfRecipies[i]);
	}

	//initializing ingredients for each recipe in menue
	menue[0].addIngredients("bread", "cheese");
	menue[1].addIngredients("cheese", "pasta", "chicken", "milk");
	menue[2].addIngredients("tomatoes", "onion", "lime", "cilantro");
	menue[3].addIngredients("flour", "sugar", "baking soda");
	menue[4].addIngredients("tuna", "cheese", "onion", "mayonnaise", "celery");
	menue[5].addIngredients("onion", "cabbage", "carrots");
	menue[6].addIngredients("flour", "sugar", "milk", "vanilla", "eggs");
	menue[7].addIngredients("cheese", "pasta", "milk");
	menue[8].addIngredients("avocado", "tuna", "celery", "eggs", "salt");
	menue[9].addIngredients("garlic", "ginger", "rice", "peas", "chicken");


	//variables
	Item itemsInCart[MAXCARTCAPACITY];
	char userChoice = 'y';
	int currentItem = 0;
	string itemname;
	double currentTotal = 0;

	//*******************************************************************Get User Input and Calculations*******************************************


	cout << "Do you want to add an item to cart? (y/n)";
	cin >> userChoice;

	while (userChoice == 'y' || userChoice == 'Y')
	{
		checkWhatsInStock(listOfItemNames, isInCart, listOfItemPrices);
		cout << "----------------------------------------------------" << endl;
		cout << "Please enter item name: ";
		cin >> itemname;
		addItemToCart(itemname, itemsInStock, itemsInCart, currentItem, isInCart);
		setItemPrice(listOfItemNames, listOfItemPrices, itemsInCart);

		cout << "----------------------------------------------------" << endl;


		checkWhatsInCart(itemsInCart);
		cout << "Running Total: $" << checkTotal(itemsInCart, currentTotal) << endl << endl;

		cout << "----------------------------------------------------" << endl;

		checkAvailableRecipies(isInCart, menue, listOfItemNames);
		cout << endl;
		cout << "----------------------------------------------------" << endl;


		ingredientsForRecipies(isInCart, menue, listOfItemNames);

		cout << "----------------------------------------------------" << endl;
		cout << "Do you want to add another item to your cart?(y/n)";
		cin >> userChoice;
		cout << endl << endl;
	}

	//*******************************************************************Final Cart, Total, and Farwell*******************************************

	checkWhatsInCart(itemsInCart);
	cout << "Sub Total: " << checkTotal(itemsInCart, currentTotal) << endl;
	cout << fixed << setprecision(2) << "Total: " << (checkTotal(itemsInCart, currentTotal) * 0.0725) + checkTotal(itemsInCart, currentTotal) << endl;
	cout << "Thank You For Shopping!!!!" << endl << endl;
}


//*******************************************************************Methods*******************************************

void addItemToCart(string itemNamePar, Item itemsInStockPar[TOTALNUMOFITEMS], Item itemsInCartPar[MAXCARTCAPACITY], int& currentItem, bool isInCartPar[TOTALNUMOFITEMS])
{
	bool wasFound = false;
	for (int i = 0; i < TOTALNUMOFITEMS; i++)
	{
		if (itemNamePar == itemsInStockPar[i].getItemName())
		{
			itemsInCartPar[currentItem].setItemName(itemNamePar);
			currentItem += 1;
			wasFound = true;
			isInCartPar[i] = true;
			break;
		}
	}
	if (wasFound == false)
	{
		cout << "Sorry item is not in stock" << endl;
	}
}

void checkWhatsInCart(Item itemsInCartPar[MAXCARTCAPACITY])
{
	cout << "----------------------------------------------------" << endl;
	cout << "Cart: " << endl;
	for (int i = 0; i < MAXCARTCAPACITY; i++)
	{
		if (itemsInCartPar[i].getItemName().length() > 1)
		{
			cout << itemsInCartPar[i].getItemName() << " ------- $" << itemsInCartPar[i].getItemPrice() << endl;
		}
	}
	cout << "----------------------------------------------------" << endl;
}

void checkAvailableRecipies(bool isInCartPar[TOTALNUMOFITEMS], Recipe menuePar[TOTALNUMOFRECIPES], string listOfItemNamesPar[TOTALNUMOFITEMS])
{
	cout << "You have one or more items for the following dishes: " << endl;
	for (int i = 0; i < TOTALNUMOFITEMS; i++)
	{
		for (int j = 0; j < TOTALNUMOFRECIPES; j++)
		{
			if (isInCartPar[i] == true && menuePar[j].isAnIngredient(listOfItemNamesPar[i]) == true)
			{
				cout << menuePar[j].getRecipeName() << " ----- " << listOfItemNamesPar[i] << endl;
			}
		}
	}
}

void checkWhatsInStock(string listOfItemNamesPar[TOTALNUMOFITEMS], bool isInCartPar[TOTALNUMOFITEMS], double listOfItemPrices[TOTALNUMOFITEMS])
{
	cout << "Items in stock: " << endl;
	for (int i = 0; i < TOTALNUMOFITEMS; i++)
	{
		if (isInCartPar[i] == false)
		{
			cout << listOfItemNamesPar[i] << " ------- $" << listOfItemPrices[i] << endl;
		}
	}
}

double checkTotal(Item itemsInCartPar[MAXCARTCAPACITY], double currentTotalPar)
{
	double sum = currentTotalPar;
	for (int i = 0; i < MAXCARTCAPACITY; i++)
	{
		if (itemsInCartPar[i].getItemPrice() < 8 && itemsInCartPar[i].getItemPrice() > 0.2)
		{
			sum += itemsInCartPar[i].getItemPrice();
		}
	}
	return sum;
}

void setItemPrice(string listOfItemNamesPar[TOTALNUMOFITEMS], double listOfItemPrices[TOTALNUMOFITEMS], Item itemsInCartPar[MAXCARTCAPACITY])
{
	for (int i = 0; i < MAXCARTCAPACITY; i++)
	{
		for (int j = 0; j < TOTALNUMOFITEMS; j++)
		{
			if (itemsInCartPar[i].getItemName() == listOfItemNamesPar[j] || itemsInCartPar[i].getItemPrice() == listOfItemPrices[j])
			{
				itemsInCartPar[i].setItemPrice(listOfItemPrices[j]);
			}
		}
	}
}

void ingredientsForRecipies(bool isInCartPar[TOTALNUMOFITEMS], Recipe menuePar[TOTALNUMOFRECIPES], string listOfItemNamesPar[TOTALNUMOFITEMS])
{
	for (int i = 0; i < TOTALNUMOFITEMS; i++)
	{
		for (int j = 0; j < TOTALNUMOFRECIPES; j++)
		{
			if (isInCartPar[i] == true && menuePar[j].isAnIngredient(listOfItemNamesPar[i]) == true)
			{
				menuePar[j].getIngredients();
			}
		}
	}
}
