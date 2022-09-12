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
    if(checkError()==0){
        
    }
}

int crcReceiver(char* sgp, char* data){

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
    while(ch != EOF)
    {
        int i=0;
        while(ch!=EOF && i<n){
            data[i] = ch;
            ch = fgetc(fp2);
            i++;
        }
        crcSender(sgf,data);
        //check for error
            //if no error
                //continue for next n char
            //if error
    }
    fclose(fp2);
    return 0;
}