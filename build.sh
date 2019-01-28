CONFIGURE_OPTS=""

set e

if [ "$1" == "ycm" ]; then
	git clean -xi
	autoreconf -vfi
	ycm_generator -f -b autotools   --verbose . --configure_opts="$CONFIGURE_OPTS"
	exit 0
fi

./autogen.sh

#mkdir -p build; cd build
#set e

cd src

if [ "$1" == "win" ]; then
	../configure --prefix=/mingw64
else
	  ../configure --prefix=/usr $CONFIGURE_OPTS -C

	  #NOTE: flag -C enables use of cache, will need to manually delete cache if new package is installed
	# might not work with some third party macros [https://www.gnu.org/savannah-checkouts/gnu/autoconf/manual/autoconf-2.69/html_node/Caching-Results.html#Caching-Results]
fi
make -j6

#git submodule foreach git clean -xdf

