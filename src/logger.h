//
// Created by Iskandar Askarov on 3/2/21.
//

#ifndef ZIZIKA_LOGGER_H
#define ZIZIKA_LOGGER_H
#include "util.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>
#include <fcntl.h>
typedef struct logger_ {

    FILE *fp;
    void(*fp_info)(struct logger_ *, char *);
    void(*fp_error)(struct logger_ *, char *);
    void(*fp_warning)(struct logger_ *, char *);
    void(*fp_debug)(struct logger_ *, char *);
    char *(*fp_gettime)(struct logger_ *);

} _logger;

struct aplogger_struct{
    _logger *plogger;
    char *pipe_path;
};

_logger * init_logger(char *);
void destruct_logger(_logger *);

void serror(struct logger_ *, char *);
void info(struct logger_ *, char *);
void warning(struct logger_ *, char *);
void debug(struct logger_ *, char *);

static void *th_logger_cb(void *arg_struct);


#define gettime(X) time_t rawtime; \
				  time( &rawtime ); \
				  strftime(X, 18, "%Y%m%d-%H:%M:%S", localtime(&rawtime));


#endif //ZIZIKA_LOGGER_H
