// Copyright 2022 UNN-IASR
#include "common.h"

bool isContains(const char *str, char item) {
  while (*str != 0) {
    if (*str == item) return true;
    str++;
  }
  return false;
}

bool isDigit(char ch) { return isContains("1234567890", ch); }
bool isSpace(char ch) { return isContains(" \n\t", ch); }
bool isLower(char ch) { return isContains("abcdefghijklmnopqrstuvwxyz", ch); }
bool isUpper(char ch) { return isContains("ABCDEFGHIJKLMNOPQRSTUVWXYZ", ch); }