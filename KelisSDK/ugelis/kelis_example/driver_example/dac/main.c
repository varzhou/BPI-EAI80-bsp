/**
*
* Copyright (C) 2019 Gree Edgeless Microelectronics. All Rights Reserved.
*
* @file        main.c
*
* @author      Richard.Liu
*
* @version     v1.0.0
*
* @date        2019/01/24
*
* @brief       dac demo source file
*
* @note
*              2019/01/24, Richard.Liu, v1.0.0
*                  Initial version.
*
**/

#include <ugelis.h>
#include <device.h>
#include "board.h"
#include <gm_hal_gpio.h>
#include <gm_hal_dac.h>
#include <dac.h>
#ifndef TC_PASS
    #define TC_PASS 0
#endif
#define CONFIG_DAC_0_NAME "DAC_0"
DAC_Handle_T dac_handle;

#define DEBUG_PRINTF
#define WARNING_PRINTF
#define ERR_PRINTF

#ifndef DEBUG_PRINTF
    #define PR_DEBUG(...)       do{}while(0)
#else
    #define PR_DEBUG            printk
#endif

#ifndef ERR_PRINTF
    #define PR_ERR(...)        do{}while(0)
#else
    #define PR_ERR             printk
#endif

#ifndef WARNING_PRINTF
    #define PR_WARNINR(...)    do{}while(0)
#else
    #define PR_WARNINR         printk
#endif


int dac_demo(struct dac_config_data *cfg)
{
    struct device *dac_dev0;
    struct device *dac_dev1;
    /*unsigned int dac_out = 0;*/
    /*struct dac_config_data dac_data;*/

    PR_DEBUG("================Enter func[%s] Test====dac%d=============\n", __FUNCTION__, cfg->config_data.dacSel);

    if (cfg->config_data.dacSel == DAC0_SEL)
    {
        dac_dev0 = device_get_binding(CONFIG_DAC_0_NAME);
        if (dac_dev0 == NULL)
        {
            printk("Failed to get dac0 device.");
            return -EINVAL;
        }

        dac_config(dac_dev0, cfg);
        dac_enable(dac_dev0);
        dac_triger(dac_dev0, cfg);
        dac_read(dac_dev0, cfg);
    }
#if defined(CHIP_GM6721)
    else if (cfg->config_data.dacSel == DAC1_SEL)
    {
        dac_dev1 = device_get_binding(CONFIG_DAC_1_NAME);
        if (dac_dev1 == NULL)
        {
            printk("Failed to get dac1 device.");
            return -EINVAL;
        }
        dac_config(dac_dev1, cfg);
        dac_enable(dac_dev1);
        dac_triger(dac_dev1, cfg);
        dac_read(dac_dev1, cfg);
    }
    else if (cfg->config_data.dacSel == DAC_DUAL)
    {
        dac_dev0 = device_get_binding(CONFIG_DAC_0_NAME);
        dac_dev1 = device_get_binding(CONFIG_DAC_1_NAME);
        if (dac_dev0 == NULL)
        {
            printk("Failed to get dac0 device.");
            return -EINVAL;
        }
        if (dac_dev1 == NULL)
        {
            printk("Failed to get dac1 device.");
            return -EINVAL;
        }

        dac_config(dac_dev0, cfg);
        dac_enable(dac_dev0);
        dac_triger(dac_dev0, cfg);
        dac_read(dac_dev0, cfg);

        /*PR_DEBUG("Func[%s]: dac_out0 = [0x%x], dacSel = %d\n",__FUNCTION__,dac_out, cfg->config_data.dacSel);*/

        dac_config(dac_dev1, cfg);
        dac_enable(dac_dev1);
        dac_triger(dac_dev1, cfg);
        dac_read(dac_dev1, cfg);
        /*PR_DEBUG("Func[%s]: dac_out1 = [0x%x], dacSel = %d\n",__FUNCTION__,dac_out, cfg->config_data.dacSel);*/
    }
#endif
    PR_DEBUG("================Enter func[%s] Test====dac%d=============\n", __FUNCTION__, cfg->config_data.dacSel);

    return cfg->dac_data_out;
}


struct dac_config_data config;

int demo(int dac_select)
{
    int dac_out = 0;

    if (dac_select == DAC0_SEL)
    {
        config.config_data.dacSel = DAC0_SEL;
        config.config_data.dacEn = ENABLE;
        config.config_data.samholdEn = DISABLE;
        config.config_data.waveType = DAC_WAVE_DISABLE;
        config.config_data.msAM = 0;
        config.config_data.dacDMAEn = DISABLE;
        config.config_data.resolution = DAC_DATA_MODE_12BIT;
        config.config_data.dacSoftTrigleEn = ENABLE;
        config.config_data.dacComConfig.dacHoldData = 0x7FF;
        config.config_data.dacComConfig.dacHoldSampTime = 0;
        config.config_data.dacComConfig.dacHoldTime = 0;
        config.config_data.dacComConfig.dacHoldRefTime = 0;
        config.config_data.dacComConfig.dacDAC1DualHoldData = 0;
        config.config_data.dacComConfig.dacDAC0DualHoldData = 0;
        config.config_data.triggerMode = DAC_SINGLE_SOFT_TRIG;
        dac_out = dac_demo(&config);

        PR_DEBUG("Func[%s]: dac_out = [0x%x], dacSel = %d\n", __FUNCTION__, dac_out, config.config_data.dacSel);
    }
#if defined(CHIP_GM6721)
    else if (dac_select == DAC1_SEL)
    {
#ifdef CONFIG_SRAM_ONLY_APP
        config.config_data.dacSel = DAC1_SEL;
        config.config_data.dacEn = ENABLE;
        config.config_data.samholdEn = DISABLE;
        config.config_data.waveType = DAC_WAVE_DISABLE;
        config.config_data.msAM = 0;
        config.config_data.dacDMAEn = DISABLE;
        config.config_data.resolution = DAC_DATA_MODE_12BIT;
        config.config_data.dacSoftTrigleEn = ENABLE;
        config.config_data.dacComConfig.dacHoldData = 0xFFF;
        config.config_data.dacComConfig.dacHoldSampTime = 0;
        config.config_data.dacComConfig.dacHoldTime = 0;
        config.config_data.dacComConfig.dacHoldRefTime = 0;
        config.config_data.dacComConfig.dacDAC1DualHoldData = 0xA;
        config.config_data.dacComConfig.dacDAC0DualHoldData = 0xB;
        config.config_data.triggerMode = DAC_SINGLE_SOFT_TRIG;
        dac_out = dac_demo(&config);
        PR_DEBUG("Func[%s]: dac_out = [0x%x], dacSel = %d\n", __FUNCTION__, dac_out, config.config_data.dacSel);
#endif
    }
    else if (dac_select == DAC_DUAL)
    {
#ifdef CONFIG_SRAM_ONLY_APP
        config.config_data.dacSel = DAC_DUAL;
        config.config_data.dacEn = ENABLE;
        config.config_data.samholdEn = ENABLE;
        config.config_data.waveType = DAC_WAVE_DISABLE;
        config.config_data.msAM = 0;
        config.config_data.dacDMAEn = DISABLE;
        config.config_data.resolution = DAC_DATA_MODE_12BIT;
        config.config_data.dacSoftTrigleEn = ENABLE;
        config.config_data.dacComConfig.dacHoldData = 0x55;
        config.config_data.dacComConfig.dacHoldSampTime = 0;
        config.config_data.dacComConfig.dacHoldTime = 0;
        config.config_data.dacComConfig.dacHoldRefTime = 0;
        config.config_data.dacComConfig.dacDAC1DualHoldData = 0xFFF;
        config.config_data.dacComConfig.dacDAC0DualHoldData = 0xFFF;
        config.config_data.triggerMode = DAC_DUAL_SOFTWARE_TRIG;
        dac_out = dac_demo(&config);
        PR_DEBUG("Func[%s]: dac_out = [0x%x], dacSel = %d\n", __FUNCTION__, dac_out, config.config_data.dacSel);
#endif
    }
#endif
    return TC_PASS;
}

int main(void)
{
    demo(DAC0_SEL);
#if defined (CHIP_GM6721)
    demo(DAC1_SEL);
    demo(DAC_DUAL);
#endif
    PR_DEBUG("Func[%s] test end\n", __FUNCTION__);
    return 0;
}