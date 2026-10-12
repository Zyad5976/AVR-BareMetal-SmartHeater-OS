/*
 * DIO_INTERFACE.h
 *
 * Created: 10/5/2026 12:12:45 PM
 *  Author: Eltawel
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "DIO_CFG.h"

/************************************************************************/
/* 

  this file is the interface (prototypes) for the DIO driver.

  it provides two sets of functions:

  1) pin-level functions: operate on ONE pin at a time, using the
  DIO_CFG_t struct (defined in DIO_CFG.h) to specify port, pin,
  direction and value in a single call.
  - DIO_SetPinDir, DIO_SetPinVal, DIO_TogglePin, DIO_ReadPinVal

  2) port-level functions: operate on an ENTIRE 8-bit port at once,
  useful when controlling multiple pins on the same port together
  (e.g. the 7-segment BCD lines).
  - DIO_SetPortDir, DIO_SetPortVal

  all functions return STD_RET (E_OK / E_NOK) to report success or
  failure (e.g. invalid port, invalid pin, NULL pointer).
 
                                                                     */
/************************************************************************/


/* pin functions */


/*
 *@brief:	Select the Direction(Input, Output) for the specific GPIO
 *param:	*obj_1: Pointer to the DIO Configuration Structure Containig -> Port, Pin, Dir and Val
 *@return			STD_RET: E_OK on success, E_NOK on failure (e.g. NULL pointer or invalid port/pin)
 *@note				Ensure the pointer not equal NULL before calling
*/
STD_RET DIO_SetPinDir(const DIO_CFG_t *obj);

/*
 *@brief			Select The Value(Low, High) for the specific GPIO pin
 *@param			*obj_1: Pointer to the DIO Configuration Structure Containig -> Port, Pin, Dir and Val
 *@return			STD_RET: E_OK on success, E_NOK on failure (e.g. NULL pointer or invalid port/pin)
 *@note				Ensure the pointer not equal NULL before calling
*/
STD_RET DIO_SetPinVal(const DIO_CFG_t *obj_1);

/*
 *@brief			Toggle The Value(Low, High) for the specific GPIO pin
 *@param			*obj_1: Pointer to the DIO Configuration Structure Containig -> Port, Pin, Dir and Val
 *@return			STD_RET: E_OK on success, E_NOK on failure (e.g. NULL pointer or invalid port/pin)
 *@note				Ensure the pointer not equal NULL before calling
*/
STD_RET DIO_TogglePin(const DIO_CFG_t *obj_1);

/*
 *@brief			Read The Value(Low, High) for the specific GPIO pin
 *@param			*obj_1: Pointer to the DIO Configuration Structure Containig -> Port, Pin, Dir and Val
 *@return			STD_RET: E_OK on success, E_NOK on failure (e.g. NULL pointer or invalid port/pin)
 *@note				Ensure the pointer not equal NULL before calling
*/
DIO_VAL_t DIO_ReadPinVal(const DIO_CFG_t *obj_1);


/* PORT Functions */

/**
*@brief		Select the Direction(Input, Output) for a specific GPIO Port
*@param		copy_eport: Target GPIO Port(PORT_A, PORT_B, PORT_C, PORT_D)
*@param		copy_u8dir: 8-bit value to be written on the port
*@return	none
*/
void DIO_SetPortDir(DIO_PORT_t copy_e8port, u8 copy_u8dir);

/**
*@brief		Select the Value(Low, High) for a specific GPIO Port
*@param		copy_eport: Target GPIO Port(PORT_A, PORT_B, PORT_C, PORT_D)
*@param		copy_u8dir: 8-bit direction value
*@return	none
*/
void DIO_SetPortVal(DIO_PORT_t copy_e8port, u8 copy_u8val);

#endif /* DIO_INTERFACE_H_ */