#include<stdio.h>
#include<stdlib.h>
int main(int argc ,char *argv[])
{
    FILE *f1,*f2,*f3;
    char ch;

    f1=fopen(argv[1],"r");
    printf("%s\n",argv[1]);
    f2=fopen(argv[2],"r");
    printf("%s\n",argv[2]);
    f3=fopen(argv[3],"w");
    printf("%s\n",argv[3]);

    while((ch=fgetc(f1))!=EOF)
    {

        fputc(ch,f3);

    }
    while((ch=fgetc(f2))!=EOF)
          fputc(ch,f3);

    printf("SUCCESS");
    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}
