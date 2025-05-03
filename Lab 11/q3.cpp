#include <iostream>
#include <exception>
using namespace std;

class FileException{
     private:
    const char* msg;
    public:
    FileException(){
        this->msg = "File Error occured." ;
    }

    const char* what() const noexcept{
        return msg;
    }
};
class FilenotFoundException : public FileException {
     private:
    const char* msg;
    public:
    FilenotFoundException(){
        this->msg = "File not found" ;
    }

    const char* what() const noexcept{
        return msg;
    }
};
class PermissionDeniedException : public FileException{
    private:
    const char* msg;
    public:
    PermissionDeniedException(){
        this->msg = "Access denied" ;
    }

    const char* what() const noexcept{
        return msg;
    }
};

void readFile(const string &filename){
    if(filename == "data.txt"){
        throw FilenotFoundException();
    }
    else if(filename == "secret.txt"){
        throw PermissionDeniedException();
    }
    else{
        throw FileException();
    }
}

int main(){
    string file;
    cout << "Enter filename in (name.txt) form: ";
    cin >> file;
    try{
        readFile(file);
    }
    catch(const FilenotFoundException &e){
        cout << "File not Found Exception - " << e.what() << endl;
    }
    catch(const PermissionDeniedException &e){
        cout << "Permission Denied Exception - " << e.what() << endl;
    }
    catch(const FileException &e){
        cout << "File Exception - " << e.what() << endl;
    }
}