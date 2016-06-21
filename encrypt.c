// encrypt data useing XOR operator with given key.
void encrypt(char *line, int key){
  while(*line){
    *line ^= key;
    line++;
  }
}
