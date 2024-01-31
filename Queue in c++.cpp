// CPP code to illustrate Queue in 

#include <iostream> // Include the input/output stream library
#include <queue> // Include the queue container  header

using namespace std; // Using the standard namespace

// Print the queue
void showq(queue<int> gq)
{
	queue<int> g = gq;
	while (!g.empty()) {
		cout << '\t' << g.front();
		g.pop();
	}
	cout << '\n';
}

// Driver Code
int main()
{
	queue<int> gquiz; // Declare a queue of integers
	gquiz.push(10); // Push elements onto the queue
	gquiz.push(20);
	gquiz.push(30);

	cout << "The queue gquiz is : ";
	showq(gquiz); // Print the contents of the queue

	cout << "\ngquiz.size() : " << gquiz.size(); // Print the size of the queue
	cout << "\ngquiz.front() : " << gquiz.front(); // Print the front element of the queue
	cout << "\ngquiz.back() : " << gquiz.back(); // Print the back element of the queue

	cout << "\ngquiz.pop() : ";
	gquiz.pop(); // Pop an element from the queue
	showq(gquiz); // Print the updated contents of the queue

	return 0;
}
