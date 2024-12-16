/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khzouhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:56:23 by khzouhai          #+#    #+#             */
/*   Updated: 2024/07/17 20:56:26 by khzouhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
        if(is_sep(str[i],charset) && (i==0 || str[i+1]!='\0') && !is_sep(str[i+1],charset))
            count++;
        i++;
    }
    return (count);
}
//",,abc,def,ghi,jk,,"
char *copy(char *start, char *end, int i)
{
    char *copy;
    int i=0;
    copy=(char *)malloc(end-start+1);
    if(!copy)
    {
        free_split(copy, i);
    }
    while (start < end)
    {
        copy[i]=*start;
        start++;
        i++;
    }
    copy[i]='\0';
    return (copy);
}

void free_split(char **str,int count)
{
    int i;
    i=0;

    while(i<count)
    {
        free(str[i++]);
    }
    free(str);
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

int main()
{
    //int i=0;
    char str[]=" hello, world; h ";
	char **result = ft_split(str, " ;,");
	printf("%s", result[0]);
	//printf("%d", count_words(str, " ,;"));

}
// int main()
// {   //printf("dh");
//     char s[20]=",,abc,def,ghi,jk,,";
//     char ch[2]=",";
    
    
//   //  p = (char **)malloc(sizeof(char *)*(ft_strnumb(s,ch)+1));
//     //p = ft_split(s, ch);
//     printf("%d",count_words(s,ch));
// }
// int ft_wordlen(char *str, char *charset)
// {
//     int i=0;
//     int j=0;
//     while(str[j] && is_sep(str[j], charset))
//         (j)++;
//     while(str[j] && !is_sep(str[j], charset))
//     {
//         j++;
//         i++;
//     }
//     return (i);  
// }