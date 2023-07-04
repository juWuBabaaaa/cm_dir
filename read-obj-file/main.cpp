#include <fstream>
#include <iostream>

#include <sstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	ifstream infile("obj/output.obj");
	int i = 0;
	string line;

	while (getline(infile, line)) {
		i++;
		cout << line << endl;
	}
	cout << "num of lines: " << i << endl;

	return 0;
}