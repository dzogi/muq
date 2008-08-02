#!/usr/bin/env python

"""
This script is called from mk/Makeconf and receives the output of gcc -m -MG
The output of the script is saved to Makeconf.depend which exists in the 
build directory.

Example input:

main.o: /home/josip/dev/muq/kernel/src/common/main.c \
  /home/josip/b/config/config.h \
  /home/josip/dev/muq/kernel/include/x86/types.h

Output:

Makeconf.depend src/common/main.o: /home/josip/dev/muq/kernel/src/common/main.c \
  /home/josip/dev/build/config/config.h \
  /home/josip/dev/muq/kernel/include/x86/types.h

"""

import re
import sys

if not len(sys.argv) == 2:
    print "Usage: create_depends.py <SRCDIR>"

srcdir = sys.argv[1]

rgx =  r'(?P<name>.*)\.o:[ \t]+'
rgx += re.escape(srcdir)
rgx += r'\/(?P<dir>.*)\/(?P=name)(?P<ext>.*)'
f = open('/home/josip/bla', 'w')

rgx = re.compile(rgx)

replace =  r'Makeconf.depend \g<dir>/\g<name>.o: '
replace += srcdir
replace += r'/\g<dir>/\g<name>\g<ext>'

for line in sys.stdin.readlines():
    # gcc knows to output double slashes
    line = line.replace(r'//', r'/')
    print rgx.sub(replace, line),

f.close()
