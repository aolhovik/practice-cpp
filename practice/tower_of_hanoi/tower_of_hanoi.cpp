/*
 * tower_of_hanoi.cpp
 *
 *  Created on: Aug 12, 2020
 *      Author: andrii.olkhovyk
 *
 */

#include "tower_of_hanoi.h"

#include <limits>
#include <iostream>
#include <algorithm>
#include <exception>

#include <iostream>

TowerOfHanoi::TowerOfHanoi (const tLane &initial)
{
  unsigned int SizePrev = initial.front ().size;
  for (auto Curr : initial)
    {
      if (Curr.size > SizePrev)
	{
	  throw std::logic_error (
	      "TowerOfHanoi::TowerOfHanoi initial elements are not sorted");
	}
      SizePrev = Curr.size;
      _Lanes[0].push_back (Curr);
    }
}

TowerOfHanoi::~TowerOfHanoi ()
{
}

TowerOfHanoi::tSolution
TowerOfHanoi::solve ()
{
  if (!_Lanes[0].empty ())
    {
      move (0, 2, 1, _Lanes[0].size ());
    }

  return _Solution;
}

void
TowerOfHanoi::move (unsigned int fromId, unsigned int toId)
{
  tLane &from = _Lanes[fromId];
  tLane &to = _Lanes[toId];
  if (!to.empty () && from.back ().size > to.back ().size)
    {
      throw std::runtime_error ("TowerOfHanoi::move from.size > to.size");
    }

  to.push_back (*(from.rbegin ()));
  from.pop_back ();
  tMove m =
    { &from, &to };
  _Solution.push_back (m);
}

void
TowerOfHanoi::move (unsigned int fromId, unsigned int toId,
		    unsigned int spareId, unsigned int num)
{
  if (1 == num)
    {
      move (fromId, toId);
    }
  else
    {
      move (fromId, spareId, toId, num - 1);
      move (fromId, toId, spareId, 1);
      move (spareId, toId, fromId, num - 1);
    }
}

bool
TowerOfHanoi::validate (const TowerOfHanoi::tLane &initial) const
{
  if (!_Lanes[0].empty () || !_Lanes[1].empty ())
    {
      return false;
    }
  return _Lanes[2] == initial;
}

std::ostream&
operator<< (std::ostream &out, const TowerOfHanoi &game)
{
  for (unsigned int idx = 0; idx < game._Lanes.size (); ++idx)
    {
      const TowerOfHanoi::tLane &Lane = game._Lanes[idx];
      out << &Lane << ": ";
      for (auto Piece : Lane)
	{
	  out << Piece.size << " ";
	}
      out << std::endl;
    }

  return out;
}
