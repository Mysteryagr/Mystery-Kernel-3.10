include $(srctree)/drivers/misc/mediatek/Makefile.custom

ccflags-y += -I$(srctree)/drivers/misc/mediatek/mach/$(CONFIG_MTK_PLATFORM)/$(ARCH_MTK_PROJECT)/power/

obj-$(CONFIG_MTK_PMIC)          += pmic.o upmu_common.o pmic_auxadc.o pmic_chr_type_det.o 

ifeq ($(CONFIG_MTK_PMIC_DVT_SUPPORT),y)
     obj-$(CONFIG_MTK_PMIC)     += pmic_dvt.o
endif

obj-$(CONFIG_MTK_SMART_BATTERY) += battery_meter_hal.o 

ifeq ($(CONFIG_MTK_FAN5405_SUPPORT),y)
    obj-$(CONFIG_MTK_SMART_BATTERY) += fan5405.o charging_hw_fan5405.o
else
	   ifeq ($(CONFIG_MTK_BQ24158_SUPPORT),y)
	        obj-$(CONFIG_MTK_SMART_BATTERY) += bq24158.o charging_hw_bq24158.o
	   else
	ifeq ($(CONFIG_MTK_BQ24261_SUPPORT),y)
	     obj-$(CONFIG_MTK_SMART_BATTERY) += bq24261.o charging_hw_bq24261.o
	else
	     ifeq ($(CONFIG_MTK_SWCHR_SUPPORT),y)
		  obj-$(CONFIG_MTK_SMART_BATTERY) += charging_hw_mt_sw_charger.o                
	     else
		  ifeq ($(CONFIG_MTK_NCP1854_SUPPORT),y)
		       obj-$(CONFIG_MTK_SMART_BATTERY) += ncp1854.o charging_hw_ncp1854.o             
		  else
		       ifeq ($(CONFIG_MTK_RT9536_SUPPORT),y)
			   obj-$(CONFIG_MTK_SMART_BATTERY) += rt9536/
		       else               
			    ifeq ($(CONFIG_MTK_BQ24196_SUPPORT),y)
				obj-$(CONFIG_MTK_SMART_BATTERY) += bq24196.o charging_hw_bq24196.o
			    else
				obj-$(CONFIG_MTK_SMART_BATTERY) += charging_hw_pmic.o
			    endif
		       endif
		  endif
	      endif
	endif
	endif
endif
