#include <cstdlib>
#include <iostream>

#include "./.config/custom_config.h"
using namespace std;

int main() {
  system("clang++ ./" makeData "/" defaultFileName ".cpp -o ./" build
         "/" makeData);
  system("clang++ ./" code0 "/" defaultFileName ".cpp -o ./" build "/" code0);
  system("clang++ ./" code1 "/" defaultFileName ".cpp -o ./" build "/" code1);
  char tag;
  int count = 1;
  for (int count = 0;; count++) {
    cout << ">>>  ";
    cin >> tag;
    if (tag == '0') {
      cout << "exit" << endl;
      return 0;
    }
    system("./" build "/" makeData " > " input);
    system("./" build "/" code0 " < " input " > " code_outPut);
    system("./" build "/" code1 " < " input " > " code1_outPut);
    if (system("diff " code_outPut " " code1_outPut) != 0) {
      cout << "different! " << count << " -----" << endl;
    } else {
      cout << "done! " << count << " check outPutData" << endl;
    }
  }

  return 0;
}