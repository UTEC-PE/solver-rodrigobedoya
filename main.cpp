#include <iostream>
#include <stdlib.h>
#include "node.h"
#include "tree.h"

#define EXIT_SUCCESS 0
using namespace std;

void menu() {
      system("clear");
      cout<<"==========================================================="<<endl;
      cout<<"\t\tPractica Operaciones"<<endl;
      cout<<"==========================================================="<<endl;

      //char* str="7/4*((a+b)*a)+3";
      //char* str="7/4*((a+-+--b)*a)+3";
      //char* str="2+(3)";
      //char* str="7/4*((a+b)^4*a)+3";
      char* str="a-++-+3*(2+--4)^2";

      Tree test;
      test.load(str);
      test.defineVariable('a',3);
      test.print();
}

// No maneja bien operadores unarios ni paréntesis, e.g. ((5+4))

// Probar con:
// (17*3/2-a)^b    a=5, b=1  Resultado esperado 20.5
// -(5-4)                    Resultado esperado -1
int main(int argc, char const *argv[]) {
    if (argc == 2) {
        Tree test;
        test.load((char*)argv[1]);
        test.defineVariable('a',3);
        test.defineVariable('b',1);
        test.print();
    }
    else {
      throw "One argument expected";
    }


    //menu();

    cout << "\nPress enter to continue ..."; 
    cin.get(); 
    return EXIT_SUCCESS;
}


