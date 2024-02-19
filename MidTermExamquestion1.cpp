/*
Explanation of Real-Life Scenario:
---------------------------------

In cooking, managing the ingredients for a recipe productively is crucial for organizing the 
cooking prepare. Connected records offer a practical arrangement for this situation, 
with each node representing an ingredient and containing its title and a pointer to the next
ingredient. The linked list structure permits for energetic expansion of fixings and easy 
traversal of the list to print all required fixings, giving a flexible and proficient way 
to manage fixing records for formulas.

*/


#include <iostream>  // Include input/output stream library
#include <string>    // Include string library for string manipulation
using namespace std; // Using standard namespace

class Node { // Declare class Node for individual elements in the linked list
public:
    string ingredient; // Data member to store ingredient name
    Node* next; // Pointer to the next node in the linked list

    // Constructor to initialize node with ingredient name and next pointer
    Node(string value) : ingredient(value), next(nullptr) {}
};

class IngredientsList { // Declare class IngredientsList to manage the linked list of ingredients
private:
    Node* head; // Pointer to the first node in the linked list

public:
    // Constructor to initialize IngredientsList with null head pointer
    IngredientsList() : head(nullptr) {}

    // Function to add a new ingredient to the end of the list
    void addIngredient(string ingredient) {
        // Create a new node with the given ingredient
        Node* newNode = new Node(ingredient);
        // If the list is empty, set the new node as the head
        if (head == nullptr) {
            head = newNode;
            return;
        }
        // Traverse the list to find the last node
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        // Insert the new node at the end of the list
        current->next = newNode;
    }

    // Function to print all ingredients in the list
    void printIngredients() {
        Node* current = head;
        cout << "Ingredients List:" << endl;
        int count = 1;
        // Traverse the list and print each ingredient
        while (current != nullptr) {
            cout << count << ". " << current->ingredient << endl;
            current = current->next;
            count++;
        }
    }

    // Destructor to deallocate memory for all nodes in the list
    ~IngredientsList() {
        Node* current = head;
        Node* next;
        // Traverse the list and delete each node
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() { // Main function to test the IngredientsList class
    IngredientsList recipeIngredients; // Create an instance of IngredientsList
    int size;
    cout << "Enter the number of ingredients in the recipe: ";
    cin >> size;
    cin.ignore(); // Clear newline character from buffer
    cout << "Enter the ingredient names:" << endl;
    // Add each ingredient entered by the user to the list
    for (int i = 0; i < size; ++i) {
        string ingredient;
        getline(cin, ingredient);
        recipeIngredients.addIngredient(ingredient);
    }
    // Print the list of ingredients
    recipeIngredients.printIngredients();
    return 0;
}


/*
 Explanation of Data Structure Suitability:
 -----------------------------------------

In the scenario of managing an ingredients list for a recipe, a linked list data structure is a suitable choice due to several reasons :

Dynamic Size : Linked lists are dynamic data structures, meaning they can grow or shrink in size as needed.In the context of an ingredients list, the number of ingredients required for a recipe may vary, and a linked list allows for efficient addition and removal of ingredients without the need to pre - allocate a fixed - size array.

Efficient Insertion and Deletion : Linked lists offer efficient insertion and deletion operations, particularly at the beginning or end of the list.For recipes where ingredients may need to be added or removed dynamically, such as during the cooking process or when modifying a recipe, a linked list allows for quick updates to the list without the overhead of shifting elements in an array.

Flexibility : Linked lists provide flexibility in terms of memory allocation, as memory for each node can be allocated individually.This flexibility is beneficial for managing ingredients of varying lengths(e.g., longer ingredient names) without wasting memory.Additionally, linked lists can easily accommodate nodes of different types, allowing for additional metadata or attributes to be associated with each ingredient if needed.

Traversal and Access : While sequential access in linked lists is not as efficient as arrays, linked lists still offer efficient traversal from the beginning to the end of the list.In the context of an ingredients list, where it's common to display all ingredients in order, linked lists facilitate easy traversal and printing of the entire list.

Advantages of using a linked list in this scenario include :

Dynamic Memory Allocation : Linked lists allow for efficient memory allocation and deallocation, enabling the list to grow or shrink dynamically based on the number of ingredients.
Efficient Insertion and Deletion : Adding or removing ingredients from the list is efficient, particularly at the beginning or end, as it only requires updating pointers without the need to shift elements.
Flexibility in Size : Linked lists do not have a fixed size, making them suitable for scenarios where the number of ingredients may vary.
Ease of Implementation : Linked lists are relatively simple to implement and understand, making them suitable for managing straightforward lists like ingredients for a recipe without the complexity of other data structures.


Overall, the linked list data structure offers the necessary flexibility, efficiency, and ease of use required for managing an ingredients list for a recipe.


*/