import sys

name = sys.argv[1]
name += ".cpp"
f = open(name, "w+")

f.write("#include <bits/stdc++.h>\n")
f.write("using namespace std;\n\n")
f.write("int main() {\n\n\n\n}")

f.close()
