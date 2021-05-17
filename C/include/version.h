/*************************************************************************
	> File Name: version.h
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Mon 17 May 2021 06:39:05 PM CST
 ************************************************************************/

#ifndef __VERSION__H
#define __VERSION__H

#ifdef __cplusplus
extern "C" {
#endif

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define VERSION_MAJOR  	  1
#define VERSION_MINOR     2
#define VERSION_REVISION  0
#define VERSION_STRING TOSTRING(VERSION_MAJOR) "." TOSTRING(VERSION_MINOR) "." TOSTRING(VERSION_REVISION)
#define VERSION_TEXT "Version: " VERSION_STRING " " __DATE__ " " __TIME__

#ifdef __cplusplus
}
#endif

#endif
