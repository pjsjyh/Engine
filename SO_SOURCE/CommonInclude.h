#pragma once
#include <Windows.h>

#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <functional>
#include <stack>
#include <queue>
//FILESYSTEM을 넣으면 CTIME에서 오류발생
//아직까지 원인불명상태
//임의로 재정의 해서 실행되도록만 해둠 추후수정필요
extern "C" {
    struct tm;
    char* localtime(const struct tm*);
    char* clock_t(const struct tm*);
    char* clock(const struct tm*);
    char* difftime(const struct tm*);
    char* ctime(const struct tm*);
    char* gmtime(const struct tm*);
    char* strftime(const struct tm*);
    char* mktime(const struct tm*);
    char* time(const struct tm*);
    char* asctime(const struct tm*);
    char* timespec(const struct tm*);

    char* timespec_get(const struct tm*);
}
#include <filesystem>
#include <math.h>


#include "soMath.h"
#include <mmsystem.h>
#include <dinput.h>
#pragma comment(lib, "Msimg32.lib")
#pragma comment(lib, "winmm.lib")

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

#include "Enums.h"