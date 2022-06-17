#include <unistd.h>
void ft_swap(char *s1, char *s2);
void printchar (char c);

int main (int ac, char **av)
{
    if (ac > 1)
    {
        int i = 1;
        int j = 0;
        while (av[i + 1] != '\0')
        {
            while (av[i][j] != '\0' && av[i + 1][j] != '\0')
            {
                if (av[i][j] > av[i + 1][j])
                {
                    ft_swap(av[i], av[i + 1]);
                    i++;
                    j = 0;
                }
                else
                    j++;
            }
            if (av[i][j] != '\0' && av[i + 1][j] == '\0')
                ft_swap(av[i], av[i + 1]);
            i++;
        }
        j = 0;
        i = 1;
        while (av[i] != '\0')
        {
            while (av[i][j] != '\0')
            {
                printchar (av[i][j]);
                j++;
            }
            i++;
            j = 0;
            write (1, "\n", 1);
        }
        return 0;
    }
    else
        write(1, "\n", 1);
    return 0;
}

void ft_swap(char *s1, char *s2)
{
    char temp = 0;
    char temp2 = 0;

    temp = *s1;
    temp2 = *s2;
    *s1 = temp2;
    *s2 = temp;
}

void printchar (char c)
{
    write(1, &c, 1);
}
