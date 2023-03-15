// add-nbo.h
#pragma once
#include <stdint.h>
#include <stdio.h>

uint32_t add(uint32_t, uint32_t);
uint32_t my_ntohl(uint32_t);
uint32_t my_htonl(uint32_t);

uint32_t bfile_read(char filename[], uint32_t *v1);