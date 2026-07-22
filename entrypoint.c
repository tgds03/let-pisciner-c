#include "common.h"

__attribute__((constructor))
static void fileinfo_register() {
	function_env.path = STRINGFY(TARGET_PATH);
	function_env.stubmd5 = STRINGFY(STUB_C_MD5);
}

int main() {
	init_test();
	loop_test(test);
	return 0;
}
