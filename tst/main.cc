#include "main.hh"

#include <iostream>

using namespace std;

list<TestCase *> testCases;

int main(int argc, char * argv[]) {
	int tested = 0;
	int success = 0;
	int failure = 0;

	for (list<TestCase *>::iterator it = testCases.begin();
			it != testCases.end(); ++it) {
		TestCase *testCase = *it;
		testCase->execute();

		++tested;

		cout << (testCase->success() ? "success: " : "failure: ")
				<< testCase->name() << ": " << testCase->message() << endl;

		if (testCase->success()) {
			++success;
		} else {
			++failure;
		}
	}

	cout << "-------------------------------------------" << endl;
	cout << "tested: " << tested << endl;
	cout << "success: " << success << endl;
	cout << "failure: " << failure << endl;
	return 0;
}
