
/*

 Explanation of Real-Life Scenario:
 --------------------------------
In a corporate environment, the organizational hierarchy is crucial for managing employees,
delegating tasks, and ensuring effective communication and coordination within the company.
An organizational chart serves as a visual representation of this hierarchy, illustrating the
reporting relationships and structure of the organization.

*/


#include <iostream>
#include <string>
using namespace std;

// Define a structure for an employee node in the organizational chart
struct EmployeeNode {
    string name;
    EmployeeNode* left;  // Pointer to the left child node (direct subordinate)
    EmployeeNode* right; // Pointer to the right child node (another subordinate)

    // Constructor to initialize employee node with name
    EmployeeNode(string name) : name(name), left(nullptr), right(nullptr) {}
};

// Function to create a new employee node
EmployeeNode* createEmployeeNode(string name) {
    return new EmployeeNode(name);
}

// Function to add a direct subordinate to a given employee
void addSubordinate(EmployeeNode* supervisor, string subordinateName) {
    if (supervisor->left == nullptr) {
        supervisor->left = createEmployeeNode(subordinateName);
    }
    else if (supervisor->right == nullptr) {
        supervisor->right = createEmployeeNode(subordinateName);
    }
    else {
        cout << "Supervisor '" << supervisor->name << "' already has two subordinates." << endl;
    }
}

// Function to print the organizational chart using preorder traversal
void printPreorder(EmployeeNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->name << " "; // Print current node

    // Recursive call for left and right subtrees
    printPreorder(root->left);
    printPreorder(root->right);
}

// Function to print the organizational chart using inorder traversal
void printInorder(EmployeeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Recursive call for left subtree
    printInorder(root->left);

    cout << root->name << " "; // Print current node

    // Recursive call for right subtree
    printInorder(root->right);
}

// Function to print the organizational chart using postorder traversal
void printPostorder(EmployeeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Recursive call for left and right subtrees
    printPostorder(root->left);
    printPostorder(root->right);

    cout << root->name << " "; // Print current node
}

int main() {
    // Create the CEO (root of the organizational chart)
    EmployeeNode* ceo = createEmployeeNode("CEO");

    // Add direct subordinates to the CEO
    addSubordinate(ceo, "Manager A");
    addSubordinate(ceo, "Manager B");

    // Add subordinates to Manager A
    addSubordinate(ceo->left, "Employee A1");
    addSubordinate(ceo->left, "Employee A2");

    // Add subordinates to Manager B
    addSubordinate(ceo->right, "Employee B1");
    addSubordinate(ceo->right, "Employee B2");

    // Print the organizational chart using different traversals
    cout << "Organizational Chart (Preorder Traversal): ";
    printPreorder(ceo);
    cout << endl;

    cout << "Organizational Chart (Inorder Traversal): ";
    printInorder(ceo);
    cout << endl;

    cout << "Organizational Chart (Postorder Traversal): ";
    printPostorder(ceo);
    cout << endl;

    return 0;
}

/*
Explanation of Data Structure Suitability:
------------------------------------------

In this scenario, the binary tree structure represents an organizational chart where each node represents an employee within the company. Here's how the scenario aligns with the code:

Employee Representation: Each node in the binary tree represents an employee, with attributes such as the employee's name and position within the company.

Hierarchy Establishment: The binary tree structure allows for the establishment of a hierarchical structure within the organization. Employees are organized based on their reporting relationships, with each manager having direct subordinates represented by left and right child nodes.

Traversal Methods:

Preorder Traversal: Visits the root node first, followed by the left subtree, and then the right subtree. In the organizational context, printing the organizational chart using preorder traversal lists the employees from the top-down, starting with the CEO and then listing managers and their subordinates.
Inorder Traversal: Visits the left subtree first, followed by the root node, and then the right subtree. While not directly applicable to organizational charts, inorder traversal could be used to list employees alphabetically based on their names.
Postorder Traversal: Visits the left subtree first, followed by the right subtree, and then the root node. In the organizational context, printing the organizational chart using postorder traversal lists the employees from the bottom-up, starting with the lowest-level employees and then moving up to their respective managers and the CEO.
Scalability and Flexibility: The binary tree structure can accommodate organizations of varying sizes and complexities, making it suitable for representing organizational charts in different corporate environments. Additionally, the code provides flexibility to add or remove employees dynamically, allowing the organizational chart to adapt to changes within the company.

Overall, the code example demonstrates how a binary tree structure can be utilized to represent an organizational chart, providing a clear and hierarchical visualization of the reporting relationships and structure within a company.


*/