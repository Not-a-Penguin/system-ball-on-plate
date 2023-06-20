#include <iostream>
#include <stdio.h>

void variadicF(void){
  return;
}

template<typename T, typename P, typename... Args> 
void variadicF(T value, P value2, Args... args){
  
  std::cout << value << "and" << value2 << std::endl;
  return variadicF(args...);  

}

int main(){
  
  // variadicF("banana");
  printf("\n");
  variadicF("angle1", 120, "angle2", 222, "angle3", 333); 

  return 0;
}
