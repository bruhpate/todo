#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<string> splitArgs(int argc, char *argv[]){ 
    vector<string> arguments;
    for(int i = 1; i < argc; i++){
        arguments.push_back(argv[i]);
    }
    return arguments;
}

void printVector(size_t t, vector<string> v){
    for(int i = 0; i < t; i++){
        cout << v[i] << ", ";
    }
    cout << endl;
}

int printList(string doc){
    ifstream file(doc);
    if(!file.is_open()){
        cerr << "[Errore]   Impossible to open \".todo\" file" << endl;
        return 1;
    }
    string line;
    while(getline(file, line)){
        cout << line << endl;
    }
    file.close();
    return 0;
}

int main(int argc, char *argv[]) {
  const string file = ".todo";
  const auto arguments = splitArgs(argc, argv);
  const auto n_arguments = arguments.size();
  printList(file);
  return 0;
}
