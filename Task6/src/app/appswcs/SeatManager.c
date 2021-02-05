/**
 *
 * \file SeatManger_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatManger
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 2/4/2021 03:50 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SeatManager.h"


static boolean IsMotorAdjustNeeded(SensorPositionType Position, SensorWeightType Weight, StepMotorStepType* Step)
{
	boolean AdjustMotor = FALSE;

	switch (Position)
	{
	case SENSOR_POSITION_STEP_0:
	if (Weight > 60)
	{
		*Step = MOTOR_STEP_PLUS;
		AdjustMotor = TRUE;
	}
	else
	{
		/*Do Nothing as it's best Position for People with Weight <60 */
	}
	break;
	case SENSOR_POSITION_STEP_1:
	if (Weight > 80)
	{
		*Step = MOTOR_STEP_PLUS;
		AdjustMotor = TRUE;
	}
	else if (Weight < 60)
	{
		*Step = MOTOR_STEP_MINUS;
		AdjustMotor = TRUE;
	}
	else
	{
		/*Do Nothing as it's best Position for People with 60 < Weight < 80*/
	}
	break;
	case SENSOR_POSITION_STEP_2:
	if (Weight > 100)
	{
		*Step = MOTOR_STEP_PLUS;
		AdjustMotor = TRUE;
	}
	else if (Weight < 80)
	{
		*Step = MOTOR_STEP_MINUS;
		AdjustMotor = TRUE;
	}
	else
	{
		/*Do Nothing as it's best Position for People with 80 < Weight < 100*/
	}
	break;
	case SENSOR_POSITION_STEP_3:
	if (Weight < 100)
	{
		*Step = MOTOR_STEP_MINUS;
		AdjustMotor = TRUE;
	}
	else
	{
		/*Do Nothing as it's best Position for People with Weight > 100*/
	}
	break;
	}
	return AdjustMotor;
}

/**
 *
 * Runnable SeatManager_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoHeight_200ms
 *
 */

void SeatManager_AutoHeight(void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	SensorPositionType position;
	MultiStateBtnType weight;
	boolean AdjustMotor;

	/* Server Call Points */
	status=Rte_Call_rpHeightSensor_GetPosition(&position);
	if (status == RTE_E_OK)
	{
		status = Rte_Call_rpWeightSensor_GetWeight(&weight);
		if (status == RTE_E_OK)
		{
			AdjustMotor = IsMotorAdjustNeeded(position, weight, &step);

			if (AdjustMotor)
			{
				status = Rte_Call_rpHeightMotor_Move(step);
			}
		}
	}
}


/**
 *
 * Runnable SeatManager_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoIncline_200ms
 *
 */

void SeatManager_AutoIncline(void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	SensorPositionType position;
	MultiStateBtnType weight;
	boolean AdjustMotor;

	/* Server Call Points */
	status = Rte_Call_rpInclineSensor_GetPosition(&position);
	if (status == RTE_E_OK)
	{
		status = Rte_Call_rpWeightSensor_GetWeight(&weight);
		if (status == RTE_E_OK)
		{
			AdjustMotor = IsMotorAdjustNeeded(position, weight, &step);

			if (AdjustMotor)
			{
				status = Rte_Call_rpInclineMotor_Move(step);
			}
		}
	}
}


/**
 *
 * Runnable SeatManager_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoSlide_200ms
 *
 */

void SeatManager_AutoSlide(void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	SensorPositionType position;
	MultiStateBtnType weight;
	boolean AdjustMotor;

	/* Server Call Points */
	status = Rte_Call_rpSlideSensor_GetPosition(&position);
	if (status == RTE_E_OK)
	{
		status = Rte_Call_rpWeightSensor_GetWeight(&weight);
		if (status == RTE_E_OK)
		{
			AdjustMotor = IsMotorAdjustNeeded(position, weight, &step);
			if (AdjustMotor)
			{
				status = Rte_Call_rpSlideMotor_Move(step);
			}
		}
	}
}


/**
 *
 * Runnable SeatManager_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_HeightBtnState
 *
 */

void SeatManager_SetHeight(void)
{
	Std_ReturnType status;
	MultiStateBtnType HeightBtnState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);

	if (HeightBtnState == MULTI_STATE_BTN_MINUS && status== RTE_E_OK)
	{
		status=Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS);
	}
	else if (HeightBtnState == MULTI_STATE_BTN_PLUS&& status==RTE_E_OK)
	{
		status=Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);
	}
	else
	{
		/* Do Nothing*/
	}
}


/**
 *
 * Runnable SeatManager_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_InclineBtnState
 *
 */

void SeatManager_SetIncline(void)
{
	Std_ReturnType status;
	MultiStateBtnType InclineBtnState;
	
	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);

	if (InclineBtnState == MULTI_STATE_BTN_MINUS&& status==RTE_E_OK)
	{
		status=Rte_Call_rpInclineMotor_Move(MOTOR_STEP_MINUS);
	}
	else if (InclineBtnState == MULTI_STATE_BTN_PLUS && status==RTE_E_OK)
	{
		status=Rte_Call_rpInclineMotor_Move(MOTOR_STEP_PLUS);
	}
	else
	{
		/* Do Nothing*/
	}
}


/**
 *
 * Runnable SeatManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_SlideBtnState
 *
 */

void SeatManager_SetSlide(void)
{
	Std_ReturnType status;
	MultiStateBtnType SlideBtnState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);

	if (SlideBtnState == MULTI_STATE_BTN_MINUS && status==RTE_E_OK)
	{
		status=Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS);
	}
	else if (SlideBtnState == MULTI_STATE_BTN_PLUS && status==RTE_E_OK)
	{
		status=Rte_Call_rpSlideMotor_Move(MOTOR_STEP_PLUS);
	}
	else
	{
		/* Do Nothing*/
	}
}