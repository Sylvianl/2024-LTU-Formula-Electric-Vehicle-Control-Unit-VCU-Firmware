
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#include "isolation_binUtil.h"

#ifdef __DEF_ISOLATION__

Isolation_rx_t Isolation_rx;

#endif

uint32_t Isolation_Receive(Isolation_rx_t* _m, const uint8_t* _d, uint32_t _id, uint8_t dlc_)
{
 uint32_t recid = 0;
 if (_id == 0x37U) {
  recid = Unpack_IMD_Info_Isolation(&(_m->IMD_Info), _d, dlc_);
 }

 return recid;
}

