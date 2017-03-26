
include $(srctree)/drivers/misc/mediatek/Makefile.custom

ifneq ($(CONFIG_ARCH_MTK_PROJECT),)
ARCH_MTK_PROJECT := $(shell echo $(CONFIG_ARCH_MTK_PROJECT))
obj-y   += core/
obj-y   += dct/dct/
endif

ifneq ($(CONFIG_ARM64), y)
obj-y   +=  camera/camera/
endif
#obj-y   +=  flashlight/constant_flashlight/
obj-$(CONFIG_MTK_VIBRATOR)   +=  vibrator/
obj-$(CONFIG_MTK_LEDS)   +=  leds/
#obj-y   +=  keypad/
#obj-y   +=  sound/
obj-$(CONFIG_MTK_ACCDET)   +=  accdet/

ifeq ($(CONFIG_MTK_SENSOR_SUPPORT),y)

#ifeq ($(CONFIG_MTK_CM36283_NEW),y)
#obj-y	+=  alsps/cm36283-new/
#endif

ifeq ($(CONFIG_MTK_CM36283),y)
obj-y	+=  alsps/cm36283/
endif

#ifeq ($(CONFIG_MTK_BMA222E),y)
#obj-y   +=  accelerometer/bma222e/
#endif

ifeq ($(CONFIG_MTK_BMA222E_NEW),y)
obj-y   +=  accelerometer/bma222e-new/
endif

ifeq ($(CONFIG_MTK_ITG1010_NEW),y)
obj-y   +=  gyroscope/ITG1010-new/
endif

ifeq ($(CONFIG_MTK_AKM09911_NEW),y)
obj-y	+=  magnetometer/akm09911-new/
endif

endif
