#ifndef PERSIST_H
#define PERSIST_H

#include <stdio.h>
#include "NumeroAstronomico.h"

void read(NumeroAstronomico*);
void write(NumeroAstronomico*, FILE*);

#endif