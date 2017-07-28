/**
 * @file
 *
 * @author jeff.daily@pnnl.gov
 *
 * Copyright (c) 2015 Battelle Memorial Institute.
 */
#include "config.h"

#include <stdlib.h>

#include <immintrin.h>

#include "parasail.h"
#include "parasail/memory.h"
#include "parasail/internal_avx.h"


#if HAVE_AVX2_MM256_INSERT_EPI32
#define _mm256_insert_epi32_rpl _mm256_insert_epi32
#else
static inline __m256i _mm256_insert_epi32_rpl(__m256i a, int32_t i, int imm) {
    __m256i_32_t A;
    A.m = a;
    A.v[imm] = i;
    return A.m;
}
#endif

#if HAVE_AVX2_MM256_EXTRACT_EPI32
#define _mm256_extract_epi32_rpl _mm256_extract_epi32
#else
static inline int32_t _mm256_extract_epi32_rpl(__m256i a, int imm) {
    __m256i_32_t A;
    A.m = a;
    return A.v[imm];
}
#endif

#define _mm256_cmplt_epi32_rpl(a,b) _mm256_cmpgt_epi32(b,a)

#define _mm256_srli_si256_rpl(a,imm) _mm256_or_si256(_mm256_slli_si256(_mm256_permute2x128_si256(a, a, _MM_SHUFFLE(3,0,0,1)), 16-imm), _mm256_srli_si256(a, imm))

#define _mm256_slli_si256_rpl(a,imm) _mm256_alignr_epi8(a, _mm256_permute2x128_si256(a, a, _MM_SHUFFLE(0,0,3,0)), 16-imm)


#ifdef PARASAIL_TABLE
static inline void arr_store_si256(
        int *array,
        __m256i vWH,
        int32_t i,
        int32_t s1Len,
        int32_t j,
        int32_t s2Len)
{
    if (0 <= i+0 && i+0 < s1Len && 0 <= j-0 && j-0 < s2Len) {
        array[(i+0)*s2Len + (j-0)] = (int32_t)_mm256_extract_epi32_rpl(vWH, 7);
    }
    if (0 <= i+1 && i+1 < s1Len && 0 <= j-1 && j-1 < s2Len) {
        array[(i+1)*s2Len + (j-1)] = (int32_t)_mm256_extract_epi32_rpl(vWH, 6);
    }
    if (0 <= i+2 && i+2 < s1Len && 0 <= j-2 && j-2 < s2Len) {
        array[(i+2)*s2Len + (j-2)] = (int32_t)_mm256_extract_epi32_rpl(vWH, 5);
    }
    if (0 <= i+3 && i+3 < s1Len && 0 <= j-3 && j-3 < s2Len) {
        array[(i+3)*s2Len + (j-3)] = (int32_t)_mm256_extract_epi32_rpl(vWH, 4);
    }
    if (0 <= i+4 && i+4 < s1Len && 0 <= j-4 && j-4 < s2Len) {
        array[(i+4)*s2Len + (j-4)] = (int32_t)_mm256_extract_epi32_rpl(vWH, 3);
    }
    if (0 <= i+5 && i+5 < s1Len && 0 <= j-5 && j-5 < s2Len) {
        array[(i+5)*s2Len + (j-5)] = (int32_t)_mm256_extract_epi32_rpl(vWH, 2);
    }
    if (0 <= i+6 && i+6 < s1Len && 0 <= j-6 && j-6 < s2Len) {
        array[(i+6)*s2Len + (j-6)] = (int32_t)_mm256_extract_epi32_rpl(vWH, 1);
    }
    if (0 <= i+7 && i+7 < s1Len && 0 <= j-7 && j-7 < s2Len) {
        array[(i+7)*s2Len + (j-7)] = (int32_t)_mm256_extract_epi32_rpl(vWH, 0);
    }
}
#endif

#ifdef PARASAIL_ROWCOL
static inline void arr_store_rowcol(
        int *row,
        int *col,
        __m256i vWH,
        int32_t i,
        int32_t s1Len,
        int32_t j,
        int32_t s2Len)
{
    if (i+0 == s1Len-1 && 0 <= j-0 && j-0 < s2Len) {
        row[j-0] = (int32_t)_mm256_extract_epi32_rpl(vWH, 7);
    }
    if (j-0 == s2Len-1 && 0 <= i+0 && i+0 < s1Len) {
        col[(i+0)] = (int32_t)_mm256_extract_epi32_rpl(vWH, 7);
    }
    if (i+1 == s1Len-1 && 0 <= j-1 && j-1 < s2Len) {
        row[j-1] = (int32_t)_mm256_extract_epi32_rpl(vWH, 6);
    }
    if (j-1 == s2Len-1 && 0 <= i+1 && i+1 < s1Len) {
        col[(i+1)] = (int32_t)_mm256_extract_epi32_rpl(vWH, 6);
    }
    if (i+2 == s1Len-1 && 0 <= j-2 && j-2 < s2Len) {
        row[j-2] = (int32_t)_mm256_extract_epi32_rpl(vWH, 5);
    }
    if (j-2 == s2Len-1 && 0 <= i+2 && i+2 < s1Len) {
        col[(i+2)] = (int32_t)_mm256_extract_epi32_rpl(vWH, 5);
    }
    if (i+3 == s1Len-1 && 0 <= j-3 && j-3 < s2Len) {
        row[j-3] = (int32_t)_mm256_extract_epi32_rpl(vWH, 4);
    }
    if (j-3 == s2Len-1 && 0 <= i+3 && i+3 < s1Len) {
        col[(i+3)] = (int32_t)_mm256_extract_epi32_rpl(vWH, 4);
    }
    if (i+4 == s1Len-1 && 0 <= j-4 && j-4 < s2Len) {
        row[j-4] = (int32_t)_mm256_extract_epi32_rpl(vWH, 3);
    }
    if (j-4 == s2Len-1 && 0 <= i+4 && i+4 < s1Len) {
        col[(i+4)] = (int32_t)_mm256_extract_epi32_rpl(vWH, 3);
    }
    if (i+5 == s1Len-1 && 0 <= j-5 && j-5 < s2Len) {
        row[j-5] = (int32_t)_mm256_extract_epi32_rpl(vWH, 2);
    }
    if (j-5 == s2Len-1 && 0 <= i+5 && i+5 < s1Len) {
        col[(i+5)] = (int32_t)_mm256_extract_epi32_rpl(vWH, 2);
    }
    if (i+6 == s1Len-1 && 0 <= j-6 && j-6 < s2Len) {
        row[j-6] = (int32_t)_mm256_extract_epi32_rpl(vWH, 1);
    }
    if (j-6 == s2Len-1 && 0 <= i+6 && i+6 < s1Len) {
        col[(i+6)] = (int32_t)_mm256_extract_epi32_rpl(vWH, 1);
    }
    if (i+7 == s1Len-1 && 0 <= j-7 && j-7 < s2Len) {
        row[j-7] = (int32_t)_mm256_extract_epi32_rpl(vWH, 0);
    }
    if (j-7 == s2Len-1 && 0 <= i+7 && i+7 < s1Len) {
        col[(i+7)] = (int32_t)_mm256_extract_epi32_rpl(vWH, 0);
    }
}
#endif

#ifdef PARASAIL_TABLE
#define FNAME parasail_nw_stats_table_diag_avx2_256_32
#else
#ifdef PARASAIL_ROWCOL
#define FNAME parasail_nw_stats_rowcol_diag_avx2_256_32
#else
#define FNAME parasail_nw_stats_diag_avx2_256_32
#endif
#endif

parasail_result_t* FNAME(
        const char * const restrict _s1, const int s1Len,
        const char * const restrict _s2, const int s2Len,
        const int open, const int gap, const parasail_matrix_t *matrix)
{
    const int32_t N = 8; /* number of values in vector */
    const int32_t PAD = N-1;
    const int32_t PAD2 = PAD*2;
    const int32_t s1Len_PAD = s1Len+PAD;
    const int32_t s2Len_PAD = s2Len+PAD;
    int32_t * const restrict s1      = parasail_memalign_int32_t(32, s1Len+PAD);
    int32_t * const restrict s2B     = parasail_memalign_int32_t(32, s2Len+PAD2);
    int32_t * const restrict _H_pr = parasail_memalign_int32_t(32, s2Len+PAD2);
    int32_t * const restrict _HM_pr = parasail_memalign_int32_t(32, s2Len+PAD2);
    int32_t * const restrict _HS_pr = parasail_memalign_int32_t(32, s2Len+PAD2);
    int32_t * const restrict _HL_pr = parasail_memalign_int32_t(32, s2Len+PAD2);
    int32_t * const restrict _F_pr = parasail_memalign_int32_t(32, s2Len+PAD2);
    int32_t * const restrict _FM_pr = parasail_memalign_int32_t(32, s2Len+PAD2);
    int32_t * const restrict _FS_pr = parasail_memalign_int32_t(32, s2Len+PAD2);
    int32_t * const restrict _FL_pr = parasail_memalign_int32_t(32, s2Len+PAD2);
    int32_t * const restrict s2 = s2B+PAD; /* will allow later for negative indices */
    int32_t * const restrict H_pr = _H_pr+PAD;
    int32_t * const restrict HM_pr = _HM_pr+PAD;
    int32_t * const restrict HS_pr = _HS_pr+PAD;
    int32_t * const restrict HL_pr = _HL_pr+PAD;
    int32_t * const restrict F_pr = _F_pr+PAD;
    int32_t * const restrict FM_pr = _FM_pr+PAD;
    int32_t * const restrict FS_pr = _FS_pr+PAD;
    int32_t * const restrict FL_pr = _FL_pr+PAD;
#ifdef PARASAIL_TABLE
    parasail_result_t *result = parasail_result_new_table3(s1Len, s2Len);
#else
#ifdef PARASAIL_ROWCOL
    parasail_result_t *result = parasail_result_new_rowcol3(s1Len, s2Len);
#else
    parasail_result_t *result = parasail_result_new();
#endif
#endif
    int32_t i = 0;
    int32_t j = 0;
    int32_t end_query = s1Len-1;
    int32_t end_ref = s2Len-1;
    const int32_t NEG_LIMIT = (-open < matrix->min ?
        INT32_MIN + open : INT32_MIN - matrix->min) + 1;
    const int32_t POS_LIMIT = INT32_MAX - matrix->max - 1;
    int32_t score = NEG_LIMIT;
    int32_t matches = NEG_LIMIT;
    int32_t similar = NEG_LIMIT;
    int32_t length = NEG_LIMIT;
    __m256i vNegLimit = _mm256_set1_epi32(NEG_LIMIT);
    __m256i vPosLimit = _mm256_set1_epi32(POS_LIMIT);
    __m256i vSaturationCheckMin = vPosLimit;
    __m256i vSaturationCheckMax = vNegLimit;
    __m256i vNegInf = _mm256_set1_epi32(NEG_LIMIT);
    __m256i vOpen = _mm256_set1_epi32(open);
    __m256i vGap  = _mm256_set1_epi32(gap);
    __m256i vZero = _mm256_set1_epi32(0);
    __m256i vNegInf0 = _mm256_insert_epi32_rpl(vZero, NEG_LIMIT, 7);
    __m256i vOne = _mm256_set1_epi32(1);
    __m256i vN = _mm256_set1_epi32(N);
    __m256i vGapN = _mm256_set1_epi32(gap*N);
    __m256i vNegOne = _mm256_set1_epi32(-1);
    __m256i vI = _mm256_set_epi32(0,1,2,3,4,5,6,7);
    __m256i vJreset = _mm256_set_epi32(0,-1,-2,-3,-4,-5,-6,-7);
    __m256i vMaxH = vNegInf;
    __m256i vMaxM = vNegInf;
    __m256i vMaxS = vNegInf;
    __m256i vMaxL = vNegInf;
    __m256i vILimit = _mm256_set1_epi32(s1Len);
    __m256i vILimit1 = _mm256_sub_epi32(vILimit, vOne);
    __m256i vJLimit = _mm256_set1_epi32(s2Len);
    __m256i vJLimit1 = _mm256_sub_epi32(vJLimit, vOne);
    __m256i vIBoundary = _mm256_set_epi32(
            -open-0*gap,
            -open-1*gap,
            -open-2*gap,
            -open-3*gap,
            -open-4*gap,
            -open-5*gap,
            -open-6*gap,
            -open-7*gap);

    /* convert _s1 from char to int in range 0-23 */
    for (i=0; i<s1Len; ++i) {
        s1[i] = matrix->mapper[(unsigned char)_s1[i]];
    }
    /* pad back of s1 with dummy values */
    for (i=s1Len; i<s1Len_PAD; ++i) {
        s1[i] = 0; /* point to first matrix row because we don't care */
    }

    /* convert _s2 from char to int in range 0-23 */
    for (j=0; j<s2Len; ++j) {
        s2[j] = matrix->mapper[(unsigned char)_s2[j]];
    }
    /* pad front of s2 with dummy values */
    for (j=-PAD; j<0; ++j) {
        s2[j] = 0; /* point to first matrix row because we don't care */
    }
    /* pad back of s2 with dummy values */
    for (j=s2Len; j<s2Len_PAD; ++j) {
        s2[j] = 0; /* point to first matrix row because we don't care */
    }

    /* set initial values for stored row */
    for (j=0; j<s2Len; ++j) {
        H_pr[j] = -open - j*gap;
        HM_pr[j] = 0;
        HS_pr[j] = 0;
        HL_pr[j] = 0;
        F_pr[j] = NEG_LIMIT;
        FM_pr[j] = 0;
        FS_pr[j] = 0;
        FL_pr[j] = 0;
    }
    /* pad front of stored row values */
    for (j=-PAD; j<0; ++j) {
        H_pr[j] = 0;
        HM_pr[j] = 0;
        HS_pr[j] = 0;
        HL_pr[j] = 0;
        F_pr[j] = 0;
        FM_pr[j] = 0;
        FS_pr[j] = 0;
        FL_pr[j] = 0;
    }
    /* pad back of stored row values */
    for (j=s2Len; j<s2Len+PAD; ++j) {
        H_pr[j] = 0;
        HM_pr[j] = 0;
        HS_pr[j] = 0;
        HL_pr[j] = 0;
        F_pr[j] = 0;
        FM_pr[j] = 0;
        FS_pr[j] = 0;
        FL_pr[j] = 0;
    }
    H_pr[-1] = 0; /* upper left corner */

    /* iterate over query sequence */
    for (i=0; i<s1Len; i+=N) {
        __m256i case1 = vZero;
        __m256i case2 = vZero;
        __m256i vNH = vZero;
        __m256i vNM = vZero;
        __m256i vNS = vZero;
        __m256i vNL = vZero;
        __m256i vWH = vZero;
        __m256i vWM = vZero;
        __m256i vWS = vZero;
        __m256i vWL = vZero;
        __m256i vE = vNegInf0;
        __m256i vE_opn = vNegInf;
        __m256i vE_ext = vNegInf;
        __m256i vEM = vZero;
        __m256i vES = vZero;
        __m256i vEL = vZero;
        __m256i vF = vNegInf0;
        __m256i vF_opn = vNegInf;
        __m256i vF_ext = vNegInf;
        __m256i vFM = vZero;
        __m256i vFS = vZero;
        __m256i vFL = vZero;
        __m256i vJ = vJreset;
        __m256i vs1 = _mm256_set_epi32(
                s1[i+0],
                s1[i+1],
                s1[i+2],
                s1[i+3],
                s1[i+4],
                s1[i+5],
                s1[i+6],
                s1[i+7]);
        __m256i vs2 = vNegInf;
        const int * const restrict matrow0 = &matrix->matrix[matrix->size*s1[i+0]];
        const int * const restrict matrow1 = &matrix->matrix[matrix->size*s1[i+1]];
        const int * const restrict matrow2 = &matrix->matrix[matrix->size*s1[i+2]];
        const int * const restrict matrow3 = &matrix->matrix[matrix->size*s1[i+3]];
        const int * const restrict matrow4 = &matrix->matrix[matrix->size*s1[i+4]];
        const int * const restrict matrow5 = &matrix->matrix[matrix->size*s1[i+5]];
        const int * const restrict matrow6 = &matrix->matrix[matrix->size*s1[i+6]];
        const int * const restrict matrow7 = &matrix->matrix[matrix->size*s1[i+7]];
        vNH = _mm256_insert_epi32_rpl(vNH, H_pr[-1], 7);
        vWH = _mm256_insert_epi32_rpl(vWH, -open - i*gap, 7);
        H_pr[-1] = -open - (i+N)*gap;
        /* iterate over database sequence */
        for (j=0; j<s2Len+PAD; ++j) {
            __m256i vMat;
            __m256i vNWH = vNH;
            __m256i vNWM = vNM;
            __m256i vNWS = vNS;
            __m256i vNWL = vNL;
            vNH = _mm256_srli_si256_rpl(vWH, 4);
            vNH = _mm256_insert_epi32_rpl(vNH, H_pr[j], 7);
            vNM = _mm256_srli_si256_rpl(vWM, 4);
            vNM = _mm256_insert_epi32_rpl(vNM, HM_pr[j], 7);
            vNS = _mm256_srli_si256_rpl(vWS, 4);
            vNS = _mm256_insert_epi32_rpl(vNS, HS_pr[j], 7);
            vNL = _mm256_srli_si256_rpl(vWL, 4);
            vNL = _mm256_insert_epi32_rpl(vNL, HL_pr[j], 7);
            vF = _mm256_srli_si256_rpl(vF, 4);
            vF = _mm256_insert_epi32_rpl(vF, F_pr[j], 7);
            vFM = _mm256_srli_si256_rpl(vFM, 4);
            vFM = _mm256_insert_epi32_rpl(vFM, FM_pr[j], 7);
            vFS = _mm256_srli_si256_rpl(vFS, 4);
            vFS = _mm256_insert_epi32_rpl(vFS, FS_pr[j], 7);
            vFL = _mm256_srli_si256_rpl(vFL, 4);
            vFL = _mm256_insert_epi32_rpl(vFL, FL_pr[j], 7);
            vF_opn = _mm256_sub_epi32(vNH, vOpen);
            vF_ext = _mm256_sub_epi32(vF, vGap);
            vF = _mm256_max_epi32(vF_opn, vF_ext);
            case1 = _mm256_cmpgt_epi32(vF_opn, vF_ext);
            vFM = _mm256_blendv_epi8(vFM, vNM, case1);
            vFS = _mm256_blendv_epi8(vFS, vNS, case1);
            vFL = _mm256_blendv_epi8(vFL, vNL, case1);
            vFL = _mm256_add_epi32(vFL, vOne);
            vE_opn = _mm256_sub_epi32(vWH, vOpen);
            vE_ext = _mm256_sub_epi32(vE, vGap);
            vE = _mm256_max_epi32(vE_opn, vE_ext);
            case1 = _mm256_cmpgt_epi32(vE_opn, vE_ext);
            vEM = _mm256_blendv_epi8(vEM, vWM, case1);
            vES = _mm256_blendv_epi8(vES, vWS, case1);
            vEL = _mm256_blendv_epi8(vEL, vWL, case1);
            vEL = _mm256_add_epi32(vEL, vOne);
            vs2 = _mm256_srli_si256_rpl(vs2, 4);
            vs2 = _mm256_insert_epi32_rpl(vs2, s2[j], 7);
            vMat = _mm256_set_epi32(
                    matrow0[s2[j-0]],
                    matrow1[s2[j-1]],
                    matrow2[s2[j-2]],
                    matrow3[s2[j-3]],
                    matrow4[s2[j-4]],
                    matrow5[s2[j-5]],
                    matrow6[s2[j-6]],
                    matrow7[s2[j-7]]
                    );
            vNWH = _mm256_add_epi32(vNWH, vMat);
            vWH = _mm256_max_epi32(vNWH, vE);
            vWH = _mm256_max_epi32(vWH, vF);
            case1 = _mm256_cmpeq_epi32(vWH, vNWH);
            case2 = _mm256_cmpeq_epi32(vWH, vF);
            vWM = _mm256_blendv_epi8(
                    _mm256_blendv_epi8(vEM, vFM, case2),
                    _mm256_add_epi32(vNWM,
                        _mm256_and_si256(
                            _mm256_cmpeq_epi32(vs1,vs2),
                            vOne)),
                    case1);
            vWS = _mm256_blendv_epi8(
                    _mm256_blendv_epi8(vES, vFS, case2),
                    _mm256_add_epi32(vNWS,
                        _mm256_and_si256(
                            _mm256_cmpgt_epi32(vMat,vZero),
                            vOne)),
                    case1);
            vWL = _mm256_blendv_epi8(
                    _mm256_blendv_epi8(vEL, vFL, case2),
                    _mm256_add_epi32(vNWL, vOne), case1);
            /* as minor diagonal vector passes across the j=-1 boundary,
             * assign the appropriate boundary conditions */
            {
                __m256i cond = _mm256_cmpeq_epi32(vJ,vNegOne);
                vWH = _mm256_blendv_epi8(vWH, vIBoundary, cond);
                vWM = _mm256_andnot_si256(cond, vWM);
                vWS = _mm256_andnot_si256(cond, vWS);
                vWL = _mm256_andnot_si256(cond, vWL);
                vE = _mm256_blendv_epi8(vE, vNegInf, cond);
                vEM = _mm256_andnot_si256(cond, vEM);
                vES = _mm256_andnot_si256(cond, vES);
                vEL = _mm256_andnot_si256(cond, vEL);
            }
            vSaturationCheckMin = _mm256_min_epi32(vSaturationCheckMin, vWH);
            vSaturationCheckMax = _mm256_max_epi32(vSaturationCheckMax, vWH);
            vSaturationCheckMax = _mm256_max_epi32(vSaturationCheckMax, vWM);
            vSaturationCheckMax = _mm256_max_epi32(vSaturationCheckMax, vWS);
            vSaturationCheckMax = _mm256_max_epi32(vSaturationCheckMax, vWL);
            vSaturationCheckMax = _mm256_max_epi32(vSaturationCheckMax, vWL);
            vSaturationCheckMax = _mm256_max_epi32(vSaturationCheckMax, vJ);
#ifdef PARASAIL_TABLE
            arr_store_si256(result->score_table, vWH, i, s1Len, j, s2Len);
            arr_store_si256(result->matches_table, vWM, i, s1Len, j, s2Len);
            arr_store_si256(result->similar_table, vWS, i, s1Len, j, s2Len);
            arr_store_si256(result->length_table, vWL, i, s1Len, j, s2Len);
#endif
#ifdef PARASAIL_ROWCOL
            arr_store_rowcol(result->score_row, result->score_col, vWH, i, s1Len, j, s2Len);
            arr_store_rowcol(result->matches_row, result->matches_col, vWM, i, s1Len, j, s2Len);
            arr_store_rowcol(result->similar_row, result->similar_col, vWS, i, s1Len, j, s2Len);
            arr_store_rowcol(result->length_row, result->length_col, vWL, i, s1Len, j, s2Len);
#endif
            H_pr[j-7] = (int32_t)_mm256_extract_epi32_rpl(vWH,0);
            HM_pr[j-7] = (int32_t)_mm256_extract_epi32_rpl(vWM,0);
            HS_pr[j-7] = (int32_t)_mm256_extract_epi32_rpl(vWS,0);
            HL_pr[j-7] = (int32_t)_mm256_extract_epi32_rpl(vWL,0);
            F_pr[j-7] = (int32_t)_mm256_extract_epi32_rpl(vF,0);
            FM_pr[j-7] = (int32_t)_mm256_extract_epi32_rpl(vFM,0);
            FS_pr[j-7] = (int32_t)_mm256_extract_epi32_rpl(vFS,0);
            FL_pr[j-7] = (int32_t)_mm256_extract_epi32_rpl(vFL,0);
            /* as minor diagonal vector passes across table, extract
               last table value at the i,j bound */
            {
                __m256i cond_valid_I = _mm256_cmpeq_epi32(vI, vILimit1);
                __m256i cond_valid_J = _mm256_cmpeq_epi32(vJ, vJLimit1);
                __m256i cond_all = _mm256_and_si256(cond_valid_I, cond_valid_J);
                vMaxH = _mm256_blendv_epi8(vMaxH, vWH, cond_all);
                vMaxM = _mm256_blendv_epi8(vMaxM, vWM, cond_all);
                vMaxS = _mm256_blendv_epi8(vMaxS, vWS, cond_all);
                vMaxL = _mm256_blendv_epi8(vMaxL, vWL, cond_all);
            }
            vJ = _mm256_add_epi32(vJ, vOne);
        }
        vI = _mm256_add_epi32(vI, vN);
        vSaturationCheckMax = _mm256_max_epi32(vSaturationCheckMax, vI);
        vIBoundary = _mm256_sub_epi32(vIBoundary, vGapN);
    }

    /* max in vMaxH */
    for (i=0; i<N; ++i) {
        int32_t value;
        value = (int32_t) _mm256_extract_epi32_rpl(vMaxH, 7);
        if (value > score) {
            score = value;
            matches = (int32_t) _mm256_extract_epi32_rpl(vMaxM, 7);
            similar = (int32_t) _mm256_extract_epi32_rpl(vMaxS, 7);
            length= (int32_t) _mm256_extract_epi32_rpl(vMaxL, 7);
        }
        vMaxH = _mm256_slli_si256_rpl(vMaxH, 4);
        vMaxM = _mm256_slli_si256_rpl(vMaxM, 4);
        vMaxS = _mm256_slli_si256_rpl(vMaxS, 4);
        vMaxL = _mm256_slli_si256_rpl(vMaxL, 4);
    }

    if (_mm256_movemask_epi8(_mm256_or_si256(
            _mm256_cmplt_epi32_rpl(vSaturationCheckMin, vNegLimit),
            _mm256_cmpgt_epi32(vSaturationCheckMax, vPosLimit)))) {
        result->saturated = 1;
        score = 0;
        matches = 0;
        similar = 0;
        length = 0;
        end_query = 0;
        end_ref = 0;
    }

    result->score = score;
    result->matches = matches;
    result->similar = similar;
    result->length = length;
    result->end_query = end_query;
    result->end_ref = end_ref;
    result->flag = PARASAIL_FLAG_NW | PARASAIL_FLAG_DIAG
        | PARASAIL_FLAG_STATS
        | PARASAIL_FLAG_BITS_32 | PARASAIL_FLAG_LANES_8;
#ifdef PARASAIL_TABLE
    result->flag |= PARASAIL_FLAG_TABLE;
#endif
#ifdef PARASAIL_ROWCOL
    result->flag |= PARASAIL_FLAG_ROWCOL;
#endif

    parasail_free(_FL_pr);
    parasail_free(_FS_pr);
    parasail_free(_FM_pr);
    parasail_free(_F_pr);
    parasail_free(_HL_pr);
    parasail_free(_HS_pr);
    parasail_free(_HM_pr);
    parasail_free(_H_pr);
    parasail_free(s2B);
    parasail_free(s1);

    return result;
}


