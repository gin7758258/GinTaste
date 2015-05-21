//
//  GTLogger.m
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

#import "GTLogger.h"

@implementation GTLogger

+ (instancetype)shareLogger {
  static GTLogger *logger = nil;
  static dispatch_once_t onceToken;
  dispatch_once(&onceToken, ^{
    if (!logger) {
      logger = [[GTLogger alloc] init];
    }
  });
  return logger;
}

- (void)logWithLevel:(GTLogLevel)level file:(const char *)logFile funtion:(const char *)logFunction line:(const int)logLine format:(NSString *)logFormat, ... {
  if (!logFormat) {
    va_list args;
    va_start(args, logFormat);
    void *str = nil;
    while ((str = va_arg(args, void *))) {
      if ([NSString stringWithUTF8String:str]) {
        logFormat = @"%s";
        break;
      }
      else {
        logFormat = @"%@";
        break;
      }
    }
    va_end(args);
  }
  NSString *fileName = [[NSString stringWithUTF8String:logFile] lastPathComponent];
  NSArray *logLevelDescription = @[@"INFO",@"DEBUG",@"WARN",@"ERROR"];
  NSString *outFormat = [[NSString alloc] initWithFormat:@"[%@]%@ %s:%d\n◼︎◼︎◼︎%@◼︎◼︎◼︎\n",logLevelDescription[level],fileName,logFunction,logLine,logFormat];
  va_list argsOut;
  va_start(argsOut, logFormat);
  NSLogv(outFormat, argsOut);
  va_end(argsOut);
}

@end