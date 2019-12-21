# g++ main.cpp $(find ./src | grep -E ".*.cpp$" | while read line; do printf "$line "; done) -lpthread -lallegro -lallegro_image 

# find ./src -iname "*.cpp"
BUILD_OUT="./BUILD/allegro_wrappers.o"

export build_list="";

if [ -e "$BUILD_OUT" ]; then

	echo "$BUILD_OUT exists. Checking if the version is up to date...";
	find ./src -iname "*.cpp" | while read line; do
		if [ "$line" -nt "$BUILD_OUT" ]; then 
			echo "Changes to file $line were found."
			build_list+=$line;
		fi
	done;

else
	echo "$BUILD_OUT does not exist. building project..."
	find ./src -iname "*.cpp" | while read line; do
		build_list+=$line;
	done;
fi;

echo $build_list;