/**
 *
 * \file SeatManger_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatManger
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 1/26/2021 12:02 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SeatManger.h"


/**
 *
 * Runnable SeatManager_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_HeightBtnState
 *
 */

void SeatManager_SetHeight (void)
{
	Std_ReturnType status;
	MultiStateBtnType HeightBtnState;
	StepMotorStepType step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);
	
	if (HeightBtnState == MULTI_STATE_BTN_MINUS)
	{
		step = MOTOR_STEP_MINUS;
	}
	else if (HeightBtnState == MULTI_STATE_BTN_PLUS)
	{
		step = MOTOR_STEP_PLUS;
	}

	/* Server Call Points */
	status = Rte_Call_rpHeightMotor_Move(step);
		
}


/**
 *
 * Runnable SeatManager_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_InclineBtnState
 *
 */

void SeatManager_SetIncline (void)
{
	Std_ReturnType status;
	MultiStateBtnType InclineBtnState;
	StepMotorStepType step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);
	
	if (InclineBtnState == MULTI_STATE_BTN_MINUS)
	{
		step = MOTOR_STEP_MINUS;
	}
	else if (InclineBtnState == MULTI_STATE_BTN_PLUS)
	{
		step = MOTOR_STEP_PLUS;
	}

	/* Server Call Points */
	status = Rte_Call_rpInclineMotor_Move(step);
	
}


/**
 *
 * Runnable SeatManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_SlideBtnState
 *
 */

void SeatManager_SetSlide (void)
{
	Std_ReturnType status;
	MultiStateBtnType SlideBtnState;
	StepMotorStepType step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);
	
	if (SlideBtnState == MULTI_STATE_BTN_MINUS)
	{
		step = MOTOR_STEP_MINUS;
	}
	else if (SlideBtnState == MULTI_STATE_BTN_PLUS)
	{
		step = MOTOR_STEP_PLUS;
	}

	/* Server Call Points */
	status = Rte_Call_rpSlideMotor_Move(step);
	
}

