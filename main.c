/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: kiptubei
 *
 * Created on August 8, 2020, 9:38 PM
 * 
 * usage:
 * copybybuffer filename outputname
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 200
/*
 * 
*/

int copyfile(FILE *from, FILE *to) {

    char buffer[BUFFER_SIZE];
    int buffer_length;
    
    while(!feof(from)){
        buffer_length = fread(buffer, sizeof(char),BUFFER_SIZE,from);
        fwrite(buffer, sizeof(char), buffer_length, to);
    }

    return 0;
}
int main(int argc, char** argv) {

    FILE *src;
    FILE *dest;

    if (argc != 3) {
        fprintf(stderr, "Wrong number of arguments\n");
        fprintf(stderr, "format: copyfile srcfile destfile");
        return (EXIT_FAILURE);
    }

    src = fopen(argv[1], "r");

    if (src == NULL) {
        fprintf(stderr, "could not open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    dest = fopen(argv[2], "w");

    if (dest == NULL) {
        fprintf(stderr, "could not open destination file %s\n", argv[2]);
        fclose(src);
        return (EXIT_FAILURE);
    }

    copyfile(src, dest);

    fclose(src);
    fclose(dest);
    return (EXIT_SUCCESS);
}

