
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#pragma once


#ifdef __cplusplus
extern "C" {
#endif

#include "isolation.h"

// @dbccodeconf.h file should be placed in inc folder. If the user wants
// to allocate big DBC struct inside the driver - appropriate define (__DEF_xxxxx__)
// should be placed in this file
#include "dbccodeconf.h"

typedef struct
{
  IMD_Info_t IMD_Info;            // TX [Vector__XXX].RX [].
} Isolation_rx_t;

// There is no any message detected with tx direction.

uint32_t Isolation_Receive(Isolation_rx_t* _m, const uint8_t* _d, uint32_t _id, uint8_t dlc_);


// define @__DEF_ISOLATION__ in the @dbccodeconf.h file for allocation in utility source code.
#ifdef __DEF_ISOLATION__

extern Isolation_rx_t Isolation_rx;

#endif


#ifdef __cplusplus
}
#endif

