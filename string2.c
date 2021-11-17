Here's an example of how you can do it efficiently, if you are allowed to write into the long string:

#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv)
{
   char longString[] = "This is a long string.\nIt has multiple lines of text in it.\nWe want to examine each of these lines separately.\nSo we will do that.";
   char * curLine = longString;
   while(curLine)
   {
      char * nextLine = strchr(curLine, '\n');
      if (nextLine) *nextLine = '\0';  // temporarily terminate the current line
      printf("curLine=[%s]\n", curLine);
      if (nextLine) *nextLine = '\n';  // then restore newline-char, just to be tidy
      curLine = nextLine ? (nextLine+1) : NULL;
   }
   return 0;
}
If you're not allowed to write into the long string, then you'll need to make a temporary string for each line instead, in order to have the per-line string NUL terminated. Something like this:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv)
{
   const char longString[] = "This is a long string.\nIt has multiple lines of text in it.\nWe want to examine each of these lines separately.\nSo we will do that.";
   const char * curLine = longString;
   while(curLine)
   {
      const char * nextLine = strchr(curLine, '\n');
      int curLineLen = nextLine ? (nextLine-curLine) : strlen(curLine);
      char * tempStr = (char *) malloc(curLineLen+1);
      if (tempStr)
      {
         memcpy(tempStr, curLine, curLineLen);
         tempStr[curLineLen] = '\0';  // NUL-terminate!
         printf("tempStr=[%s]\n", tempStr);
         free(tempStr);
      }
      else printf("malloc() failed!?\n");

      curLine = nextLine ? (nextLine+1) : NULL;
   }
   return 0;
}
