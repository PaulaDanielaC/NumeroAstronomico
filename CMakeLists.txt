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
        header/op_helper.h
        src/creacion_op.c
        src/errores.c
        src/salida_op.c
        src/ui/op_helper.c
        src/ui/main.c src/aritm_op.c src/persistencia_op.c src/utils.c header/utils.h)
