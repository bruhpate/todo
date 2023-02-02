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

//int swapLines(string doc, size_t line1, size_t line2){
//    ofstream file;
//    file.open(doc);
//
//    if(!file.is_open()){
//        return 1;
//    }
//
//    string recompile = "", line;
//    size_t counter=0;
//
//    while(getline(file, line)){
//        if(counter==line1){
//             
//        }
//        else{
//            recompile += line; 
//        }
//    }    

int sortFile(string doc){
    ifstream file;
    file.open(doc);

    if(!file.is_open()){
        cerr << "[Error]   Impossible to open \".todo\" file" << endl;
        return 1;
    }

    string recompile, line, last_line = "";
    size_t counter = 0, line_number, last_line_number;
    const size_t ascii = 48;

    while(getline(file, line)){
        line_number = (size_t)line[0] - ascii;
        
        //prima deve controllare se vanno in ordine i numeri del record, poi che non ne salti nessuno 
        
        if(counter > 0){
            if(last_line_number >= last_number){
                //funzione inverti linee    
            }
            else{
                
            }
            last_line = line;
            last_line_number = last_number;
        }

                
    }
    file.close();
    return 0;
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
    //cout << "";
    int e = sortFile(file);
    return 0;
}
