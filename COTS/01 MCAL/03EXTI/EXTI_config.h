#ifndef         EXTI_CONFIG_H
#define         EXTI_CONFIG_H
/*select port : 1-PA
 *              2-PB
 *              3-PC
 */

#define   EXTI_PORT        PA
/*select sense mode :  1-RISING_EDGE
              	  	 2-FALLING_EDGE
    				 3-IOC
    				 */
#define   SENSE_MODE         FALLING_EDGE
/*select line number :  1- LIN0
 *                      2- LIN1
 *                      3- LIN3
 *                      4- LIN4
 *                      5- LIN5
 *                      6- LIN6
 *                      7- LIN7
 *                      8- LIN8
 *                      9- LIN9
 *                      10- LIN10
 *                      11- LIN11
 *                      12- LIN12
 *                      13- LIN13
 *                      14- LIN14
 *                      15- LIN15
 */
#define      LINE_NUM      LIN1
#endif
