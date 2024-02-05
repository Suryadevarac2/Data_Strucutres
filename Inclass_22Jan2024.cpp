#include<iostream>
using namespace std;
int main()
{
	string cars[4] = { "Volvo", "BMW", "Ford", "Mazda" };
	cout << cars[0] << endl;//printing 1st element of Array

	int myNum[4] = { 10,20,30,70 };
	cout << myNum[2] << "\n";//\n for getting new line 

	for (int i = 0; i < 4; i++) {
		cout << cars[i] << endl;//Accessing all the element of Array using for loop
		cout << myNum[i] << endl;
	}
	
	cout << "Hello World!"<<endl;

	cars[0] = "Opel";// Replacing cars Array with Opel string at 1st element
	cout << cars[0];

	for (int i = 0; i < 4; i++) {
		cout << cars[i] << endl;//Pring each array after replacing 1st element
		
	}

	int myNumbers[5] = { 10, 20, 30, 40, 50 };//For each loop Examplw
	for (int i : myNumbers) {
		cout << i << "\n";
	}

	string Carmodels[] = { "Volvo", "BMW", "Ford" };//Three Element Array declaration  with out declaring size
	string Carmodels1[3]= {"Volvo", "BMW", "Ford"};//Element Declaration with declaring size

	int myNumbers1[5] = { 10,20,30,40,50 };
	cout << sizeof(myNumbers1) << endl;//sizeof() give sizes in terms of bytes for numerics each element is 4 byte  so 5*4=20 ids o/p
	int length_Array = sizeof(myNumbers1) / sizeof(myNumbers1[0]);//It gives length of array
	cout << length_Array << endl;
	
	string letters[2][4] = {
		{"A","B","C","D"},
	{ "E","F","G","H"}
	};

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			cout << letters[i][j] << "\n";
		}
	}

	string letters1[2][2][2] = {
{
{ "A", "B" },
{ "C", "D" }
},
{
{ "E", "F" },
{ "G", "H" }
}
	};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				cout << letters1[i][j][k] << "\n";
				cout << letters1[i][j][k] << "\t";
			}
		}
	}

	// We put "1" to indicate there is a ship.
	bool ships[4][4] = {
	  { 0, 1, 1, 0 },
	  { 0, 0, 0, 0 },
	  { 0, 0, 1, 0 },
	  { 0, 0, 1, 0 }
	};

	// Keep track of how many hits the player has and how many turns they have played in these variables
	int hits = 0;
	int numberOfTurns = 0;

	// Allow the player to keep going until they have hit all four ships
	while (hits < 4) {
		int row, column;

		cout << "Selecting coordinates\n";

		// Ask the player for a row
		cout << "Choose a row number between 0 and 3: ";
		cin >> row;

		// Ask the player for a column
		cout << "Choose a column number between 0 and 3: ";
		cin >> column;

		// Check if a ship exists in those coordinates
		if (ships[row][column]) {
			// If the player hit a ship, remove it by setting the value to zero.
			ships[row][column] = 0;

			// Increase the hit counter
			hits++;

			// Tell the player that they have hit a ship and how many ships are left
			cout << "Hit! " << (4 - hits) << " left.\n\n";
		}
		else {
			// Tell the player that they missed
			cout << "Miss\n\n";
		}

		// Count how many turns the player has taken
		numberOfTurns++;
	}

	cout << "Victory!\n";
	cout << "You won in " << numberOfTurns << " turns";

	return 0;
	}