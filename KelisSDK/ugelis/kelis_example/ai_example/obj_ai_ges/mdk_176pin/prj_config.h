#ifndef _PRJ_CONFIG_H_
#define _PRJ_CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 *platform select
 *#########################################
 *!!!you must be sure only open one
 *!!!!plafrom marco and close the others
 *########################################
 */
//#define  F6721B_EVB_144PIN 1
#define  F6721B_EVB_176PIN 1
//#define  F6721B_EVB_QFN40PIN 1
//#define  F6721B_EVB_QFN80PIN 1

//#define  GM6721_EVB_QFN40PIN
//#define  GM6721_EVB_QFN80PIN
//#define  GM6721_EVB_144PIN
//#define  GM6721_EVB_176PIN

#define  CHIP_F6721B
//#define QFN80_SORTING_BOARD //open when use sorting board, default is demo board
//#define  LQFP176_DEMO_BOARD
/**
 *feature for your project
 */
#define CONFIG_CONSOLE    1

#define CONFIG_SFLASH     1


/*Kernel Configurtion*/
#define CONFIG_POLL

/*Subsystem: USB Host Stack Configuration*/

/*Subsystem: Console Shell*/
#define CONFIG_SHELL


/*Driver Configuration*/
#define CONFIG_OV5640
#define CONFIG_DISPLAY

#ifdef __cplusplus
}
#endif

#endif /* _PRJ_CONFIG_H_ */
