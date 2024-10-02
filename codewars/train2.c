void fakeBin(const char *digits, char *binary) {
  // Please place result in the memory pointed to by
  // the binary parameter. binary has enough memory to
  // accommodate the answer as well as the null-terminating
  // character.
  int i;
  int size;
  for(i = 0; digits != '\0';i++) {
    size = i + 1;
  }
  while(i = 0; digits > size - 1 ;i++) {
    if (digits[i] < 5) {
      binary[i] = '0';
    }else{
      binary[i] = '1'
    }
  }
 	binary[i] = '\0';
}
