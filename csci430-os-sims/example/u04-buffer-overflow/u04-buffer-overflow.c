/** @file u04-buffer-overflow.c
 * @brief Buffer overflow security example from unit 04 chapter 7
 *   memory management.
 *
 * @author Derek Harter
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Demonstration of basic vulnerability when memory access is not protected
 * sufficiently.  Here a security vulnerability in system function gets allows
 * for a buffer overflow attach.  The system function does not adequately
 * check for buffer size problems with input from regular user.
 */
#include <stdio.h> // printf function
#include <stdbool.h>
#include <string.h> // strcpy() and other char* string processing


/**
 * @brief get stored password
 *
 * Just an example, in a real application password would be stored in a file
 * or more likely a database.  And hopefully password is not stored as plain
 * text, but a password hash is used to encrypt the password.  In this example
 * the user password is "ASECRET"
 *
 * @param storedPassword A buffer to copy the retrieved stored password into
 *   so we can return it back to the caller.
 *
 * @returns void Nothing explicit is returned, but tvalidhe password is retrieved
 *   and returned in the buffer given as parameter to this function.
 */
 void retrieveStoredPassword(char storedPassword[])
 {
   // for this demonstration, we simply use the password "MYSECRET"
   // notice password is 7 characters, but c-style char* strings use
   // the null character '\0' as a flag to indicate end of string. Thus,
   // we actually fill in a buffer of size 8 fully by this strcpy()
   strcpy(storedPassword, "ASECRET");
 }


/**
 * @brief main entry
 *
 * Main entry point of process when run.  Code execution starts here.
 *
 * @param argc The count of the number of arguments on the command line.
 * @param argv[] An array of char* strings, the command line arguments
 *   provided by the user when this program is run.
 *
 * @returns int Returns a status/exit code.  0 means normal termination.
 */
int main(int argc, char* argv[])
{
  int loginSuccessful = false;
  char storedPassword[8];
  char userEnteredPassword[8];

  // demonstration, a function to get the stored password for
  // authentication of the user
  retrieveStoredPassword(storedPassword);

  // prompt user for password to authenticate
  printf("Enter your user password: ");

  // retrieve the user entered password from the standard input
  // gets() is known to be unsecure, it will accept as much input as you give it
  // and stuff it into the given buffer.  Notice you don't specify the buffer
  // size when calling gets()
  gets(userEnteredPassword);

  // authenticate the password.  For a plain text password, the pathword is
  // valid if it matches the stored password
  // strncmp() returns 0 if passwords are equal, and (-1,+1) if first string
  // is less,greater than the second string.
  // Notice strncmp() takes a length parameter, it expects that both strings are
  // 8 characters or less in length.  strncmp() is a good function, it does not
  // go past indicated buffer length of strings when doing comparison.
  int res = strncmp(storedPassword, userEnteredPassword, 8);
  printf("String compare result: %d\n", res);
  if (strncmp(storedPassword, userEnteredPassword, 8) == 0)
  {
    loginSuccessful = true;
  }

  // what do our string buffers currently hold?
  printf("stored password      : <%s>\n", storedPassword);
  printf("user entered password: <%s>\n", userEnteredPassword);
  if (loginSuccessful)
  {
    printf("Valid password received, user authentication successful.\n");
  }
  else
  {
    printf("Invalid password entered, user authentication failed.\n");
  }

  printf("Other useful information:\n");
  printf("Size of char: %d\n", (int)sizeof(char));
  printf("Base address of storedPassword     : %p %0ld\n",
     (void*)&storedPassword, (unsigned long int)&storedPassword);
  printf("Base address of userEnteredPassword: %p %0ld\n",
     (void*)&userEnteredPassword, (unsigned long int)&userEnteredPassword);

  // return 0 to indicate successful completion
  return 0;
}
