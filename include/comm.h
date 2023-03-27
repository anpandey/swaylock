#ifndef _SWAYLOCK_COMM_H
#define _SWAYLOCK_COMM_H

#include <stdbool.h>

struct swaylock_password;

bool spawn_comm_child(void);
ssize_t read_comm_request(char **buf_ptr);
bool write_comm_reply(bool success);
// Requests the provided password to be checked. The password is always cleared
// when the function returns.
bool write_comm_request(struct swaylock_password *pw);
bool read_comm_reply(void);
// FD to poll for password authentication replies.
int get_comm_reply_fd(void);
// FD to poll for authentication messages.
bool write_comm_message(const char *buf, size_t len);
ssize_t read_comm_message(char *buf);
int get_comm_message_fd(void);

#endif
