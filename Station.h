
#ifndef STATION_H
#define STATION_H
#include "iostream"
#include "Stack.h"
#include "Queue.h"
#include "Writing.h"

using namespace std;

class Station {     //I created this class, to make transportation
public:
    struct Object2 {
        string city;
        Stack<Package> obj;
        Queue<Truck> obj2;
    };

    struct transportation { //As you said,I created Doubly Linked List
        Package name;
        transportation *next;
        transportation *prev;

    };
    transportation *head = NULL;

    Object2 array[81];   ////It could be at most 81 city

    void array_beginning() {     //I have defined all elements as "" since there can be empty arrays
        for (int i = 81; i < 81; i++) {
            array[i].city = "";
        }
    }

    void array_filling(string city_name, Stack<Package> obj, Queue<Truck> obj2) {
        for (int i = 0; i < 81; i++) {
            if (array[i].city == "") {
                array[i].city = city_name;
                array[i].obj = obj;
                array[i].obj2 = obj2;
                return;
            }
        }
    }

    void sending(string path3) {   //I created this method to find and send elements in every stack and queue, after thransportation

    		Writing writing;
    		writing.define(path3);

            for(int i = 0 ; i<81 ; i++) {
                if(array[i].city!="") {
                writing.writefile(array[i].city+"\nPackages:\n");
                while (!(array[i].obj.isEmpty())) {
                    Package packages;
                    array[i].obj.getTop(packages);
                    array[i].obj.pop();
                    writing.writefile(packages.name+"\n");
                }
                writing.writefile("Trucks:\n");
                while (!(array[i].obj2.isEmpty())) {
                    Truck truck;
                    array[i].obj2.getFront(truck);
                    array[i].obj2.dequeue();
                    writing.writefile(truck.name+"\n");
                }
                writing.writefile("-------------\n");
            }
        }
        }


    void readingMissions(string path) {
        string controlarray[6];
        ifstream file(path);
        if (!file) {
            cerr << "File couldn't find" << endl;
            exit(1);
        }
        while (file.good()) {

            string name;

            getline(file, name);

            int l = name.length();

            char commandarray[l + 1];   //to using strtok , I converted string to char array
            char split[] = "-";
            strcpy(commandarray, name.c_str());
            char *token = strtok(commandarray, split);

            int i = 0;
            while (token) {
                controlarray[i] = token;      //to find which command, I define every element into the array after separating it with spaces
                token = strtok(NULL, split);
                i++;
            }
            Transportation(controlarray);
        }
    }

    void Transportation(string controlarray[]) {
        int number1;
        int number2;
        number1 = stoi(controlarray[3]);   //Number1 is used as number of getting package from starting city
        number2 = stoi(controlarray[4]);   //Number2 is used as number of getting package from middle city
        Package firstpackages[number1+number2];  //I created this array to finding element with indices



        for (int i = 0; i < 81; i++) {
            if (array[i].city != "") {
                if (controlarray[0] == array[i].city) {
                    Truck a;              //adding starting city's truck
                    array[i].obj2.getFront(a);
                    array[i].obj2.dequeue();
                    Package package;
                    package.name=a.name;
                    addinglinkedlist(package);

                    for (int j = 0; j < number1; j++) {
                          Package b;			   // //adding starting city's packages
                          array[i].obj.getTop(b);
                          firstpackages[j]=b;
                          array[i].obj.pop();
                          addinglinkedlist(b);
                    }
                }
            }
        }
        for(int i=0;i<81;i++) {
            if(array[i].city!="") {
                if(controlarray[1]==array[i].city) {
                    int number3 = stoi(controlarray[4]);  //Number3 is used as number of getting package from middle city
                    for(int j = number1 ; j<number1+number2; j++) {
                        Package b;			   // //adding starting city's packages
                        array[i].obj.getTop(b);
                        firstpackages[j]=b;
                    }
                        for (; number3 > 0; number3--) {
                            Package b;			   // //adding middle city's packages
                            array[i].obj.getTop(b);
                            array[i].obj.pop();
                           addinglinkedlist(b);
                    }

                }
            }
        }
        int number4=(controlarray[5].length()+1)/2;  //Number4 is used as indices of storing packages
        string indices[number4];
        int l=controlarray[5].length();

        char commandarray[l + 1];   //to using strtok, I converted string to char array
        char split[]=",";
        strcpy(commandarray, controlarray[5].c_str());
        char *token=strtok(commandarray,split);

        int i=0;
        while(token){
            indices[i]=token;
            token = strtok(NULL,split);
            i++;
        }
        for(int j = 0 ; j<number4 ; j++) {

            int number=stoi(indices[j]);
            Package a;
            a=firstpackages[number];
            for(int i=0;i<81;i++){
                if(array[i].city==controlarray[1]){

                    array[i].obj.push(a);    //In this line, it adds required elements to middle station
                    break;
                }
            }
            deletinglinkedlist(a);
        }
        for(int i = 0 ; i<81 ; i++) {   //At the end, it adds the remaining elements and truck to last station
            if(array[i].city!="") {
                if(array[i].city==controlarray[2]) {
                    Truck truck;
                    truck.name= head->name.name;
                    array[i].obj2.enqueue(truck);
                    transportation *temp=head;
                    head=head->next;
                    if(head->next!=NULL) {
                        head->next->prev = NULL;
                        free(temp);
                        break;
                    }
                    free(temp);
                    while(head!=NULL) {
                        transportation *temp = head;

                        array[i].obj.push(temp->name);

                        if(head->next!=NULL) {
                            head->next->prev=NULL;
                            head=head->next;
                            free(temp);
                        }
                        else {
                            head=NULL;
                            free(temp);
                        }
                    }
                }
            }
        }
    }
    void addinglinkedlist(Package a){   //Insert method of Doubly Linked List
        transportation* newitem=new transportation();
        newitem->name=a;

        if(head==NULL){
            head=newitem;
            newitem->next=NULL;
            newitem->prev=NULL;
        }
        else{
            transportation* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newitem;
            newitem->next=NULL;
            newitem->prev=temp;
        }
    }
    void deletinglinkedlist(Package a){   //Deletion method of Doubly Linked List
        transportation* temp=head;
        while(temp!=NULL){
            if(temp->name.name==a.name){
                if(temp->next==NULL){
                    temp->prev->next=NULL;
                    free(temp);
                    return;
                }
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                free(temp);
                return;
            }
            temp=temp->next;
        }
    }
};
#endif //STATION_H
