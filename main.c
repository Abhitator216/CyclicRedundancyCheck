#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkError(){
    int r1 = rand();
    return r1%2; 
}

int randBitFlip(int m, int k){
    int r2 = rand();
    int i = r2%(m+k);
    return i;
}

int crcSender(char* sgp, char* data){

}

int crcReceiver(char* sgp, char* data){

}

int main(){
    // read n characters from a file at a time
    int n = 10;
    char* data = (char*)malloc(n*sizeof(char));
    FILE* fp = fopen("input.txt", "r");
    int i = 0;
    while(i<n){
        fscanf(fp, "%c", &data[i]);
        i++;
    }
    fclose(fp);
    // crcSender(sgp, data);
    // crcReceiver(sgp, data);
    return 0;
}