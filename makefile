
BUILDDIR=build/
BINDIR=bin/

CMAKE=cmake -S . -B $(BUILDDIR)

CMAKEMAKE=make -C $(BUILDDIR)

.PHONY : all clean directories generate-library generate-all build install

all :

clean :
	rm -rf $(BUILDDIR)* $(BUILDDIR).+ $(BINDIR)*
	rm -f log-*.txt

directories :
	mkdir -p $(BUILDDIR) $(BINDIR)

generate-library : clean directories
	$(CMAKE)

generate-all : clean directories
	$(CMAKE) -DBUILD_EXAMPLES=ON

build :
	$(CMAKEMAKE)

install : generate-library
	$(CMAKEMAKE) install