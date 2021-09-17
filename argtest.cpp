#include <iostream>
#include <cstdlib>

int main(int argc, char*argv[]){
  int i;
  for(i = 1; i < 10; i++){
    std::cout << argv[1] << " likes " << argv[2] << std::endl;
  }
  std::cout << "End of Program" << std::endl;
  return 0;
}