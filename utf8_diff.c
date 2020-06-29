#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int utf8_nbyte(uint8_t *s) {
  /* 0xxx-xxxx */
  if ((s[0] & 0x80) == 0) {
    return 1;
  }
  /* 110x-xxxx */
  if ((s[0] & 0xE0) == 0xC0) {
    return 2;
  }
  /* 1110-xxxx */
  if ((s[0] & 0xF0) == 0xE0) {
    return 3;
  }
  /* 1111-0xxx */
  if ((s[0] & 0xF8) == 0xF0) {
    return 4;
  }
  return -1;
}

int print_diff(uint8_t *s0, int l0, uint8_t *s1, int l1, bool verbose) {
  printf("\x1b[7m");
  putchar('/');
  for (int k = 0; k < l0; k++) {
    putchar(s0[k]);
  }
  putchar('/');
  for (int k = 0; k < l1; k++) {
    putchar(s1[k]);
  }
  putchar('/');
  if (verbose) {
    for (int k = 0; k < l0; k++) {
      printf("%02X ", s1[k]);
    }
    printf("\b/");
    for (int k = 0; k < l0; k++) {
      printf("%02X ", s0[k]);
    }
    printf("\b/");
  }
  printf("\x1b[0m");
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("argc =%d\n", argc);
    puts("<program> s1 s1");
    return 0;
  }
  uint8_t *s0 = (uint8_t *)argv[1];
  uint8_t *s1 = (uint8_t *)argv[2];

  if (strlen((char *)s0) != strlen((char *)s1)) {
    puts("length is not equal.");
    return 0;
  }

  size_t len = strlen((char *)s0);

  size_t i = 0;

  while (*s0 != '\0' || *s1 != '\0') {
    if (i >= len) {
      puts("error.");
      break;
    }
    int l0 = utf8_nbyte(s0);
    int l1 = utf8_nbyte(s1);
    if (l0 <= 0 || l1 <= 0) {
      puts("utf8 error.");
      break;
    }
    if (l0 != l1) {
      printf("length is not equal.\n%zu th\n", i);
      break;
    } else {
      int j = 0;
      for (j = 0; j < l0; j++) {
        if (s0[j] != s1[j]) {
          print_diff(s0, l0, s1, l1, true);
          break;
        }
      }
      if (j == l0) {
        for (int j = 0; j < l0; j++) {
          putchar(s0[j]);
        }
      }
    }
    s0 += l0;
    s1 += l1;
    i++;
  }
  putchar('\n');
  return 0;
}
