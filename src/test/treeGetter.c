/**
 * source: http://xmlsoft.org/tutorial/ar01s05.html
 * section: xpath
 * synopsis: retrieve sets of nodes that match a specified criteria
 * purpose: search through a document for the contents of
 * 					all *keyword* elements.
*/

#include <libxml/parser.h>
#include <libxml/xpath.h>


xmlXPathObjectPtr getnodeset (xmlDocPtr doc, xmlChar *balise){
	xmlXPathContextPtr context;
	xmlXPathObjectPtr result;

	//Initialize the context variable.
	context = xmlXPathNewContext(doc);
	if (context == NULL) {
		printf("Error in xmlXPathNewContext\n");
		return NULL;
	}
	//Apply the XPath expression.
	result = xmlXPathEvalExpression(balise, context);
	xmlXPathFreeContext(context);
	if (result == NULL) {
		printf("Error in xmlXPathEvalExpression\n");
		return NULL;
	}
	//Check result and free the memory allocated if balise isnt found.
	if(xmlXPathNodeSetIsEmpty(result->nodesetval)){
		xmlXPathFreeObject(result);
		printf("No result for '%s'\n",balise);
		return NULL;
	}
	return result;
}

void printerTestFun(xmlXPathObjectPtr xPathObj){
	if (xPathObj) {
		xmlNodeSetPtr nodeset = xPathObj->nodesetval;
		xmlChar *keyword;
		int i;
		for (i=0; i < nodeset->nodeNr; i++) {
			keyword = xmlNodeListGetString(nodeset->nodeTab[i]->doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
			printf("Name : %s, keyword: %s\n",nodeset->nodeTab[i]->name, keyword);
			xmlFree(keyword);
		}
		xmlXPathFreeObject(xPathObj);
	}
}

int main (int argc, char **argv) {
	xmlDocPtr doc;
	xmlChar *xpath = (xmlChar*) "/stcmassembly/*";
	xmlXPathObjectPtr result;

	if (argc < 2) {
		printf("Usage: %s docname\n", argv[0]);
		return(0);
	}

	doc = xmlParseFile(argv[1]);

	if (doc == NULL ) {
		fprintf(stderr,"Document not parsed successfully.\n");
		return(0);
	}

	result = getnodeset(doc, xpath);

	if (result) {
		printerTestFun(result);
	}

	xmlFreeDoc(doc);
	xmlCleanupParser();
	return (1);
}
