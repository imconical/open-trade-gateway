/////////////////////////////////////////////////////////////////////////
///@file http.h
///@brief	http 工具函数
///@copyright	上海信易信息科技股份有限公司 版权所有 
/////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <stdio.h>

long HttpGet(const char* url, std::string* response);