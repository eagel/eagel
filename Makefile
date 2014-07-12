CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -Ilib/boost/inc -Iinc

OBJS =		src/main.o

LIBS =		lib/boost/lib/libboost_system.a

TARGET =	dst/eagel

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
