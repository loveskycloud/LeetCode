/*************************************************************************
	> File Name: strtok.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 May 2021 10:13:29 AM CST
 ************************************************************************/

#include<iostream>
#include <string.h>
using namespace std;

int main() {
    char str[] = "1,2,3,4,5,6";
    char *temp = strtok(str, ",");
    
    while (temp != NULL) {
        printf("%s\n", temp);
        temp = strtok(NULL, ",");
    }
    
    return 0;
}
