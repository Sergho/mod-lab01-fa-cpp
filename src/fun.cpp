// Copyright 2022 UNN-IASR
#include "fun.h"

#include <cmath>

#include "common.h"

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

unsigned int faStr2(const char *str) {
  int counter = 0;
  bool inWord = false;
  bool containsOnlyLower = true;
  while (*str != 0) {
    if (inWord && isSpace(*str)) {
      inWord = false;
      containsOnlyLower = true;
    }
    if (!inWord && isUpper(*str)) {
      counter++;
      inWord = true;
    } else if (inWord && containsOnlyLower && !isLower(*str)) {
      counter--;
      containsOnlyLower = false;
    }
    str++;
  }
  return counter;
}

unsigned int faStr3(const char *str) {
  bool inWord = false;
  int lengthSum = 0;
  int wordsCount = 0;
  while (*str != 0) {
    if (inWord && isSpace(*str)) {
      inWord = false;
    }
    if (!inWord && !isSpace(*str)) {
      wordsCount++;
      inWord = true;
    }
    if (inWord) lengthSum++;
    str++;
  }
  return std::round(static_cast<double>(lengthSum) / wordsCount);
}
