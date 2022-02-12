/** @file  vector-example.cpp
 *
 * @author Derek Harter
 * @assg   STL List Example
 * @date   June 11, 2018
 * @ide    gcc 7.2.0 and emacs 25 editor
 *
 * @descrption Example of using the C++ Standard Template Library
 *    vectors and other items.
 */
#include <iostream>
#include <queue>
#include <list>
using namespace std;


/** Main entry point of program
 *  The main entry point of the example program.
 *  We accept command line arguments if needed in main.
 *
 * @param argc The argument count
 * @param argv The command line argument values. We expect argv[1] to
 *              be the name of a file in the current directory holding
 *              process events to simulate.
 *
 * @returns int Returns 0 to OS to indicate successful completion, or
 *              non zero value to indicate an error.
 */
int main(int argc, char** argv)
{
  // ============ An example of using a list as a stack  ============
  list<string> stringStack;

  // think of the front as the top of the stack, so we just
  // push to front to add items, and pop front to remove items from stack
  stringStack.push_front("The first item on the stack");
  stringStack.push_front("Item the second");
  stringStack.push_front("The last item I will push on stack, we are the top!");

  cout << "Top of stack   : " << stringStack.front() << endl;
  cout << "Bottom of stack: " << stringStack.back() << endl;
  cout << "Size of stack  : " << stringStack.size() << endl;
  cout << endl;

  // iterate over stack, since we push on front, front item
  // is conceptually the "top" of the stack, and last item is "bottom"
  cout << "Iterate over the stack items" << endl;
  cout << ":Top:" << endl;
  for (string item : stringStack)
  {
    cout << "Found item on stack: '" << item << "'" << endl;
  }
  cout << ":Bottom:" << endl << endl;

  // pop item from stack and disply it and the remaining stack
  string topItem = stringStack.front();
  cout << "Top of stack: " << topItem << endl;
  stringStack.pop_front();
  cout << "After popping top of stack, stack has following items:" << endl;
  cout << ":Top:" << endl;
  for (string item : stringStack)
  {
    cout << "Found item on stack: '" << item << "'" << endl;
  }
  cout << ":Bottom:" << endl << endl;

  // pop two more items, see if stack is empty
  stringStack.pop_front();
  stringStack.pop_front();
  cout << "Is the stringStack empty? " << boolalpha
       << stringStack.empty() << endl;

  // What happens in STL if we try and pop an empty stack/list?
  // Behavior is undefined if we try and pop from an empty
  // containter.  Does not throw an exception, but gives a segmentation
  // fault usually.  You need to always make sure containter is non-empty
  // before poping item off of it.
  //stringStack.pop_front();
  cout << endl << endl;



  // ============ An example of using a list as a queue ============
  list<string> stringQueue;

  // We can use front and back methods to mean the front of
  // the queue and back of the queue, as we normally think of it.
  // Thus we should always push items to the back of the queue, and
  // pop them from the front of the queue.
  stringQueue.push_back("I'm the first in the queue");
  stringQueue.push_back("I'm second in line");
  stringQueue.push_back("I arrived last on the queue...");

  cout << "Front of queue : " << stringQueue.front() << endl;
  cout << "Back of queue  : " << stringQueue.back() << endl;
  cout << "Size of queue  : " << stringQueue.size() << endl;
  cout << endl;

  // iterate over queue, since we push on back, first item
  // displayed will be the "Front" of the queue, and last item
  // will be the "Back".   Here I display on the same
  //  line from back to fron of queue:
  cout << "Iterate over the queue items" << endl;
  cout << "Front: ";
  for (string item : stringQueue)
  {
    cout << "'" << item << "', ";
  }
  cout << " :Back" << endl << endl;;

  // dequeue item from front of queue and disply it and the remaining stack
  string frontItem = stringQueue.front();
  cout << "Front of queue: " << frontItem << endl;
  stringQueue.pop_front();
  cout << "After popping front of queue, queue has following items:" << endl;
  cout << "Front: ";
  for (string item : stringQueue)
  {
    cout << "'" << item << "', ";
  }
  cout << " :Back" << endl << endl;

  // dequeue two more items from front of queue, see if queue empty
  stringQueue.pop_front();
  stringQueue.pop_front();
  cout << "After popping last two items from queue" << endl;
  cout << "Is the stringQueue empty? " << boolalpha
       << stringQueue.empty() << endl;

  // What happens in STL if we try and dequeue an empty queue?
  // Behavior is undefined if we try and pop front from an empty
  // container.  Does not throw an exception, but gives a segmentation
  // fault usually.  You need to always make sure containter is non-empty
  // before poping item off of it.
  //stringQueue.pop_front();


  // return 0 to indicate successful completion to OS
  return 0;
}
