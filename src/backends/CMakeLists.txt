function(validate_backend_mode NAME VALUE)
    set(valid auto static shared dynamic)
    list(FIND valid "${VALUE}" idx)
    if(idx EQUAL -1)
        message(FATAL_ERROR
            "Invalid value for ${NAME}: '${VALUE}'. "
            "Allowed values: auto, static, shared, dynamic."
        )
    endif()
endfunction()

if(H2OT3_BACKEND_SUPPORT_DUMMY)
    add_subdirectory(dummy)
endif()

if(H2OT3_BACKEND_SUPPORT_XCB)
    add_subdirectory(xcb)
endif()