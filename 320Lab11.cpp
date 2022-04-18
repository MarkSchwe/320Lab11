#include <iostream>
#include "d_graph.h"
#include "d_util.h"
#include <list>
using namespace std;


int main(){
graph<char> C;
ifstream file;
file.open("graphB.dat");
file >> C;
file.close();
char input;
cout << "Input character to check: ";
cin >> input;
list<char> E;
int min = minimumPath(C,'A',input,E);
list<char>::iterator iter3 = E.begin();
list<char>::iterator iter2 = iter3;
int large;
char lorg = 'A';
iter3++;
while(iter3 != E.end()){
if(C.getWeight(*iter2,*iter3) > large){
    large = C.getWeight(*iter2,*iter3);
    lorg = *iter3;
}

iter2++;
iter3++;
}
cout << "Vertex with largest minimum-path value = " << lorg << endl;
cout << "Minimum path value: " << min << endl;
list<char>::iterator iter = E.begin();
while(iter != E.end()){
cout << *iter << " ";
iter++;
}
cout << endl;
    return 0;
}
