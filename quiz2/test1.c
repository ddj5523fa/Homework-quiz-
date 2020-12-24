#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define PACKED_BYTE(b) (((uint64_t)(b) & (0xff)) * 0x0101010101010101u)
//
bool is_ascii(const char str[], size_t size)  //¤@
{
    if (size == 0)
        return false;
    int i = 0;
    for (i = 0; i + 8 <= size; i += 8) {
        uint64_t payload;
        printf("%d\n",size);
        memcpy(&payload, str + i, 8);
        if (payload & PACKED_BYTE(0x80))
            return false;
    }

    while (i < size) {
        if (str[i] & 0x80)
            return false;
        i++;
    }
    return true;
}

bool is_EngAlphabet(const char s[], size_t size) //
{
    if (size == 0)
        return false;

    int i = 0;
    while (i + 8 <= size) {
        uint64_t payload;
        memcpy(&payload, s + i, 8);
        if(payload & PACKED_BYTE(0x80))  //§P
            return false ;

        uint64_t A = payload + PACKED_BYTE(128 - 'A');
        uint64_t Z = payload + PACKED_BYTE(128 - 'Z'-1);
        uint64_t uppercase=(A ^ Z) & PACKED_BYTE(0x80);

        uint64_t a = payload + PACKED_BYTE(128 - 'a');
        uint64_t z = payload + PACKED_BYTE(128 - 'z'-1);
        uint64_t lowercase=(a ^ z) & PACKED_BYTE(0x80);

        if ((uppercase | lowercase) ^ PACKED_BYTE(0x80))
            return false;

        i += 8;
    }

    while (i < size) {
        if (s[i] < 65 || s[i] > 122 || (s[i] > 90 && s[i] < 97))  //
            return false;
        i++;
    }
    return true;
}

int main()
{
    printf("--------PartI:-------\n");
    char str[] = "zxcvb123456FDSA";
    printf("input:%s\n",str);
    printf("======Is_Acii?======\n");
    if (is_ascii(str, strlen(str))) {
        printf("True\n");
    }else {
        printf("False\n");
    }
    printf("======Is_Alphabet======\n");
    if (is_EngAlphabet(str, strlen(str))) {
        printf("True\n");
    }
    else {
        printf("False\n");
    }
    printf("--------PartII:-------\n");
    char str2[] = "GHJMnbvcx";
    printf("input:%s\n",str2);
     if (is_ascii(str2, strlen(str2))) {
        printf("True\n");
    }else {
        printf("False\n");
    }
    printf("======Is_Alphabet======\n");
    if (is_EngAlphabet(str2, strlen(str2))) {
        printf("True\n");
    }
    else {
        printf("False\n");
    }
}

