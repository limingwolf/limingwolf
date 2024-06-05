#include "MyLibrary.h"
#include <iostream>

int main()
{
  std::cout << "Hello, World!" << std::endl;
  MyLibraryFunction();
  std::cout << "按任意键退出" << std::endl;
  getchar();
  return 0;
}
