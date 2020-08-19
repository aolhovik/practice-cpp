/*
 * missing_packets.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: andrii.olkhovyk
 */

#include "missing_packets.h"
#include <iostream>

MissingPacketsCounter::MissingPacketsCounter (const char buffer[],
					      unsigned int len) :
    _buffer (buffer), _len (len)
{
  for (unsigned int pid = 0; pid < 2 << 12; ++pid)
    {
      _MissingPacketsCounter[pid] = 0;
      _LastPacketRecieved[pid] = nullptr;
    }

  count ();
}

void
MissingPacketsCounter::count ()
{
  unsigned int offset = 0;
  while (offset < _len)
    {
      const tPacket *ptrCurr = reinterpret_cast<const tPacket*> (_buffer
	  + offset);
      tPacket::tPid pid = ptrCurr->pid;

      const tPacket *ptrLast = _LastPacketRecieved[pid];
      if (ptrLast != nullptr)
	{
	  _MissingPacketsCounter[pid] += countMissing (ptrLast, ptrCurr);
	}
      _LastPacketRecieved[pid] = ptrCurr;
      offset += sizeof(tPacket);
    }
}

unsigned int
MissingPacketsCounter::countMissing (const tPacket *p1, const tPacket *p2)
{
  int d = p2->cc - p1->cc - 1;

  if (0 <= d)
    {
      return d;
    }
  else
    {
      return d + _CcSize;
    }
}

unsigned int
MissingPacketsCounter::getCount (const tPacket::tPid pid) const
{
  return _MissingPacketsCounter[pid];
}

std::ostream&
operator<< (std::ostream &out, const MissingPacketsCounter c)
{
  for (tPacket::tPid pid = 0; pid < MissingPacketsCounter::_PidSze; ++pid)
    {
      if (nullptr != c._LastPacketRecieved[pid])
	{
	  out << pid << ' ' << c.getCount (pid) << std::endl;
	}
    }

  return out;
}
