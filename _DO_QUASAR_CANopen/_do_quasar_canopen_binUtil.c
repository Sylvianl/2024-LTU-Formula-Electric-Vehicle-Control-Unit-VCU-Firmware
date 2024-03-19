
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#include "_do_quasar_canopen_binUtil.h"

#ifdef __DEF__DO_QUASAR_CANOPEN__

_DO_QUASAR_CANopen_rx_t _DO_QUASAR_CANopen_rx;

#endif

uint32_t _DO_QUASAR_CANopen_Receive(_DO_QUASAR_CANopen_rx_t* _m, const uint8_t* _d, uint32_t _id, uint8_t dlc_)
{
 uint32_t recid = 0;
 if (_id >= 0x0U && _id < 0x3FAU) {
  if (_id >= 0x0U && _id < 0x23AU) {
   if (_id >= 0x0U && _id < 0x1BAU) {
    if (_id == 0x0U) {
     recid = Unpack_ECU_NMT_command__DO_QUASAR_CANopen(&(_m->ECU_NMT_command), _d, dlc_);
    } else if (_id == 0x80U) {
     recid = Unpack_ECU_SYNC__DO_QUASAR_CANopen(&(_m->ECU_SYNC), _d, dlc_);
    }
   } else {
    if (_id == 0x1BAU) {
     recid = Unpack_EMD_TxPDO_5__DO_QUASAR_CANopen(&(_m->EMD_TxPDO_5), _d, dlc_);
    } else if (_id == 0x1FAU) {
     recid = Unpack_EMD_TxPDO_1__DO_QUASAR_CANopen(&(_m->EMD_TxPDO_1), _d, dlc_);
    }
   }
  } else {
   if (_id >= 0x23AU && _id < 0x2FAU) {
    if (_id == 0x23AU) {
     recid = Unpack_EMD_RxPDO_5__DO_QUASAR_CANopen(&(_m->EMD_RxPDO_5), _d, dlc_);
    } else if (_id == 0x27AU) {
     recid = Unpack_EMD_RxPDO_1__DO_QUASAR_CANopen(&(_m->EMD_RxPDO_1), _d, dlc_);
    }
   } else {
    if (_id == 0x2FAU) {
     recid = Unpack_EMD_TxPDO_2__DO_QUASAR_CANopen(&(_m->EMD_TxPDO_2), _d, dlc_);
    } else if (_id == 0x37AU) {
     recid = Unpack_EMD_RxPDO_2__DO_QUASAR_CANopen(&(_m->EMD_RxPDO_2), _d, dlc_);
    }
   }
  }
 } else {
  if (_id >= 0x3FAU && _id < 0x5FAU) {
   if (_id >= 0x3FAU && _id < 0x4FAU) {
    if (_id == 0x3FAU) {
     recid = Unpack_EMD_TxPDO_3__DO_QUASAR_CANopen(&(_m->EMD_TxPDO_3), _d, dlc_);
    } else if (_id == 0x47AU) {
     recid = Unpack_EMD_RxPDO_3__DO_QUASAR_CANopen(&(_m->EMD_RxPDO_3), _d, dlc_);
    }
   } else {
    if (_id == 0x4FAU) {
     recid = Unpack_EMD_TxPDO_4__DO_QUASAR_CANopen(&(_m->EMD_TxPDO_4), _d, dlc_);
    } else if (_id == 0x57AU) {
     recid = Unpack_EMD_RxPDO_4__DO_QUASAR_CANopen(&(_m->EMD_RxPDO_4), _d, dlc_);
    }
   }
  } else {
   if (_id >= 0x5FAU && _id < 0x701U) {
    if (_id == 0x5FAU) {
     recid = Unpack_EMD_TxSDO__DO_QUASAR_CANopen(&(_m->EMD_TxSDO), _d, dlc_);
    } else if (_id == 0x67AU) {
     recid = Unpack_EMD_RxSDO__DO_QUASAR_CANopen(&(_m->EMD_RxSDO), _d, dlc_);
    }
   } else {
    if (_id == 0x701U) {
     recid = Unpack_ECU_NMT_heart_beat__DO_QUASAR_CANopen(&(_m->ECU_NMT_heart_beat), _d, dlc_);
    } else if (_id == 0x77AU) {
     recid = Unpack_ECU_EMD_NMT_node_guarding__DO_QUASAR_CANopen(&(_m->ECU_EMD_NMT_node_guarding), _d, dlc_);
    }
   }
  }
 }

 return recid;
}

