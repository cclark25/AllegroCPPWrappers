CXX= g++
CXXFLAGS= -std=c++11
# RM= rm -vf

OUT_DIR=./BUILD/object_files

./BUILD/AllegroWrappers.o: $(OUT_DIR)/Bitmap.o $(OUT_DIR)/Transform.o $(OUT_DIR)/Display.o
	$(CXX) $(CXXFLAGS)  $(OUT_DIR)/* -shared -o ./BUILD/AllegroWrappers.o

$(OUT_DIR)/Bitmap.o: ./src/Bitmap/Bitmap.cpp ./src/Bitmap/Bitmap.h
	$(CXX) $(CXXFLAGS)  -c ./src/Bitmap/Bitmap.cpp -fPIC -o "$(OUT_DIR)/Bitmap.o";

$(OUT_DIR)/Transform.o: ./src/Transform/Transform.cpp ./src/Transform/Transform.h
	$(CXX) $(CXXFLAGS)  -c ./src/Transform/Transform.cpp -fPIC -o "$(OUT_DIR)/Transform.o";

$(OUT_DIR)/Display.o: ./src/Display/Display.cpp ./src/Display/Display.h
	$(CXX) $(CXXFLAGS)  -c ./src/Display/Display.cpp -fPIC -o "$(OUT_DIR)/Display.o";
