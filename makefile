
BUILDDIR=build/
BINDIR=bin/

.PHONY : build clean generate compile directories

all :

build : clean directories generate compile

clean :
	rm -rf $(BUILDDIR)* $(BINDIR)*
	rm -f log-*.txt

generate :
	cmake -S . -B $(BUILDDIR)

compile :
	make -C $(BUILDDIR)

directories :
	mkdir -p $(BUILDDIR) $(BINDIR)
