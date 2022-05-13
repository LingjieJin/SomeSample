void encodeASCII(char *buffer, unsigned char value)
{
    unsigned char temp;

    temp = value >> 4;
    if (temp < 10)
        temp += '0';
    else
        temp += 'A' - 10;
    *buffer++ = (char)temp;
    temp = value & 0x0F;
    if (temp < 10)
        temp += '0';
    else
        temp += 'A' - 10;
    *buffer = (char)temp;
}

void decodeASCII(char *buffer, char *value)
{
    char temp;
    unsigned char uvalue;

    temp = *buffer++;
    if (temp > '9')
        uvalue = temp - 'A' + 10;
    else
        uvalue = temp - '0';
    uvalue = uvalue << 4;
    temp = *buffer;
    if (temp > '9')
        uvalue += temp - 'A' + 10;
    else
        uvalue += temp - '0';
    *value = (char)uvalue;
}