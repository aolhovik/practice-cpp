/*
 * count_unique_words.cpp
 *
 *  Created on: Aug 2, 2020
 *      Author: aolhovik
 */

#include "count_unique_words.h"

#include <iterator>
#include <set>
#include <iostream>

using namespace std;

namespace cuw
{

  const set<char> g_Alphabet =
    { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
	'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

  const char g_Delimiter = ' ';

  int
  countUniqueWords (const string &str, set<char> Alphabet, const char Delimiter) noexcept;

  int countUniqueWords(const std::string &strIn) noexcept
  {
    return countUniqueWords(strIn, g_Alphabet, g_Delimiter);
  }

  int
  countUniqueWords (const string &str, set<char> Alphabet, const char Delimiter) noexcept
  {
    if (str.empty())
      { return 0; }
    if (Alphabet.empty())
      {	return 0; }

    string strFiltered;

    string word;

    set<string> WordsUnique;
    for (auto c : str)
      {
	// filter chars which are not present in the alphabet
	if( Alphabet.find(c)!= Alphabet.end()) // log(N), N - size of alphabet
	  {
	    word += c;
	    // split into words
	  } else if ( Delimiter == c)
	    {
	      if(!word.empty())
		{ WordsUnique.insert(word);} // log(N) - N, size of set
	      word = "";
	    }
      }

    // last word marker might end of input text;
    if(!word.empty())
      {
	WordsUnique.insert(word);
      }

    return WordsUnique.size();
  }
}



