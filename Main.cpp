#include "ReadFromFile.h"

#include <iostream>
using namespace std;

int main(int argc, const char *argv[]) {
	ReadFromFile readfromfile;
	readfromfile.creating_object(argv[1]);
	readfromfile.truck(argv[3]);
	readfromfile.package(argv[2],argv[4],argv[5]);

	return 0;
}
