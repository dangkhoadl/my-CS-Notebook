/*
https://www.hackerrank.com/challenges/attribute-parser

We have defined our own markup language HRML.
In HRML, each element consists of a starting and ending tag, and there are attributes associated with each tag.
Only starting tags can have attributes. We can call an attribute by referencing the tag, followed by a tilde,
'~' and the name of the attribute. The tags may also be nested.

The opening tags follow the format:
	<tag-name attribute1-name = "value1" attribute2-name = "value2" ... >

The closing tags follow the format:
	< /tag-name >

For example:
	<tag1 value = "HelloWorld">
	<tag2 name = "Name1">
	</tag2>
	</tag1>

The attributes are referenced as:
	tag1~value  
	tag1.tag2~name

You are given the source code in HRML format consisting of  lines. 
You have to answer  queries. Each query asks you to print the value of the attribute specified.
 Print "Not Found!" if there isn't any such attribute.

Input Format
	The first line consists of two space separated integers,  and .  specifies the number of lines in the HRML source program. 
	specifies the number of queries.
	The following  lines consist of either an opening tag with zero or more attributes or a closing tag.
	 queries follow. Each query consists of string that references an attribute in the source program.

Constraints
	Each line in the source program contains, at max,  characters. 
	Every reference to the attributes in the  queries contains at max  characters. 
	All tag names are unique.

Output Format
	Print the value of the attribute for each query. Print "Not Found!" without quotes if there is no such attribute in the source program.

Sample Input
	4 3
	<tag1 value = "HelloWorld">
	<tag2 name = "Name1">
	</tag2>
	</tag1>
	tag1.tag2~name
	tag1~name
	tag1~value

Sample Output
	Name1
	Not Found!
	HelloWorld
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <set>
#include <iomanip>
#include <sstream>

using namespace std;

struct Attribute {
	string name;
	string value;
};
typedef struct Attribute Attribute;

struct Tag {
	string name;
	vector<Tag> children;
	vector<Attribute> attr;
	Tag* parent;
};
typedef struct Tag Tag;

vector<Attribute> getAttributes(stringstream &ss) {
	vector<Attribute> attributes;

	bool nameflag = true;
	bool attrflag = false;
	string name = "";
	string attr = "";
	char ch;

	// Get attributes
	while (!ss.eof()) {
		ss >> ch;
		if (ch == '>') break;

		if (nameflag) {
			if (ch != ' ' && ch != '=') name.push_back(ch);
			else nameflag = false;
			continue;
		}

		if (ch == '"' && !attrflag) {
			attrflag = true;
			continue;
		}

		if (attrflag) {
			if (ch != ' ' && ch != '"') attr.push_back(ch);
			else {
				attrflag = false; nameflag = true;
				attributes.push_back(Attribute{ name, attr });
				name = ""; attr = "";
			}
			continue;
		}
	}

	return attributes;
}

string findAttr(Tag *root, string atr) {
	bool found = false;

	vector<Attribute>::iterator it;
	for (it = root->attr.begin(); it < root->attr.end(); it++) {
		if (it->name == atr) { return it->value; };
	}
	return "";
}

Tag* FindTag(Tag *root, string name) {
	vector<Tag>::iterator it;
	for (it = root->children.begin(); it < root->children.end(); it++) {
		if ((*it).name == name) {
			return &(*it);
		}
	}
	return NULL;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N, Q;
	stringstream ss;
	string line;
	string out;

	Tag *root = new Tag{ "root", vector<Tag>(), vector<Attribute>(),NULL };
	Tag *current = root;
	Tag *newTag;
	vector<Attribute> newAttrs;

	getline(cin, line);
	ss.str(line);
	ss >> N >> Q;
	ss.str("");
	ss.clear();

	while (N--) {
		getline(cin, line);

		if (line.find("</") == -1) {                         //opening tag 
			string tagname;
			char ch;
			ss.str("");
			ss.clear();
			ss.str(line);
			// Get name of tag
			ss >> ch >> tagname;

			int tag_idx = tagname.find(">");
			if (tag_idx != -1) tagname = tagname.substr(0, tag_idx);

			// Get attributes
			newAttrs = getAttributes(ss);

			newTag = new Tag{ tagname, vector<Tag>(), newAttrs, current };
			current->children.push_back(Tag{ tagname, vector<Tag>(), newAttrs, current });
			current = &(current->children.back());
		}
		else {                                              //closing tag
			current = current->parent;
		}
	}

	// Do queries
	while (Q--) {
		current = root;
		string token;
		getline(cin, line);
		istringstream iss(line);
		vector<string> query;
		vector<Tag>::iterator it;

		while (getline(iss, token, '.')) {
			int attr_idx = token.find("~");
			if (attr_idx != -1) {
				string tag = token.substr(0, attr_idx);
				// Look for tag
				current = FindTag(current, tag);

				if (current == NULL) {
					cout << "Not Found!" << endl;
					break;
				}
				string atr = token.substr(attr_idx + 1, token.length() - 1);
				out = findAttr(current, token.substr(attr_idx + 1, token.length() - 1));

				if (out != "") {
					cout << out << endl;
				}
				else cout << "Not Found!" << endl;
			}
			else {
				// Look for tag
				current = FindTag(current, token);

				if (current == NULL) {
					cout << "Not Found!" << endl;
					break;
				}
			}
		}
	}
    return 0;
}