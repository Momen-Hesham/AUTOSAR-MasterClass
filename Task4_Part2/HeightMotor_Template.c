/**
 *
 * \file HeightMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HeightMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 2/4/2021 05:27 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HeightMotor.h"


/**
 *
 * Runnable HeightMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHeightMotor_Move
 *
 */

void HeightMotor_Move (StepMotorStepType Step)
{
	Std_ReturnType status;

	/* Server Call Points */
	
	if (Step == MOTOR_STEP_PLUS)
	{
		status = Rte_Call_rpIOSetHeight_IOSetForward();
	}
	else if (Step == MOTOR_STEP_MINUS)
	{
		status = Rte_Call_rpIOSetHeight_IOSetReverse();
	}
	else
	{
		/* Do Nothing*/
	}
}

