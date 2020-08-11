/*
 * get_unique.cpp
 *
 *  Created on: Jul 17, 2020
 *      Author: andrey.olhovik
 */

#include "get_unique.h"

#include <list>
#include <map>
#include <iostream>

using namespace std;

/** \b Return a map where key is unique element and value is a number of occurrences of the element in the given container. less than O(N logN) */
template<class TElement, class TContainer>
  map<TElement, unsigned int>
  getOccurrences (const TContainer &Container)
  {

    map<TElement, unsigned int> Occurances;

    for (auto element : Container)
      {
	auto iFound = Occurances.find (element);
	if (iFound != Occurances.end ())
	  {
	    (*iFound).second += 1;
	  }
	else
	  {
	    Occurances[element] = 1;
	  }
      }
    return Occurances;
  }

char
get_unique (const std::string &s)
{

  if (s.empty ())
    {
      return '\0';
    }

  // get occurrences of each character present in the string
  auto Occurrences = getOccurrences<char, string> (s);

  // filter out elements which appear more than once; O(N)
  list<decltype(Occurrences)::key_type> Filtered;

  for (auto el : Occurrences)
    {
      if (1 == el.second)
	{
	  Filtered.push_back (el.first);
	}
    }

  if (Filtered.empty ())
    {
      return '\0';
    }

  // iterate over Filtered, find position in s to determine position of 1st unique
  string::size_type posFirst = s.size ();
  for (auto c : Filtered)
    {
      auto pos = s.find (c);
      if (pos < posFirst)
	{
	  posFirst = pos;
	}
    }

  return s[posFirst];
}
