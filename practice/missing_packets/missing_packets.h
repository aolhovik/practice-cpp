/*
 * missing_packets.h
 *
 *  Created on: Aug 19, 2020
 *      Author: andrii.olkhovyk
 */

#ifndef MISSING_PACKETS_MISSING_PACKETS_H_
#define MISSING_PACKETS_MISSING_PACKETS_H_

#include <array>
#include <ostream>

/// Continues packets with the same 'pid' come with 'cc' incrementing 'cc'; once 'cc' reaches max values it's reset to min value.
typedef struct
{
  typedef unsigned int tPid;
  typedef unsigned int tCC;

  tPid pid :12; // packet id
  tCC cc :4; // continuity counter
} tPacket;

/// Counts missing packets
class MissingPacketsCounter
{
  // contains missing packs
  std::array<unsigned int, 2 << 12> _MissingPacketsCounter;
  std::array<const tPacket*, 2 << 12> _LastPacketRecieved;

  const char *_buffer;
  unsigned int _len;

  static constexpr unsigned int _PidSze = 1 << 12;
  static constexpr unsigned int _CcSize = 1 << 4; // number of distinct values 'cc' can hold

  void
  count ();
  unsigned int
  countMissing (const tPacket *p1, const tPacket *p2);
public:
  MissingPacketsCounter (const char *buffer, unsigned int len);

  unsigned int
  getCount (const tPacket::tPid pid) const;

  friend std::ostream&
  operator<< (std::ostream &out, const MissingPacketsCounter c);
};

#endif /* MISSING_PACKETS_MISSING_PACKETS_H_ */
