/**
 * source: http://xmlsoft.org/
 * section: Tree
 * synopsis: Navigates a tree to print element names
 * purpose: Parse a file to a tree, use xmlDocGetRootElement() to
 *          get the root element, then walk the document and print
 *          all the element name in document order.
 * test: tree1 test2.xml > tree1.tmp && diff tree1.tmp $(srcdir)/tree1.res
 * author: Dodji Seketeli
 * copy: see Copyright for the status of this software.
 */
#include <libxml/parser.h>
#include <libxml/tree.h>

#ifdef LIBXML_TREE_ENABLED

/*
 *To use this file using gcc you can type
 *make
 *./testParser yourfile.xml
 *NB: j'ai dû installer la librairie libxml2-dev
 */


 static void print_element_attributes(xmlNode * a_node)
 {
   xmlAttr* attribute = a_node->properties;
   xmlChar* value;
   while(attribute)
   {
     value = xmlNodeListGetString(a_node->doc, attribute->children, 1);
     printf("Attribute name: %s, value : %s\n", attribute->name, value);
     xmlFree(value);
     attribute = attribute->next;
   }
 }

/**
 * print_element_names:
 * @a_node: the initial xml node to consider.
 *
 * Prints the names of the all the xml elements
 * that are siblings or children of a given xml node.
 */
static void print_element_names (xmlNode * a_node) {
    xmlNode *cur_node = NULL;

    for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
        if (cur_node->type == XML_ELEMENT_NODE) {
            printf("Element name: %s\n", cur_node->name);
            print_element_attributes(cur_node);
        }

        print_element_names(cur_node->children);
    }
}


/*
static void parse_element_attributes(xmlNode * a_node)
{
  xmlAttr* attribute = a_node->properties;
  xmlChar* value;
  while(attribute)
  {
    value = xmlNodeListGetString(a_node->doc, attribute->children, 1);
    printf("Attribute name: %s, value : %s\n", attribute->name, value);
    xmlFree(value);
    attribute = attribute->next;
  }
}
static void parse_declaration (xmlNode * a_node) {
    xmlNode *cur_node = NULL;

    for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
        if (cur_node->type == XML_ELEMENT_NODE) {
            printf("Element name: %s\n", cur_node->name);
            //print_element_attributes(cur_node);
            switch (cur_node->name) {
              case "component":
                //TODO: crée l'objet component avec ses dataIn et dataOut
                break;
              case "instance":
                //TODO: crée l'objet instance avec ses attributs
                break;
              case "configport":
                //TODO: crée l'objet configPort, son inout et ses setPorts
                break;
              default:
                std::cout << cur_node->name << " pas pris en charge !" << '\n';
            }
        }
        parse_element_names(cur_node->children);
    }
}
static STCMAssembly parse_stcm (xmlNode * a_node) {
    STCMAssembly stcmassembly;
    xmlNode *cur_node = NULL;

    for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
        if (cur_node->type == XML_ELEMENT_NODE) {
            printf("Element name: %s\n", cur_node->name);
            //print_element_attributes(cur_node);
            switch (cur_node->name) {
              case "declare":
                //TODO: crée l'objet component avec ses dataIn et dataOut
                parse_declaration(cur_node);
                break;
              //case "instruction":
                //TODO: crée l'objet instance avec ses attributs
                //break;
              default:
                std::cout << cur_node->name << " pas pris en charge !" << '\n';
            }
        }
    }

    return stcmassembly;
}
*/
/**
 * Simple example to parse a file called "file.xml",
 * walk down the DOM, and print the name of the
 * xml elements nodes.
 */
int main(int argc, char **argv)
{
    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;

    if (argc != 2)
        return(1);

    /*
     * this initialize the library and check potential ABI mismatches
     * between the version it was compiled for and the actual shared
     * library used.
     */
    LIBXML_TEST_VERSION

    /*
    * parse the file and get the DOM
    * voir http://xmlsoft.org/html/libxml-parser.html#xmlReadFile
    * ici, on le SUPPOSE bien-formé
    */
    doc = xmlReadFile(argv[1], NULL, 0);

    if (doc == NULL) {
        printf("error: could not parse file %s\n", argv[1]);
        return(1);
    }

    /*Get the root element node */
    root_element = xmlDocGetRootElement(doc);

    print_element_names(root_element);

    /*free the document */
    xmlFreeDoc(doc);

    /*
     *Free the global variables that may
     *have been allocated by the parser.
     */
    xmlCleanupParser();

    return 0;
}
#else
int main(void) {
    fprintf(stderr, "Tree support not compiled in\n");
    exit(1);
}
#endif
