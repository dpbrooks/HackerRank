/*
 * Parse lines of the custom HRML language made up of tags, attributes and
 * attribute values. Then read and execute queries to return the value of
 * an attribute tied to a tag or return that it does not exist
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    // Number of tags equals n/2 because n include end tags
    int n, q;
    string curr = "";
    string attrName;
    map<string, string> m;
    cin >> n >> q;
    // Use cin.ignore() to make sure you start on the next line when parsing tags
    cin.ignore();
    
    // Loop to parse through tags
    // Use extract to pull out sections of line being parsed
    string line, tag, extract;
    for (int i = 0; i < n; i++) {
        // Get the next line to be parsed
        getline(cin, line);
        stringstream ss(line);
        
        // Process HRML line, use ' ' as delim
        while(getline(ss, extract, ' ')) {
            // Check if extract is a tag
            if (extract[0] == '<') {
                // Check if opening tag
                if (extract[1] != '/') {
                    // Is an opening tag, remove '<'
                    tag = extract.substr(1);
                    
                    if (tag[tag.length() - 1] == '>') {
                        // Remove closing '>'
                        tag.pop_back();
                    }
                    // Check if nesting is needed
                    if (curr.size() > 0) {
                        // Nest tag
                        curr += "." + tag;
                    } else {
                        curr = tag;
                    }
                } else {
                    // Closing tag
                    tag = extract.substr(2, (extract.find('>') - 2));
                    // Check if a nested tag has to be closed
                    
                    size_t pos = curr.find("." + tag);
                    if (pos != string::npos) {
                        // Remove nested tag
                        curr = curr.substr(0, pos);
                    } else {
                        // All tags are closed
                        curr = "";
                    }
                }
            // Check if extract is an attribute's value
            } else if (extract[0] == '"') {
                // Get full value
                size_t pos = extract.find_last_of('"');
                string attrValue = extract.substr(1, pos - 1);
                // Add to the map
                m[attrName] = attrValue;
            } else {
                if (extract != "=") {
                    // Extract is an attribute name
                    attrName = curr + "~" + extract;
                }
            }
        }
    }
    
    // Loop to handle queries
    string query;
    for (int i = 0; i < q; i++) {
        getline(cin, query);
        
        // Search the map
        map<string, string>::iterator it = m.find(query);
        if (it != m.end()) {
            cout << it->second << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }
    return 0;
}
