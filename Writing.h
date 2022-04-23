#ifndef WRITING_H_
#define WRITING_H_
#include <iostream>
#include <fstream>
using namespace std;

class Writing {
public:
	Writing();
	virtual ~Writing();
	void writefile(string line);
	void define(string c);
};

#endif /* WRITING_H_ */

