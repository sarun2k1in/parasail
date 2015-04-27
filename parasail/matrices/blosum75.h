/**
 * @file
 *
 * @author jeff.daily@pnnl.gov
 *
 * Copyright (c) 2014 Battelle Memorial Institute.
 *
 * All rights reserved. No warranty, explicit or implicit, provided.
 *
 * This file was converted to C code from the raw file found at
 * ftp://ftp.cbi.pku.edu.cn/pub/software/blast/matrices/BLOSUM75, the
 * Center for Bioinformatics, Peking University, China.
 */
#ifndef _PARASAIL_BLOSUM75_H_
#define _PARASAIL_BLOSUM75_H_

#include "parasail.h"
#include "blosum_map.h"

/* #  Matrix made by matblas from blosum75.iij */
/* #  * column uses minimum score */
/* #  BLOSUM Clustered Scoring Matrix in 1/2 Bit Units */
/* #  Blocks Database = /data/blocks_5.0/blocks.dat */
/* #  Cluster Percentage: >= 75 */
/* #  Entropy =   0.9077, Expected =  -0.6845 */

static const int8_t parasail_blosum75_[] = {
/*        A   R   N   D   C   Q   E   G   H   I   L   K   M   F   P   S   T   W   Y   V   B   Z   X   * */
/* A */   4, -2, -2, -2, -1, -1, -1,  0, -2, -2, -2, -1, -1, -3, -1,  1,  0, -3, -2,  0, -2, -1, -1, -5,
/* R */  -2,  6, -1, -2, -4,  1,  0, -3,  0, -3, -3,  2, -2, -3, -2, -1, -1, -3, -2, -3, -1,  0, -1, -5,
/* N */  -2, -1,  6,  1, -3,  0, -1, -1,  0, -4, -4,  0, -3, -4, -3,  0,  0, -4, -3, -3,  3,  0, -1, -5,
/* D */  -2, -2,  1,  6, -4, -1,  1, -2, -1, -4, -4, -1, -4, -4, -2, -1, -1, -5, -4, -4,  4,  1, -2, -5,
/* C */  -1, -4, -3, -4,  9, -3, -5, -3, -4, -1, -2, -4, -2, -2, -4, -1, -1, -3, -3, -1, -4, -4, -2, -5,
/* Q */  -1,  1,  0, -1, -3,  6,  2, -2,  1, -3, -3,  1,  0, -4, -2,  0, -1, -2, -2, -2,  0,  3, -1, -5,
/* E */  -1,  0, -1,  1, -5,  2,  5, -3,  0, -4, -4,  1, -2, -4, -1,  0, -1, -4, -3, -3,  1,  4, -1, -5,
/* G */   0, -3, -1, -2, -3, -2, -3,  6, -2, -5, -4, -2, -3, -4, -3, -1, -2, -3, -4, -4, -1, -2, -2, -5,
/* H */  -2,  0,  0, -1, -4,  1,  0, -2,  8, -4, -3, -1, -2, -2, -2, -1, -2, -2,  2, -4, -1,  0, -1, -5,
/* I */  -2, -3, -4, -4, -1, -3, -4, -5, -4,  4,  1, -3,  1,  0, -3, -3, -1, -3, -2,  3, -4, -4, -2, -5,
/* L */  -2, -3, -4, -4, -2, -3, -4, -4, -3,  1,  4, -3,  2,  0, -3, -3, -2, -2, -1,  1, -4, -3, -1, -5,
/* K */  -1,  2,  0, -1, -4,  1,  1, -2, -1, -3, -3,  5, -2, -4, -1,  0, -1, -4, -2, -3, -1,  1, -1, -5,
/* M */  -1, -2, -3, -4, -2,  0, -2, -3, -2,  1,  2, -2,  6,  0, -3, -2, -1, -2, -2,  1, -3, -2, -1, -5,
/* F */  -3, -3, -4, -4, -2, -4, -4, -4, -2,  0,  0, -4,  0,  6, -4, -3, -2,  1,  3, -1, -4, -4, -2, -5,
/* P */  -1, -2, -3, -2, -4, -2, -1, -3, -2, -3, -3, -1, -3, -4,  8, -1, -1, -5, -4, -3, -2, -2, -2, -5,
/* S */   1, -1,  0, -1, -1,  0,  0, -1, -1, -3, -3,  0, -2, -3, -1,  5,  1, -3, -2, -2,  0,  0, -1, -5,
/* T */   0, -1,  0, -1, -1, -1, -1, -2, -2, -1, -2, -1, -1, -2, -1,  1,  5, -3, -2,  0, -1, -1, -1, -5,
/* W */  -3, -3, -4, -5, -3, -2, -4, -3, -2, -3, -2, -4, -2,  1, -5, -3, -3, 11,  2, -3, -5, -3, -3, -5,
/* Y */  -2, -2, -3, -4, -3, -2, -3, -4,  2, -2, -1, -2, -2,  3, -4, -2, -2,  2,  7, -2, -3, -3, -2, -5,
/* V */   0, -3, -3, -4, -1, -2, -3, -4, -4,  3,  1, -3,  1, -1, -3, -2,  0, -3, -2,  4, -4, -3, -1, -5,
/* B */  -2, -1,  3,  4, -4,  0,  1, -1, -1, -4, -4, -1, -3, -4, -2,  0, -1, -5, -3, -4,  4,  0, -2, -5,
/* Z */  -1,  0,  0,  1, -4,  3,  4, -2,  0, -4, -3,  1, -2, -4, -2,  0, -1, -3, -3, -3,  0,  4, -1, -5,
/* X */  -1, -1, -1, -2, -2, -1, -1, -2, -1, -2, -1, -1, -1, -2, -2, -1, -1, -3, -2, -1, -2, -1, -1, -5,
/* * */  -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,  1
};

static const int parasail_blosum75__[24][24] = {
/*        A   R   N   D   C   Q   E   G   H   I   L   K   M   F   P   S   T   W   Y   V   B   Z   X   * */
/* A */{  4, -2, -2, -2, -1, -1, -1,  0, -2, -2, -2, -1, -1, -3, -1,  1,  0, -3, -2,  0, -2, -1, -1, -5},
/* R */{ -2,  6, -1, -2, -4,  1,  0, -3,  0, -3, -3,  2, -2, -3, -2, -1, -1, -3, -2, -3, -1,  0, -1, -5},
/* N */{ -2, -1,  6,  1, -3,  0, -1, -1,  0, -4, -4,  0, -3, -4, -3,  0,  0, -4, -3, -3,  3,  0, -1, -5},
/* D */{ -2, -2,  1,  6, -4, -1,  1, -2, -1, -4, -4, -1, -4, -4, -2, -1, -1, -5, -4, -4,  4,  1, -2, -5},
/* C */{ -1, -4, -3, -4,  9, -3, -5, -3, -4, -1, -2, -4, -2, -2, -4, -1, -1, -3, -3, -1, -4, -4, -2, -5},
/* Q */{ -1,  1,  0, -1, -3,  6,  2, -2,  1, -3, -3,  1,  0, -4, -2,  0, -1, -2, -2, -2,  0,  3, -1, -5},
/* E */{ -1,  0, -1,  1, -5,  2,  5, -3,  0, -4, -4,  1, -2, -4, -1,  0, -1, -4, -3, -3,  1,  4, -1, -5},
/* G */{  0, -3, -1, -2, -3, -2, -3,  6, -2, -5, -4, -2, -3, -4, -3, -1, -2, -3, -4, -4, -1, -2, -2, -5},
/* H */{ -2,  0,  0, -1, -4,  1,  0, -2,  8, -4, -3, -1, -2, -2, -2, -1, -2, -2,  2, -4, -1,  0, -1, -5},
/* I */{ -2, -3, -4, -4, -1, -3, -4, -5, -4,  4,  1, -3,  1,  0, -3, -3, -1, -3, -2,  3, -4, -4, -2, -5},
/* L */{ -2, -3, -4, -4, -2, -3, -4, -4, -3,  1,  4, -3,  2,  0, -3, -3, -2, -2, -1,  1, -4, -3, -1, -5},
/* K */{ -1,  2,  0, -1, -4,  1,  1, -2, -1, -3, -3,  5, -2, -4, -1,  0, -1, -4, -2, -3, -1,  1, -1, -5},
/* M */{ -1, -2, -3, -4, -2,  0, -2, -3, -2,  1,  2, -2,  6,  0, -3, -2, -1, -2, -2,  1, -3, -2, -1, -5},
/* F */{ -3, -3, -4, -4, -2, -4, -4, -4, -2,  0,  0, -4,  0,  6, -4, -3, -2,  1,  3, -1, -4, -4, -2, -5},
/* P */{ -1, -2, -3, -2, -4, -2, -1, -3, -2, -3, -3, -1, -3, -4,  8, -1, -1, -5, -4, -3, -2, -2, -2, -5},
/* S */{  1, -1,  0, -1, -1,  0,  0, -1, -1, -3, -3,  0, -2, -3, -1,  5,  1, -3, -2, -2,  0,  0, -1, -5},
/* T */{  0, -1,  0, -1, -1, -1, -1, -2, -2, -1, -2, -1, -1, -2, -1,  1,  5, -3, -2,  0, -1, -1, -1, -5},
/* W */{ -3, -3, -4, -5, -3, -2, -4, -3, -2, -3, -2, -4, -2,  1, -5, -3, -3, 11,  2, -3, -5, -3, -3, -5},
/* Y */{ -2, -2, -3, -4, -3, -2, -3, -4,  2, -2, -1, -2, -2,  3, -4, -2, -2,  2,  7, -2, -3, -3, -2, -5},
/* V */{  0, -3, -3, -4, -1, -2, -3, -4, -4,  3,  1, -3,  1, -1, -3, -2,  0, -3, -2,  4, -4, -3, -1, -5},
/* B */{ -2, -1,  3,  4, -4,  0,  1, -1, -1, -4, -4, -1, -3, -4, -2,  0, -1, -5, -3, -4,  4,  0, -2, -5},
/* Z */{ -1,  0,  0,  1, -4,  3,  4, -2,  0, -4, -3,  1, -2, -4, -2,  0, -1, -3, -3, -3,  0,  4, -1, -5},
/* X */{ -1, -1, -1, -2, -2, -1, -1, -2, -1, -2, -1, -1, -1, -2, -2, -1, -1, -3, -2, -1, -2, -1, -1, -5},
/* * */{ -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,  1}
};

static const parasail_matrix_t parasail_blosum75 = {
    "blosum75",
    parasail_blosum75_,
    parasail_blosum75__,
    parasail_blosum_map,
    24
};

#endif /* _PARASAIL_BLOSUM75_H_ */
