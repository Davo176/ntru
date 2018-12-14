#ifndef POLY_H
#define POLY_H

#include <stdint.h>
#include "params.h"

typedef struct{
  uint16_t coeffs[NTRU_N];
} poly;

void poly_Rq_sum_zero_tobytes(unsigned char *r, const poly *a);
void poly_Rq_sum_zero_frombytes(poly *r, const unsigned char *a);

void poly_S3_tobytes(unsigned char msg[NTRU_PACK_TRINARY_BYTES], const poly *r);
void poly_S3_frombytes(poly *r, const unsigned char msg[NTRU_PACK_TRINARY_BYTES]);

void poly_S3_sample(poly *r, const unsigned char *seed, const unsigned char nonce);
void poly_S3_sample_plus(poly *r, const unsigned char *seed, const unsigned char nonce);

void poly_Rq_mul(poly *r, const poly *a, const poly *b);
void poly_Rq_mul_x_minus_1(poly *r, const poly *a);
void poly_S3_mul(poly *r, const poly *a, const poly *b);
void poly_S3_to_Rq(poly *r, const poly *a);
void poly_Rq_to_S3(poly *r, const poly *a);

void poly_Rq_inv(poly *r, const poly *a);
void poly_S3_inv(poly *r, const poly *a);

void poly_Z3_to_Zq(poly *r);
void poly_trinary_Zq_to_Z3(poly *r);

#endif