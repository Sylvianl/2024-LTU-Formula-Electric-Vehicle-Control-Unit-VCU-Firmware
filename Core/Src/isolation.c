
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#include "isolation.h"

// --------------------------------------------------------------------------
uint32_t Unpack_IMD_Info_Isolation(IMD_Info_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->D_IMC_R_ISO = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->D_IMC_STATUS = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
  _m->D_VIFC_STATUS = ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return IMD_Info_CANID;
}

uint32_t Pack_IMD_Info_Isolation(const IMD_Info_t* _m, uint8_t* _d, uint8_t* _len, uint8_t* _ide)
{
  uint8_t i; for (i = 0; i < IMD_Info_DLC; _d[i++] = 0);

  _d[0] |= (_m->D_IMC_R_ISO & (0xFFU));
  _d[1] |= ((_m->D_IMC_R_ISO >> 8) & (0xFFU));
  _d[2] |= (_m->D_IMC_STATUS & (0xFFU));
  _d[3] |= ((_m->D_IMC_STATUS >> 8) & (0xFFU));
  _d[4] |= (_m->D_VIFC_STATUS & (0xFFU));
  _d[5] |= ((_m->D_VIFC_STATUS >> 8) & (0xFFU));
  *_len = 8; *_ide = 0;
  return IMD_Info_CANID;
}

