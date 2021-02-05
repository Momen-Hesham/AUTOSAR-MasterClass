/**
 *
 * \file HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 2/4/2021 09:53 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HMI.h"


/**
 *
 * Runnable HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_HMI_MainFunction_100ms
 *
 */

void HMI_MainFunction(void)
{
	Std_ReturnType status;
	MultiStateBtnType HeightBtnState;
	MultiStateBtnType InclineBtnState;
	MultiStateBtnType SlideBtnState;
	uint8 Height;
	uint8 Incline;
	uint8 Slide;
	boolean UpdateStatus;

	UpdateStatus = Rte_IsUpdated_HMI_rpSeatCtrlData_Height();
	status = Rte_Read_rpSeatCtrlData_Height(&Height);
	if (status == RTE_E_OK && UpdateStatus == TRUE)
	{
		switch (Height)
		{
		case 1:
			HeightBtnState = MULTI_STATE_BTN_MINUS;
			break;
		case 2:
			HeightBtnState = MULTI_STATE_BTN_PLUS;
			break;
		default:
			HeightBtnState = MULTI_STATE_BTN_INIT;
			break;
		}
		(void)Rte_Write_ppSeatCtrlBtns_HeightBtnState(HeightBtnState);
	}

	UpdateStatus = Rte_IsUpdated_HMI_rpSeatCtrlData_Slide();
	status = Rte_Read_rpSeatCtrlData_Slide(&Slide);
	if (status == RTE_E_OK && UpdateStatus == TRUE)
	{
		switch (Slide)
		{
		case 1:
			SlideBtnState = MULTI_STATE_BTN_MINUS;
			break;
		case 2:
			SlideBtnState = MULTI_STATE_BTN_PLUS;
			break;
		default:
			SlideBtnState = MULTI_STATE_BTN_INIT;
			break;
		}
		(void)Rte_Write_ppSeatCtrlBtns_SlideBtnState(SlideBtnState);
	}

	UpdateStatus = Rte_IsUpdated_HMI_rpSeatCtrlData_Incline();
	status = Rte_Read_rpSeatCtrlData_Incline(&Incline);
	if (status == RTE_E_OK && UpdateStatus == TRUE)
	{
		switch (Incline)
		{
		case 1:
			InclineBtnState = MULTI_STATE_BTN_MINUS;
			break;
		case 2:
			InclineBtnState = MULTI_STATE_BTN_PLUS;
			break;
		default:
			InclineBtnState = MULTI_STATE_BTN_INIT;
			break;
		}
		(void)Rte_Write_ppSeatCtrlBtns_InclineBtnState(InclineBtnState);
	}
}

/**
 *
 * Runnable HMI_SeatModeChanged
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatModeBtn_SeatModeBtn
 *
 */

void HMI_SeatModeChanged(void)
{
	Std_ReturnType status;
	SeatModeBtnType SeatModeBtn;
	uint8 SeatCtrlMode = RTE_MODE_SeatCtrlMode_INIT;

	/* Data Receive Points */
	status = Rte_Read_rpSeatModeBtn_SeatModeBtn(&SeatModeBtn);

	if (SeatModeBtn == SEAT_MODE_BTN_MANUAL && status==RTE_E_OK)
	{
		SeatCtrlMode = RTE_MODE_SeatCtrlMode_MANUAL;
	}
	else if (SeatModeBtn == SEAT_MODE_BTN_AUTO && status == RTE_E_OK)
	{
		SeatCtrlMode = RTE_MODE_SeatCtrlMode_AUTO;
	}
	else
	{
		/* Do Nothing*/
	}

	/* Mode Switch Points */
	status = Rte_Switch_ppSeatCtrlMode_SeatCtrlMode(SeatCtrlMode);
	
}

