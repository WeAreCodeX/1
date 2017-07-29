#include <stdio.h>
#include <string.h>
#include <conio.h>

void game();
int check_subsequence (char [], char[]);
char s1[1000]="apple", s2[1000];
int lives=5,tries;

void main()
{
	for(tries=0;)
	{
		game();
	}
}

void game() {
   int flag;
   clrscr();

   //printf("Input first string\n");
   //gets(s1);

   printf("Enter guess: ");
   gets(s2);

   /** Passing smaller length string first */

   if (strlen(s1) < strlen(s2))
      flag = check_subsequence(s1, s2);
   else
      flag = check_subsequence(s2, s1);

   (flag)?printf("%s",s2):printf("-");

   getch();
}

int check_subsequence (char a[], char b[]) {
   int c, d;

   c = d = 0;

   while (a[c] != '\0') {
      while ((a[c] != b[d]) && b[d] != '\0') {
      printf("-");
	 d++;
      }
      if (b[d] == '\0'){
      printf("-");
	 break;
      }
      d++;
      c++;
   }
   if (a[c] == '\0')
      return 1;
   else
      return 0;
}

/*
The logic of function is simple we keep on comparing characters of two strings,
if mismatch occur then we move to next character of second string and if characters
match indexes of both strings is increased by one and so on. If the first string ends
then it is a subsequence otherwise not.
*/