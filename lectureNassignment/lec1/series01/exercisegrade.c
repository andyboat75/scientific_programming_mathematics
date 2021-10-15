#include <stdio.h>

int main() {
  int solved;
  double percent_marked;

  printf("Total number of marked (solved) exercises: ");
  scanf("%d",&solved);

  percent_marked = (solved/80.0) * 100;

  printf("The percentage of marked exercises is %lf%% \n", percent_marked);

  if (percent_marked >= 50) {
    printf("Hurray, you passed!!!\n");
  }
   else {
     printf("Sorry, that's a fail.\n");
  }
}