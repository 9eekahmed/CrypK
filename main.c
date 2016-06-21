/*
  Author: Mohamed Ahmed.
  URL: http://twitter.com/9eekM
  Copyright: 2016.
  CrypK
*/

#include <stdio.h> // i/o functions ..
#include <string.h> // [strlen()]
#include <unistd.h> // [getopt(), optarg]
#include "encrypt.h"

int main (int argc, char *argv[]){
  int ch;
  char *File_name_in;
  char *File_name_out;
  int key;

  // check for correct option..
  if (argc < 6){
    printf("Usage: ./Crypter -f [FileName] -k [INT-KEY] -o [Output-FileName]\t\n");
    return 1;
  }

  // get options ..
  while((ch = getopt(argc, argv, "f:k:o:")) != -1)
    switch (ch) {
      case 'f':
        File_name_in = optarg;
        break;
      case 'o':
        File_name_out = optarg;
        break;
      case 'k':
        if (isInt(optarg)==0){
          key = atoi(optarg);
        }else{
          printf("Warning: [-k] Option expected int Value !\t\n");
          return -1;
        }
        break;
      default:
        printf("Unknown Option: '%s'\t\n",optarg);
        return -1;
    }

  printf("[#] File: [ %s ]\n", File_name_in);

  FILE *in = fopen(File_name_in, "r");
  FILE *out = fopen(File_name_out, "w");

  printf("[#] Load Data\t\n");

  char buf[255];
  while (fgets(buf, 255, in)){
    buf[(int)strlen(buf)-1] = '\0'; // delete \n char ..
    encrypt(buf, key);  // pass to encrypt function ..
    fprintf(out, "%s\n", buf);
  }

  printf("[#] Key: %i\n", key);
  printf("[#] Success \n");

  fclose(in);
  fclose(out);
  return 0;
}

int isInt(char *ch){
  while(*ch){
    if(!(*ch & 0b11000000) == 0){
      return -1;
    }
    ch++;
  }
  return 0;
}
