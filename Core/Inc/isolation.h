
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#pragma once


#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// This file must define:
// base monitor struct
// function signature for CRC calculation
// function signature for getting system tick value (100 us step)
//#include "canmonitorutil.h"



// def @IMD_Info CAN Message (55)
#define IMD_Info_IDE (0U)
#define IMD_Info_DLC (8U)
#define IMD_Info_CANID (0x37U)
typedef struct
{

  uint16_t D_IMC_R_ISO;                     //      Bits=16.  [ 0     , 65535  ]  Unit:'Ohm'  

  uint16_t D_IMC_STATUS;                    //      Bits=16.  [ 0     , 65535  ]  Unit:''     

  uint16_t D_VIFC_STATUS;                   //      Bits=16.  [ 0     , 65535  ]  Unit:''     
} IMD_Info_t;

uint32_t Unpack_IMD_Info_Isolation(IMD_Info_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Pack_IMD_Info_Isolation(const IMD_Info_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide);

#ifdef __cplusplus
}
#endif

