// void	ft_putstr(char *str);

// int main()
// {
//     ft_putstr("hello");
//     return (0);
// }

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

// char	*ft_strcpy(char *dest, char *src)
// {
// 	int	i;

// 	i = 0;
// 	while (src[i] != '\0')
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

// int is_sep(char c,char *charset)
// {
//     int i =0;
//     while(charset[i])
//     {
//         if(c == charset[i])
//             return (1);
//         i++;
//     }
//     return (0);
// }

// int count_words(char *str ,char *charset)
// {
//     int i;
//     int count=0;
//     i=0;
//     while (str[i])
//     { 
//         if (!is_sep(str[i], charset) && (i==0 || is_sep(str[i-1], charset)))
//             count++;
//         i++;
//     }
//     return (count);
// }

// char *copy(char *start, char *end)
// {
//     char *copy;
//     int i=0;
//     copy = (char *)malloc(end -start + 1);
//     while(start < end)
//     {
//         copy[i] = *start;
//         start++;
//         i++;
//     }
//     copy[i]='\0'; 
//     return (copy);
// }
// char **split(char *str , char *charset ){
//     char *start ; 
//     char **result ; 
//     int i =0 ; 
//     int count= count_words(str,charset); 
//     result =(char **)malloc(sizeof(char *)* (count +1 )); 
//     while(*str){
//         while(is_sep(*str,charset) && *str)
//             str++; 
//         start = str ; 
//         while(!is_sep(*str,charset) && *str)
//             str++; 
//         result[i++]=copy(start,str); 
//             }
//     return result ; 
// }
int is_sep(char c, char *charset)
{
    int i=0;
    while (charset[i])
    {
        if(c == charset[i])
            return (1);
        i++;
    }
    return (0);
}

int count_words(char *str, char *charset)
{
    int i=0;
    int count = 0;
    while (str[i])
    {
        if(is_sep(str[i],charset) && (i==0 || str[i+1]!='\0') )
            count++;
        i++;
    }
    return (count);
}

char *copy(char *start, char *end)
{
    char *copy;
    int i=0;
    copy=(char *)malloc(end-start+1);
    while (start < end)
    {
        copy[i]=*start;
        start++;
        i++;
    }
    copy[i]='\0';
    return (copy);
}

char **ft_split(char *str, char *charset)
{
    char **split;
    char *start;
    int i=0;
    int count = count_words(str, charset);
    split = (char **)malloc(sizeof(char *)*(count+1));
    while(*str)
    {
        while(is_sep(*str,charset) && *str)
            str++;
        start = str;
        while(!is_sep(*str,charset) && *str)
            str++;
        split[i++]=copy(start,str);
    }
    split[i]=0;
    return (split);
}
// char **split(char *str , char *charset ){
//     char *start ; 
//     char **result ; 
//     int i =0 ; 
//     int count= count_words(str,charset); 
//     result =(char **)malloc(sizeof(char *)* (count +1 )); 
//     while(*str){
//         while(is_sep(*str,charset) && *str)
//             str++; 
//         start = str ; 
//         while(!is_sep(*str,charset) && *str)
//             str++; 
//         result[i++]=copy(start,str); 
//             }
//     return result ; 
// }
int main (){
    char *str="  hello  ,,word";
    char *charset=", "; 
    char **result =ft_split(str,charset);
    printf("%s",result[0]); 

    return 0 ; 
}
