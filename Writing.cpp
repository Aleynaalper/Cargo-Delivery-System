#include "Writing.h"

Writing::Writing() {
}
Writing::~Writing() {
}
string text;

void Writing::define(string path3){
	text=path3;

}
void Writing::writefile(string line){

	ofstream outfile;

	outfile.open(text, ios_base::app);		//It crates new text file that name is output.txt
	outfile << line;						//It prints each element it takes as a parameter to text file

	}

