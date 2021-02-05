/**
 *
 * \brief Sprints AUTOSAR Master Class - SeatCtrlApp
 * \author Hassan Farahat
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */
 
#ifndef RTE_TYPE_H
#define RTE_TYPE_H

#include "Std_Types.h"

typedef uint8				StepMotorStepType;
typedef uint8				MultiStateBtnType;
typedef uint8				SensorPositionType;
typedef uint8				SensorWeightType;
typedef uint8				IoPositionSensorReadingType;
typedef uint32				IoWeightSensorReadingType;	/* Changed from uint16 to uint32 as Max of uint16 is 65,536 which corresponds to 65 Kg in our case */
typedef uint8				SeatModeBtnType;

#define RTE_E_OK			0U
#define RTE_E_NOK			1U

#endif