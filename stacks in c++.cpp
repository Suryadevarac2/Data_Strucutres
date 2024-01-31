#include <iostream> 
#include <stack>
using namespace std;

int main() {
    // Creating a stack to hold integers
	stack<int> stack;
    
    // Pushing integers onto the stack
	stack.push(21); // Pushing 21 onto the stack
	stack.push(22); // Pushing 22 onto the stack
	stack.push(24); // Pushing 24 onto the stack
	stack.push(25); // Pushing 25 onto the stack
    
    // Declaring and initializing an integer variable
	int num = 0;
    
    // Pushing the value of 'num' onto the stack
	stack.push(num); // Pushing the value of 'num' (which is 0) onto the stack
    
    // Removing the top element from the stack twice
	stack.pop(); // Removing the top element from the stack
	stack.pop(); // Removing the top element from the stack
	stack.pop(); // Removing the top element from the stack

    // Printing the remaining elements of the stack
	while (!stack.empty()) {
		cout << stack.top() << " "; // Printing the top element of the stack
		stack.pop(); // Removing the top element from the stack
	}
}
