/*
** EPITECH PROJECT, 2023
** test_my_printf
** File description:
** Test file for my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/my_printf.h"
#include <stdio.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    char str[80];
    my_printf("hello world");
    sprintf(str, "hello world");
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, simple_string2, .init = redirect_all_std)
{
    char str[80];
    my_printf("");
    sprintf(str, "");
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingstring, .init = redirect_all_std)
{
    char str[80];
    my_printf("hello world %s", "Salut");
    sprintf(str, "hello world %s", "Salut");
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingcharacter, .init = redirect_all_std)
{
    char str[80];
    my_printf("hello world %c\n", 's');
    sprintf(str, "hello world %c\n", 's');
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addinginteger, .init = redirect_all_std)
{
    char str[80];
    my_printf("hello world %i\n", 4);
    sprintf(str, "hello world %i\n", 4);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, iflag2, .init = redirect_all_std)
{
    char str[80];
    my_printf("--+%i\n", -42);
    sprintf(str, "--+%i\n", -42);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, iflag3, .init = redirect_all_std)
{
    char str[80];
    my_printf("+++-%---i\n", 12345678);
    sprintf(str, "+++-%---i\n", 12345678);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, iflag4, .init = redirect_all_std)
{
    char str[80];
    my_printf("%#.2i\n", 21);
    sprintf(str, "%#.2i\n", 21);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, dflag1, .init = redirect_all_std)
{
    char str[80];
    my_printf("--+%d\n", -42);
    sprintf(str, "--+%d\n", -42);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, dflag2, .init = redirect_all_std)
{
    char str[80];
    my_printf("--+%d\n", -42);
    sprintf(str, "--+%d\n", -42);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, dflag3, .init = redirect_all_std)
{
    char str[80];
    my_printf("--+%d\n", -42);
    sprintf(str, "--+%d\n", -42);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, dflag4, .init = redirect_all_std)
{
    char str[80];
    my_printf("--+%d\n", -42);
    sprintf(str, "--+%d\n", -42);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingintegersec, .init = redirect_all_std)
{
    char str[80];
    my_printf("hello world %d\n", 4);
    sprintf(str, "hello world %d\n", 4);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, pourcent, .init = redirect_all_std)
{
    char str[80];
    my_printf("h%%\n");
    sprintf(str, "h%%\n");
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, folllowpourcent, .init = redirect_all_std)
{
    char str[80];
    my_printf("h%%%%\n");
    sprintf(str, "h%%%%\n");
    cr_assert_stdout_eq_str(str);
}
Test(my_printf, notcool1, .init = redirect_all_std)
{
    char str[80];
    my_printf("%%%\n");
    sprintf(str, "%%%\n");
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, multiple, .init = redirect_all_std)
{
    char str[80];
    my_printf("%d Salut %s %comment va %%\n", 1, "Noa", 'c');
    sprintf(str, "%d Salut %s %comment va %%\n", 1, "Noa", 'c');
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, multiple2, .init = redirect_all_std)
{
    char str[80];
    my_printf("%%TEST, %d Mathys %s je %c t'aime %i\n", 1, "Noa", 'c', 5);
    sprintf(str, "%%TEST, %d Mathys %s je %c t'aime %i\n", 1, "Noa", 'c', 5);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingoctal1, .init = redirect_all_std)
{
    char str[80];
    my_printf("%o", 7);
    sprintf(str, "%o", 7);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingoctal2, .init = redirect_all_std)
{
    char str[80];
    my_printf("%o", 5);
    sprintf(str, "%o", 5);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingoctal3, .init = redirect_all_std)
{
    char str[80];
    my_printf("%o", 978);
    sprintf(str, "%o", 978);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingoctalwithsimplestr1, .init = redirect_all_std)
{
    char str[80];
    my_printf("Salut %o", 7);
    sprintf(str, "Salut %o", 7);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingoctalwithsimplestr2, .init = redirect_all_std)
{
    char str[80];
    my_printf("Salut %o", 5);
    sprintf(str, "Salut %o", 5);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingoctalwithsimplestr3, .init = redirect_all_std)
{
    char str[80];
    my_printf("Salut %o", 978);
    sprintf(str, "Salut %o", 978);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingoctalwithaddingstr1, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %o","Salut", 7);
    sprintf(str, "%s %o","Salut", 7);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingoctalwithaddingstr2, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %o","Salut", 5);
    sprintf(str, "%s %o","Salut", 5);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingoctalwithaddingstr3, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %o","Salut", 978);
    sprintf(str, "%s %o","Salut", 978);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingoctalwithaddingstrandaddingprc1, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %o %%", "Salut", 7);
    sprintf(str, "%s %o %%", "Salut", 7);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingoctalwithaddingstrandaddingprc2, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %o %%", "Salut", 5);
    sprintf(str, "%s %o %%", "Salut", 5);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingoctalwithaddingstrandaddingprc3, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %o %%", "Salut", 978);
    sprintf(str, "%s %o %%", "Salut", 978);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingusi1, .init = redirect_all_std)
{
    char str[80];
    my_printf("%u", 0);
    sprintf(str, "%u", 0);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingusi2, .init = redirect_all_std)
{
    char str[80];
    my_printf("%u", 4294967295);
    sprintf(str, "%u", 4294967295);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingusi3, .init = redirect_all_std)
{
    char str[80];
    my_printf("%u", 2147483647);
    sprintf(str, "%u", 2147483647);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingusiwithsimplestr1, .init = redirect_all_std)
{
    char str[80];
    my_printf("Salut %u", 0);
    sprintf(str, "Salut %u", 0);
    cr_assert_stdout_eq_str("Salut 0");
}

Test(my_printf, addingusiwithsimplestr2, .init = redirect_all_std)
{
    char str[80];
    my_printf("Salut %u", 4294967295);
    sprintf(str, "Salut %u", 4294967295);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingusiwithsimplestr3, .init = redirect_all_std)
{
    char str[80];
    my_printf("Salut %u", 2147483647);
    sprintf(str, "Salut %u", 2147483647);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingusiwithaddingstr1, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %u","Salut", 0);
    sprintf(str, "%s %u","Salut", 0);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingusiwithaddingstr2, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %u","Salut", 4294967295);
    sprintf(str, "%s %u","Salut", 4294967295);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingusiwithaddingstr3, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %u","Salut", 2147483647);
    sprintf(str, "%s %u","Salut", 2147483647);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingusiwithaddingstrandaddingprc1, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %u %%", "Salut", 0);
    sprintf(str, "%s %u %%", "Salut", 0);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingusiwithaddingstrandaddingprc2, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %u %%", "Salut", 4294967295);
    sprintf(str, "%s %u %%", "Salut", 4294967295);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingousiwithaddingstrandaddingprc3, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %u %%", "Salut", 2147483647);
    sprintf(str, "%s %u %%", "Salut", 2147483647);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addinghexa1, .init = redirect_all_std)
{
    char str[80];
    my_printf("%x", 7);
    sprintf(str, "%x", 7);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addinghexa2, .init = redirect_all_std)
{
    char str[80];
    my_printf("%x", 15);
    sprintf(str, "%x", 15);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addinghexa3, .init = redirect_all_std)
{
    char str[80];
    my_printf("%x", 19);
    sprintf(str, "%x", 19);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addinghexawithsimplestr1, .init = redirect_all_std)
{
    char str[80];
    my_printf("Salut %x", 7);
    sprintf(str, "Salut %x", 7);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addinghexawithsimplestr2, .init = redirect_all_std)
{
    char str[80];
    my_printf("Salut %x", 15);
    sprintf(str, "Salut %x", 15);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addinghexawithsimplestr3, .init = redirect_all_std)
{
    char str[80];
    my_printf("Salut %x", 19);
    sprintf(str, "Salut %x", 19);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addinghexawithaddingstr1, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %x","Salut", 7);
    sprintf(str, "%s %x","Salut", 7);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addinghexawithaddingstr2, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %x","Salut", 15);
    sprintf(str, "%s %x","Salut", 15);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addinghexawithaddingstr3, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %x","Salut", 19);
    sprintf(str, "%s %x","Salut", 19);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addinghexawithaddingstrandaddingprc1, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %x %%", "Salut", 7);
    sprintf(str, "%s %x %%", "Salut", 7);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addinghexawithaddingstrandaddingprc2, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %x %%", "Salut", 15);
    sprintf(str, "%s %x %%", "Salut", 15);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addinghexawithaddingstrandaddingprc3, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %x %%", "Salut", 19);
    sprintf(str, "%s %x %%", "Salut", 19);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingHEXA1, .init = redirect_all_std)
{
    char str[80];
    my_printf("%X", 7);
    sprintf(str, "%X", 7);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingHEXA2, .init = redirect_all_std)
{
    char str[80];
    my_printf("%X", 15);
    sprintf(str, "%X", 15);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingHEXA3, .init = redirect_all_std)
{
    char str[80];
    my_printf("%X", 19);
    sprintf(str, "%X", 19);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingHEXAwithsimplestr1, .init = redirect_all_std)
{
    char str[80];
    my_printf("Salut %X", 7);
    sprintf(str, "Salut %X", 7);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingHEXAwithsimplestr2, .init = redirect_all_std)
{
    char str[80];
    my_printf("Salut %X", 15);
    sprintf(str, "Salut %X", 15);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingHEXAwithsimplestr3, .init = redirect_all_std)
{
    char str[80];
    my_printf("Salut %X", 19);
    sprintf(str, "Salut %X", 19);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingHEXAwithaddingstr1, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %X","Salut", 7);
    sprintf(str, "%s %X","Salut", 7);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingHEXAwithaddingstr2, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %X","Salut", 15);
    sprintf(str, "%s %X","Salut", 15);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingHEXAwithaddingstr3, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %X","Salut", 19);
    sprintf(str, "%s %X","Salut", 19);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingHEXAwithaddingstrandaddingprc1, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %X %%", "Salut", 7);
    sprintf(str, "%s %X %%", "Salut", 7);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingHEXAwithaddingstrandaddingprc2, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %X %%", "Salut", 15);
    sprintf(str, "%s %X %%", "Salut", 15);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingHEXAwithaddingstrandaddingprc3, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %X %%", "Salut", 19);
    sprintf(str, "%s %X %%", "Salut", 19);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingbin1, .init = redirect_all_std)
{
    char str[80];
    my_printf("%b", 1);
    sprintf(str, "%b", 1);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingbin2, .init = redirect_all_std)
{
    char str[80];
    my_printf("%b", 2);
    sprintf(str, "%b", 2);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingbin3, .init = redirect_all_std)
{
    char str[80];
    my_printf("%b", 19);
    sprintf(str, "%b", 19);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingbinwithsimplestr1, .init = redirect_all_std)
{
    char str[80];
    my_printf("Salut %b", 1);
    sprintf(str, "Salut %b", 1);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingbinwithsimplestr2, .init = redirect_all_std)
{
    char str[80];
    my_printf("Salut %b", 2);
    sprintf(str, "Salut %b", 2);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingbinwithsimplestr3, .init = redirect_all_std)
{
    char str[80];
    my_printf("Salut %b", 19);
    sprintf(str, "Salut %b", 19);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingbinwithaddingstr1, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %b","Salut", 1);
    sprintf(str, "%s %b","Salut", 1);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingbinAwithaddingstr2, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %b","Salut", 2);
    sprintf(str, "%s %b","Salut", 2);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingbinwithaddingstr3, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %b","Salut", 19);
    sprintf(str, "%s %b","Salut", 19);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingbinwithaddingstrandaddingprc1, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %b %%", "Salut", 1);
    sprintf(str, "%s %b %%", "Salut", 1);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingbinwithaddingstrandaddingprc2, .init = redirect_all_std)
{
    char str[80];
    my_printf("%s %b %%", "Salut", 2);
    sprintf(str, "%s %b %%", "Salut", 2);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, addingbinwithaddingstrandaddingprc3, .init = redirect_all_std)
{
    char srt[80];
    my_printf("%s %b %%", "Salut", 19);
    sprintf(srt, "%s %b %%", "Salut", 19);
    cr_assert_stdout_eq_str(srt);
}

Test(my_printf, adresshex1, .init = redirect_all_std)
{
    int c = 1;
    char srt[80];
    my_printf("%p", &c);
    sprintf(srt, "%p", &c);
    cr_assert_stdout_eq_str(srt);
}

Test(my_printf, adresshex2, .init = redirect_all_std)
{
    int c = 1;
    char srt[80];
    my_printf("%p", 0);
    sprintf(srt, "%p", 0);
    cr_assert_stdout_eq_str(srt);
}

Test(my_printf, adresshex3, .init = redirect_all_std)
{
    int c = 1;
    char srt[80];
    my_printf("\n%p", 0);
    sprintf(srt, "\n%p", 0);
    cr_assert_stdout_eq_str(srt);
}

Test(my_printf, ffl1, .init = redirect_all_std)
{
   char srt[80];
   my_printf("\n%f", -3.0042559);
   sprintf(srt, "\n%f", -3.0042559);
   cr_assert_stdout_eq_str(srt);
}

Test(my_printf, ffl2, .init = redirect_all_std)
{
   char srt[80];
   my_printf("\n%f", 0.8888899);
   sprintf(srt, "\n%f", 0.8888899);
   cr_assert_stdout_eq_str(srt);
}

Test(my_printf, ffl3, .init = redirect_all_std)
{
   char srt[80];
   my_printf("\n%f", 1.9999999);
   sprintf(srt, "\n%f", 1.9999999);
   cr_assert_stdout_eq_str(srt);
}

Test(my_printf, ffl4, .init = redirect_all_std)
{
   char srt[80];
   my_printf("\n%f", 1.0999909);
   sprintf(srt, "\n%f", 1.0999909);
   cr_assert_stdout_eq_str(srt);
}

Test(my_printf, uppffl1, .init = redirect_all_std)
{
   char srt[80];
   my_printf("\n%F", -3.0042559);
   sprintf(srt, "\n%F", -3.0042559);
   cr_assert_stdout_eq_str(srt);
}

Test(my_printf, uppffl2, .init = redirect_all_std)
{
   char srt[80];
   my_printf("\n%F", 0.8888899);
   sprintf(srt, "\n%F", 0.8888899);
   cr_assert_stdout_eq_str(srt);
}

Test(my_printf, uppffl3, .init = redirect_all_std)
{
   char srt[80];
   my_printf("\n%F", 1.9999999);
   sprintf(srt, "\n%F", 1.9999999);
   cr_assert_stdout_eq_str(srt);
}

Test(my_printf, uppffl4, .init = redirect_all_std)
{
   char srt[80];
   my_printf("\n%F", 1.0999909);
   sprintf(srt, "\n%F", 1.0999909);
   cr_assert_stdout_eq_str(srt);
}
//
Test(my_printf, e1, .init = redirect_all_std)
{
   char srt[80];
   my_printf("\n%e", -3.0042559);
   sprintf(srt, "\n%e", -3.0042559);
   cr_assert_stdout_eq_str(srt);
}

Test(my_printf, e2, .init = redirect_all_std)
{
   char srt[80];
   my_printf("\n%e", 0.8888899);
   sprintf(srt, "\n%e", 0.8888899);
   cr_assert_stdout_eq_str(srt);
}

Test(my_printf, e3, .init = redirect_all_std)
{
   char srt[80];
   my_printf("\n%e", 4.05584154);
   sprintf(srt, "\n%e", 4.05584154);
   cr_assert_stdout_eq_str(srt);
}

Test(my_printf, e4, .init = redirect_all_std)
{
   char srt[80];
   my_printf("\n%e", 1.00000);
   sprintf(srt, "\n%e", 1.00000);
   cr_assert_stdout_eq_str(srt);
}
//
Test(my_printf, E1, .init = redirect_all_std)
{
   char srt[80];
   my_printf("\n%E", -3.0042559);
   sprintf(srt, "\n%E", -3.0042559);
   cr_assert_stdout_eq_str(srt);
}

Test(my_printf, E2, .init = redirect_all_std)
{
   char srt[80];
   my_printf("\n%E", 0.8888899);
   sprintf(srt, "\n%E", 0.8888899);
   cr_assert_stdout_eq_str(srt);
}

Test(my_printf, E3, .init = redirect_all_std)
{
   char srt[80];
   my_printf("\n%E", 4.05584154);
   sprintf(srt, "\n%E", 4.05584154);
   cr_assert_stdout_eq_str(srt);
}

Test(my_printf, E4, .init = redirect_all_std)
{
   char srt[80];
   my_printf("\n%E", 1.00000);
   sprintf(srt, "\n%E", 1.00000);
   cr_assert_stdout_eq_str(srt);
}

Test(my_printf, n1, .init = redirect_all_std)
{
    int e = 0;
    char srt1[80];
    char str2[80];
    my_printf("Hello %n", &e);
    my_printf("%i", e);
    e = 0;
    sprintf(srt1, "Hello %n", &e);
    sprintf(str2, "%i", e);
    cr_assert_stdout_eq_str(my_strcat(srt1, str2));
}

Test(my_printf, n2, .init = redirect_all_std)
{
    int e = 0;
    char srt1[80];
    char str2[80];
    my_printf("%n", &e);
    my_printf("%i", e);
    e = 0;
    sprintf(srt1, "%n", &e);
    sprintf(str2, "%i", e);
    cr_assert_stdout_eq_str(str2);
}

Test(my_printf, n4, .init = redirect_all_std)
{
    int e = 0;
    char srt1[80];
    char str2[80];
    my_printf("%x %n this is a test",15, &e);
    my_printf("%i", e);
    e = 0;
    sprintf(srt1, "%x %n this is a test",15, &e);
    sprintf(str2, "%i", e);
    cr_assert_stdout_eq_str(my_strcat(srt1, str2));
}

Test(my_printf, mo1, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%##################################################s", "this is a test");
    sprintf(srt1, "%s", "this is a test");
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo2, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%##################################################x", 15);
    sprintf(srt1, "%##################################################x", 15);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo3, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%##################################################X", 15);
    sprintf(srt1, "%##################################################X", 15);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo4, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%##################################################X", 155);
    sprintf(srt1, "%##################################################X", 155);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo5, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%##################################################o", 155);
    sprintf(srt1, "%##################################################o", 155);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo6, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%##################################################o", 5);
    sprintf(srt1, "%##################################################o", 5);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo7, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%### b", 1);
    sprintf(srt1, "%### b", 1);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo8, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%##################################################b", 5);
    sprintf(srt1, "%##################################################b", 5);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, gflag1, .init = redirect_all_std)
{
   char srt[80];
   my_printf("\n%g", 0.8888899);
   sprintf(srt, "\n%g", 0.8888899);
   cr_assert_stdout_eq_str(srt);
}

Test(my_printf, gflag2, .init = redirect_all_std)
{
   char srt[80];
   my_printf("\n%g", 1.9999999);
   sprintf(srt, "\n%g", 1.9999999);
   cr_assert_stdout_eq_str(srt);
}

Test(my_printf, ge1, .init = redirect_all_std)
{
   char srt[80];
   my_printf("\n%g", -0.000042559);
   sprintf(srt, "\n%g", -0.000042559);
   cr_assert_stdout_eq_str(srt);
}

Test(my_printf, ge2, .init = redirect_all_std)
{
   char srt[80];
   my_printf("\n%g", 0.00008899);
   sprintf(srt, "\n%g", 0.00008899);
   cr_assert_stdout_eq_str(srt);
}

Test(my_printf, ge3, .init = redirect_all_std)
{
   char srt[80];
   my_printf("\n%g", 0.000000004154);
   sprintf(srt, "\n%g", 0.000000004154);
   cr_assert_stdout_eq_str(srt);
}

Test(my_printf, mo9, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%.2e", 5.08);
    sprintf(srt1, "%.2e", 5.08);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo10, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%.0e", 5.08);
    sprintf(srt1, "%.0e", 5.08);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo11, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%.3e", 5.08);
    sprintf(srt1, "%.3e", 5.08);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo12, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%.3e", 1551.08);
    sprintf(srt1, "%.3e", 1551.08);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo13, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%-14.2f", 1551.08);
    sprintf(srt1, "%-14.2f", 1551.08);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo14, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%#-14.2x", 155108);
    sprintf(srt1, "%#-14.2x", 155108);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo15, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%#-14i", 155108);
    sprintf(srt1, "%#-14i", 155108);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo16, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%#-14.2e", 155108.05);
    sprintf(srt1, "%#-14.2e", 155108.05);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo17, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%#-14s", "Hello how are you ?");
    sprintf(srt1, "%#-14s", "Hello how are you ?");
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo18, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%#-14.2i", 15);
    sprintf(srt1, "%#-14.2i", 15);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo19, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%#-14.2e", 15.5);
    sprintf(srt1, "%#-14.2e", 15.5);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo20, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%#-14.5i", 15);
    sprintf(srt1, "%#-14.5i", 15);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo21, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%#-14.8e", 15.5);
    sprintf(srt1, "%#-14.8e", 15.5);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo22, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%#14.8i", 15);
    sprintf(srt1, "%#14.8i", 15);
    cr_assert_stdout_eq_str(srt1);
}
 
Test(my_printf, mo23, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%#+-14.8i", 15);
    sprintf(srt1, "%#+-14.8i", 15);
    cr_assert_stdout_eq_str(srt1);
}
 
Test(my_printf, mo24, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%#14.1i", 15);
    sprintf(srt1, "%#14.1i", 15);
    cr_assert_stdout_eq_str(srt1);
}
 
Test(my_printf, mo25, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%#+-2.3i", 15);
    sprintf(srt1, "%#+-2.3i", 15);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, diable, .init = redirect_all_std)
{
    char str[80];
    my_printf("DRS27CTYVIBUOI22°I2%.15s9DYU39YBJOIZL.XQ/§A%M%+.2i", "die", -42);
    sprintf(str, "DRS27CTYVIBUOI22°I2%.15s9DYU39YBJOIZL.XQ/§A%M%+.2i", "die", -42);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, bossfinal, .init = redirect_all_std)
{
    char str[80];
    my_printf("%cDR%#xS27C%sTYVIB%XUOI22°I29DYU%%%.3f3%e9YBJOIZL%u.XQ/§A%M%+.2i", '@', 987654321, "you'r gonna", 27834, "die", 123456789, 1465.345, 00.024, 123498765, 42);
    sprintf(str, "%cDR%#xS27C%sTYVIB%XUOI22°I29DYU%%%.3f3%e9YBJOIZL%u.XQ/§A%M%+.2i", '@', 987654321, "you'r gonna", 27834, "die", 123456789, 1465.345, 00.024, 123498765, 42);
    cr_assert_stdout_eq_str(str);
}

Test(my_printf, mo26, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%#+-2.3s", "This is a test");
    sprintf(srt1, "%#+-2.3s", "This is a test");
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo27, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%#+-2.3x", 15);
    sprintf(srt1, "%#+-2.3x", 15);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo28, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%#+-2.3o", 15);
    sprintf(srt1, "%#+-2.3o", 15);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo29, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%#+2.3b", 20);
    sprintf(srt1, "%#+2.3b", 20);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo30, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%#+2.3x", 15);
    sprintf(srt1, "%#+2.3x", 15);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo31, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%#+2.3o", 15);
    sprintf(srt1, "%#+2.3o", 15);
    cr_assert_stdout_eq_str(srt1);
}

Test(my_printf, mo32, .init = redirect_all_std)
{
    char srt1[80];
    my_printf("%#+2.3b", 20);
    sprintf(srt1, "%#+2.3b", 20);
    cr_assert_stdout_eq_str(srt1);
}

// Test(my_printf, mo33, .init = redirect_all_std)
// {
//     char srt1[80];
//     my_printf("%i", 20.4);
//     sprintf(srt1, "%i", 20.4);
//     cr_assert_stdout_eq_str(srt1);
// }