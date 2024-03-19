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

extern CAN_HandleTypeDef hcan1;

void nodeGuarding(void);
void startNode(void);
void clearErrors(void);
void torqueControlMessage(int _speedRefLimit, int* _torqueRefLimit);

#endif /* INC_CAN_H_ */
