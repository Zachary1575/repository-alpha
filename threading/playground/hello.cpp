#include <iostream>
#include <thread> // Threading library

using namespace std;

void hello() {
	cout << "Hello Concurrent World! \n" << endl;
}


int main() { // main itself is a thread
	thread t(hello); // Hello counts as an initial function
	t.join(); // Ask the main running thread to wait till 't' thread object has finished

	return 0;
}









