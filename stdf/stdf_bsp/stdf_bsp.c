/*******************************************************************************
  Filename:       .

  Version         V1.0.

  Author          Yuping.Mo.

  Description:    .


  IMPORTANT:      .

*******************************************************************************/

/*******************************************************************************
 * INCLUDES
 */
#include "stdf_define.h" 
#include "stdf_bsp.h"
#ifdef __STDF_EXTERNAL_CHAGER_ENABLE__
#include "stdf_bsp_charger.h"
#endif
#include "stdf_bsp_key.h"

/*******************************************************************************
 * MACROS
 */
#define STDF_BSP_LOG(str, ...)              STDF_LOG("[BSP] %s "str, __func__, ##__VA_ARGS__)
#define STDF_BSP_ASSERT(cond)               STDF_ASSERT(cond)

/*******************************************************************************
 * TYPEDEFS
 */

/*******************************************************************************
* GLOBAL VARIABLES
*/

/*******************************************************************************
 * EXTERNAL VARIABLES
 */

/*******************************************************************************
 * FUNCTIONS
 */

/*******************************************************************************
 * @fn      .
 * @brief   .
 * @param   .
 * @return  .
 * @notice  .
 */
void stdf_bsp_init(void)
{
#ifdef __STDF_EXTERNAL_CHAGER_ENABLE__
    stdf_bsp_charger_init();
#endif
    
    stdf_bsp_key_init();
}

/*******************************************************************************
*******************************************************************************/

