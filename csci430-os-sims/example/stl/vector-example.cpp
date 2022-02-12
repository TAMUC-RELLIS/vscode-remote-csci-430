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
#include <vector>
#include "Process.hpp"
using namespace std;


/** MyClass and example class
 *
 * Just an example of a class that we might create instances of
 * and hold inside of STL containers.
 */
class MyClass
{
private:
  int x, y;
public:
  MyClass()
  {
    x = 5; y = 10;
  }                           // class constructor


};


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
  // a STL vector is stored as a contiguous array.  It is
  // relatively cheap to make bigger and to add to end, but
  // you cannot easily insert into the middle of a vector.
  // (you can, but it can be expnsive to do so).  If you need
  // to add to the middle or beginning, or remove from middle
  // or beginning a lot, should use a STL list instead

  // can create a vector container to hold any fundamental or
  // user defined type
  vector<int> vints; // vector to hold int types
  vector<string> vstrings; // vector to hold some strings
  vector<MyClass> vmyclasses; // vector to hold instances of MyClass

  // we will use the vector of strings, lets put a few strings onto
  // our vector
  vstrings.push_back("Hello I am an item on the vector");
  vstrings.push_back("The second item on the vector");
  vstrings.push_back("How are we doing?");
  vstrings.push_back("Am I the last item?");

  // http://www.cplusplus.com/reference/vector/vector/ is a simple
  // reference for C++ and the STL
  // Lets see what the current size of our vector of objects is
  cout << "vstrings current size: " << vstrings.size() << endl;

  // there are several ways you can iterate over the items in
  // a vector (or list like container) in STL
  // We can use overloaded [] operator to index the vector
  cout << "Iterate over vector using integer indexing notation" << endl;
  for (int i = 0; i < (int)vstrings.size(); i++)
  {
    cout << "element vstrings[" << i << "] = '" << vstrings[i] << "'"
         << endl;
  }
  cout << endl;

  // Usually it is preferred to use newer style iterators to iterate
  // over containers like this.  It is preferred because containers
  // generically may not be organized as sequences where integer
  // index or order is meaningful, like a set or a map of items
  cout << "Iterate over vector using an iterator" << endl;
  for (auto itr = vstrings.begin(); itr != vstrings.end(); ++itr)
  {
    cout << "Found item on vector: '" << *itr << "'" << endl;
  }
  cout << endl;

  // The auto keyword is relatively new, C++ 11 or new standard.
  // Here it just automatically determines the type of the iterator.
  // You may see code that instead explicitly states the type of the
  // iterator, like this
  cout << "Iterate over vector again using iterator, but" << endl
       << "declare the iterator variable using original method" << endl;
  for (vector<string>::iterator itr = vstrings.begin();
       itr != vstrings.end();
       ++itr)
  {
    cout << "Found item on vector: '" << *itr << "'" << endl;
  }
  cout << endl;

  // And finally, there is an even more concise syntax now for
  // creating iterators.  Something like this is also available
  // in newer java as well.  Here we implicitly construct an iteration
  // over the vstrings vector container.
  // So in this syntax, item will hold each item that is fetched
  // from the vector, and we iterate/fetch through the items of vstrings
  cout << "Iterate over vector using newer more explict syntax" << endl;
  for (string item : vstrings)
  {
    cout << "Found item on vector: '" << item << "'" << endl;
  }
  cout << endl;

  // Once again you can look at the reference documentation
  // to see what else you can do with a vector, or other
  // STL container.  Here are some other common actions

  // test whether vector is empty
  cout << "Is vstrings empty? " << boolalpha << vstrings.empty()
       << endl; // boolalpha forces boolean to display as true/false

  cout << "Is vints empty? " << boolalpha << vints.empty() << endl;

  // peak at the first (front) and last (back) items, useful to
  // treat vector as stack or queue
  cout << "vstrings first item is: '" << vstrings.front() << "'" << endl;
  cout << "vstrings last item is: '" << vstrings.back() << "'" << endl;
  cout << endl;

  // we already used push_back to add item to back.  Vector is
  // much more efficient to only beused to grow or shrink on end,
  // thus we can also pop the back item of a vector
  vstrings.pop_back();

  // This only deletes the last item, but doesn't return it.  Use
  // vstrings.back() to get the item before popping it if needed.
  // Lets confirm that the vector has shrunk.
  cout << "After popping off back item, vstrings now contains:" << endl;
  for (string item : vstrings)
  {
    cout << "Found item on vector: '" << item << "'" << endl;
  }
  cout << endl;

  // We can insert items in middle of vector using insert.
  // Things like insert and erase use iterators again to specify
  // the position in the container to do the operation.  So it
  // a bit uggly and kludgy.  But here is an example of inserting
  // an item into vstrings between item 1 and 2 (where I am
  // referring to the 3 items now in vstrings as items 0, 1 and 2
  // respectively).
  auto itr = vstrings.begin();
  vstrings.insert(itr + 2, "Insert me in the middle of the vector please");
  cout << "After inserting item in middle, vector now contains:" << endl;
  for (int i = 0; i < (int)vstrings.size(); i++)
  {
    cout << "element vstrings[" << i << "] = '" << vstrings[i] << "'"
         << endl;
  }
  cout << endl;

  // by extension, we can use insert to insert an item on the beginning
  // of a vector, and we can recreate push_back and use it to insert
  // on the end as well:
  itr = vstrings.begin();
  vstrings.insert(itr, "I am the beginning now!");
  itr = vstrings.begin();
  vstrings.insert(itr + vstrings.size(), "I am the new end!");
  cout << "We used insert to add an item to beginning, and at the end:"
       << endl;
  for (int i = 0; i < (int)vstrings.size(); i++)
  {
    cout << "element vstrings[" << i << "] = '" << vstrings[i] << "'"
         << endl;
  }
  cout << endl;

  // erase item at position 3
  itr = vstrings.begin();
  vstrings.erase(itr + 3);
  cout << "We used erase to remove the 3rd item:"
       << endl;
  for (int i = 0; i < (int)vstrings.size(); i++)
  {
    cout << "element vstrings[" << i << "] = '" << vstrings[i] << "'"
         << endl;
  }
  cout << endl;

  // Example of erasing item while iterating through the container.
  // Need to be careful you don't mess up the iterator when you remove
  // items.
  itr = vstrings.begin();
  while (itr != vstrings.end())
  {
    if (*itr == "How are we doing?")
    {
      cout << "We found item to erase, now erase it" << endl;
      itr = vstrings.erase(itr);
    }
    else
    {
      ++itr;
    }
  }

  cout << "After iterating through container and searching for item to erase:"
       << endl;
  for (int i = 0; i < (int)vstrings.size(); i++)
  {
    cout << "element vstrings[" << i << "] = '" << vstrings[i] << "'"
         << endl;
  }
  cout << endl;

  // and finally, lets just clear out the contents of the vector
  vstrings.clear();
  cout << "After cleaning vector, it now contains:" << endl;
  for (string item : vstrings)
  {
    cout << "Found item on vector: '" << item << "'" << endl;
  }
  cout << "And its size is: " << vstrings.size() << endl;
  cout << endl;

  // try a vector of Process objects
  vector<Process> processControlBlock;

  // create a dummy/idle process and push to back
  Process idle;
  processControlBlock.push_back(idle);

  // create pid 1 and 2
  Process p1(1, 5);
  processControlBlock.push_back(p1);

  Process p2(2, 8);
  processControlBlock.push_back(p2);

  // iterate over to display current processes in the control block
  cout << "Process Control Block" << endl;
  cout << "---------------------" << endl;
  for (Process p : processControlBlock)
  {
    cout << p << endl;
  }
  cout << "---------------------" << endl;
  cout << "Process Control Block" << endl << endl;

  // example of accessing process pid=2, make the process ready
  // and perform a cpu cycle on it
  int pid = 2;
  processControlBlock[pid].ready();
  processControlBlock[pid].dispatch();
  processControlBlock[pid].cpuCycle();

  cout << "Process pid=" << pid << endl;
  cout << processControlBlock[pid] << endl;

  // return status 0 to indicate successful program completion
  return 0;
}