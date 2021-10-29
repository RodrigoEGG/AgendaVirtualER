// basic file operations
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ofstream myfile;
  myfile.open ("lessgo.txt");
  myfile << "https://www.youtube.com/watch?v=oWqAf4eex14 \n";
  myfile.close();
  return 0;
}