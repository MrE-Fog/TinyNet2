/*
 *  CopyRight  2014 , bingyu.song   All Right Reserved
    I believe  Spring brother
 */

#ifndef     _LOG_H_
#define     _LOG_H_


#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<string.h>

// TODO : add write file, color control ,  option ...

class Log
{

public:
    enum LogLevel
    {
        INFO,
        DEBUG,
        WARN,
        ERROR,
    };

    enum
    {
        MAX_LOG_LEN = 1024,
    };

public :

    void    static  WriteLog(const char* logLevel,const  char* file, const int  line, const char* date, const char* time , const char* fmt , ...  )
    {

            char  buf[ MAX_LOG_LEN ] = { 0 };
            char  logbuf[ 512 ]      = { 0 };

            va_list  ap;

            va_start(ap, fmt);
            (void) vsnprintf( logbuf , 512 , fmt, ap);
            va_end(ap);

            sprintf(buf,"[%s]%s %s %s %d : ", logLevel, date, time, file, line );
            strcat( buf, logbuf );
            strcat( buf, "\n"   );
            printf( buf );
    }

};

#define     LOG_INFO(  fmt, args... )    Log::WriteLog( "INFO",   __FILE__, __LINE__, __DATE__, __TIME__, fmt, args  )
#define     LOG_DEBUG( fmt, args... )    Log::WriteLog( "DEBUG",  __FILE__, __LINE__, __DATE__, __TIME__, fmt, args  );
#define     LOG_WARN(  fmt, args... )    Log::WriteLog( "WARN",   __FILE__, __LINE__, __DATE__, __TIME__, fmt, args  );
#define     LOG_ERROR( fmt, args... )    Log::WriteLog( "ERROR",  __FILE__, __LINE__, __DATE__, __TIME__, fmt, args  );



#endif // _LOG_H_


