
#include <unistd.h>
#include <pthread.h>
#include "clog/clog.h"

void *f1(void *arg) {
    log_trace("f1 start");
    for (int i = 0; i < 3; i++) {
        log_info("f1: %d", i);
    }
    log_trace("f1 end");
    return NULL;
}

void *f2(void *arg) {
    log_trace("f2 start");
    for (int i = 0; i < 3; i++) {
        log_info("f2: %d", i);
    }
    log_trace("f2 end");
    return NULL;
}

void *f3(void *arg) {
    log_trace("f3 start");
    for (int i = 0; i < 3; i++) {
        log_info("f3: %d", i);
    }
    log_trace("f3 end");
    return NULL;
}

int main() {
    log_trace("main start");

    clog_set_level(CLOG_LEVEL_TRACE);

    int res;
    pthread_t t1, t2, t3;
    log_trace("main: create thread1");
    res = pthread_create(&t1, NULL, f1, NULL);
    log_check(res == 0, "thread1 creation failed");

    log_trace("main: create thread2");
    res = pthread_create(&t2, NULL, f2, NULL);
    log_check(res == 0, "thread2 creation failed");

    log_trace("main: create thread3");
    res = pthread_create(&t3, NULL, f3, NULL);
    log_check(res == 0, "thread3 creation failed");

    log_info("main: sleep for 5 seconds");
    sleep(5);

    res = pthread_join(t1, NULL);
    log_check(res == 0, "thread1 join failed");

    res = pthread_join(t2, NULL);
    log_check(res == 0, "thread2 join failed");

    res = pthread_join(t3, NULL);
    log_check(res == 0, "thread3 join failed");

    log_trace("main end");
    return 0;
}