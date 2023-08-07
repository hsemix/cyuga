
#ifndef ZEPHIR_KERNEL_CONCAT_H
#define ZEPHIR_KERNEL_CONCAT_H
#include <php.h>
#include <Zend/zend.h>
#include "kernel/main.h"
#define ZEPHIR_CONCAT_SSV(result, op1, op2, op3) \
	 zephir_concat_ssv(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, 0);
#define ZEPHIR_SCONCAT_SSV(result, op1, op2, op3) \
	 zephir_concat_ssv(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, 1);

#define ZEPHIR_CONCAT_SV(result, op1, op2) \
	 zephir_concat_sv(result, op1, sizeof(op1)-1, op2, 0);
#define ZEPHIR_SCONCAT_SV(result, op1, op2) \
	 zephir_concat_sv(result, op1, sizeof(op1)-1, op2, 1);

#define ZEPHIR_CONCAT_SVS(result, op1, op2, op3) \
	 zephir_concat_svs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, 0);
#define ZEPHIR_SCONCAT_SVS(result, op1, op2, op3) \
	 zephir_concat_svs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, 1);

#define ZEPHIR_CONCAT_SVSV(result, op1, op2, op3, op4) \
	 zephir_concat_svsv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, 0);
#define ZEPHIR_SCONCAT_SVSV(result, op1, op2, op3, op4) \
	 zephir_concat_svsv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, 1);

#define ZEPHIR_CONCAT_SVSVV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svsvv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, 0);
#define ZEPHIR_SCONCAT_SVSVV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svsvv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, 1);

#define ZEPHIR_CONCAT_SVV(result, op1, op2, op3) \
	 zephir_concat_svv(result, op1, sizeof(op1)-1, op2, op3, 0);
#define ZEPHIR_SCONCAT_SVV(result, op1, op2, op3) \
	 zephir_concat_svv(result, op1, sizeof(op1)-1, op2, op3, 1);

#define ZEPHIR_CONCAT_VS(result, op1, op2) \
	 zephir_concat_vs(result, op1, op2, sizeof(op2)-1, 0);
#define ZEPHIR_SCONCAT_VS(result, op1, op2) \
	 zephir_concat_vs(result, op1, op2, sizeof(op2)-1, 1);

#define ZEPHIR_CONCAT_VSSV(result, op1, op2, op3, op4) \
	 zephir_concat_vssv(result, op1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, op4, 0);
#define ZEPHIR_SCONCAT_VSSV(result, op1, op2, op3, op4) \
	 zephir_concat_vssv(result, op1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, op4, 1);

#define ZEPHIR_CONCAT_VSV(result, op1, op2, op3) \
	 zephir_concat_vsv(result, op1, op2, sizeof(op2)-1, op3, 0);
#define ZEPHIR_SCONCAT_VSV(result, op1, op2, op3) \
	 zephir_concat_vsv(result, op1, op2, sizeof(op2)-1, op3, 1);

#define ZEPHIR_CONCAT_VSVV(result, op1, op2, op3, op4) \
	 zephir_concat_vsvv(result, op1, op2, sizeof(op2)-1, op3, op4, 0);
#define ZEPHIR_SCONCAT_VSVV(result, op1, op2, op3, op4) \
	 zephir_concat_vsvv(result, op1, op2, sizeof(op2)-1, op3, op4, 1);

#define ZEPHIR_CONCAT_VV(result, op1, op2) \
	 zephir_concat_vv(result, op1, op2, 0);
#define ZEPHIR_SCONCAT_VV(result, op1, op2) \
	 zephir_concat_vv(result, op1, op2, 1);

#define ZEPHIR_CONCAT_VVV(result, op1, op2, op3) \
	 zephir_concat_vvv(result, op1, op2, op3, 0);
#define ZEPHIR_SCONCAT_VVV(result, op1, op2, op3) \
	 zephir_concat_vvv(result, op1, op2, op3, 1);

#define ZEPHIR_CONCAT_VVVVVV(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_vvvvvv(result, op1, op2, op3, op4, op5, op6, 0);
#define ZEPHIR_SCONCAT_VVVVVV(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_vvvvvv(result, op1, op2, op3, op4, op5, op6, 1);


void zephir_concat_ssv(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, zval *op3, int self_var);
void zephir_concat_sv(zval *result, const char *op1, uint32_t op1_len, zval *op2, int self_var);
void zephir_concat_svs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, int self_var);
void zephir_concat_svsv(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, int self_var);
void zephir_concat_svsvv(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, zval *op5, int self_var);
void zephir_concat_svv(zval *result, const char *op1, uint32_t op1_len, zval *op2, zval *op3, int self_var);
void zephir_concat_vs(zval *result, zval *op1, const char *op2, uint32_t op2_len, int self_var);
void zephir_concat_vssv(zval *result, zval *op1, const char *op2, uint32_t op2_len, const char *op3, uint32_t op3_len, zval *op4, int self_var);
void zephir_concat_vsv(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, int self_var);
void zephir_concat_vsvv(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, zval *op4, int self_var);
void zephir_concat_vv(zval *result, zval *op1, zval *op2, int self_var);
void zephir_concat_vvv(zval *result, zval *op1, zval *op2, zval *op3, int self_var);
void zephir_concat_vvvvvv(zval *result, zval *op1, zval *op2, zval *op3, zval *op4, zval *op5, zval *op6, int self_var);
void zephir_concat_function(zval *result, zval *op1, zval *op2);
#endif /* ZEPHIR_KERNEL_CONCAT_H */
