// Copyright 2022 UNN-IASR
#include "fun.h"

bool isContains(const char *str, char item) {
  while (*str != 0) {
    if (*str == item) return true;
    str++;
  }
  return false;
}

bool isDigit(char ch) { return isContains("1234567890", ch); }
bool isSpace(char ch) { return isContains(" \n\t", ch); }

unsigned int faStr1(const char *str) {
  int counter = 0;
  bool inWord = false;
  bool containsNumber = false;
  while (*str != 0) {
    if (inWord && isSpace(*str)) {
      inWord = false;
      containsNumber = false;
    }
    if (!inWord && !isSpace(*str)) {
      counter++;
      inWord = true;
    }
    if (!containsNumber && isDigit(*str)) {
      counter--;
      containsNumber = true;
    }
    str++;
  }
  return counter;
}

unsigned int faStr2(const char *str) { return 0; }

unsigned int faStr3(const char *str) { return 0; }
