#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main() {
  char password[100];
  int randNum;
  int sum = 0;
  int index = 0;
  int diff1;
  int diff2;

  srand(time(0));
  while(sum < 2772){
    password[index] = 33 + rand() % 94;
    sum += password[index++];
  }
  password[index] = '\0';

  if (sum != 2772) {
     diff1 = (sum - 2772) / 2;
     diff2 = (sum - 2772) / 2;
     if ((sum - 2772) % 2 != 0)
       diff1++;
     for (index= 0; password[index]; index++){
        if(password[index] >= (33 + diff1)){
           password[index] -= diff1;
           sum -= diff1;
           break;
        }
     }
     for (index= 0; password[index]; index++){
        if(password[index] >= (33 + diff2)){
           password[index] -= diff2;
           sum -= diff2;
           break;
        }
     }
  }
  printf("%s\n", password);
}
