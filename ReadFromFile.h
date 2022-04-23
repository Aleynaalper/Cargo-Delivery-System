#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

#ifndef READFROMFILE_H_
#define READFROMFILE_H_

using namespace std;

class ReadFromFile {
public:
    ReadFromFile();
    virtual ~ReadFromFile();
    void creating_object(string path);
    void package(string path, string path2,string path3);
    void truck(string path);
};

#endif /* READFROMFILE_H_ */
