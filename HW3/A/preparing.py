#!/usr/bin/python3
f = open("index.h", "w")
f.write("#include <iostream>\n")
f.write("void show() {\n")
f.write("std::cout << \"index.h works\" << std::endl;\n")
f.write("}\n")
f.close()