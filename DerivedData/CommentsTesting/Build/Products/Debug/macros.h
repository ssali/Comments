/* Copyright 2011 Mezeo Software Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* This will unleash more information than you should ever need */
//#define INSANE_DEBUG 1

#undef INSANE_DEBUG

#define CONCAT(s1, s2) s1 s2

/*
 Trace Macro
 */
#define MTRACE(...) NSLog(__VA_ARGS__);

#define _RELEASE(x) if(x) { [x release]; x = nil;}
/*
 Function Entry Macro
 */
#ifdef INSANE_DEBUG
#   define MTRACE_ENTRY NSLog(@"[ENTRY] %s (%d)", __PRETTY_FUNCTION__, __LINE__);
#else
#   define MTRACE_ENTRY
#endif

/*
 Function Exit Macro
 */
#ifdef INSANE_DEBUG
#   define MTRACE_EXIT NSLog(@"[EXIT] %s (%d)", __PRETTY_FUNCTION__, __LINE__);
#else
#   define MTRACE_EXIT
#endif

/*
 Informational Message
 */
#ifdef DEBUG
#   define MINFO(msg) MTRACE(@CONCAT("[INFO] %s (%d): ", msg), __PRETTY_FUNCTION__, __LINE__)
#else
#   define MINFO(msg)
#endif

/*
 Debug Message
 */
#ifdef DEBUG
#   define MDEBUG(fmt, ...) MTRACE(@CONCAT("[DEBUG] %s (%d): ", fmt), __PRETTY_FUNCTION__, __LINE__, __VA_ARGS__)
#else
#   define MDEBUG(fmt, ...)
#endif

/*
 Error Message
 */
#define MERROR(fmt, ...) MTRACE(@CONCAT("[ERROR] %s (%d): ", fmt), __PRETTY_FUNCTION__, __LINE__, __VA_ARGS__)

/*
 NSError trace
 */
#define MNSERROR(err) if(err) { MTRACE(@"[NSError] %s (%d): (%d:%@) Reason: %@", __PRETTY_FUNCTION__, __LINE__, err.code, err.domain, err.localizedDescription) }

/*
 Exception Message
 */
#define MEXCEPTION(e) MTRACE(@"[EXCEPTION] %s (%d): %@ (%@ || %@)", __PRETTY_FUNCTION__, __LINE__, e.name, e.reason, e.userInfo)
