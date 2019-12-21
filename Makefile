# CXX= g++
# CXXFLAGS= -Wall -Wextra -g -O
# RM= rm -vf

OUT_DIR=./BUILD/object_files

./BUILD/AllegroWrappers.o: $(OUT_DIR)/*.o
	g++ $(OUT_DIR)/* -shared -o ./BUILD/AllegroWrappers.o

$(OUT_DIR)/Bitmap.o: ./src/Bitmap/Bitmap.cpp ./src/Bitmap/Bitmap.h
	g++ -c ./src/Bitmap/Bitmap.cpp -fPIC -o "$(OUT_DIR)/Bitmap.o";

$(OUT_DIR)/Transform.o: ./src/Transform/Transform.cpp ./src/Transform/Transform.h
	g++ -c ./src/Transform/Transform.cpp -fPIC -o "$(OUT_DIR)/Transform.o";

$(OUT_DIR)/Display.o: ./src/Display/Display.cpp ./src/Display/Display.h
	g++ -c ./src/Display/Display.cpp -fPIC -o "$(OUT_DIR)/Display.o";
