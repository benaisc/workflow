#include <libxml/parser.h>
#include <libxml/tree.h>
#include <string.h>
#ifdef LIBXML_TREE_ENABLED
//#include "STCMAssembly.h"

//static void parse_component (xmlNode * a_node, Component c) {
static void parse_component (xmlNode * a_node) {
  xmlNode *cur_node = NULL;

  for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
    if (cur_node->type == XML_ELEMENT_NODE) {

      if (strcmp(cur_node->name, "dataIn") == 0){
        xmlAttr* attribute = cur_node->properties;
        //récupère la valeur des attributs nom et type
        xmlChar* name;
        name = xmlNodeListGetString(cur_node->doc, attribute->children, 1);
        attribute = attribute->next;
        xmlChar* type;
        type = xmlNodeListGetString(cur_node->doc, attribute->children, 1);
        attribute = attribute->next;
        if(attribute){
          xmlChar* set;
          set = xmlNodeListGetString(cur_node->doc, attribute->children, 1);
          //c.addInPort(new InPort(name, type, set));
          printf("dataIn name= %s, type= %s, set=%s\n", name, type, set);
          xmlFree(set);
        }
        else{
          //c.addInPort(new InPort(name, type));
          printf("dataIn name= %s, type= %s\n", name, type);
        }

        xmlFree(name);
        xmlFree(type);
      }

      else if (strcmp(cur_node->name, "dataOut") == 0){
        xmlAttr* attribute = cur_node->properties;
        xmlChar* name;
        name = xmlNodeListGetString(cur_node->doc, attribute->children, 1);
        attribute = attribute->next;
        xmlChar* type;
        type = xmlNodeListGetString(cur_node->doc, attribute->children, 1);

        //c.addOutPort(new OutPort(name, type));
        printf("dataOut name = %s, type = %s\n", name, type);

        xmlFree(name);
        xmlFree(type);
      }

      else{
        //printf("#parse_component: Noeuds '%s' pas pris en charge !\n", cur_node->name);
        printf("\n");
      }
    }
  }
}

//static void parse_declaration (xmlNode * a_node, STCMAssembly assembly) {
static void parse_declaration (xmlNode * a_node) {
  xmlNode *cur_node = NULL;

  for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
    if (cur_node && cur_node->type == XML_ELEMENT_NODE) {
      if (strcmp(cur_node->name, "component") == 0){
        //on récupère son nom
        xmlAttr* attribute = cur_node->properties;
        xmlChar* name;
        name = xmlNodeListGetString(cur_node->doc, attribute->children, 1);
        //on crée l'objet
        //Component c = Component(name);
        printf("Component name = %s\n", name);
        //parse l'objet component (ses ports dataIn et dataOut)
        //parse_component(cur_node, &c);
        parse_component(cur_node->children);
        //assembly.addComponent(&c);

        xmlFree(name);
      }
      //case "instance":
      //TODO: crée l'objet instance avec ses attributs
      //break;
      //case "configport":
      //TODO: crée l'objet configPort, son inout et ses setPorts
      //break;
      else{
        //printf("#parse_declaration: Noeuds '%s' pas pris en charge !\n", cur_node->name);
        printf("\n");
      }
    }
    //parse_declaration(cur_node->children, &assembly);
    parse_declaration(cur_node->children);
  }
}

//static void parse_stcm (xmlNode * a_node, STCMAssembly stcmassembly) {
static void parse_stcm (xmlNode * a_node) {
  xmlNode *cur_node = NULL;

  for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
    if (cur_node->type == XML_ELEMENT_NODE) {

      if (strcmp(cur_node->name, "declare") == 0){
        //crée l'objet component avec ses dataIn et dataOut
        //parse_declaration(cur_node, &stcmassembly);
        parse_declaration(cur_node);
      }
      //case "instruction":
      //TODO: crée l'objet instruction avec ses attributs
      //break;
      else{
        //printf("#parse_stcm: Noeuds '%s' pas pris en charge !\n", cur_node->name);
        printf("\n");
      }
    }
    //parse_stcm(cur_node->children, &stcmassembly);
    parse_stcm(cur_node->children);
  }
}


int main(int argc, char **argv)
{
  xmlDoc *doc = NULL;
  xmlNode *root_element = NULL;

  if (argc != 2)
  return(1);

  LIBXML_TEST_VERSION

  doc = xmlReadFile(argv[1], NULL, 0);

  if (doc == NULL) {
    printf("error: could not parse file %s\n", argv[1]);
    return(1);
  }

  /*Get the root element node */
  root_element = xmlDocGetRootElement(doc);

  //STCMAssembly assembly;
  //parse_stcm(root_element, &assembly);
  parse_stcm(root_element);

  //assembly.wiggle();

  xmlFreeDoc(doc);
  xmlCleanupParser();
  return 0;
}
#else
int main(void) {
  fprintf(stderr, "Tree support not compiled in\n");
  exit(1);
}
#endif
