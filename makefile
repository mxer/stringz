cc=gcc
ld=gcc
cflags=-O3 -g0
lflags=-L. -lc -lstringz

obj=sdata.o strcatz.o strcombz.o strfillz.o strlistz.o strmergez.o strrevz.o strsplitz.o strtrimz.o strtruncz.o

test : main.o libstringz.a
	$(ld) -o $@ main.o $(lflags)

libstringz.a : $(obj) stringz.h
	ar cr $@ $(obj)

%.o : %.c stringz.h
	$(cc) $(cflags) -c -o $@ $<

install:
	cp stringz.h $(install_root)/include
	cp libstringz.a $(install_root)/lib

clean:
	rm test
	rm *.o
	rm *.a
