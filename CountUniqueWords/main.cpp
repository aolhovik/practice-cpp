
#include "count_unique_words.h"
#include "run_tests.h"

#include <iostream>
#include <iterator>

using namespace std;

string
readInput (istream &is)
{
  is >> noskipws;
  istream_iterator<char> begin (is);
  istream_iterator<char> end;

  return string (begin, end);

}

int
main (int argc, char *argv[])
{
  cout << cuw::countUniqueWords(readInput(cin)) << endl;

  return run_tests();
}
