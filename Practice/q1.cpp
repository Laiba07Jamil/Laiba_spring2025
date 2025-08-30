#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream outfile("example.txt");
    if(!outfile.is_open()){
        cerr << "Error" << endl; 
    }
    outfile << "Laiba+2007" << endl;
    outfile << "absar,+1234fg" << endl;
    outfile.close();

    ifstream infile("example.txt");   //Laiba+2007\nabsar,+1234fg\nhassan+2009\n
    if(!infile.is_open()){
        cerr << "Error" << endl; 
    };
    string line;
    while(getline(infile,line)){
        cout << line << endl;
    }
    infile.close();

    streampos begin,end;
    ifstream file("example.txt" , ios :: in);
    if(!file.is_open()){
        cerr << "Error" << endl; 
    }
    file.seekg(16,ios::beg);
    begin = file.tellg();
    cout << begin << endl;
    string l;
    while(getline(file,l)){
        cout << l << endl;
    }
    file.close();

    ifstream me("example.txt",ios::in);
    me.seekg(6 , ios ::beg);
    end = me.tellg();
    cout << "Position: " <<end << endl;
    string li;
    while(getline(me,li)){      //Laiba+2007\nabsar,+1234fg\n
        cout << li ;
    }
}

/*void searchword(string filename , const string& keyword){
ifstream file(filename.c_str());
if(!file || keyword.empty()){
throw "Error file opening or File not opened."}
string line;
bool found = false;
while(getline(file,line)){
if(line.find(keyword) != string ::npos){
cout << line << endl;
found =t rue;}}
file.close();
if(!found){
cout << "Word not found"}


string line;
ifstream infile,templine;
while(getline(infile,line)){
size_t pos = 0 ;
while(pos = line.find(keyword,pos) != string :: npos){
line.replace(pos , keyword.length() , replacement);
pos += replacement.length();
templie << line << endl;
}} 
templine.closE();
infile.close();




}*/