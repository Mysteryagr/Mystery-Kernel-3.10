
#ifndef _MT_PMIC_LDO_H_
#define _MT_PMIC_LDO_H_
#include <asm/io.h>
#include <linux/spinlock.h>
#include <linux/interrupt.h>
#include <linux/types.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/xlog.h>
#include <asm/uaccess.h>
#include <mach/mt_pm_ldo.h>
#include "mt_typedefs.h"

#define __USE_LINUX_REGULATOR_FRAMEWORK__

#define MAX_DEVICE      32
#define MAX_MOD_NAME    32

#define NON_OP "NOP"

/* Debug message event */
#define DBG_PMAPI_NONE 0x00000000    
#define DBG_PMAPI_CG   0x00000001    
#define DBG_PMAPI_PLL  0x00000002    
#define DBG_PMAPI_SUB  0x00000004    
#define DBG_PMAPI_PMIC 0x00000008    
#define DBG_PMAPI_ALL  0xFFFFFFFF    
    
#define DBG_PMAPI_MASK (DBG_PMAPI_ALL)

typedef enum MT_POWER_TAG {    

    MT6325_POWER_LDO_VTCXO0,     
    MT6325_POWER_LDO_VTCXO1,     
    MT6325_POWER_LDO_VAUD28,     
    MT6325_POWER_LDO_VAUXA28,    
    MT6325_POWER_LDO_VBIF28,     
    MT6325_POWER_LDO_VCAMA,      
    MT6325_POWER_LDO_VCN28,      
    MT6325_POWER_LDO_VCN33,      
    MT6325_POWER_LDO_VRF18_1,    
    MT6325_POWER_LDO_VUSB33,     
    MT6325_POWER_LDO_VMCH,       
    MT6325_POWER_LDO_VMC,        
    MT6325_POWER_LDO_VEMC33,     
    MT6325_POWER_LDO_VIO28,      
    MT6325_POWER_LDO_VCAM_AF,    
    MT6325_POWER_LDO_VGP1,       
    MT6325_POWER_LDO_VEFUSE,     
    MT6325_POWER_LDO_VSIM1,      
    MT6325_POWER_LDO_VSIM2,      
    MT6325_POWER_LDO_VMIPI,      
    MT6325_POWER_LDO_VCN18,      
    MT6325_POWER_LDO_VGP2,       
    MT6325_POWER_LDO_VCAMD,      
    MT6325_POWER_LDO_VCAM_IO,    
    MT6325_POWER_LDO_VSRAM_DVFS1,
    MT6325_POWER_LDO_VGP3,       
    MT6325_POWER_LDO_VBIASN,     
    MT6325_POWER_LDO_VRTC, 

    
    MT65XX_POWER_LDO_DEFAULT,
    MT65XX_POWER_COUNT_END,
    MT65XX_POWER_NONE = -1
} MT_POWER;

typedef enum MT_POWER_VOL_TAG 
{
    VOL_DEFAULT, 
    VOL_0200 = 200,
    VOL_0220 = 220,
    VOL_0240 = 240,
    VOL_0260 = 260,
    VOL_0280 = 280,
    VOL_0300 = 300,
    VOL_0320 = 320,
    VOL_0340 = 340,
    VOL_0360 = 360,
    VOL_0380 = 380,
    VOL_0400 = 400,
    VOL_0420 = 420,
    VOL_0440 = 440,
    VOL_0460 = 460,
    VOL_0480 = 480,
    VOL_0500 = 500,
    VOL_0520 = 520,
    VOL_0540 = 540,
    VOL_0560 = 560,
    VOL_0580 = 580,
    VOL_0600 = 600,
    VOL_0620 = 620,
    VOL_0640 = 640,
    VOL_0660 = 660,
    VOL_0680 = 680,
    VOL_0700 = 700,
    VOL_0720 = 720,
    VOL_0740 = 740,
    VOL_0760 = 760,
    VOL_0780 = 780,
    VOL_0800 = 800,        
    VOL_0900 = 900,
    VOL_0950 = 950,
    VOL_1000 = 1000,
    VOL_1050 = 1050,
    VOL_1100 = 1100,
    VOL_1150 = 1150,
    VOL_1200 = 1200,
    VOL_1220 = 1220,
    VOL_1250 = 1250,
    VOL_1300 = 1300,
    VOL_1350 = 1350,
    VOL_1360 = 1360,
    VOL_1400 = 1400,
    VOL_1450 = 1450,
    VOL_1500 = 1500,
    VOL_1550 = 1550,
    VOL_1600 = 1600,
    VOL_1650 = 1650,
    VOL_1700 = 1700,
    VOL_1750 = 1750,
    VOL_1800 = 1800,
    VOL_1850 = 1850,
    VOL_1860 = 1860,
    VOL_1900 = 1900,
    VOL_1950 = 1950,
    VOL_2000 = 2000,
    VOL_2050 = 2050,
    VOL_2100 = 2100,
    VOL_2150 = 2150,
    VOL_2200 = 2200,
    VOL_2250 = 2250,
    VOL_2300 = 2300,
    VOL_2350 = 2350,
    VOL_2400 = 2400,
    VOL_2450 = 2450,
    VOL_2500 = 2500,
    VOL_2550 = 2550,
    VOL_2600 = 2600,
    VOL_2650 = 2650,
    VOL_2700 = 2700,
    VOL_2750 = 2750,
    VOL_2760 = 2760,
    VOL_2800 = 2800,
    VOL_2850 = 2850,
    VOL_2900 = 2900,
    VOL_2950 = 2950,
    VOL_3000 = 3000,
    VOL_3050 = 3050,
    VOL_3100 = 3100,
    VOL_3150 = 3150,
    VOL_3200 = 3200,
    VOL_3250 = 3250,
    VOL_3300 = 3300,
    VOL_3350 = 3350,
    VOL_3400 = 3400,
    VOL_3450 = 3450,
    VOL_3500 = 3500,
    VOL_3550 = 3550,
    VOL_3600 = 3600
} MT_POWER_VOLTAGE;    

typedef struct { 
    DWORD dwPowerCount; 
    BOOL bDefault_on;
    char name[MAX_MOD_NAME];        
    char mod_name[MAX_DEVICE][MAX_MOD_NAME];    
} DEVICE_POWER;

typedef struct
{    
    DEVICE_POWER Power[MT65XX_POWER_COUNT_END];    
} ROOTBUS_HW;

//==============================================================================
// PMIC Exported Function for power service
//==============================================================================
extern void pmic_ldo_enable(MT_POWER powerId, kal_bool powerEnable){}
extern void pmic_ldo_vol_sel(MT_POWER powerId, MT_POWER_VOLTAGE powerVolt){}

/****************************************************************
 * GLOBAL DEFINATION
 ****************************************************************/
ROOTBUS_HW g_MT_PMIC_BusHW ;
    
/*******************************************************************
 * Extern Variable DEFINATIONS
 *******************************************************************/
/**********************************************************************
 * Extern FUNCTION DEFINATIONS
 *******************************************************************/
/**********************************************************************
* Debug Message Settings
*****************************************************************/
#if 1
#define MSG(evt, fmt, args...) \
do {    \
    if ((DBG_PMAPI_##evt) & DBG_PMAPI_MASK) { \
        xlog_printk(ANDROID_LOG_INFO, "Power/PMIC", fmt, ##args); \
    } \
} while(0)
#define MSG_FUNC_ENTRY(f)    MSG(ENTER, "<PMAPI FUNC>: %s\n", __FUNCTION__)
#else
#define MSG(evt, fmt, args...) do{}while(0)
#define MSG_FUNC_ENTRY(f)       do{}while(0)
#endif
int first_power_on_flag = 1;
bool hwPowerOn(MT_POWER powerId, MT_POWER_VOLTAGE powerVolt, char *mode_name)
{
    UINT32 i = 0;
    int j=0, k=0;
    if(first_power_on_flag == 1)
    {		
        for(j=0 ; j<MT65XX_POWER_COUNT_END ; j++)
        {
            for(k=0 ; k<MAX_DEVICE ; k++)
            {
                sprintf(g_MT_PMIC_BusHW.Power[j].mod_name[k] , "%s", NON_OP);
            }
            g_MT_PMIC_BusHW.Power[j].dwPowerCount=0;
        }
        first_power_on_flag = 0;
        xlog_printk(ANDROID_LOG_DEBUG, "Power/PMIC", "[hwPowerOn] init done.\r\n");
    }
	
#if 1	
    if(powerId >= MT65XX_POWER_COUNT_END)
    {
        MSG(PMIC,"[MT65XX PMU] Error!! powerId is wrong\r\n");
        return FALSE;
    }
    for (i = 0; i< MAX_DEVICE; i++)
    {
        xlog_printk(ANDROID_LOG_DEBUG, "Power/PMIC", "[hwPowerOn] %d,%s,%d\r\n", i, g_MT_PMIC_BusHW.Power[powerId].mod_name[i], g_MT_PMIC_BusHW.Power[powerId].dwPowerCount);
	
        if (!strcmp(g_MT_PMIC_BusHW.Power[powerId].mod_name[i], NON_OP))
        {
            MSG(PMIC,"[%s] acquire powerId:%d index:%d mod_name: %s powerVolt:%d\r\n", 
                __FUNCTION__,powerId, i, mode_name,powerVolt);            
            sprintf(g_MT_PMIC_BusHW.Power[powerId].mod_name[i] , "%s", mode_name);
            break ;
        }
        /* already it */
        #if 0
        else if (!strcmp(g_MT_PMIC_BusHW.Power[powerId].mod_name[i], mode_name))
        {
            MSG(CG,"[%d] Power already register\r\n",powerId );        
        }
        #endif
    }    
    g_MT_PMIC_BusHW.Power[powerId].dwPowerCount++ ;
    /* We've already enable this LDO before */
    if(g_MT_PMIC_BusHW.Power[powerId].dwPowerCount > 1)
    {
        xlog_printk(ANDROID_LOG_DEBUG, "Power/PMIC", "[hwPowerOn] g_MT_PMIC_BusHW.Power[powerId].dwPowerCount (%d) > 1\r\n", g_MT_PMIC_BusHW.Power[powerId].dwPowerCount);
        return TRUE;
    }
#endif	
    /* Turn on PMU LDO*/
    MSG(CG,"[%d] PMU LDO Enable\r\n",powerId );            
    xlog_printk(ANDROID_LOG_DEBUG, "Power/PMIC", "[hwPowerOn] enable %d by %s \r\n", powerId, mode_name);
    if ((powerId   == MT6325_POWER_LDO_VTCXO0)
    ||(powerId   == MT6325_POWER_LDO_VTCXO1)
    ||(powerId   == MT6325_POWER_LDO_VAUD28)
    ||(powerId   == MT6325_POWER_LDO_VAUXA28)    
    ||(powerId   == MT6325_POWER_LDO_VBIF28)
    ||(powerId   == MT6325_POWER_LDO_VCAMA) 
    ||(powerId   == MT6325_POWER_LDO_VCN28) 
    ||(powerId   == MT6325_POWER_LDO_VCN33) 
    ||(powerId   == MT6325_POWER_LDO_VRF18_1)    
    ||(powerId   == MT6325_POWER_LDO_VUSB33)
    ||(powerId   == MT6325_POWER_LDO_VMCH)  
    ||(powerId   == MT6325_POWER_LDO_VMC)   
    ||(powerId   == MT6325_POWER_LDO_VEMC33)
    ||(powerId   == MT6325_POWER_LDO_VIO28) 
    ||(powerId   == MT6325_POWER_LDO_VCAM_AF)    
    ||(powerId   == MT6325_POWER_LDO_VGP1)  
    ||(powerId   == MT6325_POWER_LDO_VEFUSE)
    ||(powerId   == MT6325_POWER_LDO_VSIM1) 
    ||(powerId   == MT6325_POWER_LDO_VSIM2) 
    ||(powerId   == MT6325_POWER_LDO_VMIPI) 
    ||(powerId   == MT6325_POWER_LDO_VCN18) 
    ||(powerId   == MT6325_POWER_LDO_VGP2)  
    ||(powerId   == MT6325_POWER_LDO_VCAMD) 
    ||(powerId   == MT6325_POWER_LDO_VCAM_IO)    
    ||(powerId   == MT6325_POWER_LDO_VSRAM_DVFS1)
    ||(powerId   == MT6325_POWER_LDO_VGP3)  
    ||(powerId   == MT6325_POWER_LDO_VBIASN)
    ||(powerId   == MT6325_POWER_LDO_VRTC)) 
    {
        pmic_ldo_vol_sel(powerId, powerVolt);
    }
    pmic_ldo_enable(powerId, KAL_TRUE);
    
    return TRUE; 
}
EXPORT_SYMBOL(hwPowerOn);
bool hwPowerDown(MT_POWER powerId, char *mode_name)
{
    UINT32 i;
#if 1	
    BOOL bFind = FALSE;    
    if(powerId >= MT65XX_POWER_COUNT_END)
    {
        MSG(PMIC,"%s:%s:%d powerId:%d is wrong\r\n",__FILE__,__FUNCTION__, 
            __LINE__ , powerId);
        return FALSE;
    }    
    if(g_MT_PMIC_BusHW.Power[powerId].dwPowerCount == 0)
    {
        MSG(PMIC,"%s:%s:%d powerId:%d (g_MT_PMIC_BusHW.dwPowerCount[powerId] = 0)\r\n", 
            __FILE__,__FUNCTION__,__LINE__ ,powerId);
        return FALSE;
    }
    for (i = 0; i< MAX_DEVICE; i++)
    {
        xlog_printk(ANDROID_LOG_DEBUG, "Power/PMIC", "[hwPowerDown] %d,%s,%d\r\n", i, g_MT_PMIC_BusHW.Power[powerId].mod_name[i], g_MT_PMIC_BusHW.Power[powerId].dwPowerCount);
	
        if (!strcmp(g_MT_PMIC_BusHW.Power[powerId].mod_name[i], mode_name))
        {
            MSG(PMIC,"[%s] powerId:%d index:%d mod_name: %s\r\n", 
                __FUNCTION__,powerId, i, mode_name);            
            sprintf(g_MT_PMIC_BusHW.Power[powerId].mod_name[i] , "%s", NON_OP);
            bFind = TRUE;
            break ;
        }
    }   
    if(!bFind)
    {
        MSG(PMIC,"[%s] Cannot find [%d] master is [%s]\r\n",__FUNCTION__,powerId, mode_name);        
        return TRUE;
    }        
    g_MT_PMIC_BusHW.Power[powerId].dwPowerCount--;
    if(g_MT_PMIC_BusHW.Power[powerId].dwPowerCount > 0)
    {
        xlog_printk(ANDROID_LOG_DEBUG, "Power/PMIC", "[hwPowerDown] g_MT_PMIC_BusHW.Power[powerId].dwPowerCount (%d) > 0\r\n", g_MT_PMIC_BusHW.Power[powerId].dwPowerCount);
        return TRUE;
    }
#endif	
    /* Turn off PMU LDO*/
    MSG(CG,"[%d] PMU LDO Disable\r\n",powerId );
    xlog_printk(ANDROID_LOG_DEBUG, "Power/PMIC", "[hwPowerDown] disable %d by %s \r\n", powerId, mode_name);
    pmic_ldo_enable(powerId, KAL_FALSE);
    return TRUE;    
}
EXPORT_SYMBOL(hwPowerDown);

#endif // _MT_PMIC_LDO_H_

