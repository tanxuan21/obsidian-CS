#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {

  system("clang++ rand_input.cpp -o rand_input");
  system("clang++ check_input.cpp -o check_input");
  system("clang++ solution_1.cpp -o solution_1");
  system("clang++ solution_2.cpp -o solution_2");
  system("clang++ solution_3.cpp -o solution_3");

  system("./rand_input 100 100 100 > rand.in");

  system("./solution_1 < rand.in > 1.out");
  system("./solution_2 < rand.in > 2.out");
  system("./solution_3 < rand.in > 3.out");

  return 0;
}