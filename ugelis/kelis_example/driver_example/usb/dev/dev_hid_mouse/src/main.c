#include "main.h"
#include <ugelis.h>

#include "usb_device_config.h"
#include "usb.h"
#include "usb_device.h"
#include "usb_device_class.h"
#include "usb_device_hid.h"
#include "usb_device_ch9.h"
#include "usb_device_descriptor.h"
#include "usb_device_khci.h"

#include <logging/sys_log.h>

#define USB_Echo printf
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

static usb_status_t USB_DeviceHidMouseAction(void);
static usb_status_t USB_DeviceHidMouseCallback(class_handle_t handle, uint32_t event, void *param);
static usb_status_t USB_DeviceCallback(usb_device_handle handle, uint32_t event, void *param);

/*******************************************************************************
 * Variables
 ******************************************************************************/

USB_DMA_NONINIT_DATA_ALIGN(4) static uint8_t s_MouseBuffer[USB_HID_MOUSE_REPORT_LENGTH];
usb_hid_mouse_struct_t g_UsbDeviceHidMouse;

extern usb_device_class_struct_t g_UsbDeviceHidMouseConfig;


/* Set class configurations */
usb_device_class_config_struct_t g_UsbDeviceHidConfig[1] = {{
    USB_DeviceHidMouseCallback, /* HID mouse class callback pointer */
    (class_handle_t)NULL,       /* The HID class handle, This field is set by USB_DeviceClassInit */
    &g_UsbDeviceHidMouseConfig, /* The HID mouse configuration, including class code, subcode, and protocol, class type,
                           transfer type, endpoint address, max packet size, etc.*/
}};

/* Set class configuration list */
usb_device_class_config_list_struct_t g_UsbDeviceHidConfigList = {
    g_UsbDeviceHidConfig, /* Class configurations */
    USB_DeviceCallback,   /* Device callback pointer */
    1U,                   /* Class count */
};

/*******************************************************************************
 * Code
 ******************************************************************************/

/* Update mouse pointer location. Draw a rectangular rotation*/
static usb_status_t USB_DeviceHidMouseAction(void)
{
    static int8_t x = 0U;
    static int8_t y = 0U;
    enum
    {
        RIGHT,
        DOWN,
        LEFT,
        UP
    };
    static uint8_t dir = RIGHT;

    switch (dir)
    {
        case RIGHT:
            /* Move right. Increase X value. */
            g_UsbDeviceHidMouse.buffer[1] = 2U;
            g_UsbDeviceHidMouse.buffer[2] = 0U;
            x++;
            if (x > 99U)
            {
                dir++;
            }
            break;
        case DOWN:
            /* Move down. Increase Y value. */
            g_UsbDeviceHidMouse.buffer[1] = 0U;
            g_UsbDeviceHidMouse.buffer[2] = 2U;
            y++;
            if (y > 99U)
            {
                dir++;
            }
            break;
        case LEFT:
            /* Move left. Discrease X value. */
            g_UsbDeviceHidMouse.buffer[1] = (uint8_t)(-2);
            g_UsbDeviceHidMouse.buffer[2] = 0U;
            x--;
            if (x < 2U)
            {
                dir++;
            }
            break;
        case UP:
            /* Move up. Discrease Y value. */
            g_UsbDeviceHidMouse.buffer[1] = 0U;
            g_UsbDeviceHidMouse.buffer[2] = (uint8_t)(-2);
            y--;
            if (y < 2U)
            {
                dir = RIGHT;
            }
            break;
        default:
            break;
    }
    /* Send mouse report to the host */
    return USB_DeviceHidSend(g_UsbDeviceHidMouse.hidHandle, USB_HID_MOUSE_ENDPOINT_IN, g_UsbDeviceHidMouse.buffer,
                             USB_HID_MOUSE_REPORT_LENGTH);
}

/* The hid class callback */
static usb_status_t USB_DeviceHidMouseCallback(class_handle_t handle, uint32_t event, void *param)
{
    usb_status_t error = kStatus_USB_Error;
    usb_device_endpoint_callback_message_struct_t *message = (usb_device_endpoint_callback_message_struct_t *)param;

    switch (event)
    {
        case kUSB_DeviceHidEventSendResponse:
            /* Resport sent */
            if (g_UsbDeviceHidMouse.attach)
            {
                if ((NULL != message) && (message->length == USB_UNINITIALIZED_VAL_32))
                {
                    return error;
                }
                error = USB_DeviceHidMouseAction();
            }
            break;
        case kUSB_DeviceHidEventGetReport:
        case kUSB_DeviceHidEventSetReport:
        case kUSB_DeviceHidEventRequestReportBuffer:
            error = kStatus_USB_InvalidRequest;
            break;
        case kUSB_DeviceHidEventGetIdle:
        case kUSB_DeviceHidEventGetProtocol:
        case kUSB_DeviceHidEventSetIdle:
        case kUSB_DeviceHidEventSetProtocol:
            break;
        default:
            break;
    }

    return error;
}

/* The device callback */
static usb_status_t USB_DeviceCallback(usb_device_handle handle, uint32_t event, void *param)
{
    usb_status_t error = kStatus_USB_Error;
    uint16_t *temp16 = (uint16_t *)param;
    uint8_t *temp8 = (uint8_t *)param;

    switch (event)
    {
        case kUSB_DeviceEventBusReset:
        {
            /* USB bus reset signal detected */
            g_UsbDeviceHidMouse.attach = 0U;
            error = kStatus_USB_Success;

#if (defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 0U)) || \
    (defined(USB_DEVICE_CONFIG_LPCIP3511HS) && (USB_DEVICE_CONFIG_LPCIP3511HS > 0U))
            /* Get USB speed to configure the device, including max packet size and interval of the endpoints. */
            if (kStatus_USB_Success == USB_DeviceClassGetSpeed(CONTROLLER_ID, &g_UsbDeviceHidMouse.speed))
            {
                USB_DeviceSetSpeed(handle, g_UsbDeviceHidMouse.speed);
            }
#endif
        }
        break;
#if (defined(USB_DEVICE_CONFIG_DETACH_ENABLE) && (USB_DEVICE_CONFIG_DETACH_ENABLE > 0U))
        case kUSB_DeviceEventAttach:
        {
#if (defined(USB_DEVICE_CHARGER_DETECT_ENABLE) && (USB_DEVICE_CHARGER_DETECT_ENABLE > 0U)) && \
    ((defined(FSL_FEATURE_SOC_USBDCD_COUNT) && (FSL_FEATURE_SOC_USBDCD_COUNT > 0U)) ||        \
     (defined(FSL_FEATURE_SOC_USBHSDCD_COUNT) && (FSL_FEATURE_SOC_USBHSDCD_COUNT > 0U)))
            g_UsbDeviceHidMouse.vReginInterruptDetected = 1;
            g_UsbDeviceHidMouse.vbusValid = 1;
#else
            usb_echo("USB device attached.\r\n");

#if (defined(USB_DEVICE_CONFIG_LPCIP3511HS) && (USB_DEVICE_CONFIG_LPCIP3511HS > 0U)) || \
    (defined(USB_DEVICE_CONFIG_LPCIP3511FS) && (USB_DEVICE_CONFIG_LPCIP3511FS > 0U))
#else
            USB_DeviceRun(g_UsbDeviceHidMouse.deviceHandle);
#endif

#endif
        }
        break;
        case kUSB_DeviceEventDetach:
        {
#if (defined(USB_DEVICE_CHARGER_DETECT_ENABLE) && (USB_DEVICE_CHARGER_DETECT_ENABLE > 0U)) && \
    ((defined(FSL_FEATURE_SOC_USBDCD_COUNT) && (FSL_FEATURE_SOC_USBDCD_COUNT > 0U)) ||        \
     (defined(FSL_FEATURE_SOC_USBHSDCD_COUNT) && (FSL_FEATURE_SOC_USBHSDCD_COUNT > 0U)))
            g_UsbDeviceHidMouse.vReginInterruptDetected = 1;
            g_UsbDeviceHidMouse.vbusValid = 0;
            g_UsbDeviceHidMouse.attach = 0;
#else
            usb_echo("USB device detached.\r\n");
            g_UsbDeviceHidMouse.attach = 0;

#if (defined(USB_DEVICE_CONFIG_LPCIP3511HS) && (USB_DEVICE_CONFIG_LPCIP3511HS > 0U)) || \
    (defined(USB_DEVICE_CONFIG_LPCIP3511FS) && (USB_DEVICE_CONFIG_LPCIP3511FS > 0U))

#if (defined(USB_DEVICE_CONFIG_LPCIP3511HS) && (USB_DEVICE_CONFIG_LPCIP3511HS > 0U))
            USB_DeviceDisconnected();
#endif

#else
            USB_DeviceStop(g_UsbDeviceHidMouse.deviceHandle);
#endif

#endif
        }
        break;
#endif
        case kUSB_DeviceEventSetConfiguration:
            if (param)
            {
                /* Set device configuration request */
                g_UsbDeviceHidMouse.attach = 1U;
                g_UsbDeviceHidMouse.currentConfiguration = *temp8;
                if (USB_HID_MOUSE_CONFIGURE_INDEX == (*temp8))
                {
                    error = USB_DeviceHidMouseAction();
                }
            }
            break;
        case kUSB_DeviceEventSetInterface:
            if (g_UsbDeviceHidMouse.attach)
            {
                /* Set device interface request */
                uint8_t interface = (uint8_t)((*temp16 & 0xFF00U) >> 0x08U);
                uint8_t alternateSetting = (uint8_t)(*temp16 & 0x00FFU);
                if (interface < USB_HID_MOUSE_INTERFACE_COUNT)
                {
                    g_UsbDeviceHidMouse.currentInterfaceAlternateSetting[interface] = alternateSetting;
                    if (alternateSetting == 0U)
                    {
                        error = USB_DeviceHidMouseAction();
                    }
                }
            }
            break;
        case kUSB_DeviceEventGetConfiguration:
            if (param)
            {
                /* Get current configuration request */
                *temp8 = g_UsbDeviceHidMouse.currentConfiguration;
                error = kStatus_USB_Success;
            }
            break;
        case kUSB_DeviceEventGetInterface:
            if (param)
            {
                /* Get current alternate setting of the interface request */
                uint8_t interface = (uint8_t)((*temp16 & 0xFF00U) >> 0x08U);
                if (interface < USB_HID_MOUSE_INTERFACE_COUNT)
                {
                    *temp16 = (*temp16 & 0xFF00U) | g_UsbDeviceHidMouse.currentInterfaceAlternateSetting[interface];
                    error = kStatus_USB_Success;
                }
                else
                {
                    error = kStatus_USB_InvalidRequest;
                }
            }
            break;
        case kUSB_DeviceEventGetDeviceDescriptor:
            if (param)
            {
                /* Get device descriptor request */
                error = USB_DeviceGetDeviceDescriptor(handle, (usb_device_get_device_descriptor_struct_t *)param);
            }
            break;
        case kUSB_DeviceEventGetConfigurationDescriptor:
            if (param)
            {
                /* Get device configuration descriptor request */
                error = USB_DeviceGetConfigurationDescriptor(handle,
                                                             (usb_device_get_configuration_descriptor_struct_t *)param);
            }
            break;
        case kUSB_DeviceEventGetStringDescriptor:
            if (param)
            {
                /* Get device string descriptor request */
                error = USB_DeviceGetStringDescriptor(handle, (usb_device_get_string_descriptor_struct_t *)param);
            }
            break;
        case kUSB_DeviceEventGetHidDescriptor:
            if (param)
            {
                /* Get hid descriptor request */
                error = USB_DeviceGetHidDescriptor(handle, (usb_device_get_hid_descriptor_struct_t *)param);
            }
            break;
        case kUSB_DeviceEventGetHidReportDescriptor:
            if (param)
            {
                /* Get hid report descriptor request */
                error =
                    USB_DeviceGetHidReportDescriptor(handle, (usb_device_get_hid_report_descriptor_struct_t *)param);
            }
            break;
        case kUSB_DeviceEventGetHidPhysicalDescriptor:
            if (param)
            {
                /* Get hid physical descriptor request */
                error = USB_DeviceGetHidPhysicalDescriptor(handle,
                                                           (usb_device_get_hid_physical_descriptor_struct_t *)param);
            }
            break;
#if (defined(USB_DEVICE_CONFIG_CV_TEST) && (USB_DEVICE_CONFIG_CV_TEST > 0U))
        case kUSB_DeviceEventGetDeviceQualifierDescriptor:
            if (param)
            {
                /* Get device descriptor request */
                error = USB_DeviceGetDeviceQualifierDescriptor(
                    handle, (usb_device_get_device_qualifier_descriptor_struct_t *)param);
            }
            break;
#endif
#if (defined(USB_DEVICE_CHARGER_DETECT_ENABLE) && (USB_DEVICE_CHARGER_DETECT_ENABLE > 0U)) && \
    ((defined(FSL_FEATURE_SOC_USBDCD_COUNT) && (FSL_FEATURE_SOC_USBDCD_COUNT > 0U)) ||        \
     (defined(FSL_FEATURE_SOC_USBHSDCD_COUNT) && (FSL_FEATURE_SOC_USBHSDCD_COUNT > 0U)))
        case kUSB_DeviceEventDcdTimeOut:
            if (g_UsbDeviceHidMouse.dcdDevStatus == kUSB_DeviceDCDDevStatusVBUSDetect)
            {
                g_UsbDeviceHidMouse.dcdDevStatus = kUSB_DeviceDCDDevStatusTimeOut;
            }
            break;
        case kUSB_DeviceEventDcdUnknownType:
            if (g_UsbDeviceHidMouse.dcdDevStatus == kUSB_DeviceDCDDevStatusVBUSDetect)
            {
                g_UsbDeviceHidMouse.dcdDevStatus = kUSB_DeviceDCDDevStatusUnknownType;
            }
            break;
        case kUSB_DeviceEventSDPDetected:
            if (g_UsbDeviceHidMouse.dcdDevStatus == kUSB_DeviceDCDDevStatusVBUSDetect)
            {
                g_UsbDeviceHidMouse.dcdPortType = kUSB_DeviceDCDPortTypeSDP;
                g_UsbDeviceHidMouse.dcdDevStatus = kUSB_DeviceDCDDevStatusDetectFinish;
            }
            break;
        case kUSB_DeviceEventChargingPortDetected:
            if (g_UsbDeviceHidMouse.dcdDevStatus == kUSB_DeviceDCDDevStatusVBUSDetect)
            {
                g_UsbDeviceHidMouse.dcdDevStatus = kUSB_DeviceDCDDevStatusChargingPortDetect;
            }
            break;
        case kUSB_DeviceEventChargingHostDetected:
            if (g_UsbDeviceHidMouse.dcdDevStatus == kUSB_DeviceDCDDevStatusVBUSDetect)
            {
                g_UsbDeviceHidMouse.dcdDevStatus = kUSB_DeviceDCDDevStatusDetectFinish;
                g_UsbDeviceHidMouse.dcdPortType = kUSB_DeviceDCDPortTypeCDP;
            }
            break;
        case kUSB_DeviceEventDedicatedChargerDetected:
            if (g_UsbDeviceHidMouse.dcdDevStatus == kUSB_DeviceDCDDevStatusVBUSDetect)
            {
                g_UsbDeviceHidMouse.dcdDevStatus = kUSB_DeviceDCDDevStatusDetectFinish;
                g_UsbDeviceHidMouse.dcdPortType = kUSB_DeviceDCDPortTypeDCP;
            }
            break;
#endif
        default:
            break;
    }

    return error;
}


int main(void)
{

	/* Set HID mouse to default state */
    g_UsbDeviceHidMouse.speed = USB_SPEED_FULL;
    g_UsbDeviceHidMouse.attach = 0U;
    g_UsbDeviceHidMouse.hidHandle = (class_handle_t)NULL;
    g_UsbDeviceHidMouse.deviceHandle = NULL;
    g_UsbDeviceHidMouse.buffer = s_MouseBuffer;


    /* Initialize the usb stack and class drivers */
    if (kStatus_USB_Success !=
        USB_DeviceClassInit(CONTROLLER_ID, &g_UsbDeviceHidConfigList, &g_UsbDeviceHidMouse.deviceHandle))
    {
        usb_echo("USB device mouse failed\r\n");
        return -1;
    }
    else
    {
        usb_echo("USB device HID mouse demo\r\n");
        /* Get the HID mouse class handle */
        g_UsbDeviceHidMouse.hidHandle = g_UsbDeviceHidConfigList.config->classHandle;
    }
    
	USB_Device_SetStackParam(&g_UsbDeviceHidMouse.deviceHandle);
    /* Start USB device HID mouse */
    USB_DeviceRun(g_UsbDeviceHidMouse.deviceHandle);
    while (1)
    {
		k_sleep(1000);
    }    
	return 0;
}