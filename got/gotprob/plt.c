#include <stdlib.h> 
#include <stdio.h> 

void init(){
    setvbuf(stdin,NULL,_IONBF,0);
    setvbuf(stdout,NULL,_IONBF,0);
    setvbuf(stderr,NULL,_IONBF,0);
}

void vuln(){
    char buf[64]; 
    fgets(buf, 64, stdin); 
    printf(buf);
    printf("/bin/sh");
    return;
} 

int main(){ 
    init();
    system("/bin/ls");
    printf("\nLeak: %p\n", main);
    vuln(); 
    return 0; 
} 
