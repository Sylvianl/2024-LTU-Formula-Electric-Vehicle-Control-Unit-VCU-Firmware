
/*
 * CAN.c
 *
 *  Created on: Mar 17, 2024
 *      Author: kmehta
 */

#include "CAN.h"

void initializeCAN(CAN_HandleTypeDef* hcan)
{
	if (HAL_CAN_Start(hcan) != HAL_OK)
	{
		Error_Handler();
	}

	configTempSenseCANFilter(hcan);

	if (HAL_CAN_ActivateNotification(hcan, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)
	{
		Error_Handler();
	}
}

void nodeGuarding(CAN_HandleTypeDef* hcan)
{
	CAN_TxHeaderTypeDef txHeader;
	uint8_t data[1] = { (0x00U) };
	uint32_t mailbox;

	txHeader.DLC = ECU_EMD_NMT_node_guarding_DLC;
	txHeader.ExtId = DISABLE;
	txHeader.IDE = CAN_ID_STD;
	txHeader.RTR = CAN_RTR_REMOTE;
	txHeader.StdId = ECU_EMD_NMT_node_guarding_CANID;
	txHeader.TransmitGlobalTime = DISABLE;

	if (HAL_CAN_AddTxMessage(hcan, &txHeader, data, &mailbox) != HAL_OK)
	{
		Error_Handler();
	}

	while (HAL_CAN_IsTxMessagePending(hcan, mailbox));

	return;
}

void startNode(CAN_HandleTypeDef* hcan)
{
	CAN_TxHeaderTypeDef txHeader;
	uint8_t data[8] = { (0x00U), (0x00U), (0x00U), (0x00U), (0x00U), (0x00U), (0x00U), (0x00U) };
	uint32_t mailbox;
	ECU_NMT_command_t nmt_t;
	uint8_t len, ide;

	nmt_t.ECU_NMT_CommandSpecifier = (0x01U);
	nmt_t.ECU_NMT_NodeId = (0x7AU);

	Pack_ECU_NMT_command__DO_QUASAR_CANopen(&nmt_t, data, &len, &ide);

	txHeader.DLC = ECU_NMT_command_DLC;
	txHeader.ExtId = DISABLE;
	txHeader.IDE = ide;
	txHeader.RTR = CAN_RTR_DATA;
	txHeader.StdId = ECU_NMT_command_CANID;
	txHeader.TransmitGlobalTime = DISABLE;

	if (HAL_CAN_AddTxMessage(hcan, &txHeader, data, &mailbox) != HAL_OK)
	{
		Error_Handler();
	}

	while (HAL_CAN_IsTxMessagePending(hcan, mailbox));

	return;
}

void clearErrors(CAN_HandleTypeDef* hcan)
{
	CAN_TxHeaderTypeDef txHeader;
	uint8_t data[8] = { (0x00U), (0x00U), (0x00U), (0x00U), (0x00U), (0x00U), (0x00U), (0x00U) };
	uint32_t mailbox;
	EMD_RxPDO_3_t rxPDO3_t;
	uint8_t len, ide;

	rxPDO3_t.EMD_CMD_ActiveDischarge = 0;
	rxPDO3_t.EMD_CMD_ClearErrors = (0x01U);
	rxPDO3_t.EMD_CMD_ControlMode = 0;
	rxPDO3_t.EMD_CMD_DigitalOutput1 = 0;
	rxPDO3_t.EMD_CMD_DigitalOutput2 = 0;
	rxPDO3_t.EMD_CMD_LimitationMode = 0;
	rxPDO3_t.EMD_CMD_RestartRequest = 0;
	rxPDO3_t.EMD_CMD_SpeedRefLim = 0;
	rxPDO3_t.EMD_CMD_SpeedRefLim_VAL = 0;
	rxPDO3_t.EMD_CMD_TorqueRefLim = 0;
	rxPDO3_t.EMD_CMD_TorqueRefLim_VAL = 0;
	rxPDO3_t.EMD_MSGCNT_RxPDO3 = 0;

	Pack_EMD_RxPDO_3__DO_QUASAR_CANopen(&rxPDO3_t, data, &len, &ide);

	txHeader.DLC = len;
	txHeader.ExtId = DISABLE;
	txHeader.IDE = ide;
	txHeader.RTR = CAN_RTR_DATA;
	txHeader.StdId = EMD_RxPDO_3_CANID;
	txHeader.TransmitGlobalTime = DISABLE;

	if (HAL_CAN_AddTxMessage(hcan, &txHeader, data, &mailbox) != HAL_OK)
	{
		Error_Handler();
	}

	while (HAL_CAN_IsTxMessagePending(hcan, mailbox));

	return;
}

void torqueControlMessage(CAN_HandleTypeDef* hcan, int _speedRefLimit, int* _torqueRefLimit)
{
	CAN_TxHeaderTypeDef txHeader;
	uint8_t data[8] = { (0x00U), (0x00U), (0x00U), (0x00U), (0x00U), (0x00U), (0x00U), (0x00U) };
	uint32_t mailbox;
	EMD_RxPDO_3_t rxPDO3_t;
	uint8_t len, ide;

	rxPDO3_t.EMD_CMD_ActiveDischarge = 0;
	rxPDO3_t.EMD_CMD_ClearErrors = 0;
	rxPDO3_t.EMD_CMD_ControlMode = (0x01U);
	rxPDO3_t.EMD_CMD_DigitalOutput1 = 0;
	rxPDO3_t.EMD_CMD_DigitalOutput2 = 0;
	rxPDO3_t.EMD_CMD_LimitationMode = 0;
	rxPDO3_t.EMD_CMD_RestartRequest = 0;
	rxPDO3_t.EMD_CMD_SpeedRefLim = _speedRefLimit;
	rxPDO3_t.EMD_CMD_SpeedRefLim_VAL = 0;
	rxPDO3_t.EMD_CMD_TorqueRefLim = *_torqueRefLimit;
	rxPDO3_t.EMD_CMD_TorqueRefLim_VAL = 0;
	rxPDO3_t.EMD_MSGCNT_RxPDO3 = 0;

	Pack_EMD_RxPDO_3__DO_QUASAR_CANopen(&rxPDO3_t, data, &len, &ide);

	txHeader.DLC = EMD_RxPDO_3_DLC;
	txHeader.ExtId = DISABLE;
	txHeader.IDE = ide;
	txHeader.RTR = CAN_RTR_DATA;
	txHeader.StdId = EMD_RxPDO_3_CANID;
	txHeader.TransmitGlobalTime = DISABLE;

	if (HAL_CAN_AddTxMessage(hcan, &txHeader, data, &mailbox) != HAL_OK)
	{
		Error_Handler();
	}

	while (HAL_CAN_IsTxMessagePending(hcan, mailbox));

	return;
}

void configTempSenseCANFilter(CAN_HandleTypeDef* hcan)
{
	CAN_FilterTypeDef filter;

	filter.FilterActivation = CAN_FILTER_ENABLE;
	filter.FilterBank = 0;
	filter.FilterFIFOAssignment = CAN_LOW_PRIORITY_FIFO;
	filter.FilterIdHigh = ((0x301U)<<5);
	filter.FilterIdLow = (0x000U);
	filter.FilterMaskIdHigh = ((0x301U)<<5);
	filter.FilterMaskIdLow = (0x000U);
	filter.FilterMode = CAN_FILTERMODE_IDMASK;
	filter.FilterScale = CAN_FILTERSCALE_32BIT;
	filter.SlaveStartFilterBank = 14;

	if (HAL_CAN_ConfigFilter(hcan, &filter) != HAL_OK)
	{
		Error_Handler();
	}
}
