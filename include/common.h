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
	void *func_ptr;
} FunctionInfo;

static FunctionInfo target_info;

void putstr_raw(const char *str, unsigned int size);
void randstr(char *str, unsigned int size, const char *charset);
void init_test(const char *filepath);
void loop_test(void (*callback)(int argc, char *argv[]));

#define FUNCTION(func_type, func_name, ...) \
	__attribute__((constructor)) \
	static void _func_name##_register() { \
		target_info.name = #func_name; \
		target_info.type = #func_type; \
		target_info.param = #__VA_ARGS__; \
		target_info.func_ptr = &#func_name; \
	} func_type func_name (__VA_ARGS__)
