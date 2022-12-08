#include <iostream>
#include <fstream>
#include <string>
#define numOfNode 26

using namespace std;

class layer {
public:
    layer* vertex[numOfNode];
    string* value[numOfNode];
    layer() {
        for (int i = 0; i < numOfNode; i++) {
            this->vertex[i] = nullptr;
            this->value[i] = nullptr;
        }
    }
};

string* search(string word, layer* head) {
    layer* layPar = head;
    string* result = nullptr;
    int i, index, lengthOfWord = word.length();
    for (i = 0; i < lengthOfWord; i++) {
        index = int(tolower(word[i])) - 97;
        if (layPar->vertex[index] == nullptr) {
            break;
        }
        if (i == lengthOfWord - 1) {
            result = layPar->value[index];
            break;
        }
        layPar = layPar->vertex[index];
    }
    return result;
}

int main()
{
    int i, opt, index, numOfWords = 0, lengthOfWord;
    string dicFilePath = "dic.txt", word, * result, value = "Present";
    layer* head = new layer();

    ifstream file(dicFilePath);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            word = line.c_str();
            layer* layPar = head;
            lengthOfWord = word.length();
            for (i = 0; i < lengthOfWord; i++) {
                index = int(tolower(word[i])) - 97;
                if (layPar->vertex[index] == nullptr) {
                    layPar->vertex[index] = new layer();
                }
                if (i == lengthOfWord - 1) {
                    layPar->value[index] = &value;
                    break;
                }
                layPar = layPar->vertex[index];
            }
            numOfWords++;
        }
        file.close();
    }
    else {
        cout << "Error: File could not be read" << endl;
        exit(0);

    }

    string* arr = new string[numOfWords];
    ifstream fileNew(dicFilePath);
    if (fileNew.is_open()) {
        string line;
        for (i = 0; i < numOfWords; i++) {
            getline(fileNew, line);
            arr[i] = line.c_str();
        }
        fileNew.close();
    }

    while (true) {
        cout << "\nChoose:\n1 Search\n2 Exit\n> ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "\nEnter word: ";
            cin >> word;
            result = search(word, head);
            if (result == nullptr) {
                cout << word + ": Not Present" << endl;
            }
            else {
                cout << word + ": " + *result << endl;
            }
            break;
        case 2:
            exit(0);
        default: 
            cout << "Invalid Option: " + opt;
            exit(0);
        }
    }
    return 0;
}
