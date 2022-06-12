#include <stdio.h>

int main() {

  int i = 1;
  do {
    printf("\n%d", i);
    i++;
  }
  while (i <= 10);

  /*
  for (statement 1; statement 2; statement 3) {
     code to be executed
  }
  Statement 1 is executed (one time) before the execution of the code block.
  Statement 2 defines the condition for executing the code block.
  Statement 3 is executed (every time) after the code block has been executed.*/

  for (i = 1 ; i <= 10; i++){
    printf("\n%d",i);
  }

  int y;

  for (i = 1; i <= 10; i++){
     y = i%2;
    (y!=0)? printf("\nodd"):printf("\neven");
  }

  return 0;
}
