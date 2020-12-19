#include <pthread.h>
#include <stdbool.h>
#include "c9.h"

enum {
    ALTID_SUCCESS= 0,
    ALTID_FAILURE= 1,
    
    MAINBUF= 0,
    STATBUF= 1,
    TITLBUF= 2,
    TABSBUF= 3,

	/* Has entry is set when we find a service through our callback */
    HAS_ENTRY = (1 << 0),
    CONNECTED = (1 << 1),

    SCROLLSTEP = -30,
};

typedef struct Conn Conn;
struct Conn {
    /* events callback? */
    /* open fds, etc */
	C9ctx ctx;
};

typedef struct Buffer Buffer;
struct Buffer {
    char name[256];
    int  unread;
    bool notify;
    Buffer *next;
};

typedef struct Service Service;
struct Service {
    char name[256];
    char addr[256];
    int status;
    Conn *conn;
    Buffer *current; /* current will always be top of the list */
    Service *next;
};


pthread_mutex_t lock; 
Buffer *list_tabs(void);
void* initmdns(void*);
void swap(Buffer*);
void freebuff(Buffer*);
void scanmdns(Service**);
void freeservice(Service*);
void send_input(const char *);
void write_file(int, const char *);
void draw_loop(Service*);
void connect_svc(Service*);
