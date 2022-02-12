/** @file ex01-main.cpp
 * @brief main/debug executable for Example 01, practice on writing functions.
 *
 * @author Jane Programmer
 * @note   cwid : 123 45 678
 * @note   class: COSC 2336, Summer 2020
 * @note   ide  : Atom Text Editor 1.46.0 / build package / GNU gcc tools
 * @note   assg : Assignment 02
 * @date   June 1, 2020
 *
 * Example Assignment, practice on writing functions.  This is a stub for a
 * separate main() function that can be used to build a debug executable if
 * needed.
 */
#include <cmath>
#include <iomanip>
#include <iostream>
#include "ex01-functions.hpp"
using namespace std;


/** main entry point
 * Main entry point for debugging functions.
 *
 * @param argc The command line argument count, the number of arguments
 *   provided by user on the command line.
 * @param argv An array of char* old style c-strings.  Each argv[x]
 *   that is passed in holds one of the command line arguments provided
 *   by the user to the program when started.
 *
 * @returns int Returns 0 to indicate successfull completion of program,
 *   and a non-zero value to indicate an error code.
 */
int main(int argc, char** argv)
{
  bool res;

  // test all primes from 1 to 20
  res = isPrime(1);
  cout << "Is 1 prime? Result is: " << boolalpha << res << endl;
  res = isPrime(2);
  cout << "Is 2 prime? Result is: " << boolalpha << res << endl;
  res = isPrime(3);
  cout << "Is 3 prime? Result is: " << boolalpha << res << endl;
  res = isPrime(4);
  cout << "Is 4 prime? Result is: " << boolalpha << res << endl;
  res = isPrime(5);
  cout << "Is 5 prime? Result is: " << boolalpha << res << endl;
  res = isPrime(6);
  cout << "Is 6 prime? Result is: " << boolalpha << res << endl;
  res = isPrime(7);
  cout << "Is 7 prime? Result is: " << boolalpha << res << endl;
  res = isPrime(8);
  cout << "Is 8 prime? Result is: " << boolalpha << res << endl;
  res = isPrime(9);
  cout << "Is 9 prime? Result is: " << boolalpha << res << endl;
  res = isPrime(10);
  cout << "Is 10 prime? Result is: " << boolalpha << res << endl;
  res = isPrime(11);
  cout << "Is 11 prime? Result is: " << boolalpha << res << endl;
  res = isPrime(12);
  cout << "Is 12 prime? Result is: " << boolalpha << res << endl;
  res = isPrime(13);
  cout << "Is 13 prime? Result is: " << boolalpha << res << endl;
  res = isPrime(14);
  cout << "Is 14 prime? Result is: " << boolalpha << res << endl;
  res = isPrime(15);
  cout << "Is 15 prime? Result is: " << boolalpha << res << endl;
  res = isPrime(16);
  cout << "Is 16 prime? Result is: " << boolalpha << res << endl;
  res = isPrime(17);
  cout << "Is 17 prime? Result is: " << boolalpha << res << endl;
  res = isPrime(18);
  cout << "Is 18 prime? Result is: " << boolalpha << res << endl;
  res = isPrime(19);
  cout << "Is 19 prime? Result is: " << boolalpha << res << endl;
  res = isPrime(20);
  cout << "Is 20 prime? Result is: " << boolalpha << res << endl;

  // find all primes in range from 1 million to 1.1 million
  int primeCount;
  primeCount = findPrimes(int(1.0e6), int(1.1e6), true);
  cout << "The number of primes in the range is: " << primeCount << endl;

  // return 0 to indicate successful completion
  return 0;
}