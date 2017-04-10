#include "LibParser.h"

void parse_component (xmlNode * a_node, Component &c) {
  xmlNode *cur_node = NULL;

  for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
    if (cur_node->type == XML_ELEMENT_NODE) {

      if (strcmp((const char*)cur_node->name, "dataIn") == 0){
        xmlAttr* attribute = cur_node->properties;
        //récupère la valeur des attributs nom et type puis on ajoute le port
        xmlChar* name;
        name = xmlNodeListGetString(cur_node->doc, attribute->children, 1);
        attribute = attribute->next;
        xmlChar* type;
        type = xmlNodeListGetString(cur_node->doc, attribute->children, 1);
        attribute = attribute->next;
        if(attribute){
          xmlChar* set;
          set = xmlNodeListGetString(cur_node->doc, attribute->children, 1);
          printf("dataIn name= %s, type= %s, set=%s\n", name, type, set);
          c.addInPort(new InPort((const char*)name, (const char*)type, (const char*)set));
          xmlFree(set);
        }
        else{
          printf("dataIn name= %s, type= %s\n", name, type);
          c.addInPort(new InPort((const char*)name, (const char*)type));
        }

        xmlFree(name);
        xmlFree(type);
      }

      else if (strcmp((const char*)cur_node->name, "dataOut") == 0){
        xmlAttr* attribute = cur_node->properties;
        xmlChar* name;
        name = xmlNodeListGetString(cur_node->doc, attribute->children, 1);
        attribute = attribute->next;
        xmlChar* type;
        type = xmlNodeListGetString(cur_node->doc, attribute->children, 1);

        printf("dataOut name = %s, type = %s\n", name, type);
        c.addOutPort(new OutPort((const char*)name, (const char*)type));

        xmlFree(name);
        xmlFree(type);
      }

      else{
        //preuve que l'on ne boucle pas pour rien
        printf("\n");
      }
    }
  }
}

void parse_inout (xmlNode * a_node, InOut &inout) {
  xmlNode *cur_node = NULL;

  for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
    if (cur_node->type == XML_ELEMENT_NODE) {

      if (strcmp((const char*)cur_node->name, "setPort") == 0){
        xmlAttr* attribute = cur_node->properties;
        xmlChar* in;
        in = xmlNodeListGetString(cur_node->doc, attribute->children, 1);
        attribute = attribute->next;
        xmlChar* out;
        out = xmlNodeListGetString(cur_node->doc, attribute->children, 1);

        printf("setPort in = %s, out = %s\n", in, out);
        SetPort lien = SetPort((const char*)in, (const char*)out);
        inout.addPort(lien);
      }
      //else if(strcmp(cur_node->name, "unsetPort") == 0){}
      else{
        //preuve que l'on ne boucle pas pour rien
        printf("\n");
      }
    }
  }
}

void parse_configPort (xmlNode * a_node, ConfigPort &ports) {
  xmlNode *cur_node = NULL;

  for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
    if (cur_node->type == XML_ELEMENT_NODE) {

      if (strcmp((const char*)cur_node->name, "inout") == 0){
        printf("parse_inout()\n");
        InOut inout = InOut();
        parse_inout(cur_node->children, inout);
        ports.setInOut(inout);
      }
      //else if(strcmp((const char*)cur_node->name, "clientserver") == 0){}
      else{
        //preuve que l'on ne boucle pas pour rien
        printf("\n");
      }
    }
  }
}

void parse_declaration (xmlNode * a_node, Declare *declare) {
  xmlNode *cur_node = NULL;

  for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
    if (cur_node && cur_node->type == XML_ELEMENT_NODE) {
      if (strcmp((const char*)cur_node->name, "component") == 0){
        printf("parse_component()\n");
        //on récupère son nom
        xmlAttr* attribute = cur_node->properties;
        xmlChar* name;
        name = xmlNodeListGetString(cur_node->doc, attribute->children, 1);
        //on crée l'objet
        Component c = Component((const char*)name);
        //on parse l'objet component (ses ports dataIn et dataOut)
        parse_component(cur_node->children, c);
        //on l'ajoute aux composants déclarés
        declare->addComponent((const char*)name, c);

        xmlFree(name);
      }
      else if (strcmp((const char*)cur_node->name, "instance") == 0){
        printf("parse_instance()\n");
        //on récupère ses attributs
        xmlAttr* attribute = cur_node->properties;
        xmlChar* name;
        name = xmlNodeListGetString(cur_node->doc, attribute->children, 1);

        attribute = attribute->next;
        xmlChar* componentRef;
        componentRef = xmlNodeListGetString(cur_node->doc, attribute->children, 1);

        attribute = attribute->next;
        xmlChar* path;
        path = xmlNodeListGetString(cur_node->doc, attribute->children, 1);

        attribute = attribute->next;
        xmlChar* signature;
        signature = xmlNodeListGetString(cur_node->doc, attribute->children, 1);

        printf("Instance name = %s, componentRef = %s, path = %s, signature = %s\n", name, componentRef, path, signature);
        Instance inst = Instance((const char*)name, (const char*)componentRef, (const char*)path, (const char*)signature);
        declare->addInstance((const char*)name, inst);

        xmlFree(name); xmlFree(componentRef);
        xmlFree(path); xmlFree(signature);
      }
      else if (strcmp((const char*)cur_node->name, "configPort") == 0){
        printf("parse_configPort()\n");
        //crée l'objet configPort, son inout et ses setPorts
        ConfigPort confports = ConfigPort();
        parse_configPort(cur_node->children, confports);
        declare->setPorts(confports);
      }
      else{
        //preuve que l'on ne boucle pas pour rien
        printf("\n");
      }
    }
  }
}

void parse_instruction (xmlNode * a_node) {
  printf("parse_instruction()....\n");
}

void parse_stcm (xmlNode * a_node, STCMAssembly *stcmassembly) {
  xmlNode *cur_node = NULL;

  for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
    if (cur_node->type == XML_ELEMENT_NODE) {

      if (strcmp((const char*)cur_node->name, "declare") == 0){
        printf("parse_declaration()\n");
        //crée l'objet component avec ses dataIn et dataOut
        parse_declaration(cur_node->children, stcmassembly->getDeclarations());
      }
      if (strcmp((const char*)cur_node->name, "instruction") == 0){
        printf("parse_instruction()\n");
        //TODO: crée l'objet instruction avec ses attributs
        //parse_instruction(cur_node->children, &stcmassembly);
        parse_instruction(cur_node->children);
      }
    }
    parse_stcm(cur_node->children, stcmassembly);
  }
}


void parser(const char* stcmXmlPath, STCMAssembly* assembly){
	std::cout << "parse()\n";

	xmlDoc *doc = NULL;
	xmlNode *root_element = NULL;

	doc = xmlReadFile(stcmXmlPath, NULL, 0);

	if (doc == NULL) {
		std::cerr << "error: could not parse file at '" << stcmXmlPath << "'\n";
	}
  else{
  	root_element = xmlDocGetRootElement(doc);
  	parse_stcm(root_element, assembly);
  }

	xmlFreeDoc(doc);
	xmlCleanupParser();

}
