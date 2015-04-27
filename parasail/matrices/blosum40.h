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
 * ftp://ftp.cbi.pku.edu.cn/pub/software/blast/matrices/BLOSUM40, the
 * Center for Bioinformatics, Peking University, China.
 */
#ifndef _PARASAIL_BLOSUM40_H_
#define _PARASAIL_BLOSUM40_H_

#include "parasail.h"
#include "blosum_map.h"

/* #  Matrix made by matblas from blosum40.iij */
/* #  * column uses minimum score */
/* #  BLOSUM Clustered Scoring Matrix in 1/4 Bit Units */
/* #  Blocks Database = /data/blocks_5.0/blocks.dat */
/* #  Cluster Percentage: >= 40 */
/* #  Entropy =   0.2851, Expected =  -0.2090 */

static const int8_t parasail_blosum40_[] = {
/*        A   R   N   D   C   Q   E   G   H   I   L   K   M   F   P   S   T   W   Y   V   B   Z   X   * */
/* A */   5, -2, -1, -1, -2,  0, -1,  1, -2, -1, -2, -1, -1, -3, -2,  1,  0, -3, -2,  0, -1, -1,  0, -6,
/* R */  -2,  9,  0, -1, -3,  2, -1, -3,  0, -3, -2,  3, -1, -2, -3, -1, -2, -2, -1, -2, -1,  0, -1, -6,
/* N */  -1,  0,  8,  2, -2,  1, -1,  0,  1, -2, -3,  0, -2, -3, -2,  1,  0, -4, -2, -3,  4,  0, -1, -6,
/* D */  -1, -1,  2,  9, -2, -1,  2, -2,  0, -4, -3,  0, -3, -4, -2,  0, -1, -5, -3, -3,  6,  1, -1, -6,
/* C */  -2, -3, -2, -2, 16, -4, -2, -3, -4, -4, -2, -3, -3, -2, -5, -1, -1, -6, -4, -2, -2, -3, -2, -6,
/* Q */   0,  2,  1, -1, -4,  8,  2, -2,  0, -3, -2,  1, -1, -4, -2,  1, -1, -1, -1, -3,  0,  4, -1, -6,
/* E */  -1, -1, -1,  2, -2,  2,  7, -3,  0, -4, -2,  1, -2, -3,  0,  0, -1, -2, -2, -3,  1,  5, -1, -6,
/* G */   1, -3,  0, -2, -3, -2, -3,  8, -2, -4, -4, -2, -2, -3, -1,  0, -2, -2, -3, -4, -1, -2, -1, -6,
/* H */  -2,  0,  1,  0, -4,  0,  0, -2, 13, -3, -2, -1,  1, -2, -2, -1, -2, -5,  2, -4,  0,  0, -1, -6,
/* I */  -1, -3, -2, -4, -4, -3, -4, -4, -3,  6,  2, -3,  1,  1, -2, -2, -1, -3,  0,  4, -3, -4, -1, -6,
/* L */  -2, -2, -3, -3, -2, -2, -2, -4, -2,  2,  6, -2,  3,  2, -4, -3, -1, -1,  0,  2, -3, -2, -1, -6,
/* K */  -1,  3,  0,  0, -3,  1,  1, -2, -1, -3, -2,  6, -1, -3, -1,  0,  0, -2, -1, -2,  0,  1, -1, -6,
/* M */  -1, -1, -2, -3, -3, -1, -2, -2,  1,  1,  3, -1,  7,  0, -2, -2, -1, -2,  1,  1, -3, -2,  0, -6,
/* F */  -3, -2, -3, -4, -2, -4, -3, -3, -2,  1,  2, -3,  0,  9, -4, -2, -1,  1,  4,  0, -3, -4, -1, -6,
/* P */  -2, -3, -2, -2, -5, -2,  0, -1, -2, -2, -4, -1, -2, -4, 11, -1,  0, -4, -3, -3, -2, -1, -2, -6,
/* S */   1, -1,  1,  0, -1,  1,  0,  0, -1, -2, -3,  0, -2, -2, -1,  5,  2, -5, -2, -1,  0,  0,  0, -6,
/* T */   0, -2,  0, -1, -1, -1, -1, -2, -2, -1, -1,  0, -1, -1,  0,  2,  6, -4, -1,  1,  0, -1,  0, -6,
/* W */  -3, -2, -4, -5, -6, -1, -2, -2, -5, -3, -1, -2, -2,  1, -4, -5, -4, 19,  3, -3, -4, -2, -2, -6,
/* Y */  -2, -1, -2, -3, -4, -1, -2, -3,  2,  0,  0, -1,  1,  4, -3, -2, -1,  3,  9, -1, -3, -2, -1, -6,
/* V */   0, -2, -3, -3, -2, -3, -3, -4, -4,  4,  2, -2,  1,  0, -3, -1,  1, -3, -1,  5, -3, -3, -1, -6,
/* B */  -1, -1,  4,  6, -2,  0,  1, -1,  0, -3, -3,  0, -3, -3, -2,  0,  0, -4, -3, -3,  5,  2, -1, -6,
/* Z */  -1,  0,  0,  1, -3,  4,  5, -2,  0, -4, -2,  1, -2, -4, -1,  0, -1, -2, -2, -3,  2,  5, -1, -6,
/* X */   0, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1,  0, -1, -2,  0,  0, -2, -1, -1, -1, -1, -1, -6,
/* * */  -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6,  1
};

static const int parasail_blosum40__[24][24] = {
/*        A   R   N   D   C   Q   E   G   H   I   L   K   M   F   P   S   T   W   Y   V   B   Z   X   * */
/* A */{  5, -2, -1, -1, -2,  0, -1,  1, -2, -1, -2, -1, -1, -3, -2,  1,  0, -3, -2,  0, -1, -1,  0, -6},
/* R */{ -2,  9,  0, -1, -3,  2, -1, -3,  0, -3, -2,  3, -1, -2, -3, -1, -2, -2, -1, -2, -1,  0, -1, -6},
/* N */{ -1,  0,  8,  2, -2,  1, -1,  0,  1, -2, -3,  0, -2, -3, -2,  1,  0, -4, -2, -3,  4,  0, -1, -6},
/* D */{ -1, -1,  2,  9, -2, -1,  2, -2,  0, -4, -3,  0, -3, -4, -2,  0, -1, -5, -3, -3,  6,  1, -1, -6},
/* C */{ -2, -3, -2, -2, 16, -4, -2, -3, -4, -4, -2, -3, -3, -2, -5, -1, -1, -6, -4, -2, -2, -3, -2, -6},
/* Q */{  0,  2,  1, -1, -4,  8,  2, -2,  0, -3, -2,  1, -1, -4, -2,  1, -1, -1, -1, -3,  0,  4, -1, -6},
/* E */{ -1, -1, -1,  2, -2,  2,  7, -3,  0, -4, -2,  1, -2, -3,  0,  0, -1, -2, -2, -3,  1,  5, -1, -6},
/* G */{  1, -3,  0, -2, -3, -2, -3,  8, -2, -4, -4, -2, -2, -3, -1,  0, -2, -2, -3, -4, -1, -2, -1, -6},
/* H */{ -2,  0,  1,  0, -4,  0,  0, -2, 13, -3, -2, -1,  1, -2, -2, -1, -2, -5,  2, -4,  0,  0, -1, -6},
/* I */{ -1, -3, -2, -4, -4, -3, -4, -4, -3,  6,  2, -3,  1,  1, -2, -2, -1, -3,  0,  4, -3, -4, -1, -6},
/* L */{ -2, -2, -3, -3, -2, -2, -2, -4, -2,  2,  6, -2,  3,  2, -4, -3, -1, -1,  0,  2, -3, -2, -1, -6},
/* K */{ -1,  3,  0,  0, -3,  1,  1, -2, -1, -3, -2,  6, -1, -3, -1,  0,  0, -2, -1, -2,  0,  1, -1, -6},
/* M */{ -1, -1, -2, -3, -3, -1, -2, -2,  1,  1,  3, -1,  7,  0, -2, -2, -1, -2,  1,  1, -3, -2,  0, -6},
/* F */{ -3, -2, -3, -4, -2, -4, -3, -3, -2,  1,  2, -3,  0,  9, -4, -2, -1,  1,  4,  0, -3, -4, -1, -6},
/* P */{ -2, -3, -2, -2, -5, -2,  0, -1, -2, -2, -4, -1, -2, -4, 11, -1,  0, -4, -3, -3, -2, -1, -2, -6},
/* S */{  1, -1,  1,  0, -1,  1,  0,  0, -1, -2, -3,  0, -2, -2, -1,  5,  2, -5, -2, -1,  0,  0,  0, -6},
/* T */{  0, -2,  0, -1, -1, -1, -1, -2, -2, -1, -1,  0, -1, -1,  0,  2,  6, -4, -1,  1,  0, -1,  0, -6},
/* W */{ -3, -2, -4, -5, -6, -1, -2, -2, -5, -3, -1, -2, -2,  1, -4, -5, -4, 19,  3, -3, -4, -2, -2, -6},
/* Y */{ -2, -1, -2, -3, -4, -1, -2, -3,  2,  0,  0, -1,  1,  4, -3, -2, -1,  3,  9, -1, -3, -2, -1, -6},
/* V */{  0, -2, -3, -3, -2, -3, -3, -4, -4,  4,  2, -2,  1,  0, -3, -1,  1, -3, -1,  5, -3, -3, -1, -6},
/* B */{ -1, -1,  4,  6, -2,  0,  1, -1,  0, -3, -3,  0, -3, -3, -2,  0,  0, -4, -3, -3,  5,  2, -1, -6},
/* Z */{ -1,  0,  0,  1, -3,  4,  5, -2,  0, -4, -2,  1, -2, -4, -1,  0, -1, -2, -2, -3,  2,  5, -1, -6},
/* X */{  0, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1,  0, -1, -2,  0,  0, -2, -1, -1, -1, -1, -1, -6},
/* * */{ -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6,  1}
};

static const parasail_matrix_t parasail_blosum40 = {
    "blosum40",
    parasail_blosum40_,
    parasail_blosum40__,
    parasail_blosum_map,
    24
};

#endif /* _PARASAIL_BLOSUM40_H_ */
