#ifndef _COMMON_H
#define _COMMON_H

#include <stdlib.h>
#include <stdio.h>

/**
typedef struct {
	const char *type;
	const char *value;
} Param;
**/

typedef struct {
	const char *name;
	const char *type;
	const char *param;
	const char *path;
	const char *stubmd5;
	void *ptr;
} FunctionEnv;

extern FunctionEnv function_env;

void putstr_raw(const char *str, unsigned int size);
void randstr(char *str, unsigned int size, const char *charset);
void init_test();
void loop_test(void (*callback)(int argc, char *argv[]));
void test(int argc, char *argv[]);

#ifndef TARGET_PATH
#define TARGET_PATH
#endif

#ifndef STUB_C_MD5
#define STUB_C_MD5
#endif

#ifndef STRINGFY
#define _STRINGFY_HELPER(x) #x
#define STRINGFY(x) _STRINGFY_HELPER(x)
#endif

#define FUNCTION(func_type, func_name, ...) \
	__attribute__((constructor)) \
	static void _func_name##_register() { \
		function_env.name = #func_name; \
		function_env.type = #func_type; \
		function_env.param = #__VA_ARGS__; \
		function_env.ptr = &#func_name; \
	} func_type func_name (__VA_ARGS__)

#define UNUSED(x) (void)!(x)
#endif