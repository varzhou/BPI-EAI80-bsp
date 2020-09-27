
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef _UGELIS_SYSCALL_LIST_H_
#define _UGELIS_SYSCALL_LIST_H_

#ifndef _ASMLANGUAGE

#include <ugelis/types.h>

#ifdef __cplusplus
extern "C" {
#endif

enum
{
    K_SYSCALL_ADC_DISABLE,
    K_SYSCALL_ADC_ENABLE,
    K_SYSCALL_ADC_READ,
    K_SYSCALL_AIO_CMP_DISABLE,
    K_SYSCALL_AIO_CMP_GET_PENDING_INT,
    K_SYSCALL_CAMERA_GET_FMT,
    K_SYSCALL_CAMERA_IOCTL,
    K_SYSCALL_CAMERA_SET_FMT,
    K_SYSCALL_CAMERA_SET_POWER,
    K_SYSCALL_CAN_GET_MSG,
    K_SYSCALL_CAN_SEND,
    K_SYSCALL_CAN_SET_CALLBACK,
    K_SYSCALL_COUNTER_GET_PENDING_INT,
    K_SYSCALL_COUNTER_READ,
    K_SYSCALL_COUNTER_START,
    K_SYSCALL_COUNTER_STOP,
    K_SYSCALL_DCMI_GET_FMT_VID_CAP,
    K_SYSCALL_DCMI_IOCTL,
    K_SYSCALL_DCMI_SET_FMT_VID_CAP,
    K_SYSCALL_DCMI_START_STREAMING,
    K_SYSCALL_DCMI_STOP_STREAMING,
    K_SYSCALL_DMA_START,
    K_SYSCALL_DMA_STOP,
    K_SYSCALL_ENTROPY_GET_ENTROPY,
    K_SYSCALL_FB_ALPHA_BLENDINGBULK,
    K_SYSCALL_FB_CONVERT_COLOR,
    K_SYSCALL_FB_COPY_AREA,
    K_SYSCALL_FB_DRAW_BITMAPL8,
    K_SYSCALL_FB_FILL_RECT,
    K_SYSCALL_FB_GET_DISPLAYINFO,
    K_SYSCALL_FB_IOCTL,
    K_SYSCALL_FB_LOAD_CLUT,
    K_SYSCALL_FB_MIX_COLORS,
    K_SYSCALL_FB_MIX_COLORSBULK,
    K_SYSCALL_FLASH_ERASE,
    K_SYSCALL_FLASH_GET_PAGE_COUNT,
    K_SYSCALL_FLASH_GET_PAGE_INFO_BY_IDX,
    K_SYSCALL_FLASH_GET_PAGE_INFO_BY_OFFS,
    K_SYSCALL_FLASH_GET_WRITE_BLOCK_SIZE,
    K_SYSCALL_FLASH_READ,
    K_SYSCALL_FLASH_WRITE,
    K_SYSCALL_FLASH_WRITE_PROTECTION_SET,
    K_SYSCALL_GPIO_CONFIG,
    K_SYSCALL_GPIO_DISABLE_CALLBACK,
    K_SYSCALL_GPIO_ENABLE_CALLBACK,
    K_SYSCALL_GPIO_GET_PENDING_INT,
    K_SYSCALL_GPIO_READ,
    K_SYSCALL_GPIO_WRITE,
    K_SYSCALL_I2C_CONFIGURE,
    K_SYSCALL_I2C_SLAVE_DRIVER_REGISTER,
    K_SYSCALL_I2C_SLAVE_DRIVER_UNREGISTER,
    K_SYSCALL_I2C_SLAVE_REGISTER,
    K_SYSCALL_I2C_SLAVE_UNREGISTER,
    K_SYSCALL_I2C_TRANSFER,
    K_SYSCALL_IPM_MAX_DATA_SIZE_GET,
    K_SYSCALL_IPM_MAX_ID_VAL_GET,
    K_SYSCALL_IPM_SEND,
    K_SYSCALL_IPM_SET_ENABLED,
    K_SYSCALL_K_ALERT_RECV,
    K_SYSCALL_K_ALERT_SEND,
    K_SYSCALL_K_CURRENT_GET,
    K_SYSCALL_K_IS_PREEMPT_THREAD,
    K_SYSCALL_K_MSGQ_ALLOC_INIT,
    K_SYSCALL_K_MSGQ_GET,
    K_SYSCALL_K_MSGQ_GET_ATTRS,
    K_SYSCALL_K_MSGQ_NUM_FREE_GET,
    K_SYSCALL_K_MSGQ_NUM_USED_GET,
    K_SYSCALL_K_MSGQ_PURGE,
    K_SYSCALL_K_MSGQ_PUT,
    K_SYSCALL_K_MUTEX_INIT,
    K_SYSCALL_K_MUTEX_LOCK,
    K_SYSCALL_K_MUTEX_UNLOCK,
    K_SYSCALL_K_OBJECT_ACCESS_GRANT,
    K_SYSCALL_K_OBJECT_ALLOC,
    K_SYSCALL_K_OBJECT_RELEASE,
    K_SYSCALL_K_PIPE_ALLOC_INIT,
    K_SYSCALL_K_PIPE_GET,
    K_SYSCALL_K_PIPE_PUT,
    K_SYSCALL_K_POLL,
    K_SYSCALL_K_POLL_SIGNAL,
    K_SYSCALL_K_POLL_SIGNAL_CHECK,
    K_SYSCALL_K_POLL_SIGNAL_INIT,
    K_SYSCALL_K_POLL_SIGNAL_RESET,
    K_SYSCALL_K_QUEUE_ALLOC_APPEND,
    K_SYSCALL_K_QUEUE_ALLOC_PREPEND,
    K_SYSCALL_K_QUEUE_CANCEL_WAIT,
    K_SYSCALL_K_QUEUE_GET,
    K_SYSCALL_K_QUEUE_INIT,
    K_SYSCALL_K_QUEUE_IS_EMPTY,
    K_SYSCALL_K_QUEUE_PEEK_HEAD,
    K_SYSCALL_K_QUEUE_PEEK_TAIL,
    K_SYSCALL_K_SEM_COUNT_GET,
    K_SYSCALL_K_SEM_GIVE,
    K_SYSCALL_K_SEM_INIT,
    K_SYSCALL_K_SEM_RESET,
    K_SYSCALL_K_SEM_TAKE,
    K_SYSCALL_K_SLEEP,
    K_SYSCALL_K_STACK_ALLOC_INIT,
    K_SYSCALL_K_STACK_POP,
    K_SYSCALL_K_STACK_PUSH,
    K_SYSCALL_K_STR_OUT,
    K_SYSCALL_K_THREAD_ABORT,
    K_SYSCALL_K_THREAD_CANCEL,
    K_SYSCALL_K_THREAD_CREATE,
    K_SYSCALL_K_THREAD_CUSTOM_DATA_GET,
    K_SYSCALL_K_THREAD_CUSTOM_DATA_SET,
    K_SYSCALL_K_THREAD_DEADLINE_SET,
    K_SYSCALL_K_THREAD_PRIORITY_GET,
    K_SYSCALL_K_THREAD_PRIORITY_SET,
    K_SYSCALL_K_THREAD_RESUME,
    K_SYSCALL_K_THREAD_START,
    K_SYSCALL_K_THREAD_SUSPEND,
    K_SYSCALL_K_TIMER_REMAINING_GET,
    K_SYSCALL_K_TIMER_START,
    K_SYSCALL_K_TIMER_STATUS_GET,
    K_SYSCALL_K_TIMER_STATUS_SYNC,
    K_SYSCALL_K_TIMER_STOP,
    K_SYSCALL_K_TIMER_USER_DATA_GET,
    K_SYSCALL_K_TIMER_USER_DATA_SET,
    K_SYSCALL_K_UPTIME_GET,
    K_SYSCALL_K_UPTIME_GET_32,
    K_SYSCALL_K_WAKEUP,
    K_SYSCALL_K_YIELD,
    K_SYSCALL_LED_BLINK,
    K_SYSCALL_LED_OFF,
    K_SYSCALL_LED_ON,
    K_SYSCALL_LED_SET_BRIGHTNESS,
    K_SYSCALL_LVD_CHECK_RESET_STATUS,
    K_SYSCALL_LVD_CLEAR_INTERRUPT_FLAG,
    K_SYSCALL_LVD_CLEAR_RESET_STATUS,
    K_SYSCALL_LVD_DISABLE_INTERRUPT,
    K_SYSCALL_LVD_ENABLE,
    K_SYSCALL_LVD_ENABLE_INTERRUPT,
    K_SYSCALL_LVD_GET_VDX_FLAG,
    K_SYSCALL_LVD_LOCK,
    K_SYSCALL_LVD_RESET_LEVEL,
    K_SYSCALL_LVD_SET_CONFIG,
    K_SYSCALL_MMC_GET_CAPACITY,
    K_SYSCALL_MMC_IN_SLOT,
    K_SYSCALL_MMC_READ,
    K_SYSCALL_MMC_SET_CALLBACK,
    K_SYSCALL_MMC_WRITE,
    K_SYSCALL_PM_CONFIG_WAKEUP_PIN,
    K_SYSCALL_PM_ENTER_LOW_POWER,
    K_SYSCALL_PWM_GET_CYCLES_PER_SEC,
    K_SYSCALL_PWM_PIN_SET_CYCLES,
    K_SYSCALL_RTC_CANCEL_ALARM,
    K_SYSCALL_RTC_DISABLE,
    K_SYSCALL_RTC_ENABLE,
    K_SYSCALL_RTC_GET_PENDING_INT,
    K_SYSCALL_RTC_GET_TIME,
    K_SYSCALL_RTC_READ,
    K_SYSCALL_RTC_REINIT,
    K_SYSCALL_RTC_SET_ALARM,
    K_SYSCALL_RTC_SET_DATETIME,
    K_SYSCALL_RTC_START_TIMER,
    K_SYSCALL_RTC_STOP_TIMER,
    K_SYSCALL_SENSOR_ATTR_SET,
    K_SYSCALL_SENSOR_CHANNEL_GET,
    K_SYSCALL_SENSOR_SAMPLE_FETCH,
    K_SYSCALL_SENSOR_SAMPLE_FETCH_CHAN,
    K_SYSCALL_SPI_RELEASE,
    K_SYSCALL_SPI_TRANSCEIVE,
    K_SYSCALL_UART_DRV_CMD,
    K_SYSCALL_UART_ERR_CHECK,
    K_SYSCALL_UART_IRQ_ERR_DISABLE,
    K_SYSCALL_UART_IRQ_ERR_ENABLE,
    K_SYSCALL_UART_IRQ_IS_PENDING,
    K_SYSCALL_UART_IRQ_RX_DISABLE,
    K_SYSCALL_UART_IRQ_RX_ENABLE,
    K_SYSCALL_UART_IRQ_TX_DISABLE,
    K_SYSCALL_UART_IRQ_TX_ENABLE,
    K_SYSCALL_UART_IRQ_UPDATE,
    K_SYSCALL_UART_LINE_CTRL_GET,
    K_SYSCALL_UART_LINE_CTRL_SET,
    K_SYSCALL_UART_POLL_IN,
    K_SYSCALL_UART_POLL_OUT,
    K_SYSCALL_WDT_DISABLE,
    K_SYSCALL_WDT_ENABLE,
    K_SYSCALL_WDT_GET_CONFIG,
    K_SYSCALL_WDT_RELOAD,
    K_SYSCALL_WDT_SET_CONFIG,
    K_SYSCALL_Z_ERRNO,
    K_SYSCALL__UGELIS_FPUTC,
    K_SYSCALL__UGELIS_FWRITE,
    K_SYSCALL__UGELIS_READ,
    K_SYSCALL__UGELIS_WRITE,
    K_SYSCALL_BAD,
    K_SYSCALL_LIMIT
};


extern u32_t _handler_mmc_in_slot(u32_t arg1, u32_t arg2, u32_t arg3,
                                  u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_mmc_set_callback(u32_t arg1, u32_t arg2, u32_t arg3,
                                       u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_mmc_read(u32_t arg1, u32_t arg2, u32_t arg3,
                               u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_mmc_write(u32_t arg1, u32_t arg2, u32_t arg3,
                                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_mmc_get_capacity(u32_t arg1, u32_t arg2, u32_t arg3,
                                       u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_ipm_send(u32_t arg1, u32_t arg2, u32_t arg3,
                               u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_ipm_max_data_size_get(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_ipm_max_id_val_get(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_ipm_set_enabled(u32_t arg1, u32_t arg2, u32_t arg3,
                                      u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_adc_enable(u32_t arg1, u32_t arg2, u32_t arg3,
                                 u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_adc_disable(u32_t arg1, u32_t arg2, u32_t arg3,
                                  u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_adc_read(u32_t arg1, u32_t arg2, u32_t arg3,
                               u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_lvd_enable_interrupt(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_lvd_disable_interrupt(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_lvd_clear_interrupt_flag(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_lvd_lock(u32_t arg1, u32_t arg2, u32_t arg3,
                               u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_lvd_reset_level(u32_t arg1, u32_t arg2, u32_t arg3,
                                      u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_lvd_check_reset_status(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_lvd_clear_reset_status(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_lvd_set_config(u32_t arg1, u32_t arg2, u32_t arg3,
                                     u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_lvd_enable(u32_t arg1, u32_t arg2, u32_t arg3,
                                 u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_lvd_get_VDX_flag(u32_t arg1, u32_t arg2, u32_t arg3,
                                       u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_wdt_enable(u32_t arg1, u32_t arg2, u32_t arg3,
                                 u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_wdt_disable(u32_t arg1, u32_t arg2, u32_t arg3,
                                  u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_wdt_get_config(u32_t arg1, u32_t arg2, u32_t arg3,
                                     u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_wdt_set_config(u32_t arg1, u32_t arg2, u32_t arg3,
                                     u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_wdt_reload(u32_t arg1, u32_t arg2, u32_t arg3,
                                 u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_object_access_grant(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_object_release(u32_t arg1, u32_t arg2, u32_t arg3,
                                       u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_object_alloc(u32_t arg1, u32_t arg2, u32_t arg3,
                                     u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_thread_create(u32_t arg1, u32_t arg2, u32_t arg3,
                                      u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_sleep(u32_t arg1, u32_t arg2, u32_t arg3,
                              u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_yield(u32_t arg1, u32_t arg2, u32_t arg3,
                              u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_wakeup(u32_t arg1, u32_t arg2, u32_t arg3,
                               u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_current_get(u32_t arg1, u32_t arg2, u32_t arg3,
                                    u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_thread_cancel(u32_t arg1, u32_t arg2, u32_t arg3,
                                      u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_thread_abort(u32_t arg1, u32_t arg2, u32_t arg3,
                                     u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_thread_start(u32_t arg1, u32_t arg2, u32_t arg3,
                                     u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_thread_priority_get(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_thread_priority_set(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_thread_deadline_set(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_thread_suspend(u32_t arg1, u32_t arg2, u32_t arg3,
                                       u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_thread_resume(u32_t arg1, u32_t arg2, u32_t arg3,
                                      u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_is_preempt_thread(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_thread_custom_data_set(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_thread_custom_data_get(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_timer_start(u32_t arg1, u32_t arg2, u32_t arg3,
                                    u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_timer_stop(u32_t arg1, u32_t arg2, u32_t arg3,
                                   u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_timer_status_get(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_timer_status_sync(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_timer_remaining_get(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_timer_user_data_set(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_timer_user_data_get(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_uptime_get(u32_t arg1, u32_t arg2, u32_t arg3,
                                   u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_uptime_get_32(u32_t arg1, u32_t arg2, u32_t arg3,
                                      u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_queue_init(u32_t arg1, u32_t arg2, u32_t arg3,
                                   u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_queue_cancel_wait(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_queue_alloc_append(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_queue_alloc_prepend(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_queue_get(u32_t arg1, u32_t arg2, u32_t arg3,
                                  u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_queue_is_empty(u32_t arg1, u32_t arg2, u32_t arg3,
                                       u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_queue_peek_head(u32_t arg1, u32_t arg2, u32_t arg3,
                                        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_queue_peek_tail(u32_t arg1, u32_t arg2, u32_t arg3,
                                        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_stack_alloc_init(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_stack_push(u32_t arg1, u32_t arg2, u32_t arg3,
                                   u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_stack_pop(u32_t arg1, u32_t arg2, u32_t arg3,
                                  u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_mutex_init(u32_t arg1, u32_t arg2, u32_t arg3,
                                   u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_mutex_lock(u32_t arg1, u32_t arg2, u32_t arg3,
                                   u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_mutex_unlock(u32_t arg1, u32_t arg2, u32_t arg3,
                                     u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_sem_init(u32_t arg1, u32_t arg2, u32_t arg3,
                                 u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_sem_take(u32_t arg1, u32_t arg2, u32_t arg3,
                                 u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_sem_give(u32_t arg1, u32_t arg2, u32_t arg3,
                                 u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_sem_reset(u32_t arg1, u32_t arg2, u32_t arg3,
                                  u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_sem_count_get(u32_t arg1, u32_t arg2, u32_t arg3,
                                      u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_alert_recv(u32_t arg1, u32_t arg2, u32_t arg3,
                                   u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_alert_send(u32_t arg1, u32_t arg2, u32_t arg3,
                                   u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_msgq_alloc_init(u32_t arg1, u32_t arg2, u32_t arg3,
                                        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_msgq_put(u32_t arg1, u32_t arg2, u32_t arg3,
                                 u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_msgq_get(u32_t arg1, u32_t arg2, u32_t arg3,
                                 u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_msgq_purge(u32_t arg1, u32_t arg2, u32_t arg3,
                                   u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_msgq_num_free_get(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_msgq_get_attrs(u32_t arg1, u32_t arg2, u32_t arg3,
                                       u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_msgq_num_used_get(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_pipe_alloc_init(u32_t arg1, u32_t arg2, u32_t arg3,
                                        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_pipe_put(u32_t arg1, u32_t arg2, u32_t arg3,
                                 u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_pipe_get(u32_t arg1, u32_t arg2, u32_t arg3,
                                 u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_poll(u32_t arg1, u32_t arg2, u32_t arg3,
                             u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_poll_signal_init(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_poll_signal_reset(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_poll_signal_check(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_poll_signal(u32_t arg1, u32_t arg2, u32_t arg3,
                                    u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_k_str_out(u32_t arg1, u32_t arg2, u32_t arg3,
                                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_pwm_pin_set_cycles(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_pwm_get_cycles_per_sec(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_rtc_read(u32_t arg1, u32_t arg2, u32_t arg3,
                               u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_rtc_enable(u32_t arg1, u32_t arg2, u32_t arg3,
                                 u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_rtc_disable(u32_t arg1, u32_t arg2, u32_t arg3,
                                  u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_rtc_reinit(u32_t arg1, u32_t arg2, u32_t arg3,
                                 u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_rtc_set_alarm(u32_t arg1, u32_t arg2, u32_t arg3,
                                    u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_rtc_get_pending_int(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_rtc_set_datetime(u32_t arg1, u32_t arg2, u32_t arg3,
                                       u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_rtc_get_time(u32_t arg1, u32_t arg2, u32_t arg3,
                                   u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_rtc_stop_timer(u32_t arg1, u32_t arg2, u32_t arg3,
                                     u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_rtc_cancel_alarm(u32_t arg1, u32_t arg2, u32_t arg3,
                                       u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_rtc_start_timer(u32_t arg1, u32_t arg2, u32_t arg3,
                                      u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_aio_cmp_disable(u32_t arg1, u32_t arg2, u32_t arg3,
                                      u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_aio_cmp_get_pending_int(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_i2c_configure(u32_t arg1, u32_t arg2, u32_t arg3,
                                    u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_i2c_transfer(u32_t arg1, u32_t arg2, u32_t arg3,
                                   u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_i2c_slave_register(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_i2c_slave_unregister(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_i2c_slave_driver_register(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_i2c_slave_driver_unregister(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_sensor_attr_set(u32_t arg1, u32_t arg2, u32_t arg3,
                                      u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_sensor_sample_fetch(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_sensor_sample_fetch_chan(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_sensor_channel_get(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_entropy_get_entropy(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_counter_start(u32_t arg1, u32_t arg2, u32_t arg3,
                                    u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_counter_stop(u32_t arg1, u32_t arg2, u32_t arg3,
                                   u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_counter_read(u32_t arg1, u32_t arg2, u32_t arg3,
                                   u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_counter_get_pending_int(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_can_send(u32_t arg1, u32_t arg2, u32_t arg3,
                               u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_can_get_msg(u32_t arg1, u32_t arg2, u32_t arg3,
                                  u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_can_set_callback(u32_t arg1, u32_t arg2, u32_t arg3,
                                       u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_pm_enter_low_power(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_pm_config_wakeup_pin(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_flash_read(u32_t arg1, u32_t arg2, u32_t arg3,
                                 u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_flash_write(u32_t arg1, u32_t arg2, u32_t arg3,
                                  u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_flash_erase(u32_t arg1, u32_t arg2, u32_t arg3,
                                  u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_flash_write_protection_set(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_flash_get_page_info_by_offs(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_flash_get_page_info_by_idx(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_flash_get_page_count(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_flash_get_write_block_size(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_dma_start(u32_t arg1, u32_t arg2, u32_t arg3,
                                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_dma_stop(u32_t arg1, u32_t arg2, u32_t arg3,
                               u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_gpio_config(u32_t arg1, u32_t arg2, u32_t arg3,
                                  u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_gpio_write(u32_t arg1, u32_t arg2, u32_t arg3,
                                 u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_gpio_read(u32_t arg1, u32_t arg2, u32_t arg3,
                                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_gpio_enable_callback(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_gpio_disable_callback(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_gpio_get_pending_int(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_uart_err_check(u32_t arg1, u32_t arg2, u32_t arg3,
                                     u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_uart_poll_in(u32_t arg1, u32_t arg2, u32_t arg3,
                                   u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_uart_poll_out(u32_t arg1, u32_t arg2, u32_t arg3,
                                    u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_uart_irq_tx_enable(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_uart_irq_tx_disable(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_uart_irq_rx_enable(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_uart_irq_rx_disable(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_uart_irq_err_enable(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_uart_irq_err_disable(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_uart_irq_is_pending(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_uart_irq_update(u32_t arg1, u32_t arg2, u32_t arg3,
                                      u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_uart_line_ctrl_set(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_uart_line_ctrl_get(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_uart_drv_cmd(u32_t arg1, u32_t arg2, u32_t arg3,
                                   u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_led_blink(u32_t arg1, u32_t arg2, u32_t arg3,
                                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_led_set_brightness(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_led_on(u32_t arg1, u32_t arg2, u32_t arg3,
                             u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_led_off(u32_t arg1, u32_t arg2, u32_t arg3,
                              u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_spi_transceive(u32_t arg1, u32_t arg2, u32_t arg3,
                                     u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_spi_release(u32_t arg1, u32_t arg2, u32_t arg3,
                                  u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_dcmi_start_streaming(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_dcmi_stop_streaming(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_dcmi_set_fmt_vid_cap(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_dcmi_get_fmt_vid_cap(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_dcmi_ioctl(u32_t arg1, u32_t arg2, u32_t arg3,
                                 u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_camera_set_power(u32_t arg1, u32_t arg2, u32_t arg3,
                                       u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_camera_set_fmt(u32_t arg1, u32_t arg2, u32_t arg3,
                                     u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_camera_get_fmt(u32_t arg1, u32_t arg2, u32_t arg3,
                                     u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_camera_ioctl(u32_t arg1, u32_t arg2, u32_t arg3,
                                   u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_fb_get_displayinfo(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_fb_ioctl(u32_t arg1, u32_t arg2, u32_t arg3,
                               u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_fb_fill_rect(u32_t arg1, u32_t arg2, u32_t arg3,
                                   u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_fb_copy_area(u32_t arg1, u32_t arg2, u32_t arg3,
                                   u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_fb_load_clut(u32_t arg1, u32_t arg2, u32_t arg3,
                                   u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_fb_alpha_blendingbulk(u32_t arg1, u32_t arg2, u32_t arg3,
        u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_fb_mix_colors(u32_t arg1, u32_t arg2, u32_t arg3,
                                    u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_fb_convert_color(u32_t arg1, u32_t arg2, u32_t arg3,
                                       u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_fb_mix_colorsbulk(u32_t arg1, u32_t arg2, u32_t arg3,
                                        u32_t arg4, u32_t arg5, u32_t arg6, u32_t arg7, u32_t arg8, u32_t arg9, void *ssf);

extern u32_t _handler_fb_draw_bitmapl8(u32_t arg1, u32_t arg2, u32_t arg3,
                                       u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_fb_scaler(u32_t arg1, u32_t arg, u32_t arg3,
                                u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler_z_errno(u32_t arg1, u32_t arg2, u32_t arg3,
                              u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler__ugelis_read(u32_t arg1, u32_t arg2, u32_t arg3,
                                   u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler__ugelis_write(u32_t arg1, u32_t arg2, u32_t arg3,
                                    u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler__ugelis_fputc(u32_t arg1, u32_t arg2, u32_t arg3,
                                    u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);

extern u32_t _handler__ugelis_fwrite(u32_t arg1, u32_t arg2, u32_t arg3,
                                     u32_t arg4, u32_t arg5, u32_t arg6, void *ssf);


#ifdef __cplusplus
}
#endif

#endif /* _ASMLANGUAGE */

#endif /* _UGELIS_SYSCALL_LIST_H_ */
