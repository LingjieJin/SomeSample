#ifndef __LOG_H__
#define __LOG_H__

// Regular
#define NRM      "\x1B[0m"
#define TXT_RED  "\x1B[31m"
#define TXT_GRN  "\x1B[32m"
#define TXT_YEL  "\x1B[33m"
#define TXT_BLU  "\x1B[34m"
#define TXT_MAG  "\x1B[35m"
#define TXT_CYN  "\x1B[36m"
#define TXT_WHT  "\x1B[37m"
// Bold
#define BLD_RED  "\e[1;31m"
#define BLD_GRN  "\e[1;32m"
#define BLD_YEL  "\e[1;33m"
#define BLD_BLU  "\e[1;34m"
#define BLD_MAG  "\e[1;35m"
#define BLD_CYN  "\e[1;36m"
// Underline
#define UND_RED  "\e[4;31m"
#define UND_GRN  "\e[4;32m"
#define UND_YEL  "\e[4;33m"
#define UND_BLU  "\e[4;34m"
#define UND_MAG  "\e[4;35m"
#define UND_CYN  "\e[4;36m"
// Background
#define BAK_RED  "\e[41m"
#define BAK_GRN  "\e[42m"
#define BAK_YEL  "\e[43m"
#define BAK_BLU  "\e[44m"
#define BAK_MAG  "\e[45m"
#define BAK_CYN  "\e[46m"

#define LOGINFO

#ifdef LOGINFO
#define LOG_TRACE(...)  printf("%s[TRACE]%s ", BLD_MAG, NRM); printf(__VA_ARGS__); printf("\n")
#define LOG_TRACE_PRO(...) printf("%s[TRACE]%s %sPROPOSER ", BLD_MAG, NRM, TXT_RED); printf(__VA_ARGS__); printf("%s\n", NRM)
#define LOG_TRACE_ACC(...) printf("%s[TRACE]%s %sACCEPTOR ", BLD_MAG, NRM, TXT_GRN); printf(__VA_ARGS__); printf("%s\n", NRM)
#define LOG_TRACE_CAP(...) printf("%s[TRACE]%s %sCAPTAIN ", BLD_MAG, NRM, TXT_CYN); printf(__VA_ARGS__); printf("%s\n", NRM)
#define LOG_TRACE_COM(...) printf("%s[TRACE]%s %sCOMMO ", BLD_MAG, NRM, TXT_YEL); printf(__VA_ARGS__); printf("%s\n", NRM)
#else
#define LOG_TRACE(...)
#define LOG_TRACE_PRO(...) 
#define LOG_TRACE_ACC(...) 
#define LOG_TRACE_CAP(...) 
#define LOG_TRACE_COM(...) 
#endif



#endif