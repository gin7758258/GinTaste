//
//  GTLogger.h
//  Customize for NSLog
//
//  Copyright (c) 2015 Gin Van
//
//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//  IN THE SOFTWARE.
//

#import <Foundation/Foundation.h>

// Log Level
typedef NS_ENUM(NSInteger, GTLogLevel) {
  GTLLINFO = 0,
  GTLLDEBUG,
  GTLLWARN,
  GTLLERROR
};

// Actual Use Marco
#if defined(__GTLOG_ON__) && __GTLOG_ON__
#define GTLOG(string)                                                          \
  [[GTLogger shareLogger] logWithLevel:GTLLINFO file:__FILE__ funtion:__PRETTY_FUNCTION__ line:__LINE__ format:nil, string]
#define GTINFO(format, ...)                                                    \
  [[GTLogger shareLogger] logWithLevel:GTLLINFO file:__FILE__ funtion:__PRETTY_FUNCTION__ line:__LINE__ format:format, ##__VA_ARGS__]
#define GTDEBUG(format, ...)                                                   \
  [[GTLogger shareLogger] logWithLevel:GTLLDEBUG file:__FILE__ funtion:__PRETTY_FUNCTION__ line:__LINE__ format:format, ##__VA_ARGS__]
#define GTWARN(format, ...)                                                    \
  [[GTLogger shareLogger] logWithLevel:GTLLWARN file:__FILE__ funtion:__PRETTY_FUNCTION__ line:__LINE__ format:format, ##__VA_ARGS__]
#define GTERROR(format, ...)                                                   \
  [[GTLogger shareLogger] logWithLevel:GTLLERROR file:__FILE__ funtion:__PRETTY_FUNCTION__ line:__LINE__ format:format, ##__VA_ARGS__]
#else
  #define GTLOG(string)         do{}while(0)
  #define GTINFO(format, ...)   do{}while(0)
  #define GTDEBUG(format, ...)  do{}while(0)
  #define GTWARN(format, ...)   do{}while(0)
  #define GTERROR(format, ...)  do{}while(0)
#endif

@interface GTLogger : NSObject

/**
 *  Quick instance class method
 *
 *  @return instance with type GTLogger*
 */
+ (instancetype)shareLogger;

/**
 *  Logger format method, isn't recommend directly use.Please use MARCO ablove like:
 *  GTLog(char *|NSString) - Simplest log function.It can use C type string or NSString type string param. BUT C type string is only support ASCII encode.
 *  GTINFO(format, ...)   -   Output INFO level log message.
 *  GTDEBUG(format, ...)  -   Output DEBUG level log message.
 *  GTWARN(format, ...)   -   Output WARN level log message.
 *  GTERROR(format, ...)  -   Output ERROR level log message.
 *
 *  @param level       Log Level.
 *  @param logFile     The file which raise log, usually incoming __FILE__.
 *  @param logFunction The Function which raise log, usually incoming __PRETTY_FUNCTION__.
 *  @param logLine     Line number in source file to raise log, usually incoming __LINE__.
 *  @param logFormat   Format string.
 */
- (void)logWithLevel:(GTLogLevel)level file:(const char *)logFile funtion:(const char *)logFunction line:(const int)logLine format:(NSString *)logFormat, ...;

@end





