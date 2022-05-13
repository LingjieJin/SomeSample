SrcFile := ../../src

CXX	:= g++
CXXFLAGS	:= --std=c++11
LDFLAGS :=
LIBS	:= -lmosquitto -lmosquittopp -lpthread


OBJS	:=SysTime.o cjson.o fileediter.o logger.o mqtt.o log_writer.o main.o


.PHONY: all clean


all : $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o main $(LIBS) 
	-rm $(OBJS)


SysTime.o : $(SrcFile)/sys/SysTime.cpp
	$(CXX) $(CXXFLAGS) -c $(SrcFile)/sys/SysTime.cpp -o SysTime.o

cjson.o : $(SrcFile)/file/cJSON.c
	$(CXX) $(CXXFLAGS) -c $(SrcFile)/file/cJSON.c -o cjson.o

fileediter.o : $(SrcFile)/file/FileEditer.cpp
	$(CXX) $(CXXFLAGS) -c $(SrcFile)/file/FileEditer.cpp -o fileediter.o

logger.o : $(SrcFile)/logger/Logger.cpp
	$(CXX) $(CXXFLAGS) -c $(SrcFile)/logger/Logger.cpp -o logger.o

mqtt.o : $(SrcFile)/mqtt_lib/TMqttClient.cpp
	$(CXX) $(CXXFLAGS) -c $(SrcFile)/mqtt_lib/TMqttClient.cpp -o mqtt.o

log_writer.o : ./mqtt_logwriter.cpp
	$(CXX) $(CXXFLAGS) -c ./mqtt_logwriter.cpp -o log_writer.o

main.o : ./main.cpp
	$(CXX) $(CXXFLAGS) -c ./main.cpp -o main.o

clean:
	-rm main $(OBJS)














