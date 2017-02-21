#include "demo.h"
// all zlog-api is thread-safe 

int main(int argc, char** argv)
{
	int rc;
	zlog_category_t *z_sub1, *z_sub2, *z_all;
	char buf[20] = "this is a c_str.";
	rc = zlog_init("demo.conf");
	if (rc) {
		printf("init failed\n");
		return -1;
	}

	z_sub1 = zlog_get_category("sys_sub1");
	z_sub2 = zlog_get_category("sys_sub2");
	z_all = zlog_get_category("othersOrAll");
	if (!z_sub1 || !z_sub2 || !z_all) {
		printf("get category fail\n");
		zlog_fini();
		return -2;
	}

	// log-level test, greater than rule-level and output.
	zlog_info(z_sub1, "hello, zlog-sub1");
	zlog_debug(z_sub1, "hello, zlog-sub1");
	// output c_str buf 
	zlog_info(z_sub1, buf);

	// can open more than one category
	zlog_info(z_sub2, "hello, zlog-sub%d", 2);

	// match which not in category 
	zlog_info(z_all, "%s", "hello, zlog-others or all");

	// zlog macros
	// zlog_fatal(cat, format, ...)
	// zlog_error(cat, format, ...)
	// zlog_warn(cat, format, ...)
	// zlog_notice(cat, format, ...)
	// zlog_info(cat, format, ...)
	// zlog_debug(cat, format, ...)

	zlog_fini();
	return 0;
}
