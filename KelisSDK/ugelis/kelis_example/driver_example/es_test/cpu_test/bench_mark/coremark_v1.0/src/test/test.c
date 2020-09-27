



/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <ugelis.h>
#include <misc/printk.h>

#include<gm_hal_cpu.h>
#include"test.h"






/* Icache -> disable Dcache -> disable */
#ifdef CACHE_TEST_0
/*mark:*/
void test_cache_config()
{
    printk("HAL_ICACHE_Disable  HAL_DCACHE_Disable\n");
    HAL_ICACHE_Disable();
    HAL_DCACHE_Disable();
}
#endif

/* Icache -> enable Dcache -> disable */
#ifdef CACHE_TEST_1
void test_cache_config()
{
    printk("HAL_ICACHE_Enable  HAL_DCACHE_Disable\n");

    HAL_ICACHE_Enable();
    HAL_DCACHE_Disable();
}
#endif

/* Icache -> disable Dcache -> enable */

#ifdef CACHE_TEST_2
void test_cache_config()
{

    printk("HAL_ICACHE_Disable  HAL_DCACHE_Enable\n");

    HAL_ICACHE_Disable();
    HAL_DCACHE_Enable();
}
#endif

/* Icache -> enableDcache -> enable */

#ifdef CACHE_TEST_3
void test_cache_config()
{

    printk("HAL_DCACHE_Enable  HAL_ICACHE_Enable\n");

    HAL_DCACHE_Enable();
    HAL_ICACHE_Enable();
}
#endif


void main(void)
{

    test_cache_config();
    coremark();
}










