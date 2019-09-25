// Prime Number Generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int limit;
	int index = 0;
	vector<int> primeList{ 2, 3, 5 };
	double ceiling = primeList.back() / double(primeList[index]);

	cout << "Please input the maximum of the prime list(all prime numbers will be under your maximum): ";
	cin >> limit;

	// Is last prime number smaller than the user-inputted maximum?
	while (primeList.back() < limit) {
		while (primeList[index] <= ceiling) {
			if (primeList.back() % primeList[index] == 0) {
				primeList.back() += 2;
				index = 0;
				ceiling = primeList.back() / primeList[index];
			}
			else if (primeList.back() % primeList[index] != 0) {
				index += 1;
				ceiling = primeList.back() / primeList[index];
			}
		}
		primeList.push_back(primeList.back() + 2);
		index = 0;
		ceiling = primeList.back() / primeList[index];
	}
	primeList.pop_back();
	primeList.pop_back();

	for (unsigned int i = 0; i < primeList.size(); i++) {
		if (i != primeList.size() - 1) {
			cout << primeList[i] << ", ";
		}
		else {
			cout << primeList[i] << endl;
		}
	}

	cout << "Number of prime numbers: " << primeList.size() << endl;
	return 0;

}
