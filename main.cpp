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
      char* str="2*3+2+4";

      Tree test;
      test.load(str);
      test.print();
}

int main(int argc, char const *argv[]) {
    menu();

    cout << "\nPress enter to continue ..."; 
    cin.get(); 
    return EXIT_SUCCESS;
}


