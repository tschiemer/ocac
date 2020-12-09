/**
 * MIT License
 *
 * Copyright (c) 2020 Philip Tschiemer, https://github.com/tschiemer/ocac
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include "ocac/session.h"

#if OCAC_USE_SESSION_POOL == 1
static struct ocac_session pool[OCAC_SESSION_MAX_COUNT];
#else // OCAC_USE_SESSION_POOL == 0

#if !defined(OCAC_SESSION_NEW)
#error OCAC_SESSION_NEW not defined
#endif
#if !defined(OCAC_SESSION_DELETE)
#error OCAC_SESSION_DELETE not defined
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
        if ( (pool[i].status & OCAC_SESSION_STATUS_USED) == OCAC_SESSION_STATUS_USED && ocac_net_addreq(&pool[i].sock.addr, addr)){
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
    session = OCAC_SESSION_NEW();
    #endif

    OCAC_ASSERT("session != NULL", session != NULL);

    session->status = OCAC_SESSION_STATUS_USED;

    ocac_memcpy(&session->sock.addr, addr, sizeof(struct ocac_net_addr));

    ocac_timer_init( &session->timeout );

    #if OCAC_USE_SESSION_POOL == 0
    session->next = first;
    first = session;
    #endif

//    session->sock.impl = sock_impl;

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

    OCAC_SESSION_DELETE(session);

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