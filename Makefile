CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		src/main.o

LIBS =

TARGET =	dst/eagel

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
