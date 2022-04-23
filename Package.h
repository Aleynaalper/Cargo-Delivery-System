
#ifndef PACKAGE_H_
#define PACKAGE_H_
#include <iostream>

using namespace std;

class Package {        //I created a Package class because Stack should have "Type" in it
public:
	string name;	   //I created the required value
	Package(){}
	virtual ~Package(){}
};

#endif /* PACKAGE_H_ */
