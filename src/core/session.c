//
// Created by Philip Tschiemer on 21.06.20.
//

#include "ocac/session.h"

#if OCAC_USE_SESSION_POOL == 1
static struct ocac_session pool[OCAC_SESSION_MAX_COUNT];
#else // OCAC_USE_SESSION_POOL == 0

#if !defined(OCAC_SESSION_MALLOC)
#error OCAC_SESSION_MALLOC not defined
#endif
#if !defined(OCAC_SESSION_FREE)
#error OCAC_SESSION_FREE not defined
#endif

static struct ocac_session * first;

#endif //OCAC_USE_SESSION_POOL

static volatile u16_t count;

u16_t ocac_session_count(void)
{
    return count;
}

void ocac_session_init(void)
{
    #if OCAC_USE_SESSION_POOL == 1
    ocac_memset((void*)pool, 0, sizeof(pool));
    #else
    first = NULL;
    #endif

    count = 0;
}

void ocac_session_deinit(void)
{
    #if OCAC_USE_SESSION_POOL == 1

    for(int i = 0; i < OCAC_SESSION_MAX_COUNT; i++){
        if ( (pool[i].status & OCAC_SESSION_STATUS_USED) == OCAC_SESSION_STATUS_USED){
            ocac_session_delete(&pool[i]);
        }
    }

    #else

    while(first != NULL){
        ocac_session_delete(first);
    }

    #endif
}

struct ocac_session * ocac_session_get_by_address(struct ocac_net_addr * addr)
{
    OCAC_ASSERT("addr != NULL", addr != NULL);

    #if OCAC_USE_SESSION_POOL == 1
    for(int i = 0; i < OCAC_SESSION_MAX_COUNT; i++){
        if ( (pool[i].status & OCAC_SESSION_STATUS_USED) == OCAC_SESSION_STATUS_USED && ocac_net_addreq(&pool[i].addr, addr)){
            ocac_session_delete(&pool[i]);
        }
    }
    return NULL;
    #else
    struct ocac_session * ptr = first;
    while(ptr != NULL && ocac_net_addreq(&ptr->addr, addr) == 0){
        ptr = ptr->next;
    }
    return ptr;
    #endif
}


struct ocac_session * ocac_session_new_from_address(struct ocac_net_addr * addr)
{
    OCAC_ASSERT("addr != NULL", addr != NULL);

    if (count >= OCAC_SESSION_MAX_COUNT) {
        return NULL;
    }
    count ++;

    struct ocac_session * session = NULL;

    #if OCAC_USE_SESSION_POOL == 1
    for(int i = 0; i < OCAC_SESSION_MAX_COUNT && session == NULL; i++){
        if ( (pool[i].status & OCAC_SESSION_STATUS_USED) == 0){
            session = &pool[i];
        }
    }
    #else
    session = OCAC_SESSION_MALLOC(sizeof(struct ocac_session));
    #endif

    OCAC_ASSERT("session != NULL", session != NULL);

    session->status = OCAC_SESSION_STATUS_USED;

    ocac_memcpy(&session->addr, addr, sizeof(struct ocac_net_addr));

    ocac_timer_init( &session->timeout );

    #if OCAC_USE_SESSION_POOL == 0
    session->next = first;
    first = session;
    #endif

    return session;
}

void ocac_session_delete(struct ocac_session * session)
{
    OCAC_ASSERT("session != NULL", session != NULL);

    session->status = 0;

    ocac_timer_deinit( &session->timeout );

    #if OCAC_USE_SESSION_POOL == 1

    ocac_memset((void*)session, 0, sizeof(struct ocac_session));

    #else

    // remove session from linked list
    if (first == session){
        first = session->next;
    } else {
        struct ocac_session * before = first;

        OCAC_ASSERT("before != NULL", before != NULL);

        while (before->next != session){

            OCAC_ASSERT("before->next != NULL", before->next != NULL);

            before = before->next;
        }

        before->next = session->next;
    }

    OCAC_SESSION_FREE(session);

    #endif

    OCAC_ASSERT("count > 0", count > 0);

    count--;
}


struct ocac_session * ocac_session_get_timedout(void)
{
    struct ocac_session * session = NULL;

    #if OCAC_USE_SESSION_POOL==1

    for(int i = 0; i < OCAC_SESSION_MAX_COUNT && session == NULL; i++){
        if ( (pool[i].status & OCAC_SESSION_STATUS_USED) == OCAC_SESSION_STATUS_USED && pool[i].timeout.expired){
            session = &pool[i];
        }
    }

    #else

    session = first;

    while(session != NULL && !session->timeout.expired){
        session = session->next;
    }
    #endif

    return session;
}