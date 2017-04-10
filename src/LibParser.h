#ifndef __PARSER_H__
#define __PARSER_H__

#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "STCMAssembly.h"


void parse_component (xmlNode * a_node, Component &c);

void parse_inout (xmlNode * a_node, InOut &inout);

void parse_configPort (xmlNode * a_node, ConfigPort &ports);

void parse_declaration (xmlNode * a_node, Declare * declare);

void parse_instruction (xmlNode * a_node); //TODO

void parse_stcm (xmlNode * a_node, STCMAssembly * stcmassembly);

void parser(const char * stcmXmlPath, STCMAssembly * assembly);

#endif
