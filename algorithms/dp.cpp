#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;


/* Essentially explores every cut by fixing a intial cut and traversing the remainder cuts */
/* It does iterate over the search space quite inefficiently, i.e asking the same subproblem for same n=1, n=2, n=3, etc. */
int bruteForceSolver(int n, vector<int>& price_chart) {
	int q = INT_MIN; // Storage Variable
	if (n == 0) { // If there is nothing to cut, return
		return 0;
	}
	
	for (int i = 1; i <= n; i++) { // This was the max 1 leq i leq n, have to try all initial cuts from 1 to the entire rod
		int x = price_chart[i] + bruteForceSolver((n - i), price_chart); // The recursive subproblem (initial piece + remainder)
		q = max(q, x); 
	}

	return q;
}

int optimalSolverAux(int n, vector<int>& price_chart, int r[]) { // Given a rod of steel of length 'n', return optimal cutting
	if (r[n] >= 0) { // If we find the subproblem is already solves, that is there is a number memorized
		return r[n];
	}

	// Otherwise, we run the recursive algorithm as normal
	int q = INT_MIN; // Storage Variable
	if (n == 0) {
		q = 0; // This is slightly different as we don't just return 0, I guess we have to memorize when cuts = 0
	} else {
		for (int i = 1; i <= n; i++) {
			int x = price_chart[i] + optimalSolverAux((n - i), price_chart, r);
			q = max(q, x);
		}
	}
	r[n] = q; // Remember the optmial cut at n = some cut number, this is the memoizations

	return q;
}

int optimalSolver(int n, vector<int>& price_chart) {
	int r[n + 1]; // Init a array of n+1 size as I like to start iterating from 1 not from 0

	for (int i = 0; i <= n; i++) { // Intialize the memoization table to -infty
		r[i] = INT_MIN;
	}

	return optimalSolverAux(n, price_chart, r);
}


void runTestCases(int (*f)(int, vector<int>&)) {
	cout << "Running Test Cases..." << endl << endl;
	vector<int> price_chart = {-1, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30}; // Define the price chart as in the book. -1 is a dummy

	// Runs cutting from n = 1 to n = 10
	cout << "For n = 1, " << "func returned: " << f(1, price_chart) << endl << " Result: " << (f(1, price_chart) == 1) << endl;
	cout << "For n = 2: " << "func returned: " << f(2, price_chart) << endl << " Result: " << (f(2, price_chart) == 5) << endl;
	cout << "For n = 3: " << "func returned: " << f(3, price_chart) << endl << " Result: " << (f(3, price_chart) == 8) << endl;
	cout << "For n = 4: " << "func returned: " << f(4, price_chart) << endl << " Result: " << (f(4, price_chart) == 10) << endl;
	cout << "For n = 5: " << "func returned: " << f(5, price_chart) << endl << " Result: " << (f(5, price_chart) == 13) << endl;
	cout << "For n = 6: " << "func returned: " << f(6, price_chart) << endl << " Result: " << (f(6, price_chart) == 17) << endl;
	cout << "For n = 7: " << "func returned: " << f(7, price_chart) << endl << " Result: " << (f(7, price_chart) == 18) << endl;
	cout << "For n = 8: " << "func returned: " << f(8, price_chart) << endl << " Result: " << (f(8, price_chart) == 22) << endl;
	cout << "For n = 9: " << "func returned: " << f(9, price_chart) << endl << " Result: " << (f(9, price_chart) == 25) << endl;
	cout << "For n = 10: " << "func returned: " << f(10, price_chart) << endl << " Result: " << (f(10, price_chart) == 30) << endl;

	return;
}


int main() {
	/* Here we simulate the Pipe cutting problem found in CLRS book */
	//runTestCases(bruteForceSolver);
	runTestCases(optimalSolver); 

	return 0;
}










