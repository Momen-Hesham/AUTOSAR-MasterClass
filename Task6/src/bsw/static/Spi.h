/**
 *
 * \brief Sprints AUTOSAR Master Class - SeatCtrlApp
 * \author Hassan Farahat
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */
 
#ifndef SPI_H
#define SPI_H

#include "Std_Types.h"
#include "Spi_Cfg.h"

typedef uint8				Spi_ChannelType;
typedef uint32 				Spi_DataType;	/* Changed from uint16 to uint32 as it corresponds to weight 
											which in case of uint16 will have Max of uint16 is 65,536 which corresponds to 65 Kg in our case */

extern Std_ReturnType Spi_ReadIB(Spi_ChannelType Channel, Spi_DataType* DataBufferPtr);

#endif