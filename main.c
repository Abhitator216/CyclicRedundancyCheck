#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* xor(char* a, char* b) {
    int i;
    char* result = malloc(strlen(a) + 1);
    for (i = 0; i < strlen(a); i++) {
        result[i] = a[i] ^ b[i];
    }
    result[i] = '\0';
    return result;
}

// perform modulo-2 division and return the remainder in binary
char* mod2div(char* dividend, char* divisor) {
    int pick = strlen(divisor);
    int tmp = pick;
    char* remainder = malloc(strlen(divisor) + 1);
    //todo
    return remainder;
}

char* stringToBinary(char* s) {
    if(s == NULL) return 0; /* no input string */
    size_t len = strlen(s);
    char *binary = malloc(len*8 + 1); // each char is one byte (8 bits) and + 1 at the end for null terminator
    binary[0] = '\0';
    for(size_t i = 0; i < len; ++i) {
        char ch = s[i];
        for(int j = 7; j >= 0; --j){
            if(ch & (1 << j)) {
                strcat(binary,"1");
            } else {
                strcat(binary,"0");
            }
        }
    }
    return binary;
}

int checkError(){
    int r1 = rand();
    return r1%2; 
}

int randBitFlip(int m, int k){
    int r2 = rand();
    int i = r2%(m+k);
    return i;
}

char* crcCalculator(char* data, char* sgp){
    char* dataWithZeros = malloc(strlen(data) + strlen(sgp) + 1);
    strcpy(dataWithZeros, data);
    int i;
    for(i = 0; i < strlen(sgp) - 1; i++){
        strcat(dataWithZeros, "0");
    }
    char* remainder = mod2div(dataWithZeros, sgp);
    printf("\nRemainder: %s", remainder);
    char* crc = malloc(strlen(data) + strlen(remainder) + 1);
    strcpy(crc, data);
    strcat(crc, remainder);
    return crc;
}

int crcReceiver(char*,char*,char*);

void crcSender(char* sgp, char* data){
    //convert data to binary string
    char* binData = stringToBinary(data);
    
    //calculate crc and append to fullBinData
    char* crcBin = crcCalculator(data, sgp);
    printf("\ncrc gen: %s", crcBin);

    // if(checkError()){
    //     int i = randBitFlip(strlen(fullBinData), strlen(sgp));
    //     if(fullBinData[i] == '0'){
    //         fullBinData[i] = '1';
    //     } else {
    //         fullBinData[i] = '0';
    //     }
    // }
    // printf("Data sent: %s", fullBinData);
    // crcReceiver(sgp, data, fullBinData);
    return;
}

int crcReceiver(char* sgp, char* data, char* fullBinData){
    
}

int main(){
    // read n characters from a file at a time
    int n = 10;
    char* data = (char*)malloc(n*sizeof(char));
    char* sgf = "110110101";
    
    FILE *fp2;
    char ch;
    fp2 = fopen("input.txt","r");
    ch = fgetc(fp2);
    // while(ch != EOF)
    // {
    //     int i=0;
    //     while(ch!=EOF && i<n){
    //         data[i] = ch;
    //         ch = fgetc(fp2);
    //         i++;
    //     }
    //     crcSender(sgf,data);
    //     //check for error
    //         //if no error
    //             //continue for next n char
    //         //if error
    // }
    int i=0;
    while(ch!=EOF && i<n){
            data[i] = ch;
            ch = fgetc(fp2);
            i++;
        }
    fclose(fp2);
    // for(int i=0;i<n;i++){
    //     printf("%c",data[i]);
    // }
    crcSender(sgf,data);
    return 0;
}