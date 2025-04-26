/*Q5. You're building a tool to search and replace a specific word in a text file without
rewriting the entire file.
Requirements:

1. Create and populate a file named data.txt with a few sentences. (e.g., AI is the
future. AI will transform the world. Embrace AI now.)
2. Prompt the user to enter:
○ A searchWord (e.g., "AI")
○ A replacementWord (e.g., "ML")
3. Open the file using fstream in ios::in | ios::out mode.
4. Search for the searchWord using seekg() and read sequentially.
5. When found:
○ Use tellg() to get the current read pointer location.
○ Use seekp() to position the write pointer.
○ Replace the word only if the replacement is of equal or smaller length to
avoid shifting content.

6. If the word is replaced, pad with spaces if needed (e.g., replacing "AI" with "ML" or
"XX").
7. After all replacements, display the updated file.*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream file1;
    file1.open("data.txt" , ios :: out);
    if(!file1){
        cout << "Error in opening file." << endl;
        return 1;
    }

    file1 << "AI is the future. AI will transform the world. Embrace AI now."<< endl;
    file1.close();

    fstream file2("data.txt" ,ios::out | ios::in);
    if(!file2){
        cout << "Error in opening file." << endl;
        return 1;
    }

    string searchword;
    string replaceword;
    cout << "Enter the word for search: ";
    cin >> searchword;
    cout << "Enter the word to replace: ";
    cin >> replaceword;
    
    if(searchword.length() != replaceword.length()){
        cout << "Word lengths are not same." <<endl;
        return 0;
    }
    

    fstream file("data.txt" , ios::out | ios::in);
    if(!file){
        cout << "Error in opening file." << endl;
        return 1;
    }

    string word ;
    char ch;
    streampos pos;

     while (true)
    {
        pos = file.tellg();
        word = "";

        for (int i = 0; i < searchword.length(); i++)
        {
            file.get(ch);
            if (file.eof())
                break;
            word += ch;
        }

        if (file.eof())
            break;

        if (word == searchword)
        {
            file.seekp(pos);
            file << replaceword;

            for (size_t i = replaceword.length(); i < searchword.length(); i++)
            {
                file.put(' ');
            }

            file.seekg(pos + (streamoff)searchword.length());
        }
        else
        {
            file.seekg(pos + (streamoff)1);
        }
    }
    file.close();

    ifstream open("data.txt" , ios::out);
    if(!open){
        cout << "Error in opening file." << endl;
        return 1;
    }

    string line;
    while (getline(open , line))
    {
        cout << line << endl;
    }
    
    file.close();
    return 0;
    

}