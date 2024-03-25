/*
 * CAN.h
 *
 *  Created on: Mar 17, 2024
 *      Author: kmehta
 */

#ifndef INC_CAN_H_
#define INC_CAN_H_

#include "main.h"
#include "stm32f7xx_hal.h"
#include "_do_quasar_canopen.h"
#include "isolation.h"
#include "temp.h"

extern CAN_HandleTypeDef hcan1;

#define CAN_HIGH_PRIORITY_FIFO CAN_FILTER_FIFO1
#define CAN_LOW_PRIORITY_FIFO CAN_FilterFIFO0

void initializeCAN(CAN_HandleTypeDef* hcan);
void nodeGuarding(CAN_HandleTypeDef* hcan);
void startNode(CAN_HandleTypeDef* hcan);
void clearErrors(CAN_HandleTypeDef* hcan);
void torqueControlMessage(CAN_HandleTypeDef* hcan, int _speedRefLimit, int* _torqueRefLimit);
void configCANFilters(CAN_HandleTypeDef* hcan);

#endif /* INC_CAN_H_ */
