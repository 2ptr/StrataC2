//
// Created by jake.otte on 5/12/2025.
//

#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>

// COMPILER
const std::string EXE_FILETYPE = "Windows EXE";
const std::string DLL_FILETYPE = "Windows DLL";
const std::string HTTP_SRC_DIR = "../agents/http";
const std::string HTTP_TEMPLATE_FILEPATH = "../agents/http/conf/Config.template";
const std::string HTTP_CONFIG_FILEPATH = "../agents/http/conf/Config.h";
const std::string SLEEP_TEMPLATE_MARKER = "@SLEEP_VALUE@";
const std::string CALLBACKS_TEMPLATE_MARKER = "@CALLBACKS_MAP@";

// COMMAND STUFF
const std::string MSG_COMMAND_SENT = "[*] Commands sent to Agent...\n";
const std::string MSG_OUTPUT_RECEIVED = "[+] Received command output:\n";
const std::string MSG_COMMAND_QUEUED = "[*] Command added to Agent's queue.\n";
const std::string CMD_HELP = "============ Local commands ============\n"
"help - Display this help message.\n"
"queue - View Agent command queue.\n"
"\n"
"============ Agent commands ============\n"
"sleep - Set Agent sleep time.\n"
"die - Kill Agent.\n"
"\n"
"============ Built-in commands ============\n"
"pwd - Print working directory.\n"
"ls - List working directory.\n"
"cd - Change working directory.\n"
"cat - Read file.\n"
"rm - Remove file.\n"
"cp - Copy file.\n"
"mv - Move file.\n"
"shell - Execute shell command. -- DANGER\n"
"powershell - Execute powershell command. -- DANGER\n"
"\n"
"============ .NET commands ============\n"
"assembly list - List imported .NET assemblies.\n"
"assembly rm [assembly name] - Remove imported .NET assembly.\n"
"assembly [assembly name] [arguments] - Execute .NET assembly with arguments.\n"
"========================================";


#endif //CONSTANTS_H
