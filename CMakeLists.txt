cmake_minimum_required(VERSION 3.17)
project(NumeroAstronomico C)

set(CMAKE_C_STANDARD 11)

include_directories(header)

add_executable(NumeroAstronomico
        header/aritm_op.h
        header/creacion_op.h
        header/errores.h
        header/NumeroAstronomico.h
        header/persist.h
        header/salida_op.h
        header/ui_helper.h
        src/operaciones/creacion_op.c
        src/operaciones/errores.c
        src/operaciones/salida_op.c
        src/ui/ui_helper.c
        src/ui/main.c src/operaciones/aritm_op.c src/operaciones/persistencia_op.c)
