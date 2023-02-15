#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<string> splitArgs(int argc, char *argv[]){ 
    vector<string> arguments;
    for(size_t i = 1; i < argc; i++){
        arguments.push_back(argv[i]);
    }
    return arguments;
}

void printVector(vector<string> v){
    for(size_t i = 0; i < v.size(); i++){
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

vector<string> separeLine(string s, string sep){
    vector<string> splitted;
    size_t not_found = string::npos;
    size_t pos = s.find(sep);
    
    if(pos == not_found)
        return splitted;
    
    splitted.push_back(s.substr(0,pos)); 
    s.erase(0, pos + 1);
    splitted.push_back(s);
    return splitted;    
}

vector<string> setNumber(vector<string> s){
    const string sep = " ";
    const char ascii = 48 + 1;  /* 48 char = 0, 49 char = 1*/
      // cout << s.size(); 
    for(size_t i = 0; i < s.size(); i++){
        
        string to_split = s[i];

        vector<string> temp_records = separeLine(to_split, sep);
        
        size_t n = stol(temp_records[0]);
        n = i + 1;

        string record = temp_records[1];

        s[i] = to_string(n) + " " + record;
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
    file.open(doc, ios_base::app);
    
    if(!file.is_open()){
        cerr << "[Error]   Impossible to open \".todo\" file" << endl;
        return 1;
    }
    
    string full_record;
    vector<string> s = splitFileRow(doc);
    record = ' ' + record;
    full_record += to_string(countLines(doc) + 1) + record;
    s.push_back(full_record);
    s = bubbleSort(s);
    s = setNumber(s);
    return overwrite(doc, s);
}

int remove(string doc, string to_delete){
    ifstream file;
    file.open(doc);

    if(!file.is_open()){
        cerr << "[Error]   Impossible to open \".todo\" file" << endl;
        return 1;
    }
    
    int llenght = to_delete

    string line;
    while(getline(file, line){
        if(line
    }
}

int main(int argc, char *argv[]) {
    const string file = ".todo";
    const vector<string> arguments = splitArgs(argc, argv);
    const size_t n_arguments = arguments.size();
    
    switch(n_arguments){
        case 0:
            printList(file);
            break;

        case 2:
            if(arguments[0] == "--add" || arguments[0] == "-a"){
                int result = addRecord(file, arguments[1]);
                if(result != 0){
                    cerr << "[Error]    Impossible write to file" << endl;
                    return 1;
                } 
            }
            else if (arguments[0] == "--remove" || arguments[0] == "-r"){
                
            }
             //funzione per cancellare una riga o più righe, es ./todo - 1,4 (cancella la riga 1 e 4) 1-4 (cancella dalla riga 1 alla riga 4)
            break;

        default:
            cout << "todo [option] [record]" << endl;
            cout << "Example: todo -add \"buy eggs\"" << endl;
            break;         
    }    
    return 0;
}
