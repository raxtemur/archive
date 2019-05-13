#include <stdio.h>
#include <string.h>

int strdel(char **str, char *itL, char *itR);


int strdel(char **str, char *itL, char *itR)
{
    char res[strlen(*str)];
    strcpy(res,"");
    strncat(res, *str, itL-*str);
    strcat(res, itR);
    strcpy(*str, res);
    return 1;
}

int main(int argc, char* argv[])
{
    char *br1, *br2, *str;
    char *str_new;
    char *itL, *buf, *it1, *it2;
    int flag = 0;
    if (argc != 4) printf("Error: Not correct arguments");
    br1 = argv[1];
    br2 = argv[2];
    str = argv[3];
    itL = strstr(str, br1);
    while(itL != NULL)
    {
        buf = itL + strlen(br1);
        flag = 1;
        while ((flag != 0) && (buf != str + strlen(str)))
        {
            it1 = strstr(buf, br1);
            it2 = strstr(buf, br2);
            if (it2 == NULL)
            {
                flag = 0;
                break;
            }
            if (it1 == NULL)
            {
                buf = it2 + strlen(br2);
                flag--;
            }
            else if (it1 < it2)
            {
                buf = it1 + strlen(br1);
                flag++;
            }
            else
            {
                buf = it2 + strlen(br2);
                flag--;
            }
        }
        if(flag == 0)
        {
            strdel(&str, itL + strlen(br1), buf - strlen(br2));
        }
        itL = strstr(itL + strlen(br1), br1);
    }
    printf("%s", str);
}
