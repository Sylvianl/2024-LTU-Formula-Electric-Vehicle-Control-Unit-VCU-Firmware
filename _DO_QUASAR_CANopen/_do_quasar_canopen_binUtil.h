
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#pragma once


#ifdef __cplusplus
extern "C" {
#endif

#include "_do_quasar_canopen.h"

// @dbccodeconf.h file should be placed in inc folder. If the user wants
// to allocate big DBC struct inside the driver - appropriate define (__DEF_xxxxx__)
// should be placed in this file
#include "dbccodeconf.h"

typedef struct
{
  ECU_NMT_command_t ECU_NMT_command;                       // TX [ECU].     RX [].
  ECU_SYNC_t ECU_SYNC;                                     // TX [ECU].     RX [EMD ].
  EMD_TxPDO_5_t EMD_TxPDO_5;                               // TX [EMD].     RX [ECU ].
  EMD_TxPDO_1_t EMD_TxPDO_1;                               // TX [EMD].     RX [ECU ].
  EMD_RxPDO_5_t EMD_RxPDO_5;                               // TX [ECU].     RX [EMD ].
  EMD_RxPDO_1_t EMD_RxPDO_1;                               // TX [ECU].     RX [EMD ].
  EMD_TxPDO_2_t EMD_TxPDO_2;                               // TX [EMD].     RX [ECU ].
  EMD_RxPDO_2_t EMD_RxPDO_2;                               // TX [ECU].     RX [EMD ].
  EMD_TxPDO_3_t EMD_TxPDO_3;                               // TX [EMD].     RX [ECU ].
  EMD_RxPDO_3_t EMD_RxPDO_3;                               // TX [ECU].     RX [EMD ].
  EMD_TxPDO_4_t EMD_TxPDO_4;                               // TX [EMD].     RX [ECU ].
  EMD_RxPDO_4_t EMD_RxPDO_4;                               // TX [ECU].     RX [EMD ].
  EMD_TxSDO_t EMD_TxSDO;                                   // TX [EMD].     RX [ECU ].
  EMD_RxSDO_t EMD_RxSDO;                                   // TX [ECU].     RX [EMD ].
  ECU_NMT_heart_beat_t ECU_NMT_heart_beat;                 // TX [ECU].     RX [EMD ].
  ECU_EMD_NMT_node_guarding_t ECU_EMD_NMT_node_guarding;   // TX [EMD].     RX [ECU ].
} _DO_QUASAR_CANopen_rx_t;

// There is no any message detected with tx direction.

uint32_t _DO_QUASAR_CANopen_Receive(_DO_QUASAR_CANopen_rx_t* _m, const uint8_t* _d, uint32_t _id, uint8_t dlc_);


// define @__DEF__DO_QUASAR_CANOPEN__ in the @dbccodeconf.h file for allocation in utility source code.
#ifdef __DEF__DO_QUASAR_CANOPEN__

extern _DO_QUASAR_CANopen_rx_t _DO_QUASAR_CANopen_rx;

#endif


#ifdef __cplusplus
}
#endif

