#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<string> splitArgs(int argc, char *argv[]){ 
    vector<string> arguments;
    for(size_t i = 1; i < argc; i++){
        arguments.push_back(argv[i]);
    }
    return arguments;
}

void printVector(size_t t, vector<string> v){
    for(size_t i = 0; i < t; i++){
        cout << v[i] << ", ";
    }
    cout << endl;
}

int printList(string doc){
    ifstream file;
    file.open(doc);
    if(!file.is_open()){
        cerr << "[Error]   Impossible to open \".todo\" file" << endl;
        return 1;
    }
    string line;
    while(getline(file, line)){
        cout << line << endl;
    }
    file.close();
    return 0;
}

size_t countLines(string doc){
    ifstream file;
    file.open(doc);
    
    size_t c = 0;
    string line;
    
    while(getline(file, line)){
        c++;
    }
    
    file.close();
    return c;
}

int overwrite(string doc, vector<string> overwrite_s){
    ofstream file;
    file.open(doc);
    
    if(!file.is_open())
        return 1;
    file << "";
    file.close();

    file.open(doc, ios_base::app);

    if(!file.is_open())
        return 1;

    for(size_t i = 0; i < overwrite_s.size(); i++){
        file << overwrite_s[i] << endl;
    }
    file.close();
    return 0;
}

vector<string> splitFileRow(string doc){
    ifstream file;
    file.open(doc);

    vector<string> s;

    if(!file.is_open())
        return s;
    
    size_t lines = countLines(doc);
    string line;

    while(getline(file, line)){
        s.push_back(line);
    }
    file.close();
    return s;
}

vector<string> setNumber(vector<string> s){
    string x;
    const int ascii = 48 + 1/* +1 beacause it start from 1 and not from 0*/;
    for(size_t i = 0; i < s.size(); i++){
        x = s[i];
        x[0] = (char)i + 49;
        s[i] = x;
        cout << s[i] << endl;
    }
    return s;
}

vector<string> bubbleSort(vector<string> arr){
    string temp;
    size_t llenght = arr.size();
    
    for(size_t i = 0; i < llenght; i++){
        for(size_t j = 0; j < llenght - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}

int addRecord(string doc, string record){
    ofstream file;
    file.open(doc);
    
    string full_record;

    if(!file.is_open()){
        cerr << "[Error]   Impossible to open \".todo\" file" << endl;
        return 1;
    }
    else{
        size_t row = countLines(doc) + 1;
        full_record += row;
        //da continuare qua    
    }
    return 0;
}
    
int main(int argc, char *argv[]) {
    const string file = ".todo";
    const auto arguments = splitArgs(argc, argv);
    const auto n_arguments = arguments.size();
    
    vector<string> s = splitFileRow(file); 
    auto sorted = bubbleSort(s);
    sorted = setNumber(s);
    int e = overwrite(file, sorted);
    
    
    return 0;
}
