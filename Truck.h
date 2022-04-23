
#ifndef TRUCK_H_
#define TRUCK_H_

#include <iostream>
using namespace std;

 class Truck :public Package{  //I created a Truck class because Queue should have "Type" in it
public:						   //I applied "Keep in mind that cargo truck class extends packages class." situations

	string name;			   //I created the required values
	string power;
	Truck() {}
	virtual ~Truck(){}

};

#endif /* TRUCK_H_ */
