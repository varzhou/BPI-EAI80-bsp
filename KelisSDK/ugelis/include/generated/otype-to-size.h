/* Non device/stack objects */
case K_OBJ_ALERT: return sizeof(struct k_alert);
case K_OBJ_MSGQ: return sizeof(struct k_msgq);
case K_OBJ_MUTEX: return sizeof(struct k_mutex);
case K_OBJ_PIPE: return sizeof(struct k_pipe);
case K_OBJ_QUEUE: return sizeof(struct k_queue);
case K_OBJ_POLL_SIGNAL: return sizeof(struct k_poll_signal);
case K_OBJ_SEM: return sizeof(struct k_sem);
case K_OBJ_STACK: return sizeof(struct k_stack);
case K_OBJ_THREAD: return sizeof(struct k_thread);
case K_OBJ_TIMER: return sizeof(struct k_timer);
