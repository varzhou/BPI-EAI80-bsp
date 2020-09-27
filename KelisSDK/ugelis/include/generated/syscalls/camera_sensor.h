
/* auto-generated by gen_syscalls.py, don't edit */

#ifndef _ASMLANGUAGE

#include <syscall_list.h>
#include <syscall_macros.h>

#ifdef __cplusplus
extern "C" {
#endif

K_SYSCALL_DECLARE2(K_SYSCALL_CAMERA_SET_POWER, camera_set_power, int, struct device *, dev, bool, on);

K_SYSCALL_DECLARE4(K_SYSCALL_CAMERA_SET_FMT, camera_set_fmt, int, struct device *, dev, enum camera_output_format, format, enum camera_mode_id, id, enum camera_frame_rate, frame_rate);

K_SYSCALL_DECLARE2(K_SYSCALL_CAMERA_GET_FMT, camera_get_fmt, int, struct device *, dev, struct video_format *, fmt);

K_SYSCALL_DECLARE3(K_SYSCALL_CAMERA_IOCTL, camera_ioctl, int, struct device *, dev, uint32_t, cmd, void *, arg);

#ifdef __cplusplus
}
#endif

#endif
