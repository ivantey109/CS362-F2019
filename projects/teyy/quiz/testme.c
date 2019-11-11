#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
char inputChar()
{
   char randomChar; 
   randomChar = (char)rand()%128; //generate random character with all the ascii character
   return randomChar;
}

char *inputString()
{

   int i;
   char randomStr[5] = "\0"; //we always make the array to null
   char inputArr[13] = "[({axreset})]"; //we need a temporary string for generate random number

   for(i=0; i< 5; i++)
   {
      randomStr[i] = inputArr[rand()%13]; //loop 5 times and random with the inputarr
   }

   return randomStr;
}
void testme()
{
   int tcCount = 0;
   char *s;
   char c;
   int state = 0;
   while (1)
   {
       tcCount++;
       c = inputChar();
       s = inputString();
       printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);
       if (c == '[' && state == 0) state = 1;
       if (c == '(' && state == 1) state = 2;
       if (c == '{' && state == 2) state = 3;
       if (c == ' '&& state == 3) state = 4;
       if (c == 'a' && state == 4) state = 5;
       if (c == 'x' && state == 5) state = 6;
       if (c == '}' && state == 6) state = 7;
       if (c == ')' && state == 7) state = 8;
       if (c == ']' && state == 8) state = 9;
       if (s[0] == 'r' && s[1] == 'e' && s[2] == 's' && s[3] == 'e' && s[4] == 't' && s[5] == '\0' && state == 9)
       {
           printf("error \n");
           exit(200);
       }
   }
}

int main(int argc, char *argv[])
{
   srand(time(NULL));
   testme();
   return 0;
}