/*
 * tower_of_hanoi.h
 *
 *  Created on: Aug 12, 2020
 *      Author: andrii.olkhovyk
 */

#ifndef TOWER_OF_HANOI_TOWER_OF_HANOI_H_
#define TOWER_OF_HANOI_TOWER_OF_HANOI_H_

#include <array>
#include <list>
#include <stack>

#include <ostream>

class TowerOfHanoi
{
public:

  typedef struct __Piece
  {
    unsigned int size;
    bool
    operator== (const __Piece &other) const
    {
      return other.size == size;
    }
    ;
  } tPiece;

  typedef std::list<tPiece> tLane;

  typedef struct
  {
    const tLane *IdFrom;
    const tLane *IdTo;
  } tMove;

  typedef std::list<tMove> tSolution;

  TowerOfHanoi () = delete;
  TowerOfHanoi (const TowerOfHanoi&) = delete;
  TowerOfHanoi (TowerOfHanoi&&) = delete;
  TowerOfHanoi (const tLane &initial);
  TowerOfHanoi&
  operator= (const TowerOfHanoi&) = delete;
  TowerOfHanoi&
  operator= (TowerOfHanoi&&) = delete;
  ~TowerOfHanoi ();

  tSolution
  solve ();
  bool
  validate (const tLane &initial) const;

  friend std::ostream&
  operator<< (std::ostream&, const TowerOfHanoi&);

private:
  void
  move (unsigned int fromId, unsigned int toId);

  void
  move (unsigned int fromId, unsigned int toId, unsigned int spareId,
	unsigned int num);

  std::array<tLane, 3> _Lanes;
  tSolution _Solution;
};

#endif /* TOWER_OF_HANOI_TOWER_OF_HANOI_H_ */
