#include "ReadFromFile.h"
#include "Stack.h"
#include "Queue.h"
#include "Truck.h"
#include "Package.h"
#include "Station.h"


ReadFromFile::ReadFromFile() {
}
ReadFromFile::~ReadFromFile() {
}


struct Object{     //For every city, I created Stack and Queue object.
	string city;
	Stack<Package> obj;
	Queue<Truck> obj2;
};

Object storingarray[81];   //It could be at most 81 city

void ReadFromFile::creating_object(string path){
   int index=0;
   for(int i=0;i<81;i++){
	   storingarray[i].city="";   //Firstly I have defined all elements as "" since there can be empty arrays
   }

   ifstream file(path);
    if(!file){
        cerr <<"File couldn't find" << endl;
        exit(1);
    }
    while(file){
        string name;

        getline(file,name);


        Object object;
		object.city=name;  //I stored every city and its objects(stack and queue) to storing array
		storingarray[index]=object;
		index++;
   }

}
void ReadFromFile::truck(string path){ //For reading Truck.txt
	ifstream file(path);
		if(!file){
			cerr <<"File couldn't find" << endl;
			exit(1);
		}
		while(file){

			string controlarray[3];
			string name;

			getline(file,name);

			int l=name.length();

			char commandarray[l + 1];   //to using strtok , I converted string to char array
			char split[]=" ";
			strcpy(commandarray, name.c_str());
			char *token=strtok(commandarray,split);

			int i=0;
			while(token){
				controlarray[i]=token;      //to find which command, I define every element into the array after separating it with spaces
				token = strtok(NULL,split);
				i++;
			}
			Truck truck;
			truck.name=controlarray[0];
			truck.power=controlarray[2];
			for(int i=0;i<81;i++){
				if(storingarray[i].city==controlarray[1]){
					storingarray[i].obj2.enqueue(truck);
					break;
				}
			}
		}
		for(int i=0;i<81;i++){
			if(storingarray[i].city!=""){
				if(!(storingarray[i].obj2.isEmpty())){
					Truck a;
					storingarray[i].obj2.getFront(a);
				}
			}
		}
	}
void ReadFromFile::package(string path, string path2, string path3){  //For reading Package.txt
	 ifstream file(path);
	    if(!file){
	        cerr <<"File couldn't find" << endl;
	        exit(1);
	    }
	    while(file){
	        string controlarray[2];
	        string name;

	        getline(file,name);

	        int l=name.length();

	        char commandarray[l + 1];   //to using strtok , I converted string to char array
	        char split[]=" ";
	        strcpy(commandarray, name.c_str());
	        char *token=strtok(commandarray,split);

	        int i=0;
	        while(token){
	            controlarray[i]=token;      //to find which command, I define every element into the array after separating it with spaces
	            token = strtok(NULL,split);
	            i++;
	        }
	        Package package;
			package.name=controlarray[0];
			for(int i=0;i<81;i++){
				if(storingarray[i].city==controlarray[1]){
					storingarray[i].obj.push(package);
					break;
				}
			}
	    }

	    Station station;
	    station.array_beginning();
	    for(int i=0;i<81;i++) {
	        if(storingarray[i].city!="") {
	            station.array_filling(storingarray[i].city,storingarray[i].obj,storingarray[i].obj2);
	        }
	    }
	   station.readingMissions(path2);
	   station.sending(path3);
    }



