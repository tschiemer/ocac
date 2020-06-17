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

        src/include/ocac/arch.h
        src/include/ocac/class.h
        src/include/ocac/obj.h
        src/include/ocac/debug.h
        src/include/ocac/def.h
        src/include/ocac/opt.h

        impl/occclasses/root.h
        impl/occclasses/managers/manager.h
        impl/occclasses/managers/devicemanager.h
)

set(OCAC_CORE_SOURCE_FILES
        src/core/class.c
        src/core/def.c
        src/core/obj.c

        src/core/occ/datatypes.c
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
        "${OCAC_IMPL_DIR}/occclasses/root.h"
        "${OCAC_IMPL_DIR}/occclasses/managers/manager.h"
        "${OCAC_IMPL_DIR}/occclasses/managers/devicemanager.h"
)

set(OCAC_IMPL_SOURCE_FILES
        "${OCAC_IMPL_DIR}/occclasses/root.c"
        "${OCAC_IMPL_DIR}/occclasses/managers/manager.c"
        "${OCAC_IMPL_DIR}/occclasses/managers/devicemanager.c"
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

set_property(TARGET ocacimpl PROPERTY C_STANDARD 99)
set_property(TARGET ocacimpl PROPERTY LINKER_LANGUAGE C)
target_link_libraries(ocacimpl ocaccore)




if(CMAKE_BUILD_TYPE MATCHES Debug)
    foreach(TARGET IN LISTS OCAC_TARGET_LIST)
        target_compile_definitions(${TARGET} PUBLIC DEBUG=1)
    endforeach()
elseif(CMAKE_BUILD_TYPE MATCHES Release)
    foreach(TARGET IN LISTS OCAC_TARGET_LIST)
        target_compile_definitions(${TARGET} PUBLIC RELEASE=1)
    endforeach()
endif()