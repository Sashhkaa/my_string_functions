#include <stdio.h>
#include <malloc.h>

int my_puts(const char *string) {
  int ind = 0;
  while (string[ind] != '\0') {
    int res = putchar(string[ind++]);
    if (res == EOF) {
      return res;
    }
  }
  if (putchar('\n') == EOF) {
    return EOF;
  };
  return '\n';
}

char *my_strchr(char *str, int chr) {
  int ind = 0;
  while (str[ind] != '\0') {
    if (str[ind] == chr) {
      return &str[ind];
    }
    ++ind;
  }
  if (chr == '\0') {
    return &str[ind];
  }
  return NULL;
}

int my_strlen(const char *str) {
  int len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}

char *my_strcpy(char *dst, const char *src) {
  int ind = 0;
  while ((dst[ind] = src[ind]) != '\0') {
    ++ind;
  }
  return dst;
}

char *my_strncpy(char *dst, const char *src, size_t num) {
  size_t ind = 0;
  while (ind < num && src[ind] != '\0') {
    dst[ind] = src[ind];
    ++ind;
  }
  if (src[ind] == '\0') {
    dst[ind] = '\0';
  }
  return dst;
}

char *my_strcat(char *dst, const char *str) {
  my_strcpy(my_strchr(dst, '\0'), str);
  return dst;
}

char *my_strncat(char *dst, const char *str, size_t num) {
  my_strncpy(my_strchr(dst, '\0'), str, num);
  return dst;
}

char *my_fgets(char *str, int num, FILE *stream) {
  int ind = 0;
  while (ind < num) {
    int res = fgetc(stream);
    if (res == EOF || res == '\0') {
      break;
    }
    str[ind++] = res;
    if (res == '\n') {
      break;
    }
  }
  str[ind] = '\0';
  return str;
}

char *my_strdup(const char *str) {
  char *res = malloc(my_strlen(str));
  my_strcpy(res, str);
  return res;
}

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream) {
  if (*lineptr == NULL) {
    *n = 128;
    *lineptr = malloc(*n);
    if (*lineptr == NULL) {
      return -1;
    }
  }
  size_t ind = 0;
  int read_chr;
  while ((read_chr = fgetc(stream)) != '\n' && read_chr != EOF && read_chr != '\0') {
    if (ind == *n) {
      *n *= 2;
      *lineptr = realloc(*lineptr, *n);
      if (*lineptr == NULL) {
        return -1;
      }
    }
    *lineptr[ind] = read_chr;
  }
  if (read_chr == EOF && !feof(stream)) {
    return -1;
  }
  if (read_chr == '\n') {
    *lineptr[ind++] = read_chr;
    *lineptr[ind] = '\0';
  }
  return ind;
}

int main() {
  printf("%s", my_strdup("meuw"));
  return 0;
}
