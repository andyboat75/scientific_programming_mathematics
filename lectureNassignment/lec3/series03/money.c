#include <stdio.h>

// Global variables
int n;
int notes_coins_[8] = {500, 100, 50, 20, 10, 5, 2, 1};

// void money(int n) {
//     for (int i = 0; i <8; i++) {
//         printf("amount entered = %d\n",n);
//         if (n!=0 && n%notes_coins_[i]>=0){
//             printf("i = %d\n", i);
//             printf("note = %d\n", notes_coins_[i]);
//             printf("remainder = %d\n", n%notes_coins_[i]);
//             printf("%d x %d EUR \n", n/notes_coins_[i], notes_coins_[i]);
//             n = (n%notes_coins_[i]) * notes_coins_[i];
//         }
//         else if (n == 0){
//             break;
//         }
//     }
// }

void money2() {
    for (int i=0; i<8; i++) {
        int note = notes_coins_[i];
        int remainder = n%note;
        // printf("Amount remaining %d\n",n);
        // printf("Note %d\n",note);
        // printf("Remainder %d\n",remainder);
        if (remainder == 0) {
            printf("%d x %d EUR \n\n", n/note, note);
            break;
        }
        else {
            if(n > note){
            printf("%d x %d EUR \n\n", n/note, note);
            n = remainder;
            }
            // else {
            //     printf("\n");
            // }
        }
    }
}



void main() {
    printf("Enter the amount of money: ");
    scanf("%d",&n);
    money2(n);
}