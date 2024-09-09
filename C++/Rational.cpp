/*
 * File: rational.cpp
 * ------------------
 * This file implements the Rational class.
 */

#include <string>
#include <cstdlib>

#include "rational.h"

using namespace std;

/* Function prototypes */

int greatestCommonDenominator(int x, int y);

/* Constructors */
Rational::Rational() {
   num = 0;
   den = 1;
}

Rational::Rational(int n) {
   num = n;
   den = 1;
}

Rational::Rational(int x, int y) { // try: 12/8 and 12/-8
   if (x == 0) {
      num = 0;
      den = 1;
   } else {
      int g = greatestCommonDenominator(abs(x), abs(y));
      num = x / g;
      den = abs(y) / g;
      if (y < 0) num = -num;
   }
}
/* Implementation of the arithmetic operators */

// “local” instance variables are left hand side 
// r2 is the right hand side, can still access private r2 fields
// return type of adding two rationals? Rational
Rational Rational::operator+(Rational r2) {
   return Rational(num * r2.den + r2.num * den, den * r2.den);
}

Rational Rational::operator-(Rational r2) {
   return Rational(num * r2.den - r2.num * den, den * r2.den);
}

Rational Rational::operator*(Rational r2) {
   return Rational(num * r2.num, den * r2.den);
}

Rational Rational::operator/(Rational r2) {
   return Rational(num * r2.den, den * r2.num);
}

string Rational::toString() {
   if (den == 1) {
      return to_string(num);
   } else {
      return to_string(num) + "/" + to_string(den);
   }
}

ostream & operator<<(ostream & os, Rational & r) {
   os << r.toString();
   return os;
}

int greatestCommonDenominator(int x, int y) {
   int r = x % y;
   while (r != 0) {
      x = y;
      y = r;
      r = x % y;
   }
   return y;
}
