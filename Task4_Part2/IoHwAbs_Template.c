/**
 *
 * \file IoHwAbs_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: IoHwAbs
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 2/4/2021 05:27 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_IoHwAbs.h"

/* Used to get the Reading of Position Sensors*/
#include "Adc.h"
/* Used to get the Readings of the Weight Sensor*/
#include "Spi.h"
/* Used to Supply the Step Value to Motors*/
#include "Dio.h"


/* Global Variable to Save Poistion Values: Height, Incline, Slide */
static Adc_ValueGroupType IoHwAb_PositionSensorReadings[ADC_GR0_NUM_CHANNELS] = { 0,0,0 };

/**
 *
 * Runnable IoHwAbs_ECUGet_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetHeight_IOGet
 *
 */

void IoHwAbs_ECUGet_Height (IoPositionSensorReadingType* position)
{
	Std_ReturnType status;
	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsGrp, IoHwAb_PositionSensorsReadings);
	if (status==E_OK)
	{
		position = (IoPosiyionSensorReadingType)IoHwAb_PositionSesnsorsReadings[0];
	}
	else
	{
		/* Status != E_OK , So there is an error occured and shpuld be handeled*/
	}
}


/**
 *
 * Runnable IoHwAbs_ECUGet_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetIncline_IOGet
 *
 */

void IoHwAbs_ECUGet_Incline (IoPositionSensorReadingType* position)
{
	Std_ReturnType status;
	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsGrp, IoHwAb_PositionSensorsReadings);
	if (status == E_OK)
	{
		position = (IoPosiyionSensorReadingType)IoHwAb_PositionSesnsorsReadings[1];
	}
	else
	{
		/* Status != E_OK , So there is an error occured and shpuld be handeled*/
	}
}


/**
 *
 * Runnable IoHwAbs_ECUGet_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetSlide_IOGet
 *
 */

void IoHwAbs_ECUGet_Slide (IoPositionSensorReadingType* position)
{
	Std_ReturnType status;
	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsGrp, IoHwAb_PositionSensorsReadings);
	if (status == E_OK)
	{
		position = (IoPosiyionSensorReadingType)IoHwAb_PositionSesnsorsReadings[2];
	}
	else
	{
		/* Status != E_OK , So there is an error occured and shpuld be handeled*/
	}
}


/**
 *
 * Runnable IoHwAbs_ECUGet_Weight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetWeight_IOGet
 *
 */

void IoHwAbs_ECUGet_Weight (IoWeightSensorReadingType* weight)
{
	Std_ReturnType status;
	Spi_DataType spiData;

	status = Spi_ReadIB(SpiConf_SpiChannel_WeightSensor, &spiData);
	if (status == E_OK)
	{
		weight = (IoWeightSensorReadingType)spiData;
	}
	else
	{
		/* Status != E_OK , So there is an error occured and shpuld be handeled*/
	}
}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_IOSetForward
 *
 */

void IoHwAbs_ECUSetForward_Height (void)
{
	Std_ReturnType status;
	status = Dio_WriteChannel(DioConfg_DioChannel_HeightMotorCh, STD_HIGH);
}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetIncline_IOSetForward
 *
 */

void IoHwAbs_ECUSetForward_Incline (void)
{
	Std_ReturnType status;
	status= Dio_WriteChannel(DioConfg_DioChannel_InclineMotorCh, STD_HIGH);
}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_IOSetForward
 *
 */

void IoHwAbs_ECUSetForward_Slide (void)
{
	Std_ReturnType status;
	status = Dio_WriteChannel(DioConfg_DioChannel_SlideMotorCh, STD_HIGH);
}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_IOSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Height (void)
{
	Std_ReturnType status;
	status = Dio_WriteChannel(DioConfg_DioChannel_HeightMotorCh, STD_LOW);
}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetIncline_IOSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Incline (void)
{
	Std_ReturnType status;
	status = Dio_WriteChannel(DioConfg_DioChannel_InclineMotorCh, STD_LOW);
}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_IOSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Slide (void)
{
	Std_ReturnType status;
	status = Dio_WriteChannel(DioConfg_DioChannel_SlideMotorCh, STD_LOW);
}

