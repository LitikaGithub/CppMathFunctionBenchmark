CXX      	:= 	g++
CXXFLAGS 	:= 	-flto -std=c++17 -Istdc++fs -fpermissive -Wall -m64 -DNDEBUG -O3
LDFLAGS	 	:=	-lm 
INCLUDE  	:= 	-I./


BUILD    	:= 	./build/linux
OBJ_DIR  	:= 	$(BUILD)/objects
APP_DIR  	:= 	$(BUILD)

TARGET   	:= 	CppMathFunctionBenchmark
SRC		:= 	$(wildcard ./*.cpp)
OBJECTS  	:= $(SRC:%.cpp=$(OBJ_DIR)/%.o)


all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)


.PHONY: all build clean debug release info

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rvf $(BUILD)

info:
	@echo "[*] Application dir: ${APP_DIR}     "
	@echo "[*] Object dir:      ${OBJ_DIR}     "
	@echo "[*] Sources:         ${SRC}         "
	@echo "[*] Objects:         ${OBJECTS}     "
	@echo "[*] Dependencies:    ${DEPENDENCIES}"