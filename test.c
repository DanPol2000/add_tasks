#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int check(char s, char *s1)
{
    int i;
    
    i = 0;
    while (s1[i])
    {
        if (s1[i] == s)
            return (0);
        i++;
    }
    return (1);
}

void    ft_union(char *s1, char *s2)
{
    int i;
    int j;
    char *s;
    
    i = 0;
    j = 0;
    s = malloc(1000);
    while (s1[i])
    {
        if (check(s1[i], s))
        {
            s[j] = s1[i];
            write(1, &s[j], 1);
            write(1, "\n", 1);
            j++;
        }
        i++;
        printf("S = %s\n", s);
    }
    i = 0;
    while (s2[i])
    {
        if (check(s2[i], s))
        {
            s[j] = s2[i];
            write(1, &s[j], 1);
            write(1, "\n", 1);
            j++;
        }
        i++;
        printf("S2 = %s\n", s);
    }
}



int main()
{
    ft_union("zpadinton", "paqefwtdjetyiytjneytjoeyjnejeyj");
    write(1, "\n", 1);
    return 0;
}

#include <unistd.h>

int check(char s, char *s1)
{
    int i;
    
    i = 0;
    while (s1[i])
    {
        if (s1[i] == s)
            return (1);
        i++;
    }
    return (0);
}

int last(char s, int i, char *s1)
{
    i = i - 1;
    while (i >= 0)
    {
        if (s == s1[i])
            return (0);
        i--;
    }
    return (1);
}

void    ft_inter(char *s1, char *s2)
{
    int i;
    
    i = 0;
    while (s1[i])
    {
        if (check(s1[i], s2) && last(s1[i], i, s1))
        {
            write(1, &s1[i], 1);
        }
        i++;
    }
}



int main()
{
    ft_inter("ddf6vewg64f", gtwthgdwthdwfteewhrtag6h4ffdhsd");
    write(1, "\n", 1);
    return 0;
}