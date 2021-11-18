#include "tree_height.h"

#define UINT_MAX 4294967295

char *itoa(int value, char *buffer, int radix)
{
    int cnt;
    unsigned int no_decimal, result_value;

    cnt = 0;
    if (value == 0)                     // value가 0일때
    {
        buffer[0] = '0';
        buffer[1] = '\0';
        return (buffer);
    }
    else if (value < 0)                 // value가 음수일때
    {
        if (radix == 10)            // 10진수일때(음수)
        {
            buffer[0] = '-';
            value *= -1;
            cnt++;
            result_value = value;
            while (value >= radix)
            {
                value /= radix;
                cnt++;
            }
        }
        else                        // 10진수가 아닐때(음수)
        {
            no_decimal = UINT_MAX + value + 1;
            result_value = no_decimal;
            while (no_decimal >= radix)
            {
                no_decimal /= radix;
                cnt++;
            }
        }
    }
    else                                 // value가 양수일때
    {
        result_value = value;
        while (value >= radix)
        {
            value /= radix;
            cnt++;
        }
    }
    buffer[cnt + 1] = '\0';
    while (result_value > 0)
    {
        if (result_value % radix <= 9)
            buffer[cnt] = result_value % radix + '0';
        else                                          // 11진수 이상일때만 해당('a' ~ '~')
            buffer[cnt] = result_value % radix + 'a' - 10;
        result_value /= radix;
        cnt--;
    }
    return (buffer);
}
