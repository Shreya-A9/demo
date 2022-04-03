#include <stdio.h>
int main()
{
FILE *p;
char ch;
p=fopen("BCA.txt","r");
while ((ch = getc(p)) != EOF)
{
    printf("%c",ch);
}
fclose(p);
// getch();
}
