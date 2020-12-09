cmake_minimum_required(VERSION 3.3)
project(ocac)


if(NOT USER_INCLUDE_DIRS)
    set(USER_INCLUDE_DIRS
        "contrib/ports/unix/port/include"
    )
endif()


if(NOT OCAC_IMPL_DIR)
    set(OCAC_IMPL_DIR "impl")
endif()


set(OCAC_DEV_UTILS TRUE)


set(OCAC_CORE_INCLUDES
        src/include/ocac/occ/datatypes/agent.h
        src/include/ocac/occ/datatypes/base.h
        src/include/ocac/occ/datatypes/blockmatrix.h
        src/include/ocac/occ/datatypes/eventsubscription.h
        src/include/ocac/occ/datatypes/framework.h
        src/include/ocac/occ/datatypes/library.h
        src/include/ocac/occ/datatypes/management.h
        src/include/ocac/occ/datatypes/network.h
        src/include/ocac/occ/datatypes/task.h
        src/include/ocac/occ/datatypes/time.h
        src/include/ocac/occ/datatypes/worker.h
        src/include/ocac/ocp/ocp1.h

        src/include/ocac/opt.h
        src/include/ocac/arch.h
        src/include/ocac/debug.h

        src/include/ocac/class.h
        src/include/ocac/def.h
        src/include/ocac/obj.h
        src/include/ocac/utf8.h
        src/include/ocac/session.h
        src/include/ocac/net.h
        src/include/ocac/reset.h
        src/include/ocac/api.h

        src/include/ocac/host/timer.h
        src/include/ocac/host/sock.h
)

set(OCAC_CORE_SOURCE_FILES
        src/core/occ/datatypes.c

        src/core/class.c
        src/core/def.c
        src/core/obj.c
        src/core/utf8.c
        src/core/session.c
        src/core/net.c
        src/core/reset.c
        src/core/api.c
)


list(APPEND OCAC_TARGET_LIST ocaccore)

add_library(ocaccore STATIC
        ${OCAC_CORE_INCLUDES}
        ${OCAC_CORE_SOURCE_FILES}
        ${USER_INCLUDES}
)
target_include_directories(ocaccore PUBLIC
        src/include
        src/third_party
        "${OCAC_IMPL_DIR}"
        "${USER_INCLUDE_DIRS}"
)

set_property(TARGET ocaccore PROPERTY C_STANDARD 99)
set_property(TARGET ocaccore PROPERTY LINKER_LANGUAGE C)


set(OCAC_IMPL_INCLUDES
        "${OCAC_IMPL_DIR}/ocacopts.h"
        "${OCAC_IMPL_DIR}/obj_registry.h"
        "${OCAC_IMPL_DIR}/occclasses/root.h"
        "${OCAC_IMPL_DIR}/occclasses/workers/worker.h"
        "${OCAC_IMPL_DIR}/occclasses/workers/block.h"
        "${OCAC_IMPL_DIR}/occclasses/managers/abstract.h"
        "${OCAC_IMPL_DIR}/occclasses/managers/device.h"
        "${OCAC_IMPL_DIR}/occclasses/managers/subscription.h"
)

set(OCAC_IMPL_SOURCE_FILES
        "${OCAC_IMPL_DIR}/obj_registry.c"
        "${OCAC_IMPL_DIR}/occclasses/root.c"
        "${OCAC_IMPL_DIR}/occclasses/workers/worker.c"
        "${OCAC_IMPL_DIR}/occclasses/workers/block.c"
        "${OCAC_IMPL_DIR}/occclasses/managers/abstract.c"
        "${OCAC_IMPL_DIR}/occclasses/managers/device.c"
        "${OCAC_IMPL_DIR}/occclasses/managers/subscription.c"
)


list(APPEND OCAC_TARGET_LIST ocacimpl)

add_library(ocacimpl STATIC
        ${OCAC_IMPL_INCLUDES}
        ${OCAC_IMPL_SOURCE_FILES}
)

#target_include_directories(ocacimpl PUBLIC
#        "${OCAC_IMPL_DIR}"
#        "${USER_INCLUDES}"
#)

set_property(TARGET ocacimpl PROPERTY C_STANDARD 11)
set_property(TARGET ocacimpl PROPERTY LINKER_LANGUAGE C)
target_link_libraries(ocacimpl ocaccore)


### DEV UTILS
list(APPEND OCAC_TARGET_LIST ocacmethod)
add_executable(ocacmethod EXCLUDE_FROM_ALL contrib/dev/method.c)
target_include_directories(ocacmethod PUBLIC
        src/include
        src/third_party
        "${OCAC_IMPL_DIR}"
        ${USER_INCLUDE_DIRS}
        )
target_link_libraries(ocacmethod ocaccore ocacimpl)
set_property(TARGET ocacmethod PROPERTY C_STANDARD 99)
set_property(TARGET ocacmethod PROPERTY LINKER_LANGUAGE C)


list(APPEND OCAC_TARGET_LIST ocacparamg)
add_executable(ocacparamg EXCLUDE_FROM_ALL contrib/dev/genparam.c)
target_include_directories(ocacparamg PUBLIC
        src/include
        src/third_party
        "${OCAC_IMPL_DIR}"
        ${USER_INCLUDE_DIRS}
        )
target_link_libraries(ocacparamg ocaccore ocacimpl)
set_property(TARGET ocacparamg PROPERTY C_STANDARD 99)
set_property(TARGET ocacparamg PROPERTY LINKER_LANGUAGE C)


list(APPEND OCAC_TARGET_LIST ocacparamp)
add_executable(ocacparamp EXCLUDE_FROM_ALL contrib/dev/parseparam.c)
target_include_directories(ocacparamp PUBLIC
        src/include
        src/third_party
        "${OCAC_IMPL_DIR}"
        ${USER_INCLUDE_DIRS}
        )
target_link_libraries(ocacparamp ocaccore ocacimpl)
set_property(TARGET ocacparamp PROPERTY C_STANDARD 99)
set_property(TARGET ocacparamp PROPERTY LINKER_LANGUAGE C)


add_custom_target(dev-utils DEPENDS ocacmethod ocacparamg ocacparamp)



if(CMAKE_BUILD_TYPE MATCHES Debug)
    foreach(TARGET IN LISTS OCAC_TARGET_LIST)
        target_compile_definitions(${TARGET} PUBLIC DEBUG=1)
    endforeach()
elseif(CMAKE_BUILD_TYPE MATCHES Release)
    foreach(TARGET IN LISTS OCAC_TARGET_LIST)
        target_compile_definitions(${TARGET} PUBLIC RELEASE=1)
    endforeach()
endif()



add_executable(testcc test.c )
target_link_libraries(testcc ocaccore)
target_include_directories(testcc PUBLIC
        src/include
        src/third_party
        "${OCAC_IMPL_DIR}"
        ${USER_INCLUDE_DIRS}
)
set_property(TARGET testcc PROPERTY C_STANDARD 99)
set_property(TARGET testcc PROPERTY LINKER_LANGUAGE C)