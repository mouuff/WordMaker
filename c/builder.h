char* product(int number){
    const char chars[] = "!#%&()*+,-./0123456789:;=?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}";

    const unsigned short int base = strlen(chars);
    unsigned short int i;

    char *result = malloc(sizeof(char));

    for (i = 0; number > 0; i++){
        number /= base;
        result[i] = chars[number%base];
    }
    return result;
}
